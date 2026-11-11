#!/usr/bin/env bash
# Run a command inside the rac-build container (see Dockerfile next to this
# file), with the repository mounted at the same path it has on the host so
# paths in logs and tool output line up. Builds the image on first use.
#
#   bash tools/docker/run.sh bash tools/setup_asm.sh
#   bash tools/docker/run.sh bash tools/build.sh
set -euo pipefail
repo=$(cd "$(dirname "$0")/../.." && pwd)
# Inside OpenRAC (games/rac4/decomp, a submodule), mount OpenRAC's whole
# checkout, its top being the nearest parent with games/rac4/game.json, so
# its shared baserom/ and toolchains are visible in the container at the same
# paths. Elsewhere, only this repository.
mount=$repo
dir=$(dirname "$repo")
while [ "$dir" != / ]; do
  if [ -f "$dir/games/rac4/game.json" ]; then
    mount=$dir
    break
  fi
  dir=$(dirname "$dir")
done
CONTAINER_CLI="${CONTAINER_CLI:-}"
if [ -z "$CONTAINER_CLI" ]; then
  if command -v podman >/dev/null 2>&1; then
    CONTAINER_CLI="podman"
  elif command -v docker >/dev/null 2>&1; then
    CONTAINER_CLI="docker"
  else
    echo "Error: Neither podman nor docker found in PATH" >&2
    exit 1
  fi
fi

GHCR_IMAGE="${RAC_BUILD_IMAGE:-ghcr.io/lynder063/rac1-build:latest}"
if [ "$CONTAINER_CLI" = "podman" ]; then
  LOCAL_IMAGE="localhost/rac1-build:latest"
else
  LOCAL_IMAGE="rac-build:latest"
  # rac1-decomp builds the same image locally under this name.
  if ! $CONTAINER_CLI image inspect "$LOCAL_IMAGE" >/dev/null 2>&1 \
     && $CONTAINER_CLI image inspect "rac1-build:latest" >/dev/null 2>&1; then
    LOCAL_IMAGE="rac1-build:latest"
  fi
fi
IMAGE_TO_RUN=""

if $CONTAINER_CLI image inspect "$LOCAL_IMAGE" >/dev/null 2>&1; then
  IMAGE_TO_RUN="$LOCAL_IMAGE"
elif $CONTAINER_CLI image inspect "$GHCR_IMAGE" >/dev/null 2>&1; then
  IMAGE_TO_RUN="$GHCR_IMAGE"
else
  echo "Image not found locally. Attempting to pull prebuilt image from GitHub Container Registry ($GHCR_IMAGE)..."
  if $CONTAINER_CLI pull "$GHCR_IMAGE"; then
    IMAGE_TO_RUN="$GHCR_IMAGE"
  else
    echo "Pull failed or offline. Building $LOCAL_IMAGE locally (this may take ~15 minutes)..."
    $CONTAINER_CLI build --platform linux/386 -t "$LOCAL_IMAGE" -f "$repo/tools/docker/Dockerfile" "$repo"
    IMAGE_TO_RUN="$LOCAL_IMAGE"
  fi
fi

tty=; [ -t 0 ] && [ -t 1 ] && tty=-it
sec_opts=()
if [ "$CONTAINER_CLI" = "podman" ]; then
  # On SELinux systems (e.g. Fedora), container volume mounts require label disable
  sec_opts+=(--security-opt label=disable)
fi

# ${a[@]+...}: bash 3.2 (macOS) treats an empty array as unset under set -u.
# --init: a tiny init as PID 1 reaps orphaned processes. Without it the
# command is PID 1, and a long Python run that starts thousands of Wine
# processes (gen_progress_report.py compiling every overlay file) never
# reaps the orphans; process creation then fails partway through with
# Wine's "Not enough space".
exec $CONTAINER_CLI run --rm --init $tty ${sec_opts[@]+"${sec_opts[@]}"} --platform linux/386 -v "$mount:$mount" -w "$repo" "$IMAGE_TO_RUN" "$@"

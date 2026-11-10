# Docs

Every doc of this repository, by folder. New here? Read [building.md](build/building.md), then
[workflow.md](contributing/workflow.md).

## build/: build and check the match

| Doc | What it covers |
|---|---|
| [building.md](build/building.md) | Setup and build, on Windows, Linux and macOS, for both discs |
| [toolchain.md](build/toolchain.md) | Compiler, flags, assembler passes, libraries and the container |
| [levels.md](build/levels.md) | Both discs' programs, their build, and how the functions are counted |
| [overlays.md](build/overlays.md) | The 47 US level overlays the existing C was matched against |
| [packed-executable.md](build/packed-executable.md) | How the retail executable is packed and taken apart |
| [progress.md](build/progress.md) | Progress badges by part of the game and by level |

## contributing/: write and review code

| Doc | What it covers |
|---|---|
| [workflow.md](contributing/workflow.md) | Setup in full, and matching a function step by step |
| [nonmatching.md](contributing/nonmatching.md) | Near misses and how they are kept |
| [pal-signatures.md](contributing/pal-signatures.md) | Reviewed PAL argument, return and output contracts |
| [permuter.md](contributing/permuter.md) | decomp-permuter |

## agents/: AI agents

| Doc | What it covers |
|---|---|
| [agent-workflow.md](agents/agent-workflow.md) | How agent waves run |
| [worker.md](agents/worker.md), [queue.md](agents/queue.md) | Worker instructions |
| [levers.md](agents/levers.md) | What closes a near miss |

## history/: how we got here

[notes/](history/notes/) holds the records of earlier matching sessions and batches: what was tried, the patches and
the near misses left.

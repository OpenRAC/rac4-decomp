<p align="center">
  <a href="https://openrac.dev/">
    <picture>
      <source media="(prefers-color-scheme: dark)" srcset="docs/assets/openrac-logo-dark.svg">
      <img src="docs/assets/openrac-logo-light.svg" alt="OpenRAC" width="360">
    </picture>
  </a>
</p>

<h3 align="center">Ratchet: Deadlocked decompilation project</h3>

<p align="center">
  <a href="https://bytematch.dev/OpenRAC/rac4-decomp"><img src="https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&label=Code&measure=matched_code_percent" alt="Code matched"></a>
  <a href="https://github.com/OpenRAC/rac4-decomp/actions/workflows/progress.yml"><img src="https://github.com/OpenRAC/rac4-decomp/actions/workflows/progress.yml/badge.svg" alt="Progress report"></a>
  <a href="https://openrac.dev/"><img src="https://img.shields.io/badge/website-openrac.dev-e8a317" alt="openrac.dev"></a>
  <a href="https://discord.gg/Sfd2B54PDG"><img src="https://img.shields.io/badge/Discord-join%20us-5865F2?logo=discord&logoColor=white" alt="Discord"></a>
</p>

<p align="center">
  A work-in-progress, matching decompilation of <i>Ratchet: Deadlocked</i> (<i>Ratchet: Gladiator</i> in PAL regions, 2005) for PlayStation 2.<br>
  The main program, the front end and 47 level programs, rebuilt as C that compiles back to the same bytes as retail.
</p>

> [!WARNING]
> This repository has no game data, executables, disc images or proprietary toolchains.
> You need your own copy of the game. Read [LEGAL.md](LEGAL.md) before contributing.

## Progress

Progress is tracked on [ByteMatch](https://bytematch.dev/OpenRAC/rac4-decomp), one badge per version below.
Badges by part of the game and by level are in [docs/build/progress.md](docs/build/progress.md), and
`python3 tools/progress.py` prints the counts.

## Supported versions

| Release | Region | Boot executable | Code | Notes |
| --- | --- | --- | --- | --- |
| v1.00 | NTSC-U | `SCUS_974.65` | [![Code](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65) | Primary version |
| v1.00 | PAL | `SCES_532.85` | [![Code](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85) | Released as *Ratchet: Gladiator* |

The same C counts on both discs wherever it builds to their bytes. Expected SHA-1 of the primary executable:

```text
aa91b1c3b9b1a244320c47580b77342ef9856e95
```

Both discs' programs and how they are counted: [docs/build/levels.md](docs/build/levels.md).

## Quick setup

On Linux and macOS the build runs in a container, so you need [Docker](https://www.docker.com/) or
[Podman](https://podman.io/), and Python 3.10+.

```sh
git clone https://github.com/OpenRAC/rac4-decomp.git && cd rac4-decomp
cp /path/to/SCUS_974.65 baserom/SCUS_974.65          # from your own disc
bash tools/setup_asm.sh
git clone https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01 toolchain/sn-prodg-3.01
git clone https://github.com/AngheloAlf/sce_ps2_sdk_24 toolchain/sn-prodg-24
bash tools/docker/run.sh bash tools/build.sh
```

Windows, both discs' levels and every step in detail: [docs/build/building.md](docs/build/building.md).

## Contributing

Start with [CONTRIBUTING.md](CONTRIBUTING.md) and [AGENTS.md](AGENTS.md). All docs are listed in [docs/README.md](docs/README.md):

- [docs/build/](docs/build) - building, the toolchain, levels, overlays and the packed executable
- [docs/contributing/](docs/contributing) - matching workflow, near misses, PAL signatures and the permuter
- [docs/agents/](docs/agents) - instructions for AI agents
- [docs/history/](docs/history) - notes from earlier matching sessions

Keep the build matching retail. Never commit game images, extracted game data or proprietary compiler binaries.

## Credits

- [rac1-decomp](https://github.com/OpenRAC/rac1-decomp) - layout, progress workflow, toolchain notes, the libgcc recipe and SN assembler tools.
- [rac3-uya-decomp-pal](https://github.com/OpenRAC/rac3-uya-decomp-pal) - levels from the disc, the function inventory, the catalogue and the report.
- [rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp) by vetusmagnus - compiler research for the closest engine relative.
- [OpenRAC](https://github.com/OpenRAC/OpenRAC) - sourcing policy and the sibling decompilations.
- [Lombyte](https://github.com/lombyte-project/Lombyte) - checked for coverage of this game (none).
- [Wrench](https://github.com/chaoticgd/wrench) by chaoticgd - modding tools, the packed image and the level overlays.
- [GCC](https://gcc.gnu.org) and [newlib](https://sourceware.org/newlib/) - the library sources in `src/libgcc/` and `src/libm/`.
- [splat](https://github.com/ethteck/splat), [spimdisasm](https://github.com/Decompollaborate/spimdisasm),
  [m2c](https://github.com/matt-kempster/m2c), [asm-differ](https://github.com/simonlindholm/asm-differ),
  [objdiff](https://github.com/encounter/objdiff), [ByteMatch](https://bytematch.dev) and
  [AngheloAlf](https://github.com/AngheloAlf)'s PS2 toolchain mirrors.

## License

Code written for this project is under the [GNU General Public License v3.0](LICENSE). Code reconstructed from
third-party binaries belongs to its copyright holders; see [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

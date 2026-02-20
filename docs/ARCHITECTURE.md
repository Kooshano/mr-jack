# Architecture

## Current Design

The project currently compiles as a single translation unit:

- `src/mr-jack.c` includes `include/characters.h`
- `include/characters.h` includes other headers with function bodies

This is functional but non-standard C project structure.

## Runtime Data Flow

- Static setup is read from `data/base.txt` and `data/map.txt`
- Save state is written to `state/save.bin`
- Replay snapshots are written/read from `state/replay.txt`

## Suggested Refactor Path

1. Convert headers to declarations only.
2. Move each implementation group into dedicated `.c` files under `src/`.
3. Introduce a small `game_state` module to remove global coupling.
4. Add unit tests around movement, visibility, and win conditions.

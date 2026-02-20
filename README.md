# Mr. Jack (C Console Game)

A terminal implementation of a two-player hidden-identity game inspired by *Mr. Jack*.

- Player 1: **Detective**
- Player 2: **Mr. Jack**

The game uses a hex-style board, character powers, turn-based card selection, save/load support, and replay playback.

## Repository Layout

```text
mr-jack/
├── bin/                 # Compiled binaries (ignored)
├── data/                # Static game data/templates
│   ├── base.txt         # Board + initial character/gate configuration
│   └── map.txt          # ASCII hex map template
├── docs/                # Project documentation
├── include/             # Project headers (implementation currently header-included)
│   ├── characters.h
│   ├── map.h
│   ├── move.h
│   └── specials.h
├── src/
│   └── mr-jack.c        # Main program entry and game loop
├── state/               # Runtime save/replay files
│   └── .gitkeep
├── .gitignore
├── .gitattributes
├── Makefile
└── README.md
```

## Quick Start

### 1. Build

```bash
make build
```

### 2. Run

```bash
make run
```

Or run directly:

```bash
./bin/mr-jack
```

On Windows, output is `bin/mr-jack.exe`.

## Requirements

- C compiler (`gcc`/`clang`)
- `make`
- Terminal that supports ANSI colors (recommended)

## Gameplay Overview

At startup:

- The engine loads board/config from `data/base.txt` and `data/map.txt`.
- Mr. Jack is randomly selected from 8 characters.
- You can start new or load saved state.

Core loop:

- 16 round phases max
- 4 character activations per phase
- Detective and Mr. Jack alternate by card-draft order
- Detective may arrest adjacent suspects after detective turns

Win conditions:

- Detective arrests Mr. Jack
- Mr. Jack escapes through an open gate
- Mr. Jack survives to end of round limit

## Character Codes

- `SH`, `JW`, `JS`, `IL`, `MS`, `SG`, `WG`, `JB`

Each character has unique movement/special behavior implemented in `include/specials.h` and `include/map.h`.

## Save and Replay

Runtime state files are stored under `state/`:

- `state/save.bin`: binary save file
- `state/replay.txt`: replay snapshots

Useful targets:

```bash
make reset-state   # Remove save/replay runtime files
make clean         # Remove compiled binaries
```

## Development Notes

Current architecture is a legacy single translation unit style (`src/mr-jack.c` includes headers containing function definitions). It is intentionally preserved for compatibility.

Recommended future refactor:

- Move implementations from `include/*.h` to `src/*.c`
- Keep only declarations in headers
- Add tests for movement, arrest logic, and visibility
- Harden input parsing and memory management

## Contributing

1. Create a branch from `main`
2. Keep changes focused and small
3. Build and run before opening PR
4. Update docs when behavior changes

## License

No license is currently defined.
Add a `LICENSE` file before distributing outside personal/private use.

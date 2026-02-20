# Mr. Jack (C Console Project)

A console implementation of the board game-inspired **Mr. Jack** for two players:

- **Detective**
- **Mr. Jack**

The game runs on a hex-grid map, uses character powers, supports save/load, and can replay the match from recorded states.

## Project Status

This is a playable prototype with custom rules implementation and terminal rendering.

- Language: `C`
- Platform target in current code: `Windows` (uses `windows.h` / `Sleep`)
- Build style: single translation unit via header-inclusion (`mr-jack.c` includes project headers with function bodies)

## Features

- Hex-style board display in terminal
- 8 playable characters with distinct movement/special actions:
  - `SH`, `JW`, `JS`, `IL`, `MS`, `SG`, `WG`, `JB`
- Hidden identity selection for Mr. Jack
- Turn system with alternating detective/Mr. Jack card usage
- Arrest flow for detective
- Visibility + innocence elimination logic
- Win conditions:
  - Detective arrests Mr. Jack
  - Mr. Jack escapes through an open gate
  - Mr. Jack survives until end of rounds
- Save/Load support (`save.txt`)
- Replay support (`replay.txt`)

## Repository Layout

- `mr-jack.c`: Main game loop, deck generation, save/load/replay integration
- `characters.h`: Core data structures, map loading/rendering, visibility logic
- `move.h`: Movement engine and step validation
- `specials.h`: Character-specific action orchestration and descriptions
- `map.h`: Character special ability implementations
- `base.txt`: Initial game configuration (board, character placement, gates)
- `map.txt`: ASCII board template used for rendering
- `save.txt`: Binary save file written/read by the game
- `replay.txt`: Replay snapshots written during the match
- `mr-jack.exe`: Prebuilt Windows executable (legacy artifact)

## Requirements

To build from source:

- A C compiler (GCC/Clang)
- Windows environment (or compatibility layer) because code includes `windows.h`
- Terminal with ANSI support for colors/emojis (optional but recommended)

## Build

### Windows (MinGW GCC)

```bash
gcc mr-jack.c -o mr-jack.exe
```

### Linux/macOS note

Current code uses `windows.h` and `Sleep(1000)`.  
To compile on Linux/macOS, replace `Sleep` with a portable sleep (`usleep`/`nanosleep`) and remove `windows.h`.

## Run

```bash
./mr-jack.exe
```

At startup, the game asks:

- `would you like to play new game or load ?`

Input:

- `Load` to restore from `save.txt`
- any other input to start a new game

## How Input Works

The board uses coordinate-style positions such as:

- `A1`, `C8`, `I13`

During turns, you will be prompted for:

- character to play
- move count
- destination step(s)
- special ability choices (character-dependent)
- optional arrest (detective only)

Some prompts expect exact strings (case-sensitive in current implementation), for example:

- `Load`
- `yes` / `no`
- `special`
- `None`

## Character Summary

- `SH`: move 1-3, reveal an innocent card
- `JW`: move 1-3, set a visibility direction
- `JS`: move 1-3, toggle one light off and one on
- `IL`: move 1-3, close one gate and open another
- `MS`: move 1-4, can move through buildings
- `SG`: move 1-3, can pull nearby characters
- `WG`: move 1-3 or swap with another character
- `JB`: move 1-3, relocate wells

## Save and Replay

- Save prompt appears at the beginning of even rounds after round 1.
- Saving writes full state to `save.txt` and exits loop.
- Replay snapshots are always written to `replay.txt`.
- At game end, replay can be played in terminal with 1-second frame delay.

## Data File Format (High Level)

`base.txt` contains:

1. Board dimensions (`x y`)
2. Tile type matrix
3. Character matrix
4. Gate definitions (`place mode gate1 gate2`)

Tile types used by code:

- `0`: blocked/border/building edge
- `1`: walkway/open route
- `2`: lit tile (lamp on)
- `3`: well-off
- `4`: well-on
- `5`: lamp off

## Known Limitations

- Heavy use of global state and dynamic allocation without full cleanup
- Minimal input validation (invalid text may break flow)
- Uses non-portable Windows-specific include/time function
- Includes implementation in header files (non-standard project structure)
- Save format is binary and not versioned

## Suggested Next Cleanup Steps

- Split function definitions out of headers into `.c` files
- Add robust input parsing and guardrails
- Add memory cleanup for allocated linked lists/matrices
- Make sleep/timing portable across platforms
- Add tests for movement, arrest, and win conditions

## License

No license file is currently included.
Add a `LICENSE` if you want others to safely reuse or contribute.

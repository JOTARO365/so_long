*This project has been created as part of the 42 curriculum by wiaon-in.*

# so_long

## Description

**so_long** is a small 2D game built with the **MiniLibX** graphics library.
The player moves around a tile-based map, must **collect every collectible**,
and then reach the **exit** to win. Each move is counted and printed to the
shell.

This repository contains two versions:

- **Mandatory** (`so_long`) — a top-down grid game. The player moves up / down /
  left / right with the keyboard, cannot walk through walls, and wins by
  collecting all items then stepping on the exit.
- **Bonus** (`so_long_bonus`) — a side-view platformer with gravity and jumping,
  frame-based **sprite animation**, an on-screen **move counter** (drawn in the
  window, not only the shell), and a **scrolling camera** for large maps. It
  ships with **100 difficulty-scaled levels** (`maps/level1.ber` …
  `maps/level100.ber`).

Maps are plain-text `.ber` files made of these tiles:

| Char | Meaning      |
|------|--------------|
| `0`  | empty space  |
| `1`  | wall         |
| `C`  | collectible  |
| `E`  | exit         |
| `P`  | player start |

A map is valid only if it is rectangular, fully surrounded by walls, has
exactly one `P`, exactly one `E`, at least one `C`, and a valid path from `P`
to every `C` and to the `E`. Any invalid map prints `Error\n` followed by an
explicit message and exits cleanly.

## Instructions

### Requirements

- A C compiler (`cc`/`gcc`) and `make`.
- Linux MiniLibX dependencies: `xorg`, `libxext-dev`, `libbsd-dev`
  (e.g. `sudo apt install xorg libxext-dev libbsd-dev`).

MiniLibX is built locally from the bundled `minilibx-linux.tgz`; the extracted
`minilibx-linux/` tree is git-ignored and re-created by the Makefile when
missing.

### Compilation

```sh
make           # build the mandatory game   -> ./so_long
make bonus     # build the bonus platformer -> ./so_long_bonus
make clean     # remove object files
make fclean    # remove objects + binaries
make re        # fclean + all
```

Build flags: `-Wall -Wextra -Werror`. Link flags:
`-lmlx_Linux -lXext -lX11 -lm`.

### Execution

```sh
./so_long       maps/level1.ber     # mandatory version
./so_long_bonus maps/level1.ber     # bonus platformer
```

### Controls

| Key                  | Mandatory        | Bonus            |
|----------------------|------------------|------------------|
| `W` / `↑`            | move up          | jump             |
| `S` / `↓`            | move down        | —                |
| `A` / `←`            | move left        | move left        |
| `D` / `→`            | move right       | move right       |
| `Space`              | —                | jump             |
| `ESC`                | quit cleanly     | quit cleanly     |
| window close button  | quit cleanly     | quit cleanly     |

In the bonus version you can move while jumping, so jumps carry the player
forward.

## Resources

- [42 so_long subject](en.subject.pdf) — project requirements.
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
  and the official man pages bundled in `minilibx-linux/`.
- Personal `libft` (in `libft/`) for standard helpers and `ft_printf`.

### Use of AI

AI (Claude Code) was used as an assistant during development for the following
tasks:

- Explaining the MiniLibX event/hook system while debugging keyboard input.
- Helping implement and tune the bonus jump/gravity physics.
- Generating and validating the 100 difficulty-scaled bonus maps in `maps/`.
- Setting up the Git repository, `.gitignore`/`.gitattributes`, and this
  README.

All code was reviewed, tested, and kept norm-compliant (norminette) by the
author; design decisions and final implementation remain the author's own.

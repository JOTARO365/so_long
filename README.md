# so_long

A small 2D game built with **MiniLibX** for the 42 curriculum.
The player explores a tile map, **collects every item**, then heads for the
**exit**. This repo ships both the mandatory grid game and a **bonus
platformer** with gravity, jumping, animated sprites and a scrolling camera —
plus **100 difficulty-scaled levels**.

---

## Build

Requirements: a C compiler, `make`, and the Linux MiniLibX dependencies
(`libxext-dev`, `libxext`, `libx11-dev`, `libbsd-dev`). MiniLibX itself is
built locally from the bundled `minilibx-linux.tgz`.

```sh
make           # build the mandatory game  -> ./so_long
make bonus     # build the bonus platformer -> ./so_long_bonus
make clean     # remove object files
make fclean    # remove objects + binaries
make re        # fclean + all
```

Compiled with `-Wall -Wextra -Werror`, linked against
`-lmlx_Linux -lXext -lX11 -lm`.

> The extracted `minilibx-linux/` source tree is git-ignored; if it's missing
> the Makefile re-extracts and builds it from `minilibx-linux.tgz`.

---

## Run

```sh
./so_long       maps/level1.ber     # mandatory grid version
./so_long_bonus maps/level1.ber     # bonus platformer
```

### Controls (bonus)

| Key | Action |
|-----|--------|
| `A` / `←` | move left |
| `D` / `→` | move right |
| `W` / `↑` / `Space` | jump |
| `ESC` | quit |
| window close button | quit cleanly |

You can move **while jumping**, so jumps carry you forward. The number of
moves is printed to the terminal and drawn on the window.

---

## Map format (`.ber`)

A map is a rectangular grid, fully surrounded by walls, using these tiles:

| Char | Meaning |
|------|---------|
| `0` | empty space |
| `1` | wall / platform |
| `C` | collectible |
| `E` | exit |
| `P` | player start |

A map is **valid** only if it is rectangular, wall-bordered, has exactly one
`P`, exactly one `E`, at least one `C`, and every `C`/`E` is reachable from `P`
(checked with a flood fill). Any invalid map prints `Error\n` and exits.

```
1111111111111111111
1P00000000000000001
100011000C001110001
100010000000000C001
1001110000111000001
1000000000000000001
100000C000000000001
1000001111100000001
1000000000000000E01
1111111111111111111
```

---

## Levels

`maps/` holds **100 numbered levels** (`level1.ber` … `level100.ber`) plus a
tiny `small.ber`. Difficulty ramps up steadily:

| Level | Size | Collectibles |
|-------|------|--------------|
| 2   | 9×6     | 1  |
| 25  | 17×8    | 5  |
| 50  | 32×10   | 9  |
| 75  | 69×13   | 13 |
| 100 | 147×15  | 17 |

In the bonus platformer, elevated collectibles sit on staircases of platforms;
every level is reachable using the jump physics, and larger maps scroll with a
camera that follows the player.

---

## Project layout

```
so_long/
├── Makefile
├── so_long.h / so_long_bonus.h   # structs, defines, prototypes
├── src/
│   ├── main.c       / main_bonus.c       # init, hooks, game loop
│   ├── parse.c      / parse_bonus.c      # read & build the .ber map
│   ├── validate.c   / validate_bonus.c   # flood-fill reachability
│   ├── render.c     / render_bonus.c     # draw tiles / sprites / HUD
│   ├── player.c     / player_bonus.c     # input & movement
│   ├──               physics_bonus.c     # gravity & jumping (bonus)
│   ├── error.c      / error_bonus.c      # error messages + clean exit
│   └── free.c       / free_bonus.c       # free all memory
├── textures/        # XPM sprites
├── maps/            # level1..level100 + small.ber
├── libft/           # reused standard-library functions
└── minilibx-linux.tgz
```

---

## Notes

All `.c`/`.h` files follow the 42 **norm** (norminette-clean). Error paths
free their memory and exit cleanly, so the game is leak-free under `valgrind`.

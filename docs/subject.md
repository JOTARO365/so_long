# So Long — Subject Requirements (v5.0)

## Mandatory

### Game rules
- Player collects **all** collectibles (C) then steps on exit (E) to win
- Movement keys: **W A S D** (or ZQSD or arrow keys)
- Four directions: up, down, left, right
- Player **cannot** move into walls (1)
- Every move → print move count to **shell**
- 2D view: top-down **or** profile
- Game does **not** need to be real-time

### Graphic management
- Display window with MiniLibX images (not pixel_put for tiles)
- Window must stay smooth (minimize/switch without crash)
- **ESC** → close window + exit cleanly
- **Window X button** → close window + exit cleanly

### Map rules (see docs/map.md for detail)
- Characters: `0` `1` `C` `E` `P` only
- Exactly 1 exit (E), 1 starting position (P), at least 1 collectible (C)
- Must be rectangular
- Must be surrounded by walls (1)
- Must have a valid path from P to all C and to E

### Error handling
- Any misconfiguration → print `"Error\n"` + explicit message → exit cleanly
- Duplicate E or P → error
- Invalid characters → error
- Invalid extension (not .ber) → error

### Files to submit
```
Makefile  *.h  *.c  maps/  textures/
```

### Makefile targets
`$(NAME)` `all` `clean` `fclean` `re`  (+ `bonus` if doing bonus)

### README.md required
First line (italicized): *This project has been created as part of the 42 curriculum by wiaon-in.*

Sections required:
- **Description** — project goal + overview
- **Instructions** — compilation, installation, execution
- **Resources** — references + how AI was used (which tasks, which parts)

---

## Bonus (only graded if mandatory is PERFECT)

| Bonus | Description |
|-------|-------------|
| Enemy patrol | Player loses when touching an enemy |
| Sprite animation | Animated sprites (frame-based) |
| Move count on screen | Display move count in window, not just shell |

Bonus files must use `_bonus.c` / `_bonus.h` suffix.
Add `bonus` rule to Makefile.

---

## Allowed external functions

```
open, close, read, write, malloc, free, perror, strerror, exit
math library (-lm)
All MiniLibX functions
gettimeofday()
ft_printf (self-coded) and equivalent
libft (copy in libft/ folder)
```

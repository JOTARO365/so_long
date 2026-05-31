# Map Format & Validation

## .ber file format

Plain text file, one row per line.

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

| Character | Meaning |
|-----------|---------|
| `0` | Empty floor tile |
| `1` | Wall (impassable) |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |

## Validation checklist

### Step 1 — Extension check
- Filename must end with `.ber`
- Error if wrong extension

### Step 2 — Read & store grid
```c
// Read file → ft_split(content, '\n') → map.grid
// map.height = number of rows
// map.width  = ft_strlen(grid[0])
```

### Step 3 — Rectangular check
- Every row must have the same length (== map.width)
- Error if any row differs

### Step 4 — Wall boundary check
- Row 0 and row (height-1) must be all `1`
- Column 0 and column (width-1) of every row must be `1`

### Step 5 — Character count
```c
// Count C, E, P while scanning grid
// E == 1, P == 1, C >= 1 → valid
// E != 1 or P != 1 → error (duplicate or missing)
```
- Unknown characters → error

### Step 6 — Flood-fill reachability
- Copy the grid
- BFS/DFS from P position
- All `C` tiles and the `E` tile must be reachable
- If any C or E is isolated → error

```c
// Simple recursive flood-fill (mark visited with 'V')
void    flood(char **grid, int x, int y)
{
    if (grid[y][x] == '1' || grid[y][x] == 'V')
        return ;
    grid[y][x] = 'V';
    flood(grid, x + 1, y);
    flood(grid, x - 1, y);
    flood(grid, x, y + 1);
    flood(grid, x, y - 1);
}
// After flood: scan for any C or E not marked V → error
```

**Warning:** deep recursion on large maps can stack-overflow. Use iterative BFS if map can be large.

## Error messages

```
Error
Map file cannot be opened.

Error
Invalid file extension (expected .ber).

Error
Map is not rectangular.

Error
Map is not surrounded by walls.

Error
Invalid characters in map.

Error
Map must have exactly 1 exit.

Error
Map must have exactly 1 starting position.

Error
Map must have at least 1 collectible.

Error
No valid path to exit or collectibles.
```

## Example maps

### Minimal valid map
```
111111
1P0CE1
111111
```

### Subject example (large)
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

### Invalid — not enclosed
```
111111
1P0CE0    ← right side not wall
111111
```

### Invalid — no path
```
111111
1P1CE1    ← wall blocks path
111111
```

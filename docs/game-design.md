# Game Design — So Long

## View type

**2D Side-Scrolling (profile view)**
Camera looks from the side. Player stands on platforms, gravity pulls downward.
Subject allows this as "profile" view.

## Movement model — Grid Platformer (norm-safe)

ไม่ใช้ float / physics engine — ใช้ tile-grid แทน ผ่าน norminette 100%

| Input | Action |
|-------|--------|
| A / LEFT  | เดินซ้าย 1 tile |
| D / RIGHT | เดินขวา 1 tile |
| W / UP / SPACE | กระโดด (ขึ้น 1 tile ถ้าช่องว่าง) |
| ESC | ออกเกม |

### Gravity rule (ง่าย, norm-safe)
```
ทุก frame: ถ้า tile ใต้ player == '0' (ว่าง) → player.py += 1  (ตกลง)
ถ้า tile ใต้ player == '1' (พื้น/กำแพง) → อยู่กับที่ (ยืนได้)
```
ไม่มี float, ไม่มี velocity — แค่ check tile ด้านล่างทุก loop tick

### Jump rule
```
กด W: ถ้า tile ใต้ player == '1' (กำลังยืนอยู่บนพื้น)
      → player.py -= 2  (กระโดดขึ้น 2 tile ทันที)
กด W: ถ้า player กำลังอยู่กลางอากาศ → ไม่ทำอะไร (no double jump)
```

### Loop hook (bonus — ใช้ mlx_loop_hook)
```c
int     gravity_tick;   /* นับ tick สำหรับ gravity */

/* ทุก N tick → apply gravity 1 ครั้ง */
if (game->gravity_tick++ >= GRAVITY_SPEED)
{
    apply_gravity(game);
    game->gravity_tick = 0;
}
```
`GRAVITY_SPEED` ≈ 3–5 (ปรับความเร็วตก)

---

## Tile meaning (side-scroll)

| Char | ความหมาย |
|------|-----------|
| `1`  | Solid block — กำแพง / พื้น / เพดาน (ชน = หยุด) |
| `0`  | อากาศว่าง — player ตกผ่านได้ |
| `P`  | จุดเริ่มต้น player |
| `C`  | Collectible — เก็บได้ |
| `E`  | Exit — เปิดเมื่อเก็บครบ |

## Map design tips (side-scroll)

- แถวล่างสุดควรเป็น `1` ทั้งหมด — พื้นกันตก
- ใช้ `1` เป็น platform ลอยฟ้า, `0` เป็นช่องกระโดด
- วาง `C` บนสูง บังคับให้กระโดดเก็บ
- `E` อยู่ท้ายหรือสูง — ต้องผ่าน platform ก่อน

### ตัวอย่าง map (15×9)
```
111111111111111
100000000000001
101110000111001
100010000000001
100010C00000001
111110111100001
100000000000C01
1000000E0000001
111111111111111
```

---

## Tile size

**64×64 px** — window = `map.width × 64` × `map.height × 64`

---

## Bonus features

### 1. Enemy patrol (M tile)
- เดินซ้ายขวาบน platform, กลับทิศเมื่อชนกำแพง
- ถ้า player ชน → "Game Over" → exit

### 2. Sprite animation
- idle: 2 frame
- walk: 2 frame (สลับ A / D)
- ใช้ `mlx_loop_hook` นับ tick สลับ frame

### 3. On-screen move count
```c
mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, count_str);
```
ล้าง bg tile ก่อน re-draw ทุกครั้งเพื่อไม่ให้ ghost text

---

## Implementation order (แนะนำ)

1. Map parser + validation (parse.c, validate.c)
2. Render tiles (render.c)
3. Left/Right movement + wall collision (player.c)
4. Gravity loop via mlx_loop_hook
5. Jump logic
6. Collect + Exit win condition
7. (Bonus) Enemy, animation, on-screen counter

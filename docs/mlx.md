# MiniLibX API Cheat Sheet

Library: `minilibx-linux/` (from minilibx-linux.tgz)
Header: `mlx.h`
Compile flags: `-lmlx -lXext -lX11`

## Init & window

```c
void    *mlx_init(void);
// Returns mlx pointer. NULL on failure.

void    *mlx_new_window(void *mlx, int w, int h, char *title);
// Returns win pointer. NULL on failure.

int     mlx_destroy_window(void *mlx, void *win);
int     mlx_destroy_display(void *mlx);
int     mlx_clear_window(void *mlx, void *win);
```

## Images (use these for tiles — mandatory)

```c
// Load XPM file → image pointer
void    *mlx_xpm_file_to_image(void *mlx, char *path, int *w, int *h);

// Draw image at (x, y) in window
int     mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y);

// Free image
int     mlx_destroy_image(void *mlx, void *img);
```

## Event hooks

```c
// Key press
int     mlx_key_hook(void *win, int (*fn)(), void *param);
// fn signature: int fn(int keycode, void *param)

// Window X button (event 17 = DestroyNotify)
int     mlx_hook(void *win, int event, int mask, int (*fn)(), void *param);
// For close button: mlx_hook(win, 17, 0, close_fn, param)

// Loop hook (called every frame)
int     mlx_loop_hook(void *mlx, int (*fn)(), void *param);

// Start event loop (blocks)
int     mlx_loop(void *mlx);

// Stop event loop
int     mlx_loop_end(void *mlx);
```

## Key codes (Linux X11)

```c
#define KEY_W       119
#define KEY_A       97
#define KEY_S       115
#define KEY_D       100
#define KEY_ESC     65307
#define KEY_UP      65362
#define KEY_DOWN    65364
#define KEY_LEFT    65361
#define KEY_RIGHT   65363
```

## Text on screen (bonus — move count display)

```c
int     mlx_string_put(void *mlx, void *win, int x, int y, int color, char *str);
// color: 0x00RRGGBB (e.g. 0x00FFFFFF = white)
```

## Image pixel manipulation (for animation)

```c
char    *mlx_get_data_addr(void *img, int *bpp, int *line_len, int *endian);
// Returns pointer to raw pixel data

// Write a pixel at (x, y):
// data[y * line_len + x * (bpp / 8)] = color;
```

## Typical init sequence

```c
game->mlx = mlx_init();
if (!game->mlx)
    return (error_exit(game, "mlx_init failed"));
game->win = mlx_new_window(game->mlx, map_w * TILE, map_h * TILE, "So Long");
if (!game->win)
    return (error_exit(game, "mlx_new_window failed"));
load_textures(game);        // mlx_xpm_file_to_image for each tile
render_map(game);           // mlx_put_image_to_window for every cell
mlx_key_hook(game->win, handle_key, game);
mlx_hook(game->win, 17, 0, (int (*)(void *))handle_close, game);
mlx_loop(game->mlx);
```

## Cleanup sequence

```c
// Free textures
mlx_destroy_image(game->mlx, game->img[WALL]);
// ... repeat for each image

// Destroy window & display
mlx_destroy_window(game->mlx, game->win);
mlx_destroy_display(game->mlx);
free(game->mlx);

// Free map grid
// ft_free_split(game->map.grid);
```

## Important notes

- `mlx_pixel_put` is **very slow** — never use it for tiles, always use images
- XPM textures must have unique color characters; keep them simple (max 64x64)
- On macOS use `mlx_macos_opengl` or `mlx_macos_metal` tgz instead
- `mlx_loop` blocks → all logic goes into hooks
- After `mlx_loop_end`, the loop exits on next iteration — cleanup after that

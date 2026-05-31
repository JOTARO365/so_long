# 42 Norminette Rules — Quick Reference

Run before every commit: `norminette src/ so_long.h`

## Hard limits

| Rule | Limit |
|------|-------|
| Lines per function | **25 max** (blank lines / comment lines don't count) |
| Functions per .c file | **5 max** |
| Parameters per function | **5 max** |
| Line length | **80 columns max** |
| Blank lines between functions | **1 max** |

## Forbidden constructs

```c
for (...)       // use while instead
do { } while    // banned
switch (...)    // banned
goto            // banned
cond ? a : b    // ternary banned
int arr[n]      // VLA banned
if ((n = foo())) // assignment in condition banned
```

## Variable declarations

```c
// CORRECT — all declarations at top of block
void    foo(void)
{
    int i;
    int j;

    i = 0;
    ...
}

// WRONG — declaration after statement
void    foo(void)
{
    i = 0;
    int j; // norminette error
}
```

## Indentation & braces

```c
// Functions: opening brace on SAME line as signature
void    my_func(int x)
{
    // body
}

// Control flow: brace on NEXT line
if (condition)
{
    // body
}
while (condition)
{
    // body
}
```

## Unused parameters

```c
int hook(int keycode, void *param)
{
    (void)keycode;   // must cast to void
    (void)param;
    return (0);
}
```

## Naming

- `snake_case` for variables and functions
- `t_name` for typedefs (structs)
- `#define MACRO_NAME` uppercase for macros

## Header files

- Must have include guard:
```c
#ifndef SO_LONG_H
# define SO_LONG_H

// content

#endif
```
- Includes use `# include` (with space after #)

## Splitting long lines (80 col)

```c
// Use continuation on next line, aligned
mlx_hook(game->win, 17, 0,
    (int (*)(void *))close_window, game);
```

## Common traps in so_long

- `ft_split` result loop → while, not for
- `free` in middle of function: declare cleanup label style with early returns
- Nested conditions eat lines fast — extract helper functions
- `mlx_hook` callback signatures must match exactly (cast if needed)

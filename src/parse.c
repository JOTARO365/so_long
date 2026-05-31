/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file(t_game *game, char *file)
{
	int		fd;
	int		n;
	size_t	len;
	char	buf[8192];

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".ber", 4))
		error_exit(game, "Invalid file extension (expected .ber).");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Map file cannot be opened.");
	n = read(fd, buf, 8191);
	close(fd);
	if (n <= 0)
		error_exit(game, "Map file is empty or unreadable.");
	buf[n] = '\0';
	return (ft_strdup(buf));
}

static void	build_grid(t_game *game, char *content)
{
	int	i;
	int	len;

	game->map.grid = ft_split(content, '\n');
	if (!game->map.grid)
		error_exit(game, "Memory allocation failed.");
	while (game->map.grid[game->map.height])
		game->map.height++;
	if (game->map.height == 0)
		error_exit(game, "Map is empty.");
	game->map.width = (int)ft_strlen(game->map.grid[0]);
	i = 1;
	while (i < game->map.height)
	{
		len = (int)ft_strlen(game->map.grid[i]);
		if (len != game->map.width)
			error_exit(game, "Map is not rectangular.");
		i++;
	}
}

static void	scan_tile(t_game *game, int x, int y)
{
	char	c;

	c = game->map.grid[y][x];
	if (c == 'C')
		game->map.collectibles++;
	else if (c == 'E')
		game->map.exits++;
	else if (c == 'P')
	{
		game->px = x;
		game->py = y;
		game->map.players++;
		game->map.grid[y][x] = '0';
	}
	else if (c != '0' && c != '1')
		error_exit(game, "Invalid characters in map.");
}

static void	count_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			scan_tile(game, x, y);
			x++;
		}
		y++;
	}
	if (game->map.players != 1)
		error_exit(game, "Map must have exactly 1 starting position.");
	if (game->map.exits != 1)
		error_exit(game, "Map must have exactly 1 exit.");
	if (game->map.collectibles < 1)
		error_exit(game, "Map must have at least 1 collectible.");
}

void	parse_map(t_game *game, char *file)
{
	char	*content;

	content = read_file(game, file);
	build_grid(game, content);
	free(content);
	count_chars(game);
}

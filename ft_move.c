/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:08:39 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 12:07:09 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "minilibx/mlx.h"

void	ft_move_up(t_game *g, int key)
{
	if (g->map[g->p.y - 1][g->p.x] == 'C')
		ft_gameet_col(g, key);
	else if (g->map[g->p.y - 1][g->p.x] == '0')
	{
		g->mv++;
		g->map[g->p.y - 1][g->p.x] = 'P';
		g->map[g->p.y][g->p.x] = '0';
		ft_i_w(g, g->p.down.img, g->p.x * 50, (g->p.y - 1) * 50);
		ft_i_w(g, g->g.img, g->p.x * 50, g->p.y * 50);
		g->p.y--;
	}
	else if (g->map[g->p.y - 1][g->p.x] == 'E' && g->p.c == g->col.n)
		ft_close(g);
	ft_i_w(g, g->p.down.img, g->p.x * 50, g->p.y * 50);
}

void	ft_move_down(t_game *g, int key)
{
	if (g->map[g->p.y + 1][g->p.x] == 'C')
		ft_gameet_col(g, key);
	else if (g->map[g->p.y + 1][g->p.x] == 'X')
		ft_close(g);
	else if (g->map[g->p.y + 1][g->p.x] == '0')
	{
		g->mv++;
		g->map[g->p.y + 1][g->p.x] = 'P';
		g->map[g->p.y][g->p.x] = '0';
		ft_i_w(g, g->p.down.img, g->p.x * 50, (g->p.y + 1) * 50);
		ft_i_w(g, g->g.img, g->p.x * 50, g->p.y * 50);
		g->p.y++;
	}
	else if (g->map[g->p.y + 1][g->p.x] == 'E' && g->p.c == g->col.n)
		ft_close(g);
	ft_i_w(g, g->p.down.img, g->p.x * 50, g->p.y * 50);
}

void	ft_move_left(t_game *g, int key)
{
	if (g->map[g->p.y][g->p.x - 1] == 'C')
		ft_gameet_col(g, key);
	else if (g->map[g->p.y][g->p.x - 1] == '0')
	{
		g->mv++;
		g->map[g->p.y][g->p.x - 1] = 'P';
		g->map[g->p.y][g->p.x] = '0';
		ft_i_w(g, g->p.down.img, (g->p.x - 1) * 50, g->p.y * 50);
		ft_i_w(g, g->g.img, g->p.x * 50, g->p.y * 50);
		g->p.x--;
	}
	else if (g->map[g->p.y][g->p.x - 1] == 'E' && g->p.c == g->col.n)
		ft_close(g);
	ft_i_w(g, g->p.down.img, g->p.x * 50, g->p.y * 50);
}

void	ft_move_right(t_game *g, int key)
{
	if (g->map[g->p.y][g->p.x + 1] == 'C')
		ft_gameet_col(g, key);
	else if (g->map[g->p.y][g->p.x + 1] == '0')
	{
		g->mv++;
		g->map[g->p.y][g->p.x + 1] = 'P';
		g->map[g->p.y][g->p.x] = '0';
		ft_i_w(g, g->p.down.img, (g->p.x + 1) * 50, g->p.y * 50);
		ft_i_w(g, g->g.img, g->p.x * 50, g->p.y * 50);
		g->p.x++;
	}
	else if (g->map[g->p.y][g->p.x + 1] == 'E' && g->p.c == g->col.n)
		ft_close(g);
	ft_i_w(g, g->p.down.img, g->p.x * 50, g->p.y * 50);
}

int	ft_controlls(int keykode, t_game *g)
{
	if (keykode == 0x35)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	else if (keykode == 0x0D)
		ft_move_up(g, keykode);
	else if (keykode == 0x00)
		ft_move_left(g, keykode);
	else if (keykode == 0x01)
		ft_move_down(g, keykode);
	else if (keykode == 0x02)
		ft_move_right(g, keykode);
	system("clear");
	printf("mv = %d\n", g->mv);
	return (0);
}

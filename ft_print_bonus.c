/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:08:15 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 13:08:18 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

void	ft_str_img_e(char *s, t_game g, int j)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0')
			ft_i_w(&g, g.g.img, i * 50, j * 50);
		if (s[i] == '1' && j == 0)
			ft_i_w(&g, g.w.u.img, i * 50, j * 50);
		if (s[i] == '1' && (i == 0 || i == g.mw - 2) && j > 0)
			ft_i_w(&g, g.w.l.img, i * 50, j * 50);
		if (s[i] == '1' && ((i > 0 && i < g.mw - 2) && (j > 0 && j < g.mh - 1)))
			ft_i_w(&g, g.w.t.img, i * 50, j * 50);
		if (s[i] == 'C')
			ft_i_w(&g, g.col.img, i * 50, j * 50);
		if (s[i] == '1' && j == g.mh - 1)
			ft_i_w(&g, g.w.b.img, i * 50, j * 50);
		if (s[i] == 'P')
			ft_i_w(&g, g.p.down.img, i * 50, j * 50);
		if (s[i] == 'E' && g.p.c != g.col.n)
			ft_i_w(&g, g.e.img, i * 50, j * 50);
		if (s[i] == 'E' && g.p.c == g.col.n)
			ft_i_w(&g, g.e_o.img, i * 50, j * 50);
		i++;
	}
}

void	ft_str_img(char *str, t_game g, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			ft_i_w(&g, g.g.img, i * 50, j * 50);
		if (str[i] == '1' && j == 0)
			ft_i_w(&g, g.w.u.img, i * 50, j * 50);
		if (str[i] == '1' && (i == 0 || i == g.mw - 2) && j > 0)
			ft_i_w(&g, g.w.l.img, i * 50, j * 50);
		if (str[i] == '1' \
			&& ((i > 0 && i < g.mw - 2) && (j > 0 && j < g.mh - 1)))
			ft_i_w(&g, g.w.t.img, i * 50, j * 50);
		if (str[i] == 'C')
			ft_i_w(&g, g.col.img, i * 50, j * 50);
		if (str[i] == '1' && j == g.mh - 1)
			ft_i_w(&g, g.w.b.img, i * 50, j * 50);
		if (str[i] == 'P')
			ft_i_w(&g, g.p.down.img, i * 50, j * 50);
		if (str[i] == 'E')
			ft_i_w(&g, g.e.img, i * 50, j * 50);
		i++;
	}
}

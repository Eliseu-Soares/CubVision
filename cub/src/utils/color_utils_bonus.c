/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:54:17 by sgaspar           #+#    #+#             */
/*   Updated: 2026/04/15 17:54:17 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	create_trgb_raw(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_trgb(int t, int color[3])
{
	return (create_trgb_raw(t, color[0], color[1], color[2]));
}

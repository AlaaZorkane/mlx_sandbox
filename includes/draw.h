/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 00:47:49 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/24 14:51:00 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_H
# define FT_DRAW_H
# include "cub3d.h"

void	draw_ceiling(t_rays *ray, int id);
void	draw_content(t_rays *ray, int id);
void	draw_floor(t_rays *ray, int id);
#endif

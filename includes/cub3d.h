/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:33:43 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 11:16:02 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include "player.h"
# include "rays.h"
# include "utils.h"
# include "map.h"
# include "consts.h"
# include "image.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_store
{
	t_mlx		mlx;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		*rays;
} 	t_store;

t_store store;

#endif

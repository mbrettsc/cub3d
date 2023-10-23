/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:40:10 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/22 20:12:54 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# include <stdbool.h>

typedef struct s_key
{
	bool	ak;
	bool	dk;
	bool	wk;
	bool	sk;
	bool	rk;
	bool	lk;
}				t_key;

typedef struct s_data
{
	void	*img;
	int		*addr;
}				t_data;

typedef struct s_player
{
	char	way;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	speed;
}				t_player;

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	wall_dist;
}				t_ray;

typedef struct s_draw
{
	int				draw_s;
	int				draw_e;
	int				line_h;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	unsigned int	color;
	int				tex_w;
	int				tex_h;
}				t_draw;

typedef struct s_texture
{
	t_data			*no;
	t_data			*so;
	t_data			*we;
	t_data			*ea;
	unsigned int	floorc;
	unsigned int	ceilingc;
}				t_texture;

typedef struct s_map
{
	int		*floor_val;
	int		*ceil_val;
	char	*floor;
	char	*ceil;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map_data;
	t_ray		*ray;
	t_data		*image;
	t_player	*player;
	t_texture	*tex;
	t_draw		*draw;
	t_key		key;
	char		**map;
}				t_game;

int			find_map_height(char **map);
int			check_map_surrounded(t_game *game);
int			check_pairs(t_game *game);
int			check_and_get(t_game *game, char **regex);
int			pair_map(t_game *game, char **regex);
int			exit_game(t_game *game);
int			key_press(int keycode, t_game *game);
int			ray_casting(t_game *game);
int			key_relase(int keycode, t_game *game);
void		calculate_ray(t_game *game, int x);
void		calculate_step(t_game *game);
void		movements(t_game *game);
void		init_map(t_game *game, char *file);
void		free_double(char **str);
void		convert_xpm(t_game *game);
void		free_all(t_game *game);
void		init_mlx(t_game *game);
void		init_map_data(t_game *game);
void		init_ray(t_game *game);
void		init_draw(t_game *game);
void		init_key(t_game *game);
void		check_player(t_game *game, char way);
void		ft_exit(char *str);
void		init(t_game *game);
void		check_map_valid(t_game *game);
void		cf_valid(t_game *game, char **floor, char **ceil, int i);
void		err_cf(t_game *game);
void		find_pos(t_player *player, t_game *game);
void		init_player(t_game *game);
void		rotate_cam(t_game *game);
char		*ft_straddchar(char *s1, char *s2);

#endif

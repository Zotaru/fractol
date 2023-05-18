/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:57:57 by amonier           #+#    #+#             */
/*   Updated: 2023/05/14 02:15:45 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/Includes/libft.h"
# include <math.h>
# include <mlx.h>

# define WINDOW_WIDTH 1080
# define WINDOW_LENGTH 1080
# define IMG_WIDTH 1080
# define IMG_LENGTH 1080

# define N_MAX 200

// taille axe real et imaginaire:
// # define REAL_AXE_SIZE 4
// # define IM_AXE_SIZE 4
// les center dependent des AXES_SIZE / 2, ils permettent les decalage
// # define CENTER_REAL 2
// # define CENTER_UNREAL 2

typedef struct s_mouse_zoom
{
	float	x;
	float	y;
}			t_mcaliber;

typedef struct s_scale
{
	float	x_min;
	float	x_max;
	float	y_min;
	float	y_max;
}			t_scale;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_scale	*axe;
	int		fract;
	float	julia_x;
	float	julia_y;
	int		mouse_x;
	int		mouse_y;
}			t_vars;

// --------------------------------UTILS------------------------------------

typedef struct s_fractol_point
{
	float	pixel_x;
	float	pixel_y;
	float	real_x;
	float	unreal_yi;
}			t_fpoint;

// pour calcule imaginaire:
typedef struct s_complexe
{
	float	real;
	float	unreal;
	float	modulus;
}			t_z;

void		calculate_real_unreal(t_fpoint *act_point, t_scale axe);
int			create_fract_trgb(int n_i);

// -------------------------------------------------------------------------

// ------------------------------- MANDELBROT ------------------------------

void		my_mlx_mandel_fractol(t_data *img, t_scale axe);
int			calcule_fractole_mandel(t_fpoint *act_point);

// ---------------------------------------------------------------------------

// ---------------------------------JULIA------------------------------------

int			calcule_fract_julia(t_fpoint *act, float z_re, float z_im);
// void	julia_pixel_put(t_data *img, t_fpoint *point, int n);
void		my_mlx_julia_fract(t_data *img, float z_re, float z_im,
				t_scale axe);

//---------------------------------------------------------------------------

// -------------------------------ZOOM--------------------------------------

void		mandel_zoom(t_vars *mlx, t_data *img, t_scale *axe);
void		mandel_dezoom(t_vars *mlx, t_data *img, t_scale *axe);
void		julia_zoom(t_vars *mlx, t_data *img, t_scale *axe);
void		julia_dezoom(t_vars *mlx, t_data *img, t_scale *axe);

void		clear_image(t_data *img);

//---------------------------------------------------------------------------

// ------------------------------PARSING-------------------------------------

void		parsing(int argc, char **argv, t_vars *mlx);
void		bad_command(void);
void		check_str(char *str);
float		ft_atof(char *str);

// ---------------------------------------------------------------------------

// ---------------------------HOOK-------------------------------------------

int			esc(int keycode, t_vars *param);
int			cross(t_vars *param);
int			mouse_hook(int keycode, int x, int y, t_vars *mlx);
void		all_hook(t_vars *vars);

// --------------------------------------------------------------------------

//---------------------------BONUS--------------------------------------

//hook bonus:
int			keyboard(int keycode, t_vars *param);

void		mandel_right(t_vars *mlx, t_data *img, t_scale *axe);
void		julia_right(t_vars *mlx, t_data *img, t_scale *axe);

void		mandel_left(t_vars *mlx, t_data *img, t_scale *axe);
void		julia_left(t_vars *mlx, t_data *img, t_scale *axe);

// -------------------------------------------------------------------

// fonction a faire plus rapide selon la mlx doc:
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
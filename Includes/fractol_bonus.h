/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 02:09:13 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 20:31:57 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include <mlx.h>
# include <math.h>
# include "../libft/Includes/libft.h"

# include <pthread.h>

# define NUM_THREADS 100

# define WINDOW_WIDTH 1080
# define WINDOW_LENGTH 1080
# define IMG_WIDTH 1080
# define IMG_LENGTH 1080

# define N_MAX 100

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
	int		color;
}			t_scale;

enum {
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

typedef struct s_thread
{
	int		start_index;
	int		end_index;
	t_data	*img;
	float	z_re;
	float	z_im;
	t_scale	axe;
}			t_thread;

// --------------------------------UTILS------------------------------------

typedef struct s_fractol_point
{
	float		pixel_x;
	float		pixel_y;
	float		real_x;
	float		unreal_yi;
}				t_fpoint;

// pour calcule imaginaire: 
typedef struct s_complexe
{
	float	real;
	float	unreal;
	float	modulus;
}			t_z;

void	calculate_real_unreal(t_fpoint *act_point, t_scale axe);
int		create_fract_trgb(int n_i, int color);

// -------------------------------------------------------------------------

// ------------------------------- MANDELBROT ------------------------------

void	my_mlx_mandel_fractol(t_data *img, t_scale axe);
int		calcule_fractole_mandel(t_fpoint *act_point);

// ---------------------------------------------------------------------------

// ---------------------------------JULIA------------------------------------

int		calcule_fract_julia(t_fpoint *act, float z_re, float z_im);
// void	julia_pixel_put(t_data *img, t_fpoint *point, int n);
void	my_mlx_julia_fract(t_data *img, float z_re, float z_im, t_scale axe);

//---------------------------------------------------------------------------

// -------------------------------ZOOM--------------------------------------

void	mandel_zoom(t_vars *mlx, t_data *img, t_scale *axe);
void	mandel_dezoom(t_vars *mlx, t_data *img, t_scale *axe);
void	julia_zoom(t_vars *mlx, t_data *img, t_scale *axe);
void	julia_dezoom(t_vars *mlx, t_data *img, t_scale *axe);

void	clear_image(t_data *img);

//---------------------------------------------------------------------------

// ------------------------------PARSING-------------------------------------

void	parsing(int argc, char **argv, t_vars *mlx);
void	bad_command(void);
void	check_str(char *str);
float	ft_atof(char *str);

// ---------------------------------------------------------------------------

// ---------------------------HOOK-------------------------------------------

int		esc(int keycode, t_vars *param);
int		cross(t_vars *param);
int		mouse_hook(int keycode, int x, int y, t_vars *mlx);
void	all_hook(t_vars *vars);

// --------------------------------------------------------------------------

//---------------------------BONUS--------------------------------------

//hook bonus:
void	my_mlx_newton_fractol(t_data *img, t_scale axe);
t_z		calcule_fract_newton(t_fpoint *act);

int		keyboard(int keycode, t_vars *param);

void	mandel_right(t_vars *mlx, t_data *img, t_scale *axe);
void	julia_right(t_vars *mlx, t_data *img, t_scale *axe);
void	newton_right(t_vars *mlx, t_data *img, t_scale *axe);

void	mandel_left(t_vars *mlx, t_data *img, t_scale *axe);
void	julia_left(t_vars *mlx, t_data *img, t_scale *axe);
void	newton_left(t_vars *mlx, t_data *img, t_scale *axe);

void	julia_top(t_vars *mlx, t_data *img, t_scale *axe);
void	mandel_top(t_vars *mlx, t_data *img, t_scale *axe);
void	newton_top(t_vars *mlx, t_data *img, t_scale *axe);

void	julia_down(t_vars *mlx, t_data *img, t_scale *axe);
void	mandel_down(t_vars *mlx, t_data *img, t_scale *axe);
void	newton_down(t_vars *mlx, t_data *img, t_scale *axe);

void	mandel_switch(t_vars *mlx, t_data *img, t_scale *axe);
void	julia_switch(t_vars *mlx, t_data *img, t_scale *axe);
void	newton_switch(t_vars *mlx, t_data *img, t_scale *axe);

void	newton_zoom(t_vars *mlx, t_data *img, t_scale *axe);
void	newton_dezoom(t_vars *mlx, t_data *img, t_scale *axe);

// -------------------------------------------------------------------

// fonction a faire plus rapide selon la mlx doc: 
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
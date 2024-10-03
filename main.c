/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:02:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/26 21:03:57 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

/*
NEVER FORGET:
point  w is 1
vector w is 0
*/

void	garbage(void *new, int i)
{
	static void			*s[5] = {0, 0, 0, 0, 0};
	static int			idx = 0;

	if (idx > 4 && i == 0)
		return ;
	if (i == 0)
	{
		s[idx++] = new;
		return ;
	}
	if (s[3])
		lst_inter_lstclear(s[3]);
	if (s[4])
		lst_inter_lstclear(s[4]);
	if (s[2])
		mlx_destroy_image(s[0], s[2]);
	if (s[1])
	{
		mlx_clear_window(s[0], s[1]);
		mlx_loop_end(s[0]);
		mlx_destroy_window(s[0], s[1]);
	}
	mlx_destroy_display(s[0]);
	free(s[0]);
	exit(0);
}

void	init_mlx(t_vars *vars, t_img *img, t_figure *w, t_camera *camera)
{
	vars->data = img;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(1);
	garbage(vars->mlx, 0);
	vars->win_ptr = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT,
			"MiniRT");
	if (!vars->win_ptr)
		garbage(0, 1);
	garbage(vars->win_ptr, 0);
	vars->cam = camera;
	vars->w = w;
	init_img(img, vars->mlx);
}

void	div_by_0(int ok)
{
	(void) ok;
	ft_printf("division by zero occured :: freeing everything\n");
	garbage(0, 1);
}

void	render(t_camera *camera, t_figure *w)
{
	int		xy[2];
	t_ray	r;
	t_vars	vars;
	t_img	img;
	t_f4	color_px;

	signal(SIGFPE, &div_by_0);
	init_mlx(&vars, &img, w, camera);
	xy[0] = -1;
	while (++xy[0] < WIN_HEIGHT)
	{
		xy[1] = -1;
		while (++xy[1] < WIN_WIDTH)
		{
			ray_for_pixel(camera, xy[0], xy[1], &r);
			color_px = color_hit(w, &r);
			my_mlx_pixel_put(vars.data, xy[0], xy[1], float_to_rgba(color_px));
		}
	}
	mlx_key_hook(vars.win_ptr, &keyhook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win_ptr, vars.data->img, 0, 0);
	mlx_hook(vars.win_ptr, 33, 1L << 17, ft_close, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av, char **env)
{
	static t_figure	infos = {0};
	t_content_file	*cf;

	if (!env || !*env)
		return (ft_printf("{red}Error{reset}\nNo environment path available\n"));
	if (ac != 2)
		return (ft_printf("{red}Error{reset}\nWrong arguments count\n"));
	if (check_extension_filename(av[1]) == false)
		return (ft_printf("{red}Error{reset}\nWrong filename extension\n"));
	cf = readfile(av[1], & infos);
	if (cf)
		cf_delete(cf);
	else
		return (ft_printf("{red}Error{reset}\nParsing: KO\n"));
	build_transform_matrix(&infos);
	build_camera(&infos.camera);
	render(&infos.camera, &infos);
	return (0);
}

// sp 1.0,-1.0,-0.5 1.0 255,0,0
// sp 0.0,0.0,0.0 1.0 204,255,153
// sp 0,1,0 1.0 255,0,0

// from ludi.rt

// sp -0.5,0,0 1.0 255,0,255
// sp 0.5,0,0 1.0 255,255,0

// from pattern test
// sp 0,0,0 2 255,255,255
// cy -5,3,5 0,1,0 1 4 255,255,255

// organization ::
// -have only one creating_intersection (check)
// -norme hit_cy.c (check)
// -add matrix() and orientation_matrix() to maxou_math (check)
// -norme matrix (check)
// -simplify build_transform_matrix() (check)
// -simplify render by having a function for whats inside the loop
// in one file with is_shaded() and phong_lighting()

// for next work session:
// -organize t_intrscts
// -start protecting mallocs and have a garbage collector
// -put the functions like get_floor or the manipulation color functions
// in maxou_math
// -reorganize intersect_world

// to do (not organization) ::
// -add ambient lighting
// -and the fov

// ==================== JM'S WORK ====================

// -je sais pas pk le fov est encore a 0 quoi qu'il arrive
// je pense j'ai pas modifié ce qui fallait dans cette version 
// dans le parsing pour que ca remarche

// -ajouter un dernier parametre appelé specular [0;1]
// a la fin de chaque objet donc cy, sp, pl
// si il est pas spécifié alors tu laisse a zero

// sp -9,1,-10 0.75 250,50,150 0.9
// 							specular = 0.9
// sp -9,1,-10 0.75 250,50,150 
// 							specular = 0

// -ajouter a la fin de chaque objet (cy, sp, pl)
// un nouveau identifier appeler pattern (pa)
// avec deux parametres obligatoires space (équartement entre chaque case)
// et color la couleur des cases ajouter sur l'objet
// exemple:

// sp -9,1,-10 0.75 250,50,150 0.9 pa 0.2 0,0,255
// 								remplir la structure t_pattern 
// 								dans la structure t_object dans chaque 
// 								objets
// 								et mettre la variable bool pattern = true
// 								obj.pat.space = 0.2
// 								obj.pat.color = 0,0,255 (blue)

// PS:  si c'est plus simple pour toi tu peux directement
//  mettre la structure t_pattern dans
// la structure representant l'objet comme ca (ICI):
// typedef struct	s_sphere
// {
// 	char		identifier[3];
// 	t_f4		origin;
// 	t_clr		color;
// 	float		diameter;
// 	float		specular;
// 	bool		pattern;
// 	t_pattern	pat; // <--------- ICI 

// 	t_object	obj;
// 	float	inter[2];
// }				t_sphere;

// -ajouter une nouvelle forme cube
// cb 0,0,0 0,1,0 2 255,0,0

// identifier cb
// center		0,0,0
// cube_axis	0,1,0
// cube_height	2.0
// color		255,0,0 (red)

// PS: tu peux changer l'ordre si c'est plus simple

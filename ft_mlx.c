/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:43:10 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/22 10:52:02 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include <unistd.h>

// static int	expose_hook(t_env *e)
// {
// 	int		bpp;
// 	int		sl;
// 	int		endian;

// 	e->img = mlx_new_image(e->mlx, e->s->cam->xres, e->s->cam->yres);
// 	e->addr = mlx_get_data_addr(e->img, &bpp, &sl, &endian);
// 	ft_drawscene(e->s, e);
// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
// 	mlx_destroy_image(e->mlx, e->img);
// 	return (0);
// }

// static int	key_hook(int keycode, t_env *e)
// {
// 	if (keycode == 53)
// 		exit(0);
// 	if (ft_move(keycode, e->s->cam))
// 	{
// 		ft_initcam(e->s->cam);
// 		expose_hook(e);
// 	}
// 	return (0);
// }

void		ft_redraw(t_env *e)
{
	ft_initcam(e->s->cam);
 	ft_drawscene(e->s, e);
}

void		move_cam(SDL_Keycode key, t_env *e)
{
	if (key == SDLK_w && e->event.type == SDL_KEYDOWN)
	 	e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->vec, 30));
	else if (key == SDLK_s && e->event.type == SDL_KEYDOWN)
 	 	e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->vec, -30)); 
 	 else if (key == SDLK_a && e->event.type == SDL_KEYDOWN)
 	 	e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->rightvec, -30));
 	 else if (key == SDLK_d && e->event.type == SDL_KEYDOWN)
 	 	e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->rightvec, 30)); 	 	
 	 ft_redraw(e);
}

void		test(t_env *e)
{
	while (e->run)
	{
		if (SDL_WaitEvent(&e->event))
		{
			if (e->event.window.event == SDL_WINDOWEVENT_CLOSE || e->event.key.keysym.sym == SDLK_ESCAPE)
				e->run = 0;
			move_cam(e->event.key.keysym.sym, e);
			// if (e->event.key.keysym.sym == SDLK_w && e->event.type == SDL_KEYDOWN)
			//  {
			//  	e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->vec, 10));
			//  	ft_initcam(e->s->cam);
			//  	ft_drawscene(e->s, e);
			//  }
		}
	}
}

void		ft_sdl(t_scene *s)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	e->s = s;
	// e->mlx = mlx_init();
	// e->win = mlx_new_window(e->mlx, s->cam->xres, s->cam->yres, s->name);
	// mlx_expose_hook(e->win, expose_hook, e);
	// mlx_key_hook(e->win, key_hook, e);
	// mlx_loop(e->mlx);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		SDL_Quit();
	e->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, s->cam->xres, s->cam->yres, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (e->win == NULL)
		SDL_Quit();
	e->renderer = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(e->renderer, 0, 0, 0, 255);
	SDL_RenderClear(e->renderer);
	e->run = 1;
	ft_drawscene(e->s, e);
	test(e);
}

	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:43:10 by ltesson           #+#    #+#             */
/*   Updated: 2017/08/29 22:45:51 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include <unistd.h>
/* a enlever */
#include <stdio.h>
/* ********** */

void		ft_redraw(t_env *e)
{
	ft_initcam(e->s->cam);
 	ft_drawscene(e->s, e);
 	SDL_SetRenderDrawColor(e->renderer, 0, 0, 0, 255);
	SDL_RenderClear(e->renderer);
 	printf("1\n");
}

void		rot_cam(SDL_Keycode key, t_env *e)
{
	if (key == SDLK_UP && e->event.type == SDL_KEYDOWN)
		e->s->cam->vec = ft_rotatearound(e->s->cam->vec, e->s->cam->rightvec, (double)(3) / 16);
	else if (key == SDLK_DOWN && e->event.type == SDL_KEYDOWN)
		e->s->cam->vec = ft_rotatearound(e->s->cam->vec, e->s->cam->rightvec, (double)(-3) / 16);
	else if (key == SDLK_RIGHT && e->event.type == SDL_KEYDOWN)
		e->s->cam->vec = ft_rotatevecteur(e->s->cam->vec, 0, 0, (double)(-3) / 16);
	else if (key == SDLK_LEFT && e->event.type == SDL_KEYDOWN)
		e->s->cam->vec = ft_rotatevecteur(e->s->cam->vec, 0, 0, (double)(3) / 16);
}

void		move_cam(SDL_Keycode key, t_env *e)
{
	if (key == SDLK_w && e->event.type == SDL_KEYDOWN)
		e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->vec, 50));
	else if (key == SDLK_s && e->event.type == SDL_KEYDOWN)
		e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->vec, -50));
	else if (key == SDLK_a && e->event.type == SDL_KEYDOWN)
		e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->rightvec, -50));
	else if (key == SDLK_d && e->event.type == SDL_KEYDOWN)
		e->s->cam->pos = ft_translation(e->s->cam->pos, ft_multvecteur(e->s->cam->rightvec, 50));
}

void		test(t_env *e)
{
	while (e->run)
	{
		if (SDL_WaitEvent(&e->event))
		{
			printf("2\n");
			if (e->event.window.event == SDL_WINDOWEVENT_CLOSE || e->event.key.keysym.sym == SDLK_ESCAPE)
				e->run = 0;
			else if ((KEY == SDLK_w || KEY == SDLK_s || KEY == SDLK_a || KEY == SDLK_d) && e->event.type == SDL_KEYDOWN)
			{
				printf("3\n");
				move_cam(e->event.key.keysym.sym, e);
				ft_redraw(e);
		}
			else if ((KEY == SDLK_UP || KEY == SDLK_DOWN || KEY == SDLK_RIGHT || KEY == SDLK_LEFT) && e->event.type == SDL_KEYDOWN)
			{
				printf("3\n");
				rot_cam(e->event.key.keysym.sym, e);
				ft_redraw(e);
			}
		}
	}
}

void		ft_sdl(t_scene *s)
{
	t_env	*e;
//	 int		x = 0;
//	 int		y = 0;

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
//	ft_drawscene(e->s, e);
	ft_init_texture(e);
//	SDL_Surface *image = SDL_LoadBMP("./VegetaFF.bmp");
//	if (image == NULL)
//		printf("image == NULL\n");
//	int nb_bytes_per_pixel = image->format->BytesPerPixel;
//	Uint32 format = image->format->format;
//	printf("SDL_GetPixelFormatName: %s\n", SDL_GetPixelFormatName(format));
//	printf("image->format->BytesPerPixel = %d\n", nb_bytes_per_pixel);
//	printf("image->format->format : %d\n", image->format->format);
//	printf("rgbq888: %d\n", SDL_PIXELFORMAT_RGBA8888);
//	 while (x < image->w)
//	 {
//	 	y = 0;
//	 	while (y < image->h)
//	 	{
//	 		Uint8 *p = (Uint8*)image->pixels + y * image->pitch + x * nb_bytes_per_pixel;
//			 Uint32 pixel = p[0] << 16 | p[1] << 8 | p[2];
//			 if (pixel != 16777215)
//			 {
//			 	printf("pixel = %d\n", (int)pixel);
//			 	printf("p[0] << 16 = %d\tp[1] << 8 = %d\tp[2] = %d\n", p[0], p[1], p[2]);
//			 }
//	 		y++;
//	 	}
//	 	x++;
//	 }
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(e->renderer, image);
//	if (texture == NULL)
//		printf("texture = NULL\n");
//	SDL_FreeSurface(image);
//	SDL_RenderCopy(e->renderer, texture, NULL, NULL);
//	SDL_RenderPresent(e->renderer);
	test(e);
}

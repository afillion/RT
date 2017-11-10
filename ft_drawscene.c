/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:43:30 by ltesson           #+#    #+#             */
/*   Updated: 2017/09/12 16:06:51 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <unistd.h>

t_rayon	ft_primray(t_camera *c, double i, double j)
{
	t_vecteur	haut;
	t_vecteur	droit;
	t_rayon		ray;

	droit = ft_multvecteur(c->rightvec, c->xindent * j);
	haut = ft_multvecteur(c->upvec, c->yindent * i);
	ray.pos = ft_translation(c->firstpix, ft_addvecteur(haut, droit));
	ray.vec = ft_getvecteur(c->pos, ray.pos);
	ray.vec = ft_normalizevecteur(ray.vec);
	ray.pos = c->pos;
	ray.objet = NULL;
	ray.shine = 0;
	return (ray);
}

void	ft_putcolor(t_env *e, int i, int j, t_rayon ray)
{
	int		red;
	int		green;
	int		blue;

	red = ray.color / (256 * 256);
	green = (ray.color / 256) % 256;
	blue = ray.color % 256;
	if (ray.power < 0.15)
		ray.power = 0.15;
	red += (255 - red) * ray.shine;
	green += (255 - green) * ray.shine;
	blue += (255 - blue) * ray.shine;
	SDL_SetRenderDrawColor(e->renderer, ft_min(255, ray.power * red), ft_min(255, ray.power * green), ft_min(255, ray.power * blue), 255);
	SDL_RenderDrawPoint(e->renderer, j, i);
	// e->addr[j * 4 + i * 4 * e->s->cam->xres + 2] =
	// 	ft_min(255, ray.power * red);
	// e->addr[j * 4 + i * 4 * e->s->cam->xres + 1] =
	// 	ft_min(255, ray.power * green);
	// e->addr[j * 4 + i * 4 * e->s->cam->xres] =
	// 	ft_min(255, ray.power * blue);
}

void	ft_lancerayon(t_scene *s, t_env *e, int i, int j)
{
	t_rayon		ray;
	t_listobj	*liste;
	double 		u = 0;
	double 		v = 0;
	t_vecteur 		n;
	// int			x = 0;
	// int			y = 0;

	ray = ft_primray(s->cam, i, j);
	ray.color = 0;
	ray.t = INFINITY;
	liste = s->list;
	while (liste)
	{
		ft_intersect(&ray, liste);
		liste = liste->next;
	}
	if (ray.objet == NULL)
		return ;
	if (ray.objet->type == SPHERE)
	{
		if (((t_sphere*)ray.objet->objet)->texture == 1)
		{
			t_vecteur pi;
			ray.vec = ft_normalizevecteur(ray.vec);

			// printf("{%f;%f;%f}\n", ray.vec.x, ray.vec.y, ray.vec.z);

			pi = ft_multvecteur(ray.vec, ray.t);
			pi.x += ray.pos.x;
			pi.y += ray.pos.y;
			pi.z += ray.pos.z;
			n.x = pi.x - ((t_sphere*)ray.objet->objet)->pos.x;
			n.y = pi.y - ((t_sphere*)ray.objet->objet)->pos.y;
			n.z = pi.z - ((t_sphere*)ray.objet->objet)->pos.z;
			n = ft_normalizevecteur(n);
//			u = 1 - (0.5 + ((atan2(n.x, n.z)) / (2 * M_PI)));
//			v = 1 - (0.5 - ((asin(n.y)) / M_PI));

			u = atan2(n.x, n.z) / (2 * M_PI) + 0.5;
			v = n.y * 0.5 + 0.5;

			// v = 0.5 + (atan2(n.z, n.x) / (2 * M_PI));
			// u = 0.5 - (asin(n.y / ((t_sphere*)ray.objet->objet)->r) / M_PI);

			// SDL_Surface *image = SDL_LoadBMP("./VegetaFF.bmp");
			// u  = asin(n.x / ((t_sphere*)ray.objet->objet)->r);
			// printf("pi.x = %f rayon = %f\n", n.x, ((t_sphere*)ray.objet->objet)->r);
			// double ac = 0.0;
			// if (cos(u) != 0.0)
			// {
			// 	ac = n.z / (((t_sphere*)ray.objet->objet)->r * cos(u));
		 //     	if (ac < -1)
		 //     		ac = -1;
		 //   		if (ac > 1)
		 //   			ac = 1;
		 //     	v = acos(ac);
			// }
			// else
			// 	v = 0.0;
			// if (n.y > 0.0)
			// 	v = -v;
			// v += M_PI;
			// printf("{U = %f || V = %f }\n", u, v);
			// double test = (u / M_PI + 0.5);
			// printf("%f\n", test);
			// int k = (int)(image->h * (test - (int)test));
			// test = 0.5 * v / M_PI;
			// printf("%f\n", test);
			// int l = (int)(image->w * (test - (int)test));
			// printf("{%d ; %d}\n", k, l);

			// SDL_Surface *image = SDL_LoadBMP("./redbrick.bmp");

			// printf("Intersection point p{%fx ; %fy ; %fz} in cartesian coordinate system\n", pi.x, pi.y, pi.z);
		 	// double radius = sqrt(pi.x * pi.x + pi.y * pi.y + pi.z * pi.z);
			// double theta = atan2(pi.y, pi.x);
			// double phi = atan2(sqrt(pi.x * pi.x + pi.y * pi.y), pi.z);
			// printf("Intersection point p{%fr ; %ftheta ; %fphi} in spherical coordiante system\n", radius, theta, phi);
			// printf("UV = {%f ; %f} | ST = {%f ; %f}\n", u, v, s, t);

			// int bpp = image->format->BytesPerPixel;

			 int r = ((((int)(u * 100) ^ ((int)(v * 100))) >> 2)&1);
			 if (r == 0)
			 	ray.color = 0xFF0000;
			 else
			 	ray.color = 0xFF;
			// printf("%d\n", r);

			// x = (int)(u * image->w);
			// y = (int)(v * image->h);
			// printf("x = %d\ty = %d\n", x, y);
			// Uint8 *p = (Uint8*)image->pixels + x * image->pitch + y * bpp;
			// ray.color = p[0] | p[1] << 8 | p[2] << 16;
			// printf("ray.color = %d\n", ray.color);
			// SDL_FreeSurface(image);
		}
		else
			ray.color = ((t_sphere*)ray.objet->objet)->color;
	}
	if (ray.objet->type == PLAN)
		ray.color = ((t_plan*)ray.objet->objet)->color;
	if (ray.objet->type == CYLINDRE)
	{
		if (((t_cylindre*)ray.objet->objet)->texture == 1)
		{
			double r, theta, z;
			r = 0;
			theta = 0;
			z = 0;
			t_vecteur pi;
			ray.vec = ft_normalizevecteur(ray.vec);
			pi = ft_multvecteur(ray.vec, ray.t);
			pi.x += ray.pos.x;
			pi.y += ray.pos.y;
			pi.z += ray.pos.z;
			// n.x = pi.x - ((t_cylindre*)ray.objet->objet)->pos.x;
			// n.y = pi.y - ((t_cylindre*)ray.objet->objet)->pos.y;
			// n.z = pi.z - ((t_cylindre*)ray.objet->objet)->pos.z;
			t_point pos;
			pos.x = pi.x;
			pos.y = pi.y;
			pos.z = pi.z;
			n = ft_getnormcyl(pos, ((t_cylindre*)ray.objet->objet));

			// r = sqrt((n.x * n.x) + (n.y * n.y));
			// theta = atan2(n.x, n.z);
			// z = n.y;
			// theta = atan2(n.y, n.x);
			// u = (theta / (2 * M_PI));
			// v = n.z / ((t_cylindre*)ray.objet->objet)->

			// printf("Intersection point p{%fx ; %fy ; %fz} in cartesian coordinate system\n", pi.x, pi.y, pi.z);
			// printf("Intersection point p{%fr ; %ftheta ; %fz} in cylindrical coordinate system\n", r, theta, z);
			// SDL_Surface *image = SDL_LoadBMP("./VegetaFF.bmp");
			// int bpp = image->format->BytesPerPixel;
			u = -(0.5 + (atan2(n.x, n.y) / M_PI));
			v = -(n.z / M_PI) - floor(n.z / M_PI);
			int t = ((((int)(u * 100) ^ ((int)(v * 100))) >> 2)&1);

			t_vecteur test;
			test.x = (pos.x - ((t_cylindre*)ray.objet->objet)->r) - ((t_cylindre*)ray.objet->objet)->pos.x;
			test.y = (pos.y - ((t_cylindre*)ray.objet->objet)->r) - ((t_cylindre*)ray.objet->objet)->pos.y;
			test.z = (pos.z - ((t_cylindre*)ray.objet->objet)->r) - ((t_cylindre*)ray.objet->objet)->pos.z;

			double c_pythagore = sqrt((test.x*test.x)+(test.y*test.y)+(test.z*test.z));
			double b_pythagore = (((t_cylindre*)ray.objet->objet)->r * ((t_cylindre*)ray.objet->objet)->r) - (c_pythagore * c_pythagore);
			b_pythagore = sqrt(b_pythagore);
			printf("%f\n", (b_pythagore));
			if (t == 0 && (int)(b_pythagore + 200000) % 10 >= 5)
				ray.color = 0x0000ff;
			else if (t != 0 && (int)(b_pythagore + 200000) % 10 < 5)
				ray.color = 0x0000ff;
			else
				ray.color = 0xff;

			// if (t == 0 && (int)(pi.z + 20000000) % 10 >= 5)
			// 	ray.color = 0xFF0000;
			// else if (t != 0 && (int)(pi.z + 20000000) % 10 < 5)
			// 	ray.color = 0xFF0000;
			// else
			// 	ray.color = 0xFF; // == 0x0000FF; Pas besoin de marquer les deux premiers bytes quand ils sont nuls

			// x = (r * cos(theta));
			// y = (r * sin(theta));

			// x = (int)(theta * image->w);
			// y = (int)(z * image->h);

			// if (x < 0)
			// 	x += 1;
			// if (y < 0)
			// 	y += 1;
			// if (x > 1)
			// 	x -= 1;
			// if (y > 1)
			// 	y -= 1;
			// Uint8 *p = (Uint8*)image->pixels + x * image->pitch + y * bpp;
			// ray.color = p[0] | p[1] << 8 | p[2] << 16;
			// SDL_FreeSurface(image);
		}
		else
			ray.color = ((t_cylindre*)ray.objet->objet)->color;
	}
	if (ray.objet->type == CONE)
		ray.color = ((t_cone*)ray.objet->objet)->color;
	ft_getlight(s, &ray);
	ft_putcolor(e, i, j, ray);
}

void	ft_drawscene(t_scene *s, t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->cam->yres)
	{
		j = 0;
		while (j < s->cam->xres)
		{
			ft_lancerayon(s, e, i, j);
			j++;
		}
		i++;
	}
	SDL_RenderPresent(e->renderer);
}

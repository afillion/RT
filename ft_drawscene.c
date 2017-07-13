/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:43:30 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/23 13:37:54 by afillion         ###   ########.fr       */
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
		ray.color = ((t_sphere*)ray.objet->objet)->color;
	if (ray.objet->type == PLAN)
		ray.color = ((t_plan*)ray.objet->objet)->color;
	if (ray.objet->type == CYLINDRE)
		ray.color = ((t_cylindre*)ray.objet->objet)->color;
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

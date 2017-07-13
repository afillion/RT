/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:12:12 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/22 10:38:11 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <math.h>
# include "./SDL2-2.0.5/include/SDL.h"
# define SPOT 0
# define SPHERE 1
# define PLAN 2
# define CYLINDRE 3
# define CONE 4
# define RED 13511728
# define BLUE 3093151
# define GREEN 3127874
# define DARKBLUE 1645713
# define DARKRED 5319981
# define DARKGREEN 4805931
# define GREY 8159104
# define WHITE 16777215

typedef struct			s_listobj
{
	void				*objet;
	int					type;
	struct s_listobj	*next;
}						t_listobj;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_vecteur
{
	double				x;
	double				y;
	double				z;
}						t_vecteur;

typedef struct			s_rayon
{
	t_point				pos;
	t_vecteur			vec;
	double				t;
	int					color;
	double				power;
	t_listobj			*objet;
	double				shine;
}						t_rayon;

typedef struct			s_camera
{
	int					xres;
	int					yres;
	t_point				pos;
	t_vecteur			vec;
	t_vecteur			upvec;
	t_vecteur			rightvec;
	double				viewdist;
	double				viewwidth;
	double				viewheight;
	t_point				firstpix;
	double				xindent;
	double				yindent;
}						t_camera;

typedef struct			s_sphere
{
	t_point				pos;
	double				r;
	int					color;
}						t_sphere;

typedef struct			s_plan
{
	double				a;
	double				b;
	double				c;
	double				d;
	int					color;
}						t_plan;

typedef struct			s_cylindre
{
	t_point				pos;
	double				a;
	double				b;
	double				r;
	int					color;
}						t_cylindre;

typedef struct			s_cone
{
	t_point				pos;
	double				a;
	double				b;
	double				c;
	int					color;
}						t_cone;

typedef struct			s_spot
{
	t_point				pos;
	double				power;
	struct s_spot		*next;
}						t_spot;

typedef struct			s_scene
{
	char				*name;
	t_camera			*cam;
	t_listobj			*list;
	t_spot				*spot;
	int					error;
}						t_scene;

typedef struct			s_env
{
	// void				*mlx;
	// void				*win;
	// void				*img;
	// char				*addr;
	SDL_Renderer		*renderer;
	SDL_Window			*win;
	SDL_Event			event;
	int 				run;
	t_scene				*s;
}						t_env;

void					ft_readfile(t_scene *s, char *av);
void					ft_readspot(t_scene *s, int fd, char *line, int *i);
void					ft_readsphere(t_scene *s, int fd, char *line, int *i);
void					ft_readplan(t_scene *s, int fd, char *line, int *i);
void					ft_readcylindre(t_scene *s, int fd, char *line, int *i);
void					ft_readcone(t_scene *s, int fd, char *line, int *i);
void					ft_readcamera(t_scene *s, int fd, char *line, int *i);
int						ft_readcolor(char *color);
void					ft_sdl(t_scene *s);										//anciennement ft_mlx
void					ft_drawscene(t_scene *s, t_env *e);
void					ft_initcam(t_camera *cam);
t_scene					*ft_initscene(void);
t_vecteur				ft_normalizevecteur(t_vecteur v);
t_vecteur				ft_getvecteur(t_point a, t_point b);
t_vecteur				ft_multvecteur(t_vecteur v, double t);
t_vecteur				ft_addvecteur(t_vecteur v, t_vecteur w);
t_point					ft_translation(t_point p, t_vecteur v);
t_vecteur				ft_rotatevecteur(t_vecteur v, double x, double y,
						double z);
t_vecteur				ft_rotatearound(t_vecteur v, t_vecteur a, double t);
double					ft_produitscalaire(t_vecteur u, t_vecteur v);
double					ft_getnormevecteur(t_vecteur v);
void					ft_intersect(t_rayon *ray, t_listobj *liste);
int						ft_intersphere(t_rayon *ray, t_sphere *sphere);
int						ft_interplan(t_rayon *ray, t_plan *plan);
int						ft_intercylindre(t_rayon *ray, t_cylindre *cylindre);
int						ft_intercone(t_rayon *ray, t_cone *cone);
int						ft_intercheck(t_rayon *ray, t_scene *s);
int						ft_distance(double a, double b, double c, t_rayon *ray);
int						ft_error(int e);
void					ft_addsphere(t_scene *s, t_point pos, double r,
						int color);
void					ft_addplan(t_scene *s, t_point pos, double r,
						int color);
void					ft_addcylindre(t_scene *s, t_point pos, t_point t,
						int color);
void					ft_addcone(t_scene *s, t_point pos, t_point t,
						int color);
void					ft_addlist(t_scene *s, void *objet, int type);
void					ft_addspot(t_scene *s, t_point pos, double r);
t_vecteur				ft_getnormale(t_point pos, t_listobj *liste);
t_vecteur				ft_getnormplan(t_plan *plan);
t_vecteur				ft_getnormcyl(t_point pos, t_cylindre *cylindre);
t_vecteur				ft_getnormcone(t_point pos, t_cone *cone);
void					ft_getlight(t_scene *s, t_rayon *ray);
int						ft_move(int keycode, t_camera *cam);

#endif
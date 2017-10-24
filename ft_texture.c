#include "rt.h"

void	ft_init_texture(t_env *e)
{
	e->vegeta = SDL_LoadBMP("./VegetaFF.bmp");
	e->redbrick = SDL_LoadBMP("./redbrick.bmp");
	e->earth = SDL_LoadBMP("./earth.bmp");
	printf("Vegeta pixel format : %s   & bpp : %d\n", SDL_GetPixelFormatName(e->vegeta->format->format), e->vegeta->format->BytesPerPixel);
	printf("Redbrick pixel format : %s   & bpp : %d\n", SDL_GetPixelFormatName(e->redbrick->format->format), e->redbrick->format->BytesPerPixel);
	printf("Earth pixel format : %s &   bpp : %d\n", SDL_GetPixelFormatName(e->earth->format->format), e->earth->format->BytesPerPixel);
	SDL_FreeSurface(e->vegeta);
	SDL_FreeSurface(e->redbrick);
	SDL_FreeSurface(e->earth);
}

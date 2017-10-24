# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltesson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:46:25 by ltesson           #+#    #+#              #
#    Updated: 2017/08/29 22:35:31 by afillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH= libft

SDLPATH= SDL2-2.0.5

LIB= $(LIBPATH)/libft.a

SDL= $(SDLPATH)/lib/

NAME= rtv1

CC= gcc

CFLAGS= -Wall -Wextra -Werror

LDFLAGS= -L libft -lft -I$(LIBPATH)/includes -L $(SDL) -lSDL2 -lSDL2main -I$(SDLPATH)/include

SRC = main.c ft_initcam.c ft_vecteur.c ft_mlx.c ft_drawscene.c \
	  ft_intersect.c ft_addsphere.c ft_error.c ft_move.c \
	  ft_morevecteur.c ft_intersphere.c ft_interplan.c ft_addplan.c \
	  ft_intercylindre.c ft_addcylindre.c ft_intercone.c ft_addcone.c \
	  ft_produitscalaire.c ft_getnormevecteur.c ft_getnormale.c \
	  ft_getnormplan.c ft_getnormcyl.c ft_getnormcone.c ft_getlight.c \
	  ft_addspot.c ft_intercheck.c ft_distance.c ft_readfile.c \
	  ft_readspot.c ft_readsphere.c ft_readplan.c ft_readcylindre.c \
	  ft_readcone.c ft_addlist.c ft_readcolor.c ft_readcamera.c \
	  ft_initscene.c ft_texture.c

OBJ= $(SRC:.c=.o)

all: $(LIB) $(SDL) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

$(SDL):
	cd SDL2-2.0.5; \
		./configure --prefix=$(shell pwd)/SDL2-2.0.5/ && make && make install

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)
	cd SDL2-2.0.5; \
		rm -Rf bin \
		rm -Rf lib \
		rm -Rf build \
		rm -f config.log

re: fclean all

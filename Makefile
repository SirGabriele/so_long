# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:12:21 by kbrousse          #+#    #+#              #
#    Updated: 2022/05/30 20:24:04 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

SRC = main.c             \
	  ft_error.c         \
	  clear_game.c

FILES = ft_files_inspector.c     \
	    ft_map_parsing.c         \
		map_save_objects.c    	   

INIT = game_init.c				\
	   map_init.c				\
	   init_walls.c				\
	   init_tiles.c				\
	   init_collects.c			\
	   init_char.c				\
	   init_escapes.c

WINDOW = open_window.c			\
		 ft_import_images.c		\
		 ft_put_image.c			\
		 image_printer.c		\
		 ft_put.c

SRCS = $(addprefix src/, $(SRC))		     \
	   $(addprefix src/files/, $(FILES))   \
	   $(addprefix src/init/, $(INIT))     \
	   $(addprefix src/window/, $(WINDOW)) 

CC =	gcc

FLAGS =	-Wall -Wextra -Werror -g

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~     Clean terminated!     ~"
	@echo "*          so_long          *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

fclean: clean
	@make fclean -C libft --no-print-directory
	@rm -f $(NAME)

re: fclean all

.c.o:
	@$(CC) $(FLAGS) -c -o $@ $< 
 
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -Llibft -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -Ilibft -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~  Compilation terminated!  ~"
	@echo "*          so_long          *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

$(LIBFT):
	@make -C libft --no-print-directory

#	-I libft -I minilibx-linux // chercher les header.h dans autre dossier
#	-L libft -l ft // chercher les lib.a dans autre dossier
#	-l (lib)ft abbreviation de lib
#	-l (lib)mlx

.PHONY: all clean fclean re

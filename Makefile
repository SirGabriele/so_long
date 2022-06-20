# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:12:21 by kbrousse          #+#    #+#              #
#    Updated: 2022/06/16 19:23:41 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

SRC = main.c             \
	  ft_error.c         \
	  clear_game.c		 \
	  clear_images.c	 \
	  change_matrix.c	 \
	  ft_put.c			 

FILES = ft_files_inspector.c     \
	    ft_map_parsing.c

INIT_MANDA = game_init.c			\
	   		 map_init.c				\
	   		 init_walls.c			\
	   		 init_tiles.c			\
	   		 init_collects.c		\
	   		 init_char.c			\
	   		 init_escapes.c			\
	   		 init_numbers.c			

INIT_BONUS = game_init.c			\
	   		 map_init.c				\
	   		 init_walls.c			\
	   		 init_tiles.c			\
	   		 init_collects.c		\
	   		 init_char.c			\
	   		 init_escapes.c			\
	   		 init_numbers.c			\
	   		 init_patrol.c


WINDOW_MANDA = open_window.c			\
		 	   ft_import_images.c		\
		 	   print_image.c			\
		 	   map_printer.c			

WINDOW_BONUS = open_window.c			\
		 	   ft_import_images.c		\
		 	   print_image.c			\
		 	   map_printer.c			\
		 	   map_printer2.c

MOVEMENT_MANDA = ft_move_player.c				\
		   		 movement_processing.c			\
				 display_steps.c				\
				 add_escape.c					\
		   		 moves.c						\
		   		 sprites_management.c			\
		   		 player_movement_processing.c
		  
MOVEMENT_BONUS = ft_move_player.c				\
		   		 movement_processing.c			\
		   		 display_steps.c				\
		   		 add_patrol.c					\
		   		 moves.c						\
		   		 sprites_management.c			\
		   		 player_movement_processing.c

SRCS_MANDA = $(addprefix src/mandatory/, $(SRC))						\
	   		 $(addprefix src/mandatory/files/, $(FILES))				\
	   		 $(addprefix src/mandatory/init/, $(INIT_MANDA))			\
	   		 $(addprefix src/mandatory/window/, $(WINDOW_MANDA))		\
	   		 $(addprefix src/mandatory/movement/, $(MOVEMENT_MANDA))

SRCS_BONUS = $(addprefix src/bonus/, $(SRC))						\
	   		 $(addprefix src/bonus/files/, $(FILES))				\
	   		 $(addprefix src/bonus/init/, $(INIT_BONUS))			\
	   		 $(addprefix src/bonus/window/, $(WINDOW_BONUS))		\
	   		 $(addprefix src/bonus/movement/, $(MOVEMENT_BONUS))

CC =	gcc

FLAGS =	-Wall -Wextra -Werror -g

OBJS_MANDA = $(SRCS_MANDA:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJS_MANDA) $(OBJS_BONUS)
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
 
$(NAME): $(LIBFT) $(OBJS_MANDA)
	@$(CC) $(FLAGS) $(OBJS_MANDA) -Llibft -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -Ilibft -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~  Compilation terminated!  ~"
	@echo "*          so_long          *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

bonus: $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(FLAGS) $(OBJS_BONUS) -Llibft -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -Ilibft -lXext -lX11 -lm -lz -o $(NAME)
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

.PHONY: all clean fclean bonus re

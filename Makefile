# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:12:21 by kbrousse          #+#    #+#              #
#    Updated: 2022/05/26 16:55:59 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c             \
	  ft_error.c         \
	  clear_game.c

FILES = ft_files_inspector.c     \
	    ft_map_parsing.c

INIT = game_init.c				\
	   map_init.c

SRCS = $(addprefix "src/", $(SRC))		   \
	   $(addprefix "src/files/", $(FILES))  \
	   $(addprefix "src/init/", $(INIT))

CC =	gcc

FLAGS =	-Wall -Wextra -Werror

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

#.c.o:
#	@echo "\033[0;36m"
#	@echo -n "Compiling $<..."
#	@$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -Ilibft -c $< -o $@ 
 
$(NAME):
	@make -C libft --no-print-directory
	@$(CC) $(SRCS) -g -Llibft -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -Ilibft -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~  Compilation terminated!  ~"
	@echo "*          so_long          *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"


#	-I libft -I minilibx-linux // chercher les header.h dans autre dossier
#	-L libft -l ft // chercher les lib.a dans autre dossier
#	-l (lib)ft abbreviation de lib
#	-l (lib)mlx

.PHONY: all clean fclean re

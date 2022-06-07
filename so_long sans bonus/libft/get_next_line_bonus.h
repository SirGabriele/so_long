/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:10:11 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/17 15:58:11 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int			fd;
	char		*line;
	char		*buf;
	int			tdl;
	int			i;	
	ssize_t		hmb_read;
	int			nb_of_read;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnewgnl(int entry_fd);
void	ft_lstadd_backgnl(t_list **first_elem, t_list *new);
t_list	*ft_go_to_linkgnl(t_list **first_elem, int fd);
char	*ft_erase_linkgnl(t_list **first_elem, t_list *temp);

char	*get_next_line(int fd);
void	ft_read_file_and_fill_buf(t_list *temp);
void	ft_fill_line(t_list *temp);
int	check_string(char *string);
char	*ft_increase_string_size(t_list *temp);

#endif

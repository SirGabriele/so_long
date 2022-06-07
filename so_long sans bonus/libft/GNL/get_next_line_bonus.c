/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:49:32 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/13 12:11:55 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*get_next_line(int fd)
{
	static t_listgnl	*first_elem;
	t_listgnl			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (first_elem == NULL)
		first_elem = ft_lstnewgnl(fd);
	temp = ft_go_to_linkgnl(&first_elem, fd);
	temp->line = NULL;
	while (check_string(temp) == 0)
	{
		ft_read_file_and_fill_buf(temp);
		if (temp->hmb_read < BUFFER_SIZE)
		{
			if (temp->leftovers == NULL || temp->leftovers[0] == '\0')
				return (ft_erase_linkgnl(&first_elem, temp));
			else if (temp->leftovers[0] != '\0')
				break ;
		}
	}
	ft_fill_line_and_sort_leftovers(temp);
	return (temp->line);
}

void	ft_read_file_and_fill_buf(t_listgnl *temp)
{
	char	*buf;

	buf = ft_callocgnl(BUFFER_SIZE + 1);
	if (buf == NULL)
		return ;
	temp->nb_of_read++;
	temp->hmb_read = read(temp->fd, buf, BUFFER_SIZE);
	if (buf[0] == '\0' && (temp->leftovers == NULL
			|| temp->leftovers[0] == '\0'))
	{
		free(buf);
		buf = NULL;
		return ;
	}
	temp->leftovers = ft_increase_string_size(temp, temp->leftovers);
	temp->j = -1;
	while (buf[++(temp->j)] != '\0')
	{
		temp->leftovers[temp->i] = buf[temp->j];
		temp->i++;
	}
	free(buf);
	buf = NULL;
}

void	ft_fill_line_and_sort_leftovers(t_listgnl *temp)
{
	char	*dup;

	temp->i = -1;
	temp->j = 0;
	temp->line = ft_callocgnl(BUFFER_SIZE * temp->nb_of_read + 1);
	while (temp->leftovers[++(temp->i)] != '\0')
	{
		if (temp->leftovers[temp->i] == '\n')
		{
			temp->line[temp->i] = temp->leftovers[temp->i];
			temp->i++;
			break ;
		}
		temp->line[temp->i] = temp->leftovers[temp->i];
	}
	dup = ft_callocgnl(BUFFER_SIZE * temp->nb_of_read + 1);
	while (temp->leftovers[temp->i] != '\0')
		dup[temp->j++] = temp->leftovers[temp->i++];
	free(temp->leftovers);
	temp->leftovers = NULL;
	temp->leftovers = dup;
}

char	*ft_increase_string_size(t_listgnl *temp, char *string)
{
	char	*dup;

	if (string == NULL)
	{
		string = ft_callocgnl(BUFFER_SIZE * temp->nb_of_read + 1);
		return (string);
	}
	dup = ft_callocgnl(BUFFER_SIZE * temp->nb_of_read + 1);
	temp->i = -1;
	while (string[++(temp->i)] != '\0')
		dup[temp->i] = string[temp->i];
	free(string);
	string = NULL;
	return (dup);
}

char	*ft_erase_linkgnl(t_listgnl **first_elem, t_listgnl *temp)
{
	t_listgnl	*copy;
	t_listgnl	*current;

	current = NULL;
	copy = *first_elem;
	free(temp->leftovers);
	free(temp->line);
	while (copy != NULL && copy->fd != temp->fd)
	{
		current = copy;
		copy = copy->next;
	}
	if (current == NULL)
	{
		copy = *first_elem;
		*first_elem = copy->next;
		free(copy);
		return (NULL);
	}
	if (copy != NULL)
		current->next = copy->next;
	else
		current->next = NULL;
	free(temp);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:49:53 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/02 17:02:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_listgnl	*ft_lstnewgnl(int entry_fd)
{
	t_listgnl	*elem;

	elem = malloc(sizeof(t_listgnl));
	if (elem == NULL)
		return (NULL);
	elem->fd = entry_fd;
	elem->line = NULL;
	elem->leftovers = NULL;
	elem->i = 0;
	elem->j = 0;
	elem->hmb_read = 0;
	elem->nb_of_read = 0;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_backgnl(t_listgnl **first_elem, t_listgnl *new)
{
	t_listgnl	*lst_temp;

	lst_temp = *first_elem;
	if (new == NULL)
		return ;
	if (*first_elem == NULL)
		*first_elem = new;
	else
	{
		while (lst_temp->next != NULL)
			lst_temp = lst_temp->next;
		lst_temp->next = new;
	}
}

t_listgnl	*ft_go_to_linkgnl(t_listgnl **first_elem, int fd)
{
	t_listgnl	*new_link;
	t_listgnl	*copy;

	copy = *first_elem;
	new_link = NULL;
	while (copy != NULL)
	{
		if (copy->fd == fd)
			break ;
		copy = copy->next;
	}
	if (copy == NULL)
	{
		new_link = ft_lstnewgnl(fd);
		ft_lstadd_backgnl(first_elem, new_link);
		return (new_link);
	}
	return (copy);
}

int	check_string(t_listgnl *temp)
{
	int	i;

	i = 0;
	if (temp->leftovers == NULL)
		return (0);
	while (temp->leftovers[i] != '\0')
	{
		if (temp->leftovers[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_callocgnl(int size)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * size);
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	return ((char *)tab);
}

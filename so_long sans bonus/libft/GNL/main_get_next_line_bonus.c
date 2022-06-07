/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:25:48 by kbrousse          #+#    #+#             */
/*   Updated: 2022/04/28 21:29:54 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int	main(void)
{
	int	fd;
	char *str;
	int	fd2;
	char *str2;
	
	fd = open("alphabet2.txt", O_RDONLY);
	str = get_next_line(fd);	
	printf("Ligne 1 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);	
	printf("Ligne 2 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);
	printf("Ligne 3 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);
	printf("Ligne 4 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	/*str = get_next_line(fd);	
	printf("Ligne 5 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);
	printf("Ligne 6 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);	
	printf("Ligne 7 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);
	printf("Ligne 8 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);
	printf("Ligne 9 :\n!%s!\n\n", str);
	free(str);
	str = NULL;
	
	str = get_next_line(fd);	
	printf("Ligne 10 :\n!%s!\n\n", str);
	free(str);
	str = NULL;*/
	
		fd2 = open("41_no_nl", O_RDONLY);
		str2 = get_next_line(fd2);	
		printf("Ligne 1 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;

		str2 = get_next_line(fd2);
		printf("Ligne 2 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;
	
		str2 = get_next_line(fd2);
		printf("Ligne 3 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;

		str2 = get_next_line(fd2);
		printf("Ligne 4 alphabet 2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;

		/*str2 = get_next_line(fd2);	
		printf("Ligne 5 alphabet 2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;
		
		str2 = get_next_line(fd2);
		printf("Ligne 6 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;
		
		str2 = get_next_line(fd2);
		printf("Ligne 7 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;

		str2 = get_next_line(fd2);
		printf("Ligne 8 alphabet 2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;

		str2 = get_next_line(fd2);	
		printf("Ligne 9 alphabet 2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;
		
		str2 = get_next_line(fd2);
		printf("Ligne 10 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;
		
		str2 = get_next_line(fd2);
		printf("Ligne 11 alphabet2 :\n!%s!\n\n", str2);
		free(str2);
		str2 = NULL;*/

	return (0);
}

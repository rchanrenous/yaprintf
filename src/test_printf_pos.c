/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:27:33 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 16:46:25 by rchan-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*str_pos[] = {"%1$d\n", "%*1$d\n", "%.*1$d\n", "%1$*1$d\n", "%*1$.*1$d\n", "%*1$.*1$d\n", NULL};
	int		pos[] = {42, -42, 0};

	if (argc == 2)
		fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
	{
#ifdef PRINTF
		fd = open("test_printf_res_c.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
#else
		fd = open("test_ft_printf_res_c.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
#endif
	}
	if (fd < 0)
		return (ft_putstr_fd("Error fd\n", 1), 1);
	for (int i = 0; str_pos[i] != NULL; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char	*tmp = ft_strtrim(str_pos[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(pos[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_pos[i], pos[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_pos[i], pos[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	char	*mult_pos[] = {"%2$*1$.*3$d\n", "%3$*.*1$d\n", "%*d\n", NULL};
	for (int i = 0; mult_pos[i] != NULL; i++)
	{
		char	*tmp = ft_strtrim(mult_pos[i], "\n");
		if (tmp == NULL)
			return (close(fd), 1);
		ft_putstr_fd(tmp, fd);
		ft_putstr_fd(": ", fd);
		free(tmp);
#ifdef PRINTF
		ft_putnbr_fd(printf(mult_pos[i], 42, 84, 126), fd);
#else
		ft_putnbr_fd(ft_printf(mult_pos[i], 42, 84, 126), fd);
#endif
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}

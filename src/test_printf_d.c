/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:04:15 by rchan-re         ###   ########.fr       */
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
#ifdef BONUS
	char	*str_d[] = {"%d\n", "%5d\n", "%-5d\n", "%1d\n", "%-1d\n", "%0d\n", "%-0d\n", "%5.6d\n", "%-5.6d\n", "%-05.6d\n", "%05.6d\n", "%6.6d\n", "%06.6d\n", "%-6.6d\n", "% 6.6d\n", "%- 6.6d\n", "%8.6d\n", "%-8.6d\n", "% 8.6d\n", "%08.6d\n", "% 0-#d\n", "%+- d\n", "%00d\n", "%  d\n", "% 0d\n", "%#d\n", "%.8d\n", "%.8d\n", "%0.0d\n", "%4.0d\n", "%-4.0d\n", "%1.0d\n", "% 0.0d\n", "%+0.0d\n", NULL};
#else
	char	*str_d[] = {"%d\n", NULL};
#endif
	int		d[] = {42, -42, 0, INT_MAX, INT_MIN};

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
		return (ft_putstr_fd("FD ERROR\n", 1), 1);
	for (int i = 0; str_d[i] != NULL; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char	*tmp = ft_strtrim(str_d[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(d[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_d[i], d[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_d[i], d[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:03:26 by rchan-re         ###   ########.fr       */
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
	char	*str_p[] = {"%p\n", "%5p\n", "%-5p\n", "%1p\n", "%-1p\n", "%0p\n", "%-0p\n", "%5.6p\n", "%-5.6p\n", "%-05.6p\n", "%05.6p\n", "%6.6p\n", "%06.6p\n", "%-6.6p\n", "% 6.6p\n", "%- 6.6p\n", "%8.6p\n", "%-8.6p\n", "% 8.6p\n", "%08.6p\n", "% 0-#p\n", "%+- p\n", "%00p\n", "%  p\n", "% 0p\n", "%#p\n", "%.8p\n", "%.8p\n", "%0.0p\n", "%4.0p\n", "%-4.0p\n", "%1.0p\n", "% 0.0p\n", "%+0.0p\n", "%#5p\n", "% 5p", NULL};
#else
	char	*str_p[] = {"%p\n", NULL};
#endif
	int		p[] = {42, -42, 0, INT_MAX, INT_MIN};

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
	for (int i = 0; str_p[i] != NULL; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char	*tmp = ft_strtrim(str_p[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(p[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_p[i], p[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_p[i], p[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	close(fd);
	return (0);
}

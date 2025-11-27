/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:05:25 by rchan-re         ###   ########.fr       */
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
	char	*str_x[] = {"%x\n", "%5x\n", "%-5x\n", "%1x\n", "%-1x\n", "%0x\n", "%-0x\n", "%5.6x\n", "%-5.6x\n", "%-05.6x\n", "%05.6x\n", "%6.6x\n", "%06.6x\n", "%-6.6x\n", "% 6.6x\n", "%- 6.6x\n", "%8.6x\n", "%-8.6x\n", "% 8.6x\n", "%08.6x\n", "% 0-#x\n", "%+- x\n", "%00x\n", "%  x\n", "% 0x\n", "%#x\n", "%.8x\n", "%.8x\n", "%0.0x\n", "%4.0x\n", "%-4.0x\n", "%1.0x\n", "% 0.0x\n", "%+0.0x\n", "%#5x\n", "% 5x", NULL};
#else
	char	*str_x[] = {"%x\n", NULL};
#endif
	int		x[] = {42, -42, 0, INT_MAX, INT_MIN};

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
	for (int i = 0; str_x[i] != NULL; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char	*tmp = ft_strtrim(str_x[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(x[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_x[i], x[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_x[i], x[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	close(fd);
	return (0);
}

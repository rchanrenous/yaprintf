/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_upper_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:06:01 by rchan-re         ###   ########.fr       */
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
	char	*str_upper_x[] = {"%X\n", "%5X\n", "%-5X\n", "%1X\n", "%-1X\n", "%0X\n", "%-0X\n", "%5.6X\n", "%-5.6X\n", "%-05.6X\n", "%05.6X\n", "%6.6X\n", "%06.6X\n", "%-6.6X\n", "% 6.6X\n", "%- 6.6X\n", "%8.6X\n", "%-8.6X\n", "% 8.6X\n", "%08.6X\n", "% 0-#X\n", "%+- X\n", "%00X\n", "%  X\n", "% 0X\n", "%#X\n", "%.8X\n", "%.8X\n", "%0.0X\n", "%4.0X\n", "%-4.0X\n", "%1.0X\n", "% 0.0X\n", "%+0.0X\n", NULL};
#else
	char	*str_upper_x[] = {"%X\n", NULL};
#endif
	int		upper_x[] = {42, -42, 0, INT_MAX, INT_MIN};

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
	for (int i = 0; str_upper_x[i] != NULL; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char	*tmp = ft_strtrim(str_upper_x[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(upper_x[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_upper_x[i], upper_x[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_upper_x[i], upper_x[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	close(fd);
	return (0);
}

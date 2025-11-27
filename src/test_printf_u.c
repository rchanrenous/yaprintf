/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:04:51 by rchan-re         ###   ########.fr       */
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
	char	*str_u[] = {"%u\n", "%5u\n", "%-5u\n", "%1u\n", "%-1u\n", "%0u\n", "%-0u\n", "%5.6u\n", "%-5.6u\n", "%-05.6u\n", "%05.6u\n", "%6.6u\n", "%06.6u\n", "%-6.6u\n", "% 6.6u\n", "%- 6.6u\n", "%8.6u\n", "%-8.6u\n", "% 8.6u\n", "%08.6u\n", "% 0-#u\n", "%+- u\n", "%00u\n", "%  u\n", "% 0u\n", "%#u\n", "%.8u\n", "%.8u\n", "%0.0u\n", "%4.0u\n", "%-4.0u\n", "%1.0u\n", "% 0.0u\n", "%+0.0u\n", "%#5u\n", "% 5u", NULL};
#else
	char	*str_u[] = {"%u\n", NULL};
#endif
	int		u[] = {42, -42, 0, INT_MAX, INT_MIN};

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
	for (int i = 0; str_u[i] != NULL; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char	*tmp = ft_strtrim(str_u[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(u[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_u[i], u[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_u[i], u[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	close(fd);
	return (0);
}

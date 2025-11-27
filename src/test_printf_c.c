/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:00:23 by rchan-re         ###   ########.fr       */
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
	char	*str_c[] = {"%c\n", "%5c\n", "%-5c\n", "%1c\n", "%-1c\n", "%0c\n", "%-0c\n", "%5.6c\n", "%-5.6c\n", "%-05.6c\n", "%05.6c\n", "%6.6c\n", "%06.6c\n", "%-6.6c\n", "% 6.6c\n", "%- 6.6c\n", "%8.6c\n", "%-8.6c\n", "% 8.6c\n", "%08.6c\n", "% 0-#c\n", "%+- c\n", "%00c\n", "%  c\n", "% 0c\n", "%#c\n", "%.8c\n", "%.8c\n", "%0.0c\n", "%4.0c\n", "%-4.0c\n", "%1.0c\n", "% 0.0c\n", "%+0.0c\n", "%#5c\n", "% 5c", NULL};
#else
	char	*str_c[] = {"%c\n", NULL};
#endif

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
	for (int i = 0; str_c[i] != NULL; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			char	*tmp = ft_strtrim(str_c[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putnbr_fd(j, fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_c[i], j), fd);
#else
			ft_putnbr_fd(ft_printf(str_c[i], j), fd);
#endif
			write(fd, "\n", 1);
		}
	}
	close(fd);
	return (0);
}

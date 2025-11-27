/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan-re <rchan-re@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:10:30 by rchan-re          #+#    #+#             */
/*   Updated: 2025/11/26 17:01:18 by rchan-re         ###   ########.fr       */
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
	char	*str_s[] = {"%s\n", "%5s\n", "%-5s\n", "%1s\n", "%-1s\n", "%0s\n", "%-0s\n", "%5.6s\n", "%-5.6s\n", "%-05.6s\n", "%05.6s\n", "%6.6s\n", "%06.6s\n", "%-6.6s\n", "% 6.6s\n", "%- 6.6s\n", "%8.6s\n", "%-8.6s\n", "% 8.6s\n", "%08.6s\n", "% 0-#s\n", "%+- s\n", "%00s\n", "%  s\n", "% 0s\n", "%#s\n", "%.8s\n", "%.8s\n", "%0.0s\n", "%4.0s\n", "%-4.0s\n", "%1.0s\n", "% 0.0s\n", "%+0.0s\n", "%#5s\n", "% 5s", NULL};
#else
	char	*str_s[] = {"%s\n", NULL};
#endif
	char	*s[] = {"salut", "ca va", "oui merci de prendre de mes nouvelles", "de rien c'est normal", ""};

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
	for (int i = 0; str_s[i] != NULL; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char	*tmp = ft_strtrim(str_s[i], "\n");
			if (tmp == NULL)
				return (close(fd), 1);
			ft_putstr_fd(tmp, fd);
			ft_putstr_fd(", ", fd);
			ft_putstr_fd(s[j], fd);
			ft_putstr_fd(": ", fd);
			free(tmp);
#ifdef PRINTF
			ft_putnbr_fd(printf(str_s[i], s[j]), fd);
#else
			ft_putnbr_fd(ft_printf(str_s[i], s[j]), fd);
#endif
			write(fd, "\n", 1);
		}
	}

	char	*str_null[] = {"%s\n", "%.2s\n", "%.6s\n", "%10s\n", "%10.7s\n", "%3.7s\n", "%42.1s\n", NULL};
	for (int i = 0; str_null[i] != NULL; i++)
	{
		char	*tmp = ft_strtrim(str_null[i], "\n");
		if (tmp == NULL)
			return (close(fd), 1);
		ft_putstr_fd(tmp, fd);
		ft_putstr_fd(": ", fd);
		free(tmp);
#ifdef PRINTF
		ft_putnbr_fd(printf(str_null[i], NULL), fd);
#else
		ft_putnbr_fd(ft_printf(str_null[i], NULL), fd);
#endif
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}

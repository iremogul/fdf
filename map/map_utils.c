/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:35:55 by iogul             #+#    #+#             */
/*   Updated: 2025/12/14 14:36:09 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	write_error(void)
{
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

void	clean_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

int	split_count(char *str, char c)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(str, c);
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	split_free(arr);
	return (i);
}

int	ft_atoi_hex(char *hex)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	if (hex[i] == '0' && (hex[i + 1] == 'x' || hex[i + 1] == 'X'))
		i += 2;
	while (hex[i])
	{
		val *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			val += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val += hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val += hex[i] - 'A' + 10;
		i++;
	}
	return (val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:12:13 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/10 01:24:15 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_bzero(void *buf, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)buf;
	while (i < len)
	{
		result[i] = '\0';
		i++;
	}
	buf = (void *)result;
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;

	total_size = count * size;
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

int	ft_atoi(const char *str)

{
	int	i;
	int	minus;
	int	result;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		++i;
	}
	return (result * minus);
}

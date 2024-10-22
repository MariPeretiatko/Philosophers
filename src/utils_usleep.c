/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_usleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:23:01 by mperetia          #+#    #+#             */
/*   Updated: 2024/10/21 20:52:25 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_usleep(int time)
{
	struct timeval	start;
	struct timeval	now;
	int				diff;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);
		diff = (now.tv_sec * 1000 + now.tv_usec / 1000) - (start.tv_sec * 1000
				+ start.tv_usec / 1000);
		if (diff >= time)
			break ;
		usleep(100);
	}
}

long	get_time(struct timeval time)
{
	struct timeval	now;
	int				diff;

	gettimeofday(&now, NULL);
	diff = (now.tv_sec * 1000 + now.tv_usec / 1000) - (time.tv_sec * 1000
			+ time.tv_usec / 1000);
	return (diff);
}

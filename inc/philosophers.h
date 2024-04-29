#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	bool			is_die;
	int				number;
	pthread_t		thread;
	pthread_mutex_t	fork1;
	pthread_mutex_t	fork2;
}					t_philo;

typedef struct s_program
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_each_philo_must_eat;
	t_philo			**philos;
}					t_program;

bool				is_digit(int c);
void				print_error_mes(char *mes);
unsigned long long	get_time_now(void);
void				check_arguments(int ac, bool *is_more_params);
void				check_digit(char **av);

#endif
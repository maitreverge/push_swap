/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:40 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 18:19:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_stack_a(long *buffer, t_node **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*a == NULL)
			*a = lstnew((int)buffer[i], 0);
		else
			lstadd_back(a, lstnew((int)buffer[i], 0));
		i++;
	}
}

static long	*init_pre_buff(char **av_copy)
{
	long	*pre_buff;
	int		i;

	i = 0;
	while (av_copy[i] != NULL)
		i++;
	pre_buff = malloc(sizeof(long) * i);
	if (!pre_buff)
		exit(-1);
	return (pre_buff);
}

static void	fill_pre_buff(char **av_copy, long *pre_buff)
{
	long	cur_nb;
	int		j;

	j = 0;
	while (*av_copy != NULL)
	{
		cur_nb = ft_atol(*av_copy);
		if ((cur_nb < INT_MIN || cur_nb > INT_MAX))
			quit(pre_buff, -1);
		pre_buff[j] = cur_nb;
		j++;
		av_copy++;
	}
}

void	init_stack(int ac, char **av, t_node **a)
{
	char	**av_copy;
	long	*pre_buff;
	int		i;

	if (ac == 2)
		av_copy = ft_split(av[1], ' ');
	else
		av_copy = &av[1];
	pre_buff = init_pre_buff(av_copy);
	fill_pre_buff(av_copy, pre_buff);
	i = 0;
	while (av_copy[i] != NULL)
		i++;
	fill_stack_a(pre_buff, a, i);
	if (ac == 2)
		free_split(av_copy);
	free(pre_buff);
}

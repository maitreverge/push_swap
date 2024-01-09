/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:40 by flverge           #+#    #+#             */
/*   Updated: 2024/01/09 10:51:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

void	quit(long *to_free, int exit_code)
{
	free(to_free);
	ft_printf("Error\n");
	exit(exit_code);
}

int		check_double(long *to_check, int j)
{
	int	i;
	int k;

	i = 0;
	k = 1;
	while (i < j)
	{
		if (to_check[i] == to_check[k])
		{
			// printf("Double detected\n");	
			return (1);
		}
		k++;
		if (k > j)
		{
			i++;
			k = i + 1;
		}
	}
	return (0);
}

void	fill_stack_a(long *buffer, t_node **a, int size)
{
	int	i;

	i = 0;

	while (i < size)
	{
		if (*a ==  NULL)
			lstnew((int)buffer[i]);
		else
			lstadd_back(a, lstnew((int)buffer[i]));
		i++;
	}
}

void    init_stack(int ac, char **av, t_node **a)
{
	long	cur_nb;
	long	*pre_buff;
	char	**av_copy;
	int		i;
	int 	j;
	
	// args = 0;
	i = 0;
	j = 0;
	// ! calculate number of args
	if (ac == 2)
		av_copy = ft_split(av[1], ' ');
	else
		av_copy = &av[1];
	while (av_copy[i] != NULL)
		i++;
	pre_buff = malloc(sizeof(long) * i);
	if (!pre_buff)
		exit(-1);
	while (*av_copy != NULL)
	{
		cur_nb = ft_atol(*av_copy);
		// printf("Current nb = %li\n", cur_nb);
		if ((cur_nb < INT_MIN || cur_nb > INT_MAX))
			quit(pre_buff, -1);
		pre_buff[j] = cur_nb;
		if (check_double(pre_buff, j))
			quit(pre_buff, -1);
		j++;
		av_copy++;
	}
	// ! here, the buffer is filled AND checked
	// ! needs to fill the linked_list
	
	fill_stack_a(pre_buff, a, i);
	
	// if (ac == 2)
	free(av_copy);
	free(pre_buff);
}

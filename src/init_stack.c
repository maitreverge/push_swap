/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:40 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 11:14:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

int	check_double(long *to_check, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (i < j)
	{
		if (to_check[i] == to_check[k])
			return (1);
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
	// while (i <= size)
	while (i < size)
	{
		if (*a == NULL)
			*a = lstnew((int)buffer[i], 0);
		else
			lstadd_back(a, lstnew((int)buffer[i], 0));
		i++;
	}
}

long	*init_pre_buff(char **av_copy)
{
	long	*pre_buff;
	int		i;

	i = 0;
	while (av_copy[i] != NULL)
		i++;
	// printf("index init prefbuff = %i\n", i);
	pre_buff = malloc(sizeof(long) * i);
	if (!pre_buff)
		exit(-1);
	return (pre_buff);
}

void	fill_pre_buff(char **av_copy, long *pre_buff)
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
		// if (check_double(pre_buff, j))
			// quit(pre_buff, -1);
		// printf("Current buffer location = %i\n", pre_buff[j]);
		j++;
		av_copy++;
	}
}

bool	a_is_sorted(t_node **a)
{
	t_node *current;

	// bool result;

	// result = true;
	current = *a;

	if (!current->next)
		return true;
	while (current->next)
	{
		if (current->nb > current->next->nb)
			return (false);
		current = current->next;
	}

	return (true);

	

	// true = is sorted
	// false = is not sorted
}

bool	a_contains_double(t_node **a)
{
	t_node *current;
	t_node *following_node;;

	current = *a;
	
	while (current)
	{
		following_node = current->next;
		while (following_node)
		{
			if (current->nb == following_node->nb)
				return true;
			following_node = following_node->next;
		}
		current = current->next;
	}
	return false;
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
	
	pre_buff = init_pre_buff(av_copy); // ok
	
	fill_pre_buff(av_copy, pre_buff); // ok
	// !!!!!!!!!!!!!!! CHECKER
	// for(int i = 0; i < 3; i++)
	// 		printf("Current buffer after alloc = %lu\n", pre_buff[i]);
	// !!!!!!!!!!!!!!! CHECKER
	i = 0;
	while (av_copy[i] != NULL)
		i++;
	// printf("Alloc size = %i\n", i);
	fill_stack_a(pre_buff, a, i);
	if (ac == 2)
		free_split(av_copy);
	free(pre_buff);
	if (a_contains_double(a))
	{
		printf("A contain double\n");
		ft_printf("Error\n");
		free_stack(*a);
		exit (-1);
	}
	if (a_is_sorted(a))
	{
		printf("A is sorted\n");
		free_stack(*a);
		exit (-1);
	}
	// print_full(*a, "print check");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:40 by flverge           #+#    #+#             */
/*   Updated: 2024/01/08 16:12:17 by flverge          ###   ########.fr       */
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
	int	k;

	i = 0;
	k = 1;
	while (i < j)
	{
		if (to_check[i] == to_check[k])
			return (1);
		k++;
		if (k == j)
			i++;
	}
	return (0);
}

void    init_stack(int ac, char **av, t_node **a)
{
	long	cur_nb;
	long	*pre_buff;
	int		args;
	int		i;
	int 	j;

	args = 0;
	i = 1;
	j = 0;
	if (ac == 2)
	{
		// ! TO_DO : fait un decallage de 1 si chaine splitee
		av = ft_split(av[1], ' ');
		// av++;
	}
	// ! calculate number of args
	while (av[i] != NULL)
	{
		i++;
		args++;
	}
	pre_buff = malloc(sizeof(long) * args);
	if (!pre_buff)
		exit(-1);
	while (*++av != NULL)
	{
		cur_nb = ft_atol(*av);
		printf("Current nb = %li\n", cur_nb);
		if ((cur_nb < INT_MIN || cur_nb > INT_MAX))
			quit(pre_buff, -1);
		pre_buff[j] = cur_nb;
		if (check_double(pre_buff, j))
			quit(pre_buff, -1);
		j++;
	}
	 
	
}

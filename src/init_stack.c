/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:40 by flverge           #+#    #+#             */
/*   Updated: 2024/01/08 14:06:21 by flverge          ###   ########.fr       */
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
		if ()
	}
	return (0)
}

void    init_stack(int ac, char **av, t_node **a)
{
	long	cur_nb;
	long	*pre_buff;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if (ac == 2)
			av = ft_split(av[1], ' ');
	// ! calculate number of args
	while (av[i] != NULL)
		i++;
	pre_buff = malloc((sizeof(long) * i) + 1);
	if (!pre_buff)
		exit(-1);
	// assign in a tab + check double AND limits
	while (*++av != NULL) // *++av => skips the first av
	{
		cur_nb = ft_atol(*av);
		if ((cur_nb < INT_MIN || cur_nb > INT_MAX))
			quit(pre_buff, -1);
		printf("Current nb = %li\n", cur_nb);
		pre_buff[j] = cur_nb;
		if (check_double(pre_buff))
			quit(pre_buff, -1);
		j++;
	}
	pre_buff[j] = NULL;
	 
	
}
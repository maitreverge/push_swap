/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:40 by flverge           #+#    #+#             */
/*   Updated: 2024/01/08 13:40:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

void	quit(long *to_free, int exit_code)
{
	free(to_free);
	ft_printf("Error\n");
	exit(exit_code);
}

void    init_stack(int ac, char **av, t_node **a)
{
	long	cur_nb;
	long	*pre_buff;
	int		i;

	i = 0;    
	if (ac == 2)
			av = ft_split(av[1], ' ');
	// ! calculate number of args
	while (av[i] != NULL)
		i++;
	pre_buff = malloc((sizeof(long) * i) + 1);
	// assign in a tab + check double AND limits
	while (*++av != NULL)
	{
		cur_nb = ft_atol(*av);
		if (cur_nb < INT_MIN || cur_nb > INT_MAX)
			quit(pre_buff, -1);
		printf("Current nb = %li\n", cur_nb);
	}    
	
}
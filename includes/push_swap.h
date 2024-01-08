/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:18 by flverge           #+#    #+#             */
/*   Updated: 2024/01/08 12:11:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free and exit
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
}			t_node;

// arg_parsing
int		check_double(t_node *a, int nb);
int		check_arg(int ac, char **av);
// utils
int		ft_is_space(char c);
int		ft_is_num(char *str);
long	ft_atol(const char *str);

#endif
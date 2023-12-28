/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:18 by flverge           #+#    #+#             */
/*   Updated: 2023/12/28 13:37:09 by flverge          ###   ########.fr       */
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

typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

// arg_parsing
int		check_arg(int ac, char **av);
int		check_double(t_node *a, int nb);
void	init_stack(t_node **a, char **av);

// utils
int		ft_is_space(char c);
int		ft_is_num(char *str);
long	ft_atol(const char *str);

#endif
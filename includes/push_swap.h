/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:18 by flverge           #+#    #+#             */
/*   Updated: 2024/01/09 16:10:42 by flverge          ###   ########.fr       */
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
int		check_arg(int ac, char **av);

// init_stack
int		check_double(long *to_check, int j);
void	fill_stack_a(long *buffer, t_node **a, int size);
long	*init_pre_buff(char **av_copy);
void	fill_pre_buff(char **av_copy, long *pre_buff);
void	init_stack(int ac, char **av, t_node **a);

//master_algo
int		already_sorted(t_node **a);
void	master_algo(t_node **a, t_node **b);


// utils
int		ft_is_space(char c);
int		ft_is_num(char *str);
long	ft_atol(const char *str);
void	quit(long *to_free, int exit_code);

// linked_list_functions

t_node	*lstnew(int content);
void	lstadd_back(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
void	free_stack(t_node *a);
int		lstsize(t_node *lst);

// instruction_1
void	swap_a(t_node **a);



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:18 by flverge           #+#    #+#             */
/*   Updated: 2024/01/23 18:35:24 by flverge          ###   ########.fr       */
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
# include <stdbool.h>

typedef struct s_node
{
	int				nb;
	size_t			master_index;
	struct s_node	*prev;
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
bool	not_already_sorted(t_node **a);
void	master_algo(t_node **a, t_node **b, int numerator);


// utils
int		ft_is_space(char c);
int		ft_is_num(char *str);
long	ft_atol(const char *str);
void	quit(long *to_free, int exit_code);
void	free_split(char **to_free);

// linked_list_functions

t_node	*lstnew(int content, int index);
void	lstadd_front(t_node **lst, t_node *new);
void	lstadd_back(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
void	free_stack(t_node *to_free);
int		lstsize(t_node *lst);
void	free_node(t_node **to_free);

// instruction_1
void	sa(t_node **a, bool to_print);
void	sb(t_node **b, bool to_print);
void	pa(t_node **a, t_node **b, bool to_print);
void	pb(t_node **a, t_node **b, bool to_print);
void	ss(t_node **a, t_node **b);

// instructions_2
void	ra(t_node **a, bool to_print);
void	rb(t_node **b, bool to_print);
void	rr(t_node **a, t_node **b);

// instructions_3
void	rra(t_node **a, bool to_print);
void	rrb(t_node **b, bool to_print);
void	rrr(t_node **a, t_node **b);

// psh_swap
void	print_simple(t_node *a, char *message);
void	print_full(t_node *a, char *message);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:18 by flverge           #+#    #+#             */
/*   Updated: 2024/01/25 09:44:11 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				nb;
	size_t			master_index;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_algo
{
	size_t	max;
	size_t	soustraction;
	size_t	num_lower;
	size_t	num_upper;
}			t_algo;

// init_stack
void	init_stack(int ac, char **av, t_node **a);

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

// linked_list_functions
t_node	*lstnew(int number, int index);
t_node	*lstlast(t_node *lst);
void	lstadd_back(t_node **lst, t_node *new);
void	lstadd_front(t_node **lst, t_node *new);
int		lstsize(t_node *lst);

// master_algo
void	master_algo(t_node **a, t_node **b, int numerator);

// secu
bool	a_is_sorted(t_node **a);
bool	a_contains_double(t_node **a);
int		check_arg(int ac, char **av);

// small_algo
void	selection_sort(t_node **a, t_node **b);
void	sort_3(t_node **a);

// utils_1
int		ft_is_num(char *str);
long	ft_atol(const char *str);
void	quit(long *to_free, int exit_code);
void	free_split(char **to_free);

// utils_2
void	free_stack(t_node *to_free);
int		find_min(t_node **a);
int		find_max(t_node **a);
int		find_middle(t_node **a, int min, int max);
void	quit_check(t_node **a, char *str);

// utils_master_algo
void	bubble_sort(int *buffer, int len);
void	allocate_index(t_node **a, int *buffer, int len_a);
bool	no_num_left(t_node **a, int num, int low);
bool	calculate_low(t_node **b, int max);

#endif
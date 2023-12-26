/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:18 by flverge           #+#    #+#             */
/*   Updated: 2023/12/25 16:51:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free and exit

typedef struct s_node
{
	int nb;
	struct s_node *next;
}			t_node;

#endif
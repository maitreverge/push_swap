/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:15:52 by flverge           #+#    #+#             */
/*   Updated: 2024/01/12 10:36:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i]) && str[i])
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]) && str[i])
			i++;
		if (str[i] && !ft_is_space(str[i]))
			return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	quit(long *to_free, int exit_code)
{
	free(to_free);
	ft_printf("Error\n");
	exit(exit_code);
}

void	free_split(char **to_free)
{
	int i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
}

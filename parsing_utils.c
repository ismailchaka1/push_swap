/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:16:22 by root              #+#    #+#             */
/*   Updated: 2025/03/16 03:18:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	check_number(long long result, int i, char *str)
{
	if (result > 2147483647 || result < -2147483648)
		error_exit();
	if (str[i] != '\0')
		error_exit();
}

int	ft_atoi(char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 || result < -2147483648)
			error_exit();
		i++;
	}
	check_number(result, i, str);
	return (sign * result);
}

int	check_duplicate(t_stack *stack, int value)
{
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stack_sorted(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

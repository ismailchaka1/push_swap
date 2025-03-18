/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:20:18 by root              #+#    #+#             */
/*   Updated: 2025/03/18 05:28:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(t_stack *a)
{
	int	range;

	range = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		range = 3;
	else if (stack_size(a) <= 100)
		range = 13;
	else if (stack_size(a) <= 500)
		range = 35;
	else
		range = 45;
	return (range);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_array(t_stack **stacka)
{
	int		*array;
	int		i;
	t_stack	*tmp;
	int		size;

	tmp = *stacka;
	i = 0;
	size = stack_size(*stacka);
	array = malloc(sizeof(int) * size);
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_array(array, size);
	return (array);
}

int	max_index(t_stack *b)
{
	int		index;
	int		max_value;
	t_stack	*tmp;

	if (!b)
		return (-1);
	max_value = stack_max(b)->value;
	index = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->value == max_value)
			break ;
		tmp = tmp->next;
		index++;
	}
	return (index);
}

void	max_to_top(t_stack **b)
{
	int	index;
	int	size;

	size = stack_size(*b);
	while (1)
	{
		index = max_index(*b);
		if (index == 0)
			break ;
		else if (index <= size / 2)
		{
			// print_stack(*b);
			rb(b);
			// print_stack(*b);
		}
		else if (index > size / 2)
			rrb(b);
	}
}

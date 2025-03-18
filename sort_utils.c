/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:20:18 by root              #+#    #+#             */
/*   Updated: 2025/03/16 03:31:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_top(t_stack *s)
{
	if (!s)
		return (NULL);
	return (s);
}

t_stack	*stack_min(t_stack *s)
{
	t_stack	*min;

	if (!s)
		return (NULL);
	min = s;
	while (s)
	{
		if (s->value < min->value)
			min = s;
		s = s->next;
	}
	return (min);
}

t_stack	*stack_max(t_stack *s)
{
	t_stack	*max;

	if (!s)
		return (NULL);
	max = s;
	while (s)
	{
		if (s->value > max->value)
			max = s;
		s = s->next;
	}
	return (max);
}

t_stack	*stack_bottom(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:10:35 by root              #+#    #+#             */
/*   Updated: 2025/03/18 05:27:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b);
	rb(b);
	(*i)++;
}

void	push(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
}

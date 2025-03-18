/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:10:35 by root              #+#    #+#             */
/*   Updated: 2025/03/16 03:18:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **firststack, t_stack **secondstack)
{
	t_stack	*tmp;

	if (*firststack == NULL)
		return ;
	tmp = *firststack;
	*firststack = (*firststack)->next;
	if (*firststack)
		(*firststack)->prev = NULL;
	tmp->next = *secondstack;
	if (*secondstack)
		(*secondstack)->prev = tmp;
	tmp->prev = NULL;
	*secondstack = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	last = tmp;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*curr;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	curr = *stack;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack;
	(*stack)->prev = curr;
	curr->prev = NULL;
	*stack = curr;
}

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

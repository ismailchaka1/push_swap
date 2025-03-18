/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:29:00 by root              #+#    #+#             */
/*   Updated: 2025/03/16 03:29:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack)
{
	swap(stack);
	printf("sa\n");
}

void	sb(t_stack **stack)
{
	swap(stack);
	printf("sb\n");
}

void	ss(t_stack **stack, t_stack **stackb)
{
	swap(stack);
	swap(stackb);
	printf("ss\n");
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	if (*stackb)
	{
		printf("pa\n");
		push_stack(stackb, stacka);
	}
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	if (*stacka)
	{
		printf("pb\n");
		push_stack(stacka, stackb);
	}
}

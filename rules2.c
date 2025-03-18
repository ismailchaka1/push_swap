/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:29:06 by root              #+#    #+#             */
/*   Updated: 2025/03/16 03:31:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack)
{
	printf("ra\n");
	rotate(stack);
}

void	rb(t_stack **stack)
{
	printf("rb\n");
	rotate(stack);
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	printf("rr\n");
	rotate(stacka);
	rotate(stackb);
}

void	rra(t_stack **stack)
{
	printf("rra\n");
	reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	printf("rrb\n");
	reverse_rotate(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:08:50 by root              #+#    #+#             */
/*   Updated: 2025/03/18 20:00:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (stack_sorted(*stack))
		return ;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b < c)
		return ;
	else
		rra(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	min_node = stack_min(*a);
	while (*a != min_node)
	{
		if (min_node == stack_bottom(*a) || min_node == stack_bottom(*a)->prev)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	min_node = stack_min(*a);
	while (*a != min_node)
	{
		if (min_node == stack_bottom(*a) || min_node == stack_bottom(*a)->prev)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

void print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

void	sort_others(t_stack **stacka, t_stack **stackb)
{
	int	*array;
	int	i;
	int	range;
	int	size;

	range = get_range(*stacka);
	size = stack_size(*stacka);
	i = 0;
	array = stack_to_array(stacka);
	print_stack(*stacka);
	print_array(array, size);
	printf("range = %d\n", range);
	while (*stacka)
	{
		if (range + i >= size)
			range = size - i - 1;
		if (stack_top(*stacka)->value <= array[i])
			pb_rb(stacka, stackb, &i);
		else if (*stacka && (*stacka)->value > array[i]
			&& (*stacka)->value <= array[range + i])
		{
			pb(stacka, stackb);
			// if (stack_size(*stackb) >= 2 && (*stackb)->prev != NULL
			// 	&& (*stackb)->value < (*stackb)->prev->value)
			// 	sb(stackb);
			i++;
		}
		else
			ra(stacka);
	}
	free(array);
	exit(0);
}

// void	sort_stack(t_stack **stacka, t_stack **stackb)
// {
// 	int	size;

// 	size = stack_size(*stacka);
// 	if (size == 2)
// 	{
// 		sa(stacka);
// 	}
// 	else if (size == 3)
// 		sort_three(stacka);
// 	else if (size == 4)
// 		sort_four(stacka, stackb);
// 	else if (size == 5)
// 		sort_five(stacka, stackb);
// 	else
// 	{
// 		sort_others(stacka, stackb);
// 		while (*stackb)
// 		{
// 			max_to_top(stackb);
// 			pa(stacka, stackb);
// 		}
// 	}
// }

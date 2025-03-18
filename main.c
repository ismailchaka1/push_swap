/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:28 by ichakank          #+#    #+#             */
/*   Updated: 2025/03/18 05:28:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stacka, t_stack **stackb)
{
	printf("rrr\n");
	reverse_rotate(stacka);
	reverse_rotate(stackb);
}

void	sort_stack(t_stack **stacka, t_stack **stackb)
{
	int	size;

	size = stack_size(*stacka);
	if (size == 2)
	{
		sa(stacka);
	}
	else if (size == 3)
		sort_three(stacka);
	else if (size == 4)
		sort_four(stacka, stackb);
	else if (size == 5)
		sort_five(stacka, stackb);
	else
	{
		sort_others(stacka, stackb);
		while (*stackb)
		{
			max_to_top(stackb);
			pa(stacka, stackb);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		j;
	char	**split;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 2)
	{
		printf("Error \n");
		return (-1);
	}
	while (av[i])
	{
		j = 0;
		split = ft_split(av[i], ' ');
		while (split[j])
		{
			if (check_duplicate(stack_a, ft_atoi(split[j])))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			push(&stack_a, ft_atoi(split[j]));
			j++;
		}
		free_split(split);
		i++;
	}
	// print_stack(stack_a);
	if (!stack_sorted(stack_a))
	{
		sort_stack(&stack_a, &stack_b);
		// print_stack(stack_a);
		// print_stack(stack_b);
	}
	else
	{
		printf("sorted\n");
	}
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}

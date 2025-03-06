/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:28 by ichakank          #+#    #+#             */
/*   Updated: 2025/03/06 19:49:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number(long long result, int i, char *str)
{
	if (result >= 2147483647 || result <= -2147483648)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (str[i] != '\0')
	{
		write(1, "Error\n", 6);
		exit(0);
	}
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
		if (result >= 2147483647 || result <= -2147483648)
		{
			printf("Error\n");
			exit(0);
		}
		i++;
	}
	check_number(result, i, str);
	return (sign * result);
}

int	check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

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

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	push(t_stack **stack, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = value;
	new->next = *stack;
	*stack = new;
}

void	push_stack(t_stack **firststack, t_stack **secondstack)
{
	t_stack	*tmp;

	if (*firststack == NULL)
		return ;
	tmp = *firststack;
	*firststack = (*firststack)->next;
	tmp->next = *secondstack;
	*secondstack = tmp;
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	printf("pa\n");
	push_stack(stacka, stackb);
}

void	pb(t_stack **stackb, t_stack **stacka)
{
	printf("pb\n");
	push_stack(stacka, stackb);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	last = tmp;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

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

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*curr;

    curr = *stack;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = *stack;
    *stack = curr;
    
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
void	rrr(t_stack **stacka, t_stack **stackb)
{
	printf("rrr\n");
	reverse_rotate(stacka);
	reverse_rotate(stackb);
}

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

int stack_sorted(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next != NULL)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return 1;
}

void sort_stack(t_stack **stacka, t_stack **stackb)
{
    (void)*stackb;
    (void)*stacka;
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	int j;

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
		char **split;
		split = ft_split(av[i], ' ');
		while (split[j])
		{
			if (check_duplicate(stack_a, ft_atoi(split[j])))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			push(&stack_a, ft_atoi(split[j]));
			j++;
		}
		free_split(split);
		i++;
	}
    if (stack_sorted(&stack_a) == 0)
    {
        sort_stack(&stack_a, &stack_b);
    }
    else
    {
        printf("sorted");
    }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichakank <ichakank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:28 by ichakank          #+#    #+#             */
/*   Updated: 2025/03/03 15:58:25 by ichakank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	result;

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
		i++;
	}
	return (sign * result);
}

int check_duplicate(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

void push(t_stack **stack, int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->value = value;
    new->next = *stack;
    new->prev = NULL;
    if (*stack)
        (*stack)->prev = new;
    *stack = new;
}

int main(int ac, char **av)
{    
    t_stack *stack_a;
    // t_stack *stack_b;
    int i;

    i = 1;
    stack_a = NULL;
    // stack_b = NULL;
    if (ac == 1)
        return (0);
    while (av[i])
    {
        printf("av[i] = %s atoi = %d\n", av[i], ft_atoi(av[i]));
        if (check_duplicate(stack_a, ft_atoi(av[i])))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        push(&stack_a, ft_atoi(av[i]));
        i++;
    }
    print_stack(stack_a);    
    
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichakank <ichakank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:28 by ichakank          #+#    #+#             */
/*   Updated: 2025/03/06 02:04:21 by ichakank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_number(long long result, int i, char *str)
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
	int	sign;
	int	i;
	long result;

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

void swap(t_stack **stack)
{
    t_stack *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
}

void sa(t_stack **stack)
{
    swap(stack);
    printf("sa\n");
}

void sb(t_stack **stack)
{
    swap(stack);
    printf("sb\n");
}

void ss(t_stack **stack, t_stack **stackb)
{
    swap(stack);
    swap(stackb);
    printf("ss\n");
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
    *stack = new;
}


void push_stack(t_stack **firststack, t_stack **secondstack)
{
    t_stack *tmp;

    if (*firststack == NULL)
        return;
    tmp = *firststack;

    *firststack = (*firststack)->next;
    tmp->next = *secondstack;
    *secondstack = tmp;
}


void pa(t_stack **stacka, t_stack **stackb)
{
    printf("pa\n");
    push_stack(stacka, stackb);
}

void pb(t_stack **stackb, t_stack **stacka)
{
    printf("pb\n");
    push_stack(stacka, stackb);
}

void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int main(int ac, char **av)
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
        return -1;
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
    print_stack(stack_a);
    print_stack(stack_b);
    pb(&stack_b, &stack_a);
    print_stack(stack_a);
    printf("----------\n");
    print_stack(stack_b);
    // sa(&stack_a);
    // print_stack(stack_a);
    return (0);
}
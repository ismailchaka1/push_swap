/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:28 by ichakank          #+#    #+#             */
/*   Updated: 2025/03/09 03:44:06 by root             ###   ########.fr       */
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
	if (stack == NULL)
		return (0);
	while (stack != NULL)
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
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
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

void	print_stack(t_stack *s)
{
	t_stack	*tmp;

	return ;
	tmp = s;
	while (tmp)
	{
		printf("%d -> ", tmp->value);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	printf("\n");
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

void	push_stack(t_stack **firststack, t_stack **secondstack)
{
	t_stack	*tmp;

	if (*firststack == NULL) // Check if stack is empty before popping
		return ;
	tmp = *firststack;                 // Store the top element
	*firststack = (*firststack)->next; // Move the top pointer
	if (*firststack) // If the first stack is not empty, update prev pointer
		(*firststack)->prev = NULL;
	tmp->next = *secondstack; // Move tmp to top of second stack
	if (*secondstack)
		(*secondstack)->prev = tmp;
	tmp->prev = NULL; // tmp is now the top of second stack
	*secondstack = tmp;
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	if (*stackb) // Only push if stack B is not empty
	{
		printf("pa\n");
		push_stack(stackb, stacka);
	}
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	if (*stacka) // Only push if stack A is not empty
	{
		printf("pb\n");
		push_stack(stacka, stackb);
	}
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

int	stack_sorted(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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

int	get_range(t_stack *a)
{
	int	range;

	range = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		range = 3;
	else if (stack_size(a) <= 100)
		range = 13;
	else if (stack_size(a) <= 500)
		range = 35;
	else
		range = 45;
	return (range);
}


void sort_array(int *array, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int *stack_to_array(t_stack **stacka)
{
	int *array;
	int i;
	t_stack *tmp;
	int size;

	tmp = *stacka;
	i = 0;
	size = stack_size(*stacka);
	array = malloc(sizeof(int) * size);
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_array(array, size);
	return (array);
}


static void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b);
	rb(b);
	(*i)++;
}

void sort_others(t_stack **stacka, t_stack **stackb)
{
	int *array;
	int i;
	int range = get_range(*stacka);
	int size = stack_size(*stacka);
	i = 0;
	array = stack_to_array(stacka);
	while (*stacka)
	{
		if (range + i >= size)
			range = size - i - 1;
		if (stack_top(*stacka)->value <= array[i])
			pb_rb(stacka, stackb, &i);
		else if (*stacka && (*stacka)->value > array[i] && (*stacka)->value <= array[range + i])
		{
			pb(stacka, stackb);
			if (stack_size(*stackb) >= 2 && (*stackb)->prev != NULL && (*stackb)->value < (*stackb)->prev->value)
				sb(stackb);
			i++;
		}
		else
			ra(stacka);
	}
	free(array);
}

int	max_index(t_stack *b)
{
	int	index;

	index = 0;
	while (b && stack_max(b) != b)
	{
		b = b->prev;
		index++;
	}
	return (index);
}

void	max_to_top(t_stack **b)
{
	int	index;
	int	size;

	size = stack_size(*b);
	while (1)
	{
		index = max_index(*b);
		if (index == 0)
			break ;
		else if (index <= size / 2)
			rb(b);
		else if (index > size / 2)
			rrb(b);
	}
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
		// exit(0);
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
		char **split;

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
	print_stack(stack_a);
	if (!stack_sorted(stack_a))
	{
		sort_stack(&stack_a, &stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
	}
	else
	{
		printf("sorted\n");
	}
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}

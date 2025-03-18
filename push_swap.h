/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:19:06 by ichakank          #+#    #+#             */
/*   Updated: 2025/03/18 05:27:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				sort_three(t_stack **stack);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_others(t_stack **stacka, t_stack **stackb);
void				sort_stack(t_stack **stacka, t_stack **stackb);
void				push_stack(t_stack **firststack, t_stack **secondstack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				swap(t_stack **stack);
void				error_exit(void);
void				check_number(long long result, int i, char *str);
int					ft_atoi(char *str);
int					check_duplicate(t_stack *stack, int value);
int					stack_sorted(t_stack *s);
t_stack				*stack_top(t_stack *s);
t_stack				*stack_min(t_stack *s);
t_stack				*stack_max(t_stack *s);
t_stack				*stack_bottom(t_stack *s);
int					stack_size(t_stack *stack);
int					get_range(t_stack *a);
void				sort_array(int *array, int size);
int					*stack_to_array(t_stack **stacka);
int					max_index(t_stack *b);
void				max_to_top(t_stack **b);
void				free_split(char **split);
void				clear_stack(t_stack **stack);
void				pb_rb(t_stack **a, t_stack **b, int *i);
void				push(t_stack **stack, int value);
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **stack, t_stack **stackb);
void				pa(t_stack **stacka, t_stack **stackb);
void				pb(t_stack **stacka, t_stack **stackb);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stacka, t_stack **stackb);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stacka, t_stack **stackb);

#endif
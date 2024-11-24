/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:22:17 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/13 17:42:55 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*find_stack(t_list **stack, int index)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *stack;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

static void	start_calculation(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		min_moves;
	int		lowest;

	while (ft_lstsize(*stack_a) > 3)
	{
		current = *stack_a;
		lowest = *(int *)current->content;
		min_moves = calculate_moves(stack_a, stack_b, current);
		while (current->next)
		{
			current = current->next;
			if (min_moves > calculate_moves(stack_a, stack_b, current))
			{
				lowest = *(int *)current->content;
				min_moves = calculate_moves(stack_a, stack_b, current);
			}
		}
		current = find_stack(stack_a, get_index(stack_a, lowest));
		execute_from_a(stack_a, stack_b, current);
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	start_calculation(stack_a, stack_b);
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		current = *stack_b;
		execute_from_b(stack_a, stack_b, current);
	}
	current = *stack_a;
	while (*(int *)current->content != get_min(stack_a))
	{
		if (ft_lstsize(*stack_a) / 2 >= get_index(stack_a, get_min(stack_a)))
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		current = *stack_a;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:15:37 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/11 15:46:56 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_min_index(t_list **stack)
{
	t_list	*t;
	t_list	*s;
	int		index;
	int		min;

	t = (*stack)->next;
	s = (*stack);
	index = 0;
	min = 0;
	while (t)
	{
		index++;
		if (*(int *)s->content > *(int *)t->content)
		{
			min = index;
			s = t;
		}
		t = t->next;
	}
	return (min);
}

void	put_smallest_in_b(int smallest, t_list **stack_a, t_list **stack_b)
{
	if (smallest == 0)
		pb(stack_a, stack_b);
	else if (smallest == 1)
	{
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (smallest == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (smallest == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
}

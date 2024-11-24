/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:15:01 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/12 15:56:14 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	if (*(int *)temp->content > *(int *)temp->next->content)
		sa(*stack_a, 1);
}

void	sort_three(t_list **stack_a)
{
	t_list	*t;

	t = *stack_a;
	if ((*(int *)(t->content) < *(int *)(t->next->content))
		&& (*(int *)(t->content) < *(int *)(t->next->next->content)))
	{
		ra(stack_a, 1);
		t = *stack_a;
		if ((*(int *)(t->content)) > (*(int *)(t->next->content)))
			sa(*stack_a, 1);
		rra(stack_a, 1);
	}
	else if ((*(int *)(t->content)) < (*(int *)(t->next->content)))
		rra(stack_a, 1);
	else if (*(int *)(t->content) < *(int *)(t->next->next->content))
		sa(*stack_a, 1);
	else
	{
		ra(stack_a, 1);
		t = *stack_a;
		if ((*(int *)(t->content)) > (*(int *)(t->next->content)))
			sa(*stack_a, 1);
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (find_min_index(stack_a) == 0)
		pb(stack_a, stack_b);
	else if (find_min_index(stack_a) == 1)
	{
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (find_min_index(stack_a) == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	sort_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	put_smallest_in_b(find_min_index(stack_a), stack_a, stack_b);
	if (find_min_index(stack_a) == 0)
		pb(stack_a, stack_b);
	else if (find_min_index(stack_a) == 1)
	{
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (find_min_index(stack_a) == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	sort_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_numbers(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

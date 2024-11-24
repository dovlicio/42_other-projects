/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_from_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:26:00 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/19 15:27:30 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_a_big(t_moves *move, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) / 2 >= get_index(stack_b, get_max(stack_b)))
		move->rb += get_index(stack_b, get_max(stack_b));
	else
		move->rrb += ft_lstsize(*stack_b) - \
			get_index(stack_b, get_max(stack_b));
	move->pb += 1;
}

static void	execute_a_small(t_moves *move, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) / 2 > get_index(stack_b, get_min(stack_b)))
		move->rb += get_index(stack_b, get_min(stack_b)) + 1;
	else
		move->rrb += ft_lstsize(*stack_b) - \
			(get_index(stack_b, get_min(stack_b)) + 1);
	move->pb += 1;
}

static void	run_a(t_moves *move, t_list **stack_a, t_list **stack_b)
{
	calculate_rr_rrr(move);
	while ((move->rr)-- > 0)
		rr(stack_a, stack_b);
	while ((move->rrr)-- > 0)
		rrr(stack_a, stack_b);
	while ((move->rb)-- > 0)
		rb(stack_b, 1);
	while ((move->rrb)-- > 0)
		rrb(stack_b, 1);
	while ((move->ra)-- > 0)
		ra(stack_a, 1);
	while ((move->rra)-- > 0)
		rra(stack_a, 1);
	while ((move->pb)--)
	{
		pb(stack_a, stack_b);
		// ft_printf("STACK A: ");
		// print_stack(stack_a);
		// ft_printf("STACK B: ");
		// print_stack(stack_b);
	}
}

void	execute_from_a(t_list **stack_a, t_list **stack_b, t_list *current)
{
	t_moves	move;
	int		next;

	ft_memset(&move, 0, sizeof(t_moves));
	move.current_index = get_index(stack_a, *(int *)current->content);
	if ((ft_lstsize(*stack_a) / 2) >= move.current_index)
		move.ra += move.current_index;
	else
		move.rra += ft_lstsize(*stack_a) - move.current_index;
	if (*(int *)current->content > get_max(stack_b))
		execute_a_big(&move, stack_b);
	else if (*(int *)current->content < get_min(stack_b))
		execute_a_small(&move, stack_b);
	else
	{
		next = get_next_smaller(stack_b, current->content);
		if (ft_lstsize(*stack_b) / 2 >= get_index(stack_b, next))
			move.rb += get_index(stack_b, next);
		else
			move.rrb += ft_lstsize(*stack_b) - get_index(stack_b, next);
		move.pb += 1;
	}
	run_a(&move, stack_a, stack_b);
}

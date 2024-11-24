/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:31:02 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/13 17:43:48 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_rr_rrr(t_moves *move)
{
	while (move->ra && move->rb)
	{
		move->rr += 1;
		(move->ra)--;
		(move->rb)--;
	}
	while (move->rra && move->rrb)
	{
		move->rrr += 1;
		(move->rra)--;
		(move->rrb)--;
	}
}

static void	calculate_big(t_moves *move, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) / 2 >= get_index(stack_b, get_max(stack_b)))
		move->rb += get_index(stack_b, get_max(stack_b));
	else
		move->rrb += ft_lstsize(*stack_b) - \
			get_index(stack_b, get_max(stack_b));
	move->pb += 1;
}

static void	calculate_small(t_moves *move, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) / 2 > get_index(stack_b, get_min(stack_b)))
		move->rb += get_index(stack_b, get_min(stack_b)) + 1;
	else
		move->rrb += ft_lstsize(*stack_b) - \
			(get_index(stack_b, get_min(stack_b)) + 1);
	move->pb += 1;
}

int	calculate_moves(t_list **stack_a, t_list **stack_b, t_list *current)
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
		calculate_big(&move, stack_b);
	else if (*(int *)current->content < get_min(stack_b))
		calculate_small(&move, stack_b);
	else
	{
		next = get_next_smaller(stack_b, current->content);
		if (ft_lstsize(*stack_b) / 2 >= get_index(stack_b, next))
			move.rb += get_index(stack_b, next);
		else
			move.rrb += ft_lstsize(*stack_b) - get_index(stack_b, next);
		move.pb += 1;
	}
	calculate_rr_rrr(&move);
	return (move.ra + move.rb + move.pb + move.pa + \
		move.rr + move.rra + move.rrb + move.rrr);
}

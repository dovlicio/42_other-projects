/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:41:27 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/13 17:44:14 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	pb;
	int	pa;
	int	current_index;
}				t_moves;

/*------SWAP---PUSH---ROTATE---ROTATE_REVERSE-------*/
void	sa(t_list *stack, int print);
void	sb(t_list *stack, int print);
void	ss(t_list *stack_a, t_list *stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b);

/*----------------------HELPER-----------------------*/
void	sort_numbers(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack_a);
int		find_min_index(t_list **stack);
void	put_smallest_in_b(int smallest, t_list **stack_a, t_list **stack_b);
void	print_stack(t_list **stack);
int		get_min(t_list **stack);
int		get_max(t_list **stack);
int		get_index(t_list **stack, int current);
int		get_next_smaller(t_list **stack, int *current);

/*---------------------SORTING------------------------*/
void	sort_three(t_list **stack_a);
void	sort_big(t_list **stack_a, t_list **stack_b);
void	execute_from_a(t_list **stack_a, t_list **stack_b, t_list *current);
void	execute_from_b(t_list **stack_a, t_list **stack_b, t_list *current);
int		calculate_moves(t_list **stack_a, t_list **stack_b, t_list *current);
void	calculate_rr_rrr(t_moves *move);

/*---------------------ARGUMENTS--------------------*/
void	put_args_in_stack(char **argv, t_list **stack_a);

/*-----------------------ERRORS---------------------*/
void	error_overflow(t_list **stack_a, int *number);
void	free_stack(t_list **stack_a);
void	is_valid_int(char **argv);

#endif

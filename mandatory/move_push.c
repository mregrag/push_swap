/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:56:13 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 12:48:03 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_pos_in_stack_a(t_stack **a, int b_index)
{
	t_stack	*stack_a;
	int		target_pos;
	int		tmp_index;

	stack_a = *a;
	target_pos = 0;
	position_stack(a);
	tmp_index = INT_MAX;
	while (stack_a)
	{
		if (stack_a->index > b_index && stack_a->index < tmp_index)
		{
			tmp_index = stack_a->index;
			target_pos = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
	if (tmp_index != INT_MAX)
		return (target_pos);
	stack_a = *a;
	return (get_min_index_position(&stack_a));
}

void	calcul_best_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *b;
	position_stack(b);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (tmp_b)
	{
		tmp_b->target_pos = get_pos_in_stack_a(a, tmp_b->index);
		tmp_b->mov_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->mov_b = (tmp_b->pos - size_b);
		tmp_b->mov_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->mov_a = (tmp_b->target_pos - size_a);
		tmp_b = tmp_b->next;
	}
}

void	move_push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		step;
	int		mov_a;
	int		mov_b;

	tmp = *b;
	step = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->mov_a) + abs(tmp->mov_b) < step)
		{
			step = abs(tmp->mov_b) + abs(tmp->mov_a);
			mov_a = tmp->mov_a;
			mov_b = tmp->mov_b;
		}
		tmp = tmp->next;
	}
	back_to_stack_a(a, b, mov_a, mov_b);
}

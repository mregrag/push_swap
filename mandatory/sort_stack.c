/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:58:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 12:48:54 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_except_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	push;
	int	i;

	size = ft_lstsize(*stack_a);
	push = 0;
	i = 0;
	while (i < size && push < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			push++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - push > 3)
	{
		pb(stack_a, stack_b);
		push++;
	}
}

static void	move_to_top(t_stack **stack_a)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	min_pos = get_min_index_position(stack_a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
}

static	void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_except_three(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		calcul_best_move(stack_a, stack_b);
		move_push(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		move_to_top(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
	free_stack(stack_a);
}

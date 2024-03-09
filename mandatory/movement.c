/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:21:21 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 12:32:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate_both(t_stack **a, t_stack **b, int *mov_a, int *mov_b)
{
	while (*mov_a < 0 && *mov_b < 0)
	{
		(*mov_a)++;
		(*mov_b)++;
		rrr(a, b);
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *mov_a, int *mov_b)
{
	while (*mov_a > 0 && *mov_b > 0)
	{
		(*mov_a)--;
		(*mov_b)--;
		rr(a, b);
	}
}

static void	rotate_a(t_stack **a, int *mov_a)
{
	while (*mov_a)
	{
		if (*mov_a > 0)
		{
			ra(a);
			(*mov_a)--;
		}
		else if (*mov_a < 0)
		{
			rra(a);
			(*mov_a)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *mov_b)
{
	while (*mov_b)
	{
		if (*mov_b > 0)
		{
			rb(b);
			(*mov_b)--;
		}
		else if (*mov_b < 0)
		{
			rrb(b);
			(*mov_b)++;
		}
	}
}

void	back_to_stack_a(t_stack **a, t_stack **b, int mov_a, int mov_b)
{
	if (mov_a < 0 && mov_b < 0)
		rev_rotate_both(a, b, &mov_a, &mov_b);
	else if (mov_a > 0 && mov_b > 0)
		rotate_both(a, b, &mov_a, &mov_b);
	rotate_a(a, &mov_a);
	rotate_b(b, &mov_b);
	pa(b, a);
}

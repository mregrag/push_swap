/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:50:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/08 19:23:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	position_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_min_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		min_index;
	int		min_pos;

	position_stack(stack);
	tmp = *stack;
	min_index = INT_MAX;
	min_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

void	add_to_stack(t_stack **stack, int nbr)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = ft_lstnew(nbr);
	ft_lstadd_back(stack, node);
}

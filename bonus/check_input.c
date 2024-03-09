/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:48:26 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 16:40:50 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **argv)
{
	free_stack(a);
	free_matrix(argv);
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
		return (1);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_stack **a, int nbr)
{
	t_stack	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

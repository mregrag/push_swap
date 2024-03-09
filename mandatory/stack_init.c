/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:51:28 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 15:06:20 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	index_stack(t_stack **stack)
{
	t_stack	*head1;
	t_stack	*head2;

	head1 = *stack;
	while (head1)
	{
		head1->index = 1;
		head2 = *stack;
		while (head2)
		{
			if (head1->nbr > head2->nbr)
				head1->index += 1;
			head2 = head2->next;
		}
		head1 = head1->next;
	}
}

static void	set_stack(t_stack **a, char **str)
{
	int	i;

	if (!str || !*str)
		error_free(a, str);
	i = 0;
	while (str[i])
	{
		if (check_str(str[i]))
			error_free(a, str);
		if (check_duplicate(a, ft_atoi(str[i])))
			error_free(a, str);
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
			error_free(a, str);
		add_to_stack(a, ft_atoi(str[i]));
		i++;
	}
}

void	stack_init(t_stack **a, char **argv)
{
	char	**str;
	int		i;

	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], 32);
		set_stack(a, str);
		free_matrix(str);
		i++;
	}
	index_stack(a);
}

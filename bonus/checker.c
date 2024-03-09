/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:01:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 16:20:06 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	ft_putendl_fd("Error", 1);
	exit(255);
}

static void	check_command(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		pa(stack_b, stack_a);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		error(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	*cmd;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_init(&stack_a, argv);
	cmd = get_next_line(0);
	while (cmd)
	{
		check_command(&stack_a, &stack_b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (!stack_b && stack_a && is_sorted(stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

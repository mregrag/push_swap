/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:42:16 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/09 16:40:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				pos;
	int				target_pos;
	int				mov_a;
	int				mov_b;
	struct s_stack	*next;
}					t_stack;

int		check_str(char *str);
int		check_duplicate(t_stack **a, int nbr);
int		is_sorted(t_stack *stack_a);
int		get_min_index_position(t_stack **stack);
void	add_to_stack(t_stack **stack, int nbr);
void	free_matrix(char **argv);
void	free_stack(t_stack **stack);
void	error_free(t_stack **a, char **argv);
void	calcul_best_move(t_stack **a, t_stack **b);
void	sort_3(t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	stack_init(t_stack **a, char **argv);
void	position_stack(t_stack **stack);
void	move_push(t_stack **stack_a, t_stack **stack_b);
void	back_to_stack_a(t_stack **a, t_stack **b, int mov_a, int mov_b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

t_stack	*ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **stack, t_stack *node);
int		ft_lstsize(t_stack *lst);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif

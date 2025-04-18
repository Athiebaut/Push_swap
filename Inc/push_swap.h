/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:30 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 10:52:49 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Printf/ft_printf.h"
# include "../Libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}		t_stack;

void	check_args(char **av);
void	init_stack(t_stack **pile_a, char **av);
void	index_pile(t_stack **pile_a);
void	error_handler(void);
void	ft_free(t_stack **pile_a, t_stack **pile_b);
void	sort(t_stack **pile_a, t_stack **pile_b);
int		check_sorted(t_stack **pile_a);
size_t	ft_strlen2(char **str);

/*----------Instructions----------*/
int		push_a(t_stack **pile_a, t_stack **pile_b, int bonus);
int		push_b(t_stack **pile_a, t_stack **pile_b, int bonus);
int		swap_a(t_stack **pile, int bonus);
int		swap_b(t_stack **pile, int bonus);
int		swap_s(t_stack **pile_a, t_stack **pile_b, int bonus);
int		rotate_a(t_stack **pile, int bonus);
int		rotate_b(t_stack **pile, int bonus);
int		rotate_r(t_stack **pile_a, t_stack **pile_b, int bonus);
int		reverse_rotate_a(t_stack **pile, int bonus);
int		reverse_rotate_b(t_stack **pile, int bonus);
int		reverse_rotate_r(t_stack **pile_a, t_stack **pile_b, int bonus);

/*----------Simple Sort----------*/
void	sort_five(t_stack **pile_a, t_stack **pile_b);
void	sort_four(t_stack **pile_a, t_stack **pile_b);
void	sort_three(t_stack **pile);

/*----------Big Sort Utils----------*/
int		get_max(t_stack **pile_a);
int		b_pos(int value);
int		get_target(t_stack **pile_a, int rank, int t_rank, int t_pos);
void	init_position(t_stack **pile);
void	execution(t_stack **pile_a, t_stack **pile_b, int cost_a, int cost_b);
void	loop_rotate_b(t_stack **pile_b, int cost_b);
void	loop_rotate_a(t_stack **pile_a, int cost_a);
void	loop_reverse_rotate_both(t_stack **pile_a, t_stack **pile_b,
			int *cost_a, int *cost_b);
void	loop_rotate_both(t_stack **pile_a, t_stack **pile_b, int *cost_a,
			int *cost_b);

/*----------Big Sort----------*/
void	first_push(t_stack **pile_a, t_stack **pile_b);
void	get_position(t_stack **pile_a, t_stack **pile_b);
void	get_cost(t_stack **pile_a, t_stack **pile_b);
void	less_moves(t_stack **pile_a, t_stack **pile_b);

/*----------Stack handle----------*/
int		lst_size(t_stack **lst);
void	print_pile(t_stack *pile);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int content);
t_stack	*lstlast(t_stack *lst);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:10:32 by alix              #+#    #+#             */
/*   Updated: 2023/07/05 14:56:01 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	less_moves(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	int		r_max;
	int		cost_a;
	int		cost_b;

	node = *pile_b;
	r_max = INT_MAX;
	while (node)
	{
		if ((b_pos(node->cost_a) + b_pos(node->cost_b) < r_max))
		{
			r_max = b_pos(node->cost_a) + b_pos(node->cost_b);
			cost_a = node->cost_a;
			cost_b = node->cost_b;
		}
		node = node->next;
	}
	execution(pile_a, pile_b, cost_a, cost_b);
}

void	get_cost(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node_b;
	int		size_a;
	int		size_b;

	node_b = *pile_b;
	size_a = lst_size(pile_a);
	size_b = lst_size(pile_b);
	while (node_b)
	{
		node_b->cost_b = node_b->pos;
		if (node_b->pos > size_b / 2)
			node_b->cost_b = (size_b - node_b->pos) * -1;
		node_b->cost_a = node_b->target;
		if (node_b->target > size_a / 2)
			node_b->cost_a = (size_a - node_b->target) * -1;
		node_b = node_b->next;
	}
}

void	get_position(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	int		target;

	node = *pile_b;
	init_position(pile_a);
	init_position(pile_b);
	target = 0;
	while (node)
	{
		target = get_target(pile_a, node->rank, INT_MAX, target);
		node->target = target;
		node = node->next;
	}
}

void	first_push(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	int		size;
	int		push;
	int		i;

	size = lst_size(pile_a);
	node = *pile_a;
	push = 0;
	i = 0;
	while (size > 10 && i++ < size && push < size / 2)
	{
		node = *pile_a;
		if (node->rank <= size / 2)
		{
			push_b(pile_a, pile_b, 0);
			push++;
		}
		else
			rotate_a(pile_a, 0);
	}
	while (size - push > 5)
	{
		push_b(pile_a, pile_b, 0);
		push++;
	}
}

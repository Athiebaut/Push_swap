/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:10:57 by alix              #+#    #+#             */
/*   Updated: 2023/06/30 22:34:50 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	b_pos(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

int	get_max(t_stack **pile_a)
{
	t_stack	*node;
	int		max;

	node = *pile_a;
	max = node->value;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

void	init_position(t_stack **pile)
{
	t_stack	*node;
	int		i;

	node = *pile;
	i = 0;
	while (node)
	{
		node->pos = i;
		node = node->next;
		i++;
	}
}

int	get_target(t_stack **pile_a, int rank, int t_rank, int t_pos)
{
	t_stack	*node;

	node = *pile_a;
	while (node)
	{
		if (node->rank > rank && node->rank < t_rank)
		{
			t_pos = node->pos;
			t_rank = node->rank;
		}
		node = node->next;
	}
	if (t_rank != INT_MAX)
		return (t_pos);
	node = *pile_a;
	while (node)
	{
		if (node->rank < t_rank)
		{
			t_pos = node->pos;
			t_rank = node->rank;
		}
		node = node->next;
	}
	return (t_pos);
}

void	execution(t_stack **pile_a, t_stack **pile_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		loop_reverse_rotate_both(pile_a, pile_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		loop_rotate_both(pile_a, pile_b, &cost_a, &cost_b);
	loop_rotate_a(pile_a, cost_a);
	loop_rotate_b(pile_b, cost_b);
	push_a(pile_a, pile_b, 0);
}

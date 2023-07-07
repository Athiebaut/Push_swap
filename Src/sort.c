/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:09:43 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/05 14:56:28 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	lowest_position(t_stack **pile_a)
{
	t_stack	*node;
	int		pos;

	node = *pile_a;
	pos = 0;
	while (node->rank != 0)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

void	final_sort(t_stack **pile_a)
{
	int	lowest;
	int	size;

	size = lst_size(pile_a);
	lowest = lowest_position(pile_a);
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			reverse_rotate_a(pile_a, 0);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			rotate_a(pile_a, 0);
			lowest--;
		}
	}
}

void	simple_sort(t_stack **pile_a, t_stack **pile_b)
{
	int	size;

	size = lst_size(pile_a);
	if (size < 2)
		return ;
	if (size == 2)
		swap_a(pile_a, 0);
	else if (size == 3)
		sort_three(pile_a);
	else if (size == 4)
		sort_four(pile_a, pile_b);
	else if (size == 5)
		sort_five(pile_a, pile_b);
}

void	big_sort(t_stack **pile_a, t_stack **pile_b)
{
	first_push(pile_a, pile_b);
	simple_sort(pile_a, pile_b);
	while (*pile_b)
	{
		get_position(pile_a, pile_b);
		get_cost(pile_a, pile_b);
		less_moves(pile_a, pile_b);
	}
	if (check_sorted(pile_a))
		final_sort(pile_a);
}

void	sort(t_stack **pile_a, t_stack **pile_b)
{
	if (lst_size(pile_a) <= 5)
		simple_sort(pile_a, pile_b);
	else
		big_sort(pile_a, pile_b);
}

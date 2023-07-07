/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:40:44 by alix              #+#    #+#             */
/*   Updated: 2023/06/30 22:44:55 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	get_min(t_stack **pile)
{
	t_stack	*node;
	int		min;

	node = *pile;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

int	get_distance(t_stack **pile, int min)
{
	t_stack	*node;
	int		count;

	node = *pile;
	count = 0;
	while (node)
	{
		if (node->value == min)
			break ;
		count++;
		node = node->next;
	}
	return (count);
}

void	sort_three(t_stack **pile)
{
	t_stack	*p;

	p = *pile;
	if (!check_sorted(pile))
		return ;
	if (p->value < p->next->value && p->value < p->next->next->value)
	{
		reverse_rotate_a(pile, 0);
		swap_a(pile, 0);
	}
	else if (p->value < p->next->value && p->value > p->next->next->value)
		reverse_rotate_a(pile, 0);
	else if (p->value > p->next->value && p->value < p->next->next->value)
		swap_a(pile, 0);
	else if (p->value > p->next->value && p->next->value > p->next->next->value)
	{
		rotate_a(pile, 0);
		swap_a(pile, 0);
	}
	else if (p->value > p->next->value && p->next->value < p->next->next->value)
		rotate_a(pile, 0);
}

void	sort_four(t_stack **pile_a, t_stack **pile_b)
{
	int	min;
	int	distance;

	min = get_min(pile_a);
	distance = get_distance(pile_a, min);
	if (distance == 1)
		rotate_a(pile_a, 0);
	else if (distance == 2)
	{
		rotate_a(pile_a, 0);
		rotate_a(pile_a, 0);
	}
	else if (distance == 3)
		reverse_rotate_a(pile_a, 0);
	if (!check_sorted(pile_a))
		return ;
	push_b(pile_a, pile_b, 0);
	sort_three(pile_a);
	push_a(pile_a, pile_b, 0);
}

void	sort_five(t_stack **pile_a, t_stack **pile_b)
{
	int	min;
	int	distance;

	min = get_min(pile_a);
	distance = get_distance(pile_a, min);
	if (distance == 1)
		rotate_a(pile_a, 0);
	else if (distance == 2)
	{
		rotate_a(pile_a, 0);
		rotate_a(pile_a, 0);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(pile_a, 0);
		reverse_rotate_a(pile_a, 0);
	}
	else if (distance == 4)
		reverse_rotate_a(pile_a, 0);
	if (!check_sorted(pile_a))
		return ;
	push_b(pile_a, pile_b, 0);
	sort_four(pile_a, pile_b);
	push_a(pile_a, pile_b, 0);
}

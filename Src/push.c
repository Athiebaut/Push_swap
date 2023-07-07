/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:30 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 16:27:33 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

static int	push(t_stack **pile_from, t_stack **pile_to)
{
	t_stack	*node;
	t_stack	*head_to;
	t_stack	*head_from;

	if (!pile_from)
		return (0);
	head_to = *pile_to;
	head_from = *pile_from;
	node = *pile_from;
	*pile_from = head_from->next;
	if (!head_to)
	{
		head_to = node;
		head_to->next = NULL;
		*pile_to = head_to;
	}
	else
	{
		node->next = head_to;
		*pile_to = node;
	}
	return (0);
}

int	push_a(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (!pile_b || lst_size(pile_b) == 0)
		return (0);
	if (push(pile_b, pile_a) == -1)
		return (-1);
	if (!bonus)
		ft_printf("pa\n");
	return (0);
}

int	push_b(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (!pile_a || lst_size(pile_a) == 0)
		return (0);
	if (push(pile_a, pile_b) == -1)
		return (-1);
	if (!bonus)
		ft_printf("pb\n");
	return (0);
}

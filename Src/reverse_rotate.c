/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:26 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 17:44:43 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	reverse_rotate(t_stack **pile)
{
	t_stack	*last;
	t_stack	*first;

	first = *pile;
	last = lstlast(*pile);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *pile;
	*pile = last;
	return (0);
}

int	reverse_rotate_a(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (reverse_rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("rra\n");
	return (0);
}

int	reverse_rotate_b(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (reverse_rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("rrb\n");
	return (0);
}

int	reverse_rotate_r(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (lst_size(pile_a) > 1)
		reverse_rotate(pile_a);
	if (lst_size(pile_b) > 1)
		reverse_rotate(pile_b);
	if (!bonus)
		ft_printf("rrr\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:19 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 17:45:29 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

static int	rotate(t_stack **pile)
{
	t_stack	*first;
	t_stack	*last;

	first = *pile;
	last = lstlast(*pile);
	*pile = first->next;
	last->next = first;
	first->next = NULL;
	return (0);
}

int	rotate_a(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("ra\n");
	return (0);
}

int	rotate_b(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("rb\n");
	return (0);
}

int	rotate_r(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (lst_size(pile_a) > 1)
		rotate(pile_a);
	if (lst_size(pile_b) > 1)
		rotate(pile_b);
	if (!bonus)
		ft_printf("rr\n");
	return (0);
}

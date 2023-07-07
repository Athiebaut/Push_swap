/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:04:40 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 17:45:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

static int	swap(t_stack **pile)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_value;
	int		tmp_rank;

	first = *pile;
	second = first->next;
	tmp_value = first->value;
	tmp_rank = first->rank;
	first->value = second->value;
	first->rank = second->rank;
	second->value = tmp_value;
	second->rank = tmp_rank;
	return (0);
}

int	swap_a(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (swap(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("sa\n");
	return (0);
}

int	swap_b(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (swap(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("sb\n");
	return (0);
}

int	swap_s(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (lst_size(pile_a) > 1)
		swap(pile_a);
	if (lst_size(pile_b) > 1)
		swap(pile_b);
	if (!bonus)
		ft_printf("ss\n");
	return (0);
}

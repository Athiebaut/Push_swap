/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:56:13 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 17:43:22 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

size_t	ft_strlen2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_sorted(t_stack **pile_a)
{
	t_stack	*node;
	int		tmp;

	node = *pile_a;
	tmp = node->value;
	node = node->next;
	while (node)
	{
		if (tmp > node->value)
			return (1);
		tmp = node->value;
		node = node->next;
	}
	return (0);
}

t_stack	*get_next_min(t_stack **pile_a)
{
	t_stack	*head;
	t_stack	*min;
	int		tmp;

	tmp = 0;
	min = NULL;
	head = *pile_a;
	while (head)
	{
		if (head->rank == -1 && (!tmp || head->value < min->value))
		{
			min = head;
			tmp = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_pile(t_stack **pile)
{
	t_stack	*node;
	int		index;

	index = 0;
	node = get_next_min(pile);
	while (node)
	{
		node->rank = index++;
		node->pos = -1;
		node->target = -1;
		node->cost_a = -1;
		node->cost_b = -1;
		node = get_next_min(pile);
	}
}

void	init_stack(t_stack **pile_a, char **av)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (av[i])
	{
		new = lstnew(ft_atoi(av[i]));
		lstadd_back(pile_a, new);
		i++;
	}
	index_pile(pile_a);
}

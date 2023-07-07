/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:03:18 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/04 10:52:53 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/*void	print_pile(t_stack *pile)
{
	if (!pile)
		return ;
	while (pile)
	{
		ft_printf("value : %i\n", pile->value);
		ft_printf("rank : %i\n", pile->rank);
		ft_printf("pos : %i\n", pile->pos);
		ft_printf("pos_target : %i\n", pile->target);
		ft_printf("cost a : %i\n", pile->cost_a);
		ft_printf("cost b : %i\n", pile->cost_b);
		ft_printf("-------------\n");
		pile = pile->next;
	}
}*/

int	lst_size(t_stack **lst)
{
	t_stack	*node;
	int		count;

	node = *lst;
	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_stack	*lstnew(int content)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->value = content;
	lst->rank = -1;
	lst->next = NULL;
	return (lst);
}

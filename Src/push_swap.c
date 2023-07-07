/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:58:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 17:13:53 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	push_swap(int ac, char **av)
{
	t_stack	**pile_a;
	t_stack	**pile_b;

	check_args(av);
	pile_a = (t_stack **)malloc(sizeof(t_stack));
	if (!pile_a)
		return ;
	pile_b = (t_stack **)malloc(sizeof(t_stack));
	if (!pile_b)
	{
		free(pile_a);
		return ;
	}
	*pile_a = NULL;
	*pile_b = NULL;
	init_stack(pile_a, av);
	if (!check_sorted(pile_a))
	{
		ft_free(pile_a, pile_b);
		return ;
	}	
	sort(pile_a, pile_b);
	ft_free(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 2)
		return (-1);
	else
	{
		av++;
		if (ac == 2)
		{
			if (*av[0] == '\0')
				return (0);
			av = ft_split(*av, ' ');
			ac = ft_strlen2(av);
			if (ac == 0)
				return (0);
			push_swap(ac, av);
			while (av[++i])
				free(av[i]);
			free(av);
		}
		else
			push_swap(ac, av);
	}
	return (0);
}

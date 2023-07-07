/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:55:59 by alix              #+#    #+#             */
/*   Updated: 2023/06/30 22:39:55 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	loop_rotate_both(t_stack **pile_a, t_stack **pile_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_r(pile_a, pile_b, 0);
	}
}

void	loop_reverse_rotate_both(t_stack **pile_a, t_stack **pile_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		reverse_rotate_r(pile_a, pile_b, 0);
	}
}

void	loop_rotate_a(t_stack **pile_a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			rotate_a(pile_a, 0);
			cost_a--;
		}
		else if (cost_a < 0)
		{
			reverse_rotate_a(pile_a, 0);
			cost_a++;
		}
	}
}

void	loop_rotate_b(t_stack **pile_b, int cost_b)
{
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rotate_b(pile_b, 0);
			cost_b--;
		}
		else if (cost_b < 0)
		{
			reverse_rotate_b(pile_b, 0);
			cost_b++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:55:59 by alix              #+#    #+#             */
/*   Updated: 2025/04/18 02:12:25 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Executes simultaneous rotations on both stacks until one or both costs reach zero.
 *
 * This function performs a dual rotation operation on two stacks (`pile_a` and `pile_b`)
 * while decrementing their respective costs (`cost_a` and `cost_b`). The rotation continues
 * as long as both costs are greater than zero. The `rotate_r` function is called to handle
 * the actual rotation of the stacks.
 *
 * @param pile_a Pointer to the pointer of the first stack.
 * @param pile_b Pointer to the pointer of the second stack.
 * @param cost_a Pointer to the cost associated with rotating the first stack.
 * @param cost_b Pointer to the cost associated with rotating the second stack.
 */
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

/**
 * @brief Executes simultaneous reverse rotations on both stacks (pile_a and pile_b)
 *        while decrementing the costs for each stack until they reach zero.
 *
 * This function performs the reverse rotation operation on both stacks
 * using the reverse_rotate_r function. It continues to execute the operation
 * as long as both cost_a and cost_b are negative, incrementing their values
 * towards zero with each iteration.
 *
 * @param pile_a Pointer to the pointer of the first stack (stack A).
 * @param pile_b Pointer to the pointer of the second stack (stack B).
 * @param cost_a Pointer to the cost associated with stack A's operations.
 *               This value is incremented towards zero during the loop.
 * @param cost_b Pointer to the cost associated with stack B's operations.
 *               This value is incremented towards zero during the loop.
 */
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

/**
 * @brief Executes a series of rotations or reverse rotations on stack A
 *        based on the given cost.
 *
 * This function performs rotations or reverse rotations on the stack `pile_a`
 * until the `cost_a` value is reduced to zero. A positive `cost_a` indicates
 * the number of forward rotations to perform, while a negative `cost_a`
 * indicates the number of reverse rotations to perform.
 *
 * @param pile_a A double pointer to the stack A.
 * @param cost_a The number of rotations (positive for forward, negative for reverse).
 *
 * @note The function assumes that `rotate_a` and `reverse_rotate_a` are
 *       properly defined elsewhere and handle the rotation logic.
 */
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

/**
 * @brief Executes a series of rotations or reverse rotations on stack B
 *        based on the given cost.
 *
 * This function performs rotations or reverse rotations on the stack `pile_b`
 * until the `cost_b` is reduced to zero. A positive `cost_b` indicates the
 * number of forward rotations to perform, while a negative `cost_b` indicates
 * the number of reverse rotations to perform.
 *
 * @param pile_b A double pointer to the stack B.
 * @param cost_b The number of rotations (positive for forward, negative for reverse).
 */
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

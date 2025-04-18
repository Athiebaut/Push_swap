/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:10:57 by alix              #+#    #+#             */
/*   Updated: 2025/04/18 02:08:36 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Returns the absolute value of the given integer.
 *
 * This function takes an integer as input and returns its absolute value.
 * If the input value is negative, it is multiplied by -1 to make it positive.
 * If the input value is already positive or zero, it is returned as is.
 *
 * @param value The integer whose absolute value is to be calculated.
 * @return The absolute value of the input integer.
 */
int	b_pos(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

/**
 * get_max - Finds the maximum value in a linked list stack.
 * 
 * @pile_a: A double pointer to the head of the stack (linked list).
 * 
 * This function iterates through the linked list stack pointed to by
 * `pile_a` and determines the maximum value stored in the nodes.
 * 
 * Return: The maximum value found in the stack.
 */
int	get_max(t_stack **pile_a)
{
	t_stack	*node;
	int		max;

	node = *pile_a;
	max = node->value;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

/**
 * @brief Initializes the position of each node in a stack.
 * 
 * This function iterates through a linked list representing a stack and assigns
 * a sequential position (starting from 0) to each node in the stack. The position
 * is stored in the `pos` field of each node.
 * 
 * @param pile A double pointer to the head of the stack (linked list).
 *             The stack is represented as a linked list of `t_stack` nodes.
 * 
 * @note The function assumes that the `t_stack` structure contains a `pos` field
 *       and a `next` pointer to the next node in the stack.
 */
void	init_position(t_stack **pile)
{
	t_stack	*node;
	int		i;

	node = *pile;
	i = 0;
	while (node)
	{
		node->pos = i;
		node = node->next;
		i++;
	}
}

/**
 * get_target - Finds the position of the target node in a stack based on rank.
 *
 * @pile_a: A double pointer to the head of the stack (linked list).
 * @rank: The rank of the current node being processed.
 * @t_rank: The rank of the current target node (initially set to a high value, e.g., INT_MAX).
 * @t_pos: The position of the current target node (initially set to an invalid or default value).
 *
 * This function determines the position of the node in the stack that has the smallest rank
 * greater than the given rank. If no such node exists, it finds the node with the smallest rank
 * in the stack. The function performs two passes through the stack:
 * 
 * 1. In the first pass, it searches for the node with the smallest rank greater than `rank`.
 * 2. If no such node is found, it performs a second pass to find the node with the smallest rank.
 *
 * Return: The position of the target node in the stack.
 */
int	get_target(t_stack **pile_a, int rank, int t_rank, int t_pos)
{
	t_stack	*node;

	node = *pile_a;
	while (node)
	{
		if (node->rank > rank && node->rank < t_rank)
		{
			t_pos = node->pos;
			t_rank = node->rank;
		}
		node = node->next;
	}
	if (t_rank != INT_MAX)
		return (t_pos);
	node = *pile_a;
	while (node)
	{
		if (node->rank < t_rank)
		{
			t_pos = node->pos;
			t_rank = node->rank;
		}
		node = node->next;
	}
	return (t_pos);
}

/**
 * @brief Executes the necessary operations to move elements between two stacks
 *        based on their respective costs.
 *
 * This function determines the optimal sequence of operations to align the
 * stacks and push an element from pile_b to pile_a. It handles cases where
 * both costs are negative (reverse rotations) or positive (rotations) and
 * performs the required operations accordingly.
 *
 * @param pile_a Pointer to the pointer of the first stack (pile_a).
 * @param pile_b Pointer to the pointer of the second stack (pile_b).
 * @param cost_a The cost associated with aligning pile_a.
 *               Positive values indicate rotations, and negative values
 *               indicate reverse rotations.
 * @param cost_b The cost associated with aligning pile_b.
 *               Positive values indicate rotations, and negative values
 *               indicate reverse rotations.
 */
void	execution(t_stack **pile_a, t_stack **pile_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		loop_reverse_rotate_both(pile_a, pile_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		loop_rotate_both(pile_a, pile_b, &cost_a, &cost_b);
	loop_rotate_a(pile_a, cost_a);
	loop_rotate_b(pile_b, cost_b);
	push_a(pile_a, pile_b, 0);
}

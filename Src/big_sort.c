/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:10:32 by alix              #+#    #+#             */
/*   Updated: 2025/04/18 02:09:28 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Determines the node in pile_b that requires the least number of moves
 *        to be sorted into pile_a and executes the corresponding operations.
 *
 * This function iterates through all the nodes in pile_b, calculating the total
 * cost (in terms of moves) for each node to be sorted into pile_a. The cost is
 * determined by summing the absolute values of cost_a and cost_b for each node.
 * The node with the minimum cost is selected, and the corresponding operations
 * are executed to move it to the correct position in pile_a.
 *
 * @param pile_a A double pointer to the head of the stack representing pile_a.
 * @param pile_b A double pointer to the head of the stack representing pile_b.
 */
void	less_moves(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	int		r_max;
	int		cost_a;
	int		cost_b;

	node = *pile_b;
	r_max = INT_MAX;
	while (node)
	{
		if ((b_pos(node->cost_a) + b_pos(node->cost_b) < r_max))
		{
			r_max = b_pos(node->cost_a) + b_pos(node->cost_b);
			cost_a = node->cost_a;
			cost_b = node->cost_b;
		}
		node = node->next;
	}
	execution(pile_a, pile_b, cost_a, cost_b);
}

/**
 * @brief Calculates the cost of moving each node in pile_b to its target position in pile_a.
 * 
 * This function iterates through all nodes in pile_b and calculates two costs for each node:
 * - cost_b: The cost of moving the node within pile_b to the top of the stack.
 * - cost_a: The cost of moving the node to its target position in pile_a.
 * 
 * The costs are calculated based on the position of the node in the stack. If the position
 * is in the second half of the stack, the cost is adjusted to reflect the shorter path
 * by moving in the reverse direction (negative cost).
 * 
 * @param pile_a A double pointer to the stack representing pile_a.
 * @param pile_b A double pointer to the stack representing pile_b.
 */
void	get_cost(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node_b;
	int		size_a;
	int		size_b;

	node_b = *pile_b;
	size_a = lst_size(pile_a);
	size_b = lst_size(pile_b);
	while (node_b)
	{
		node_b->cost_b = node_b->pos;
		if (node_b->pos > size_b / 2)
			node_b->cost_b = (size_b - node_b->pos) * -1;
		node_b->cost_a = node_b->target;
		if (node_b->target > size_a / 2)
			node_b->cost_a = (size_a - node_b->target) * -1;
		node_b = node_b->next;
	}
}

/**
 * @brief Updates the target position of each node in pile_b based on its rank
 *        and the current state of pile_a.
 *
 * This function initializes the positions of both pile_a and pile_b, then iterates
 * through each node in pile_b to calculate and assign its target position in pile_a.
 * The target position is determined by finding the most appropriate position in pile_a
 * for the current node's rank.
 *
 * @param pile_a A double pointer to the head of the stack pile_a.
 * @param pile_b A double pointer to the head of the stack pile_b.
 *
 * The function assumes that the stacks are properly initialized and that the
 * `rank` and `target` fields of the nodes in pile_b are used to determine and
 * store the target positions, respectively.
 */
void	get_position(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	int		target;

	node = *pile_b;
	init_position(pile_a);
	init_position(pile_b);
	target = 0;
	while (node)
	{
		target = get_target(pile_a, node->rank, INT_MAX, target);
		node->target = target;
		node = node->next;
	}
}

/**
 * @brief Performs the initial push operation to divide the elements of pile_a
 *        into pile_b based on their rank and size.
 *
 * This function is part of a sorting algorithm. It pushes elements from pile_a
 * to pile_b based on their rank and the size of pile_a. The goal is to split
 * the stack into smaller parts for easier sorting. The function first pushes
 * elements with a rank less than or equal to half the size of pile_a. Then, it
 * continues pushing elements until pile_a has 5 or fewer elements remaining.
 *
 * @param pile_a Pointer to the pointer of the first stack (source stack).
 * @param pile_b Pointer to the pointer of the second stack (destination stack).
 */
void	first_push(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	int		size;
	int		push;
	int		i;

	size = lst_size(pile_a);
	node = *pile_a;
	push = 0;
	i = 0;
	while (size > 10 && i++ < size && push < size / 2)
	{
		node = *pile_a;
		if (node->rank <= size / 2)
		{
			push_b(pile_a, pile_b, 0);
			push++;
		}
		else
			rotate_a(pile_a, 0);
	}
	while (size - push > 5)
	{
		push_b(pile_a, pile_b, 0);
		push++;
	}
}

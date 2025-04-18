/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:40:44 by alix              #+#    #+#             */
/*   Updated: 2025/04/18 02:16:29 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Finds the minimum value in a stack.
 *
 * This function iterates through a linked list representing a stack
 * and returns the smallest integer value found in the stack.
 *
 * @param pile A double pointer to the top of the stack (linked list).
 *             The stack is assumed to be a linked list of `t_stack` nodes.
 *
 * @return The minimum value in the stack.
 */
int	get_min(t_stack **pile)
{
	t_stack	*node;
	int		min;

	node = *pile;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

/**
 * @brief Calculates the distance (number of nodes) from the top of the stack
 *        to the node containing the specified minimum value.
 * 
 * @param pile A double pointer to the stack (linked list) to search through.
 * @param min The value to search for in the stack.
 * @return The number of nodes traversed to reach the node containing the 
 *         specified minimum value. If the value is not found, the function 
 *         returns the count of all nodes in the stack.
 */
int	get_distance(t_stack **pile, int min)
{
	t_stack	*node;
	int		count;

	node = *pile;
	count = 0;
	while (node)
	{
		if (node->value == min)
			break ;
		count++;
		node = node->next;
	}
	return (count);
}

/**
 * sort_three - Sorts a stack of three elements in ascending order.
 * 
 * @pile: A double pointer to the stack (linked list) to be sorted.
 * 
 * This function sorts a stack of exactly three elements using a series of 
 * operations such as swap, rotate, and reverse rotate. It first checks if 
 * the stack is already sorted using the `check_sorted` function. If the 
 * stack is not sorted, it performs the necessary operations based on the 
 * relative values of the three elements in the stack.
 * 
 * Operations used:
 * - `swap_a`: Swaps the first two elements of the stack.
 * - `rotate_a`: Rotates the stack so that the first element becomes the last.
 * - `reverse_rotate_a`: Rotates the stack in reverse so that the last element 
 *   becomes the first.
 * 
 * The function handles all possible permutations of three elements to ensure 
 * the stack is sorted in ascending order.
 */
void	sort_three(t_stack **pile)
{
	t_stack	*p;

	p = *pile;
	if (!check_sorted(pile))
		return ;
	if (p->value < p->next->value && p->value < p->next->next->value)
	{
		reverse_rotate_a(pile, 0);
		swap_a(pile, 0);
	}
	else if (p->value < p->next->value && p->value > p->next->next->value)
		reverse_rotate_a(pile, 0);
	else if (p->value > p->next->value && p->value < p->next->next->value)
		swap_a(pile, 0);
	else if (p->value > p->next->value && p->next->value > p->next->next->value)
	{
		rotate_a(pile, 0);
		swap_a(pile, 0);
	}
	else if (p->value > p->next->value && p->next->value < p->next->next->value)
		rotate_a(pile, 0);
}

/**
 * @brief Sorts a stack of four elements using auxiliary operations.
 *
 * This function sorts a stack of four elements by finding the minimum value,
 * calculating its distance from the top of the stack, and performing the
 * necessary rotations or reverse rotations to bring it to the top. Once the
 * minimum value is at the top, it is pushed to a secondary stack (pile_b),
 * and the remaining three elements are sorted using the `sort_three` function.
 * Finally, the minimum value is pushed back to the original stack (pile_a).
 *
 * @param pile_a A double pointer to the primary stack (stack A).
 * @param pile_b A double pointer to the auxiliary stack (stack B).
 *
 * @note This function assumes that the stack contains exactly four elements.
 *       It also assumes the existence of helper functions such as `get_min`,
 *       `get_distance`, `rotate_a`, `reverse_rotate_a`, `push_b`, `push_a`,
 *       `check_sorted`, and `sort_three`.
 */
void	sort_four(t_stack **pile_a, t_stack **pile_b)
{
	int	min;
	int	distance;

	min = get_min(pile_a);
	distance = get_distance(pile_a, min);
	if (distance == 1)
		rotate_a(pile_a, 0);
	else if (distance == 2)
	{
		rotate_a(pile_a, 0);
		rotate_a(pile_a, 0);
	}
	else if (distance == 3)
		reverse_rotate_a(pile_a, 0);
	if (!check_sorted(pile_a))
		return ;
	push_b(pile_a, pile_b, 0);
	sort_three(pile_a);
	push_a(pile_a, pile_b, 0);
}

/**
 * @brief Sorts a stack of five elements using auxiliary operations.
 *
 * This function sorts a stack of five elements by finding the minimum value,
 * calculating its distance from the top of the stack, and performing the
 * appropriate rotations or reverse rotations to bring it to the top. Once the
 * minimum value is at the top, it is pushed to a secondary stack (pile_b).
 * The function then recursively sorts the remaining four elements in the stack
 * using the `sort_four` function and finally pushes the minimum value back to
 * the original stack (pile_a).
 *
 * @param pile_a A double pointer to the primary stack (pile_a).
 * @param pile_b A double pointer to the auxiliary stack (pile_b).
 */
void	sort_five(t_stack **pile_a, t_stack **pile_b)
{
	int	min;
	int	distance;

	min = get_min(pile_a);
	distance = get_distance(pile_a, min);
	if (distance == 1)
		rotate_a(pile_a, 0);
	else if (distance == 2)
	{
		rotate_a(pile_a, 0);
		rotate_a(pile_a, 0);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(pile_a, 0);
		reverse_rotate_a(pile_a, 0);
	}
	else if (distance == 4)
		reverse_rotate_a(pile_a, 0);
	if (!check_sorted(pile_a))
		return ;
	push_b(pile_a, pile_b, 0);
	sort_four(pile_a, pile_b);
	push_a(pile_a, pile_b, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:09:43 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:17:44 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Finds the position of the node with the lowest rank (rank == 0) in a stack.
 *
 * This function iterates through the linked list representing the stack and 
 * returns the position (0-based index) of the first node where the rank is 0.
 *
 * @param pile_a A double pointer to the head of the stack (linked list).
 *               The stack is represented as a linked list of `t_stack` nodes.
 *
 * @return The 0-based position of the node with rank 0 in the stack.
 *         If no such node exists, the behavior is undefined.
 */
int	lowest_position(t_stack **pile_a)
{
	t_stack	*node;
	int		pos;

	node = *pile_a;
	pos = 0;
	while (node->rank != 0)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

/**
 * @brief Performs the final sorting operation on stack `pile_a` by rotating
 *        it to bring the lowest element to the top.
 *
 * This function determines the position of the lowest element in the stack
 * and rotates the stack either upwards or downwards to position the lowest
 * element at the top. The direction of rotation is chosen based on the
 * position of the lowest element relative to the size of the stack to
 * minimize the number of operations.
 *
 * @param pile_a A double pointer to the stack `pile_a` (of type `t_stack`).
 *               This stack will be modified in place.
 *
 * Helper Functions:
 * - `lst_size(t_stack **pile_a)`: Returns the size of the stack.
 * - `lowest_position(t_stack **pile_a)`: Returns the position of the lowest
 *   element in the stack.
 * - `rotate_a(t_stack **pile_a, int flag)`: Rotates the stack upwards.
 * - `reverse_rotate_a(t_stack **pile_a, int flag)`: Rotates the stack
 *   downwards.
 */
void	final_sort(t_stack **pile_a)
{
	int	lowest;
	int	size;

	size = lst_size(pile_a);
	lowest = lowest_position(pile_a);
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			reverse_rotate_a(pile_a, 0);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			rotate_a(pile_a, 0);
			lowest--;
		}
	}
}

/**
 * @brief Sorts a stack using a simple sorting algorithm based on the size of the stack.
 * 
 * This function determines the size of the stack and applies the appropriate sorting
 * algorithm for stacks of size 2, 3, 4, or 5. If the stack size is less than 2, no
 * sorting is performed.
 * 
 * @param pile_a A double pointer to the primary stack (t_stack **).
 * @param pile_b A double pointer to the auxiliary stack (t_stack **), used for sorting
 *               stacks of size 4 or 5.
 * 
 * @note The function assumes that the stack size is between 0 and 5. For larger stack
 *       sizes, additional sorting logic would need to be implemented.
 */
void	simple_sort(t_stack **pile_a, t_stack **pile_b)
{
	int	size;

	size = lst_size(pile_a);
	if (size < 2)
		return ;
	if (size == 2)
		swap_a(pile_a, 0);
	else if (size == 3)
		sort_three(pile_a);
	else if (size == 4)
		sort_four(pile_a, pile_b);
	else if (size == 5)
		sort_five(pile_a, pile_b);
}

/**
 * @brief Sorts a stack using a complex sorting algorithm designed for larger datasets.
 * 
 * This function performs a multi-step sorting process on two stacks (`pile_a` and `pile_b`):
 * 1. Moves an initial set of elements from `pile_a` to `pile_b` using `first_push`.
 * 2. Sorts the remaining elements in `pile_a` using `simple_sort`.
 * 3. Iteratively moves elements back from `pile_b` to `pile_a`:
 *    - Calculates the optimal position for each element in `pile_a` and `pile_b` using `get_position`.
 *    - Computes the cost of moving each element using `get_cost`.
 *    - Moves the element with the least cost back to `pile_a` using `less_moves`.
 * 4. Ensures the final stack (`pile_a`) is sorted and adjusts its order if necessary using `final_sort`.
 * 
 * @param pile_a Pointer to the pointer of the first stack (stack A).
 * @param pile_b Pointer to the pointer of the second stack (stack B).
 */
void	big_sort(t_stack **pile_a, t_stack **pile_b)
{
	first_push(pile_a, pile_b);
	simple_sort(pile_a, pile_b);
	while (*pile_b)
	{
		get_position(pile_a, pile_b);
		get_cost(pile_a, pile_b);
		less_moves(pile_a, pile_b);
	}
	if (check_sorted(pile_a))
		final_sort(pile_a);
}

/**
 * @brief Sorts the elements in the given stacks using an appropriate sorting algorithm.
 * 
 * This function determines the size of the stack `pile_a` and chooses the sorting
 * algorithm accordingly. If the size of `pile_a` is 5 or less, it uses `simple_sort`.
 * Otherwise, it uses `big_sort` for larger stacks.
 * 
 * @param pile_a A double pointer to the first stack (stack A) to be sorted.
 * @param pile_b A double pointer to the second stack (stack B) used as auxiliary storage.
 */
void	sort(t_stack **pile_a, t_stack **pile_b)
{
	if (lst_size(pile_a) <= 5)
		simple_sort(pile_a, pile_b);
	else
		big_sort(pile_a, pile_b);
}

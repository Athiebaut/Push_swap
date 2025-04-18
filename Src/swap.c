/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:04:40 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:18:30 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * This function swaps the values and ranks of the first two elements
 * in the given stack. It assumes that the stack has at least two elements.
 *
 * @param pile A double pointer to the stack (t_stack **).
 *             The stack is expected to be a linked list where each node
 *             contains a value and a rank.
 *
 * @return Always returns 0.
 */
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

/**
 * @brief Swaps the first two elements of stack 'a' if there are at least two elements.
 * 
 * @param pile A double pointer to the stack (t_stack) to be modified.
 * @param bonus An integer flag; if set to 0, the function prints "sa\n".
 * @return int Returns 0 on success, -1 if the swap operation fails, or 0 if the stack has fewer than two elements.
 * 
 * @note The function checks if the stack is valid and contains at least two elements before performing the swap.
 *       If the 'bonus' parameter is 0, it outputs the operation name ("sa") to the standard output.
 */
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

/**
 * @brief Swaps the first two elements of stack 'b' if there are at least two elements.
 * 
 * @param pile A pointer to the stack 'b' (a pointer to a pointer to the stack structure).
 * @param bonus An integer flag to suppress output. If set to 0, the function prints "sb".
 * 
 * @return Returns 0 on success, -1 if the swap operation fails, or 0 if the stack has fewer than two elements.
 * 
 * @note The function uses `lst_size` to check the size of the stack and `swap` to perform the swap operation.
 */
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

/**
 * @brief Performs a swap operation on both stacks (pile_a and pile_b) if they
 *        contain more than one element each. Optionally prints "ss" if the 
 *        bonus flag is not set.
 * 
 * @param pile_a Pointer to the first stack.
 * @param pile_b Pointer to the second stack.
 * @param bonus  Flag to suppress output. If set to 0, "ss" is printed.
 * 
 * @return Always returns 0.
 */
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

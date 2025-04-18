/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:30 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:13:33 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * push - Moves the top element from one stack to another.
 *
 * @pile_from: A double pointer to the source stack (stack to pop from).
 * @pile_to: A double pointer to the destination stack (stack to push to).
 *
 * This function removes the top element from the stack pointed to by
 * @pile_from and pushes it onto the stack pointed to by @pile_to. If
 * @pile_from is empty (NULL), the function does nothing and returns 0.
 *
 * Return: Always returns 0.
 */
static int	push(t_stack **pile_from, t_stack **pile_to)
{
	t_stack	*node;
	t_stack	*head_to;
	t_stack	*head_from;

	if (!pile_from)
		return (0);
	head_to = *pile_to;
	head_from = *pile_from;
	node = *pile_from;
	*pile_from = head_from->next;
	if (!head_to)
	{
		head_to = node;
		head_to->next = NULL;
		*pile_to = head_to;
	}
	else
	{
		node->next = head_to;
		*pile_to = node;
	}
	return (0);
}

/**
 * push_a - Moves the top element from stack B to stack A.
 * 
 * @pile_a: A double pointer to the top of stack A.
 * @pile_b: A double pointer to the top of stack B.
 * @bonus: An integer flag to suppress output if set to a non-zero value.
 * 
 * This function transfers the top element of stack B to stack A. If stack B
 * is empty or invalid, the function returns 0. If the push operation fails,
 * it returns -1. When the operation is successful and the bonus flag is not
 * set, the function prints "pa" to indicate the operation.
 * 
 * Return: 0 on success, -1 on failure.
 */
int	push_a(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (!pile_b || lst_size(pile_b) == 0)
		return (0);
	if (push(pile_b, pile_a) == -1)
		return (-1);
	if (!bonus)
		ft_printf("pa\n");
	return (0);
}

/**
 * push_b - Moves the top element from stack A to stack B.
 * 
 * @pile_a: A double pointer to the top of stack A.
 * @pile_b: A double pointer to the top of stack B.
 * @bonus: An integer flag to suppress output if set to a non-zero value.
 * 
 * This function checks if stack A is non-empty and then moves the top
 * element from stack A to stack B. If the operation is successful and
 * the bonus flag is not set, it prints "pb" to the standard output.
 * 
 * Return:
 *   - 0 on success.
 *   - -1 if the push operation fails.
 *   - 0 if stack A is empty or invalid.
 */
int	push_b(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (!pile_a || lst_size(pile_a) == 0)
		return (0);
	if (push(pile_a, pile_b) == -1)
		return (-1);
	if (!bonus)
		ft_printf("pb\n");
	return (0);
}

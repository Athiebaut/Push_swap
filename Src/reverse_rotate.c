/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:26 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:14:34 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * reverse_rotate - Moves the last element of a stack to the top.
 * 
 * @pile: A double pointer to the stack (linked list) to be modified.
 * 
 * This function performs a reverse rotation on the stack. It takes the last
 * element of the stack, removes it from its current position, and places it
 * at the top of the stack. The stack is represented as a linked list where
 * each node points to the next node.
 * 
 * Return: Always returns 0.
 */
int	reverse_rotate(t_stack **pile)
{
	t_stack	*last;
	t_stack	*first;

	first = *pile;
	last = lstlast(*pile);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *pile;
	*pile = last;
	return (0);
}

/**
 * reverse_rotate_a - Performs a reverse rotation on stack 'a'.
 * 
 * @pile: A double pointer to the stack (t_stack) to be reverse rotated.
 * @bonus: An integer flag to determine whether to print the operation.
 *         If bonus is 0, the operation "rra" is printed.
 * 
 * This function checks if the stack is valid and contains at least two
 * elements. If so, it performs a reverse rotation on the stack by calling
 * the reverse_rotate function. If the reverse rotation fails, it returns -1.
 * Otherwise, it prints "rra" if the bonus flag is not set and returns 0.
 * 
 * Return: 
 * - 0 on success.
 * - -1 if the reverse rotation fails.
 */
int	reverse_rotate_a(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (reverse_rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("rra\n");
	return (0);
}

/**
 * reverse_rotate_b - Performs a reverse rotation on stack B.
 *
 * @pile: A double pointer to the stack (t_stack) to be reverse rotated.
 * @bonus: An integer flag to determine whether to print the operation.
 *         If bonus is 0, the function prints "rrb\n".
 *
 * Return: 
 *   - 0 on success.
 *   - -1 if the reverse_rotate function fails.
 *   - 0 if the stack is NULL or contains fewer than 2 elements.
 *
 * Description:
 * This function checks if the stack is valid and contains at least two elements.
 * It then calls the reverse_rotate function to perform the reverse rotation.
 * If the bonus flag is not set, it outputs the operation name ("rrb\n").
 */
int	reverse_rotate_b(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (reverse_rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("rrb\n");
	return (0);
}

/**
 * reverse_rotate_r - Performs a reverse rotation on two stacks and optionally
 *                    prints the operation.
 *
 * @pile_a: A double pointer to the first stack (stack A).
 * @pile_b: A double pointer to the second stack (stack B).
 * @bonus: An integer flag to determine whether to print the operation.
 *         If bonus is 0, the operation "rrr" will be printed.
 *
 * Description:
 * This function performs a reverse rotation on both stack A and stack B
 * if their respective sizes are greater than 1. A reverse rotation moves
 * the last element of the stack to the top. If the bonus flag is set to 0,
 * the function will print "rrr\n" to indicate the operation performed.
 *
 * Return:
 * Always returns 0.
 */
int	reverse_rotate_r(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (lst_size(pile_a) > 1)
		reverse_rotate(pile_a);
	if (lst_size(pile_b) > 1)
		reverse_rotate(pile_b);
	if (!bonus)
		ft_printf("rrr\n");
	return (0);
}

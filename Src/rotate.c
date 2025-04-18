/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:19 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:15:26 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Rotates a stack by moving the first element to the end.
 *
 * This function takes a pointer to a stack (linked list) and performs a 
 * rotation operation. The first element of the stack is moved to the 
 * end of the stack, and the rest of the elements are shifted up by one position.
 *
 * @param pile A double pointer to the stack (linked list) to be rotated.
 *             The stack is represented as a linked list of type `t_stack`.
 *
 * @return Always returns 0.
 *
 * @note The function assumes that the stack has at least one element.
 *       If the stack is empty or contains only one element, the behavior 
 *       may be undefined.
 */
static int	rotate(t_stack **pile)
{
	t_stack	*first;
	t_stack	*last;

	first = *pile;
	last = lstlast(*pile);
	*pile = first->next;
	last->next = first;
	first->next = NULL;
	return (0);
}

/**
 * @brief Rotates the elements of stack 'a' upwards by one position.
 * 
 * This function performs a rotation operation on the given stack 'a' (pile),
 * moving the first element to the end of the stack. If the stack has fewer
 * than two elements or if the rotation fails, the function returns an error.
 * Optionally, it prints the operation name ("ra") if the bonus flag is not set.
 * 
 * @param pile A pointer to the stack 'a' to be rotated.
 * @param bonus A flag to suppress printing the operation name if set.
 *              If bonus is 0, the function prints "ra\n".
 * 
 * @return int Returns 0 on success, -1 if the rotation fails, or 0 if the stack
 *             has fewer than two elements.
 */
int	rotate_a(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("ra\n");
	return (0);
}

/**
 * @brief Rotates the stack 'pile' by moving the first element to the end.
 *
 * This function performs a rotation operation on the stack pointed to by 'pile'.
 * If the stack has fewer than two elements or if the 'pile' pointer is NULL, 
 * the function returns 0. If the rotation operation fails, it returns -1.
 * If the 'bonus' parameter is set to 0, the function prints "rb" to indicate
 * the rotation operation.
 *
 * @param pile A double pointer to the stack to be rotated.
 * @param bonus A flag to control whether the operation message is printed (0 to print, non-zero to suppress).
 * @return int Returns 0 on success, -1 on failure, or 0 if the stack is too small to rotate.
 */
int	rotate_b(t_stack **pile, int bonus)
{
	if (!pile || lst_size(pile) < 2)
		return (0);
	if (rotate(pile) == -1)
		return (-1);
	if (!bonus)
		ft_printf("rb\n");
	return (0);
}

/**
 * rotate_r - Rotates both stacks (pile_a and pile_b) simultaneously.
 * 
 * @pile_a: A pointer to the first stack (t_stack **).
 * @pile_b: A pointer to the second stack (t_stack **).
 * @bonus: An integer flag to determine if the operation should print "rr".
 *         If bonus is 0, the function will print "rr\n".
 * 
 * This function checks if each stack has more than one element. If so, it
 * performs a rotation operation on the respective stack. The rotation
 * operation moves the first element of the stack to the end of the stack.
 * 
 * Return: Always returns 0.
 */
int	rotate_r(t_stack **pile_a, t_stack **pile_b, int bonus)
{
	if (lst_size(pile_a) > 1)
		rotate(pile_a);
	if (lst_size(pile_b) > 1)
		rotate(pile_b);
	if (!bonus)
		ft_printf("rr\n");
	return (0);
}

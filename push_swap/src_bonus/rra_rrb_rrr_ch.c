/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_ch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:43:31 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 14:21:19 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_com(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	if (!(*stack) || !((*stack)->next))
		error ();
	lst = *stack;
	tmp = stk_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
}

void	rrb_com(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	if (!(*stack) || !((*stack)->next))
		error ();
	lst = *stack;
	tmp = stk_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
}

void	rrr_com(t_stack_list **stack, t_stack_list **stack2)
{
	rra_com(stack);
	rra_com(stack2);
}

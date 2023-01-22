/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:48:08 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 14:32:00 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	lst = *stack;
	tmp = stk_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	lst = *stack;
	tmp = stk_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_list **stack, t_stack_list **stack2)
{
	t_stack_list	*tmp;
	t_stack_list	*lst;

	lst = *stack;
	tmp = stk_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	lst = *stack2;
	tmp = stk_lstlast(*stack2);
	while ((*stack2)->next->next)
		*stack = (*stack2)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack2)->next = 0;
	*stack2 = tmp;
	write(1, "rrr\n", 4);
}

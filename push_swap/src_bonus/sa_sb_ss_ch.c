/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_ch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:43:40 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 13:43:45 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_com(t_stack_list	**stack)
{
	t_stack_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		error ();
	tmp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = tmp;
}

void	sb_com(t_stack_list	**stack)
{
	t_stack_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		error ();
	tmp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = tmp;
}

void	ss_com(t_stack_list	**stack1, t_stack_list **stack2)
{
	sa_com(stack1);
	sa_com(stack2);
}

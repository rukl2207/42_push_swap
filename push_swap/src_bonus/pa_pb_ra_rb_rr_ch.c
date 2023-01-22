/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_ra_rb_rr_ch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:43:20 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 14:20:11 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb_com(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*tmp_a;
	t_stack_list	*tmp_b;

	if (!*b)
		pb_com2(a, b);
	else
	{
		tmp_a = NULL;
		tmp_b = (*b);
		if (*a)
			tmp_a = (*a)->next;
		else
			error();
		*b = *a;
		(*b)->next = tmp_b;
		tmp_b->prev = (*b);
		*a = tmp_a;
		if (*a)
			(*a)->prev = 0;
	}
}

void	pa_com(t_stack_list **b, t_stack_list **a)
{
	t_stack_list	*tmp_b;
	t_stack_list	*tmp_a;

	if (!*a)
		pa_com2(b, a);
	else if (!(*b)->next)
	{
		tmp_a = (*a);
		tmp_b = NULL;
		*a = *b;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
		*b = tmp_b;
	}
	else
	{
		tmp_a = (*a);
		tmp_b = (*b)->next;
		*a = *b;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
		*b = tmp_b;
		(*b)->prev = 0;
	}
}

void	ra_com(t_stack_list **stack)
{
	t_stack_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		error ();
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = stk_lstlast(*stack);
	stk_lstlast(*stack)->next = tmp;
}

void	rb_com(t_stack_list **stack)
{
	t_stack_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		error ();
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = stk_lstlast(*stack);
	stk_lstlast(*stack)->next = tmp;
}

void	rr_com(t_stack_list **stack, t_stack_list **stack2)
{
	ra_com(stack);
	ra_com(stack2);
}

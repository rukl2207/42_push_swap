/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:47:58 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/20 12:37:42 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*tmp_a;
	t_stack_list	*tmp_b;

	if (!*b)
	{
		tmp_a = (*a)->next;
		*b = *a;
		*a = tmp_a;
		(*a)->prev = 0;
		(*b)->next = 0;
	}
	else
	{
		tmp_b = (*b);
		tmp_a = (*a)->next;
		*b = *a;
		(*b)->next = tmp_b;
		tmp_b->prev = (*b);
		*a = tmp_a;
		(*a)->prev = 0;
	}
	write(1, "pb\n", 3);
}

void	pa(t_stack_list **b, t_stack_list **a)
{
	t_stack_list	*tmp_b;
	t_stack_list	*tmp_a;

	if (!(*b)->next)
	{
		tmp_a = (*a);
		tmp_b = (*b)->next;
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
	write(1, "pa\n", 3);
}

void	ra(t_stack_list **stack)
{
	t_stack_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = stk_lstlast(*stack);
	stk_lstlast(*stack)->next = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack_list **stack)
{
	t_stack_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = stk_lstlast(*stack);
	stk_lstlast(*stack)->next = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack_list **stack, t_stack_list **stack2)
{
	t_stack_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = stk_lstlast(*stack);
	stk_lstlast(*stack)->next = tmp;
	tmp = *stack2;
	*stack2 = tmp->next;
	(*stack2)->prev = 0;
	tmp->next = 0;
	tmp->prev = stk_lstlast(*stack2);
	stk_lstlast(*stack2)->next = tmp;
	write(1, "rr\n", 3);
}

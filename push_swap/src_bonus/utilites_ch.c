/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites_ch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:44:05 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 13:44:18 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_com2(t_stack_list **b, t_stack_list **a)
{
	t_stack_list	*tmp_b;

	tmp_b = (*b)->next;
	*a = *b;
	*b = tmp_b;
	(*b)->prev = 0;
	(*a)->next = 0;
}

void	pa_com_check(t_stack_list **b, t_stack_list **a)
{
	if (!*b)
		error ();
	else
		pa_com(b, a);
}

void	pb_com2(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*tmp_a;

	tmp_a = (*a)->next;
	*b = *a;
	*a = tmp_a;
	(*a)->prev = 0;
	(*b)->next = 0;
}

int	error(void)
{
	ft_putstr_fd("\33[31mError\33[0m\n", 1);
	exit(0);
}

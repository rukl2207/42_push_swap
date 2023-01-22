/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:48:18 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 13:48:23 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_min_b(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	if ((*a)->index == param_t->min)
	{
		ra(a);
		param_t->min++;
		check_min(a, b, param_t);
	}
	else if (check_len_list(b) > 0 && (*b)->index == param_t->min)
	{
		(*b)->flag = -1;
		pa(b, a);
		ra(a);
		param_t->min++;
		check_min(a, b, param_t);
	}
	else if ((*a)->next->index == param_t->min && check_len_list(b) > 1
		&& (*b)->next->index == param_t->min + 1)
	{
		ss(a, b);
		(*a)->flag = -1;
		ra(a);
		param_t->min++;
		check_min(a, b, param_t);
	}
}

void	check_min(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	if ((*a)->index == param_t->min)
		check_min_b(a, b, param_t);
	else if (check_len_list(b) > 0 && (*b)->index == param_t->min)
		check_min_b(a, b, param_t);
	else if ((*a)->next->index == param_t->min && check_len_list(b) > 1
		&& (*b)->next->index == param_t->min + 1)
		check_min_b(a, b, param_t);
	else if ((*a)->next->index == param_t->min)
	{
		sa(a);
		(*a)->flag = -1;
		ra(a);
		param_t->min++;
		check_min(a, b, param_t);
	}
	else if (check_len_list(b) > 2 && check_last(b)->index == param_t->min)
	{
		rrb(b);
		pa(b, a);
		(*a)->flag = -1;
		ra(a);
		param_t->min++;
		check_min(a, b, param_t);
	}
}

void	in_b_dop(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	if ((*a)->index == param_t->min)
	{
		(*a)->flag = -1;
		ra(a);
		param_t->min++;
		check_min(a, b, param_t);
	}
	else
	{
		pb(a, b);
		check_min(a, b, param_t);
	}
}

void	in_rr(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	if (check_len_list(b) > 1 && (*b)->index < (param_t->mid / 2))
		rr(a, b);
	else
		ra(a);
}

void	in_b_first(t_stack_list **a, t_stack_list **b, t_list_param *param_t)
{
	int	i;
	int	len;

	i = -1;
	len = check_len_list(a);
	while (++i < len)
	{
		if ((*a)->index <= param_t->mid)
		{
			pb(a, b);
		}
		else
			in_rr(a, b, param_t);
	}
	ft_set_param_flag(param_t);
}

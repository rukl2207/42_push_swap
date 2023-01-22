/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:45:44 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 14:18:40 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_leaks(t_stack_list *lst)
{
	t_stack_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

t_stack_list	*stk_lstlast(t_stack_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack_list	*stk_lstfirst(t_stack_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_stack_list	*stk_lstnew(int num)
{
	t_stack_list	*new;

	new = malloc(sizeof(t_stack_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->flag = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stk_lstadd_back(t_stack_list **lst, t_stack_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
	{
		stk_lstlast(*lst)->next = new;
		new->prev = *lst;
	}
	else
		*lst = new;
}

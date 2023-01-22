/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:46:05 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 14:23:44 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	atoi_swap(char *str)
{
	int			i;
	int			is_neg;
	long int	res;

	i = 0;
	res = 0;
	is_neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			is_neg *= -1;
	}
	if (!ft_isdigit(str[i]))
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + is_neg * (str[i++] - 48);
		if (res < -2147483648 || res > 2147483647)
			error();
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		error();
	return (res);
}

int	*sorting_arr_int(int *arr, int count)
{
	int	tmp;
	int	i;
	int	k;

	i = -1;
	while (++i < count)
	{
		k = 1;
		while ((i + k) < count)
		{
			if (arr[i] > arr[i + k])
			{
				tmp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = tmp;
			}
			else if (arr[i] == arr[i + k])
				error();
			k++;
		}
	}
	return (arr);
}

t_stack_list	*creat_list(int *arr_int, int count)
{
	t_stack_list	*ret;
	int				i;

	i = -1;
	ret = NULL;
	while (++i < count)
	{
		stk_lstadd_back(&ret, stk_lstnew(arr_int[i]));
	}
	return (ret);
}

int	*full_int(t_stack_list	**stack1, char **str, int count)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * count + 2);
	if (!ret)
		return (0);
	i = 0;
	while (i < count)
	{
		ret[i] = atoi_swap(str[i]);
		i++;
	}
	ret[i] = '\0';
	*stack1 = creat_list(ret, count);
	ret = sorting_arr_int(ret, count);
	return (ret);
}

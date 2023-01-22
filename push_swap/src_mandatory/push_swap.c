/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:48:03 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 18:03:22 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error(void)
{
	ft_putstr_fd("\33[31mError\33[0m\n", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	char			*str;
	char			**str_arr;
	int				*array_int;
	int				count_arg;
	t_stack_list	*stack1;

	if (argc > 1)
	{
		str = ft_join(argv + 1);
		str_arr = ft_split(str, ' ');
		count_arg = ft_count_arg(str, ' ');
		array_int = full_int(&stack1, str_arr, count_arg);
		free(str);
		leaks(str_arr);
		main_sorting(&stack1, count_arg, array_int);
		ft_lst_leaks(stack1);
		free(array_int);
	}
	return (0);
}

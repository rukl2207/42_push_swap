/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:40:17 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 14:42:20 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack_list
{
	int					num;
	int					index;
	int					flag;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
}	t_stack_list;

typedef struct s_list_param
{
	int				min;
	int				max;
	int				mid;
	int				flag;
}	t_list_param;

/*-------------main.c---------------*/

int				error(void);

/*----------normalize.c-------------*/

int				atoi_swap(char *str);
int				*sorting_arr_int(int *arr, int count);
int				*full_int(t_stack_list	**stack1, char **str, int count);
t_stack_list	*creat_list(int *arr_int, int count);

/*------------input_str.c------------*/

char			*ft_join(char **str);
int				ft_count_arg(char const *s, char c);
void			leaks(char **res);

/*------------list.c-----------------*/

void			ft_lst_leaks(t_stack_list *lst);
t_stack_list	*stk_lstlast(t_stack_list *lst);
t_stack_list	*stk_lstfirst(t_stack_list *lst);
t_stack_list	*stk_lstnew(int num);
void			stk_lstadd_back(t_stack_list **lst, t_stack_list *new);

/*------------list_2.c-----------------*/

int				check_sort_list(t_stack_list **stack, int count);
int				check_len_list(t_stack_list **stack);
void			set_index(t_stack_list *stack, int *arr, int count);
int				check_position_list(t_stack_list **stack, t_stack_list *list);
t_stack_list	*check_min_list(t_stack_list **stack);

/*------------list_3.c-----------------*/

t_stack_list	*check_max_list(t_stack_list **stack);
void			ft_set_stack_param(t_list_param *new, t_stack_list **stack);
void			ft_set_param_flag(t_list_param *param);
t_list_param	*ft_lstnew_param(void);
t_stack_list	*check_last(t_stack_list **stack);

/*------------main_sorting.c-----------*/

void			ft_sorting_2(t_stack_list **stack1);
void			ft_sorting_3(t_stack_list **stack1);
void			min_in_b(t_stack_list **a, t_stack_list **b);
void			ft_sorting_5(t_stack_list **stack1, t_stack_list \
					**stack2, int count);
void			main_sorting(t_stack_list **stack1, int count, int *arr_int);

/*------------pa_pb_ra_rb_rr.c----------*/

void			pb(t_stack_list **a, t_stack_list **b);
void			pa(t_stack_list **b, t_stack_list **a);
void			ra(t_stack_list **stack);
void			rb(t_stack_list **stack);
void			rr(t_stack_list **stack, t_stack_list **stack2);

/*--------------rra_rrb_rrr.c-----------*/

void			rra(t_stack_list **stack);
void			rrb(t_stack_list **stack);
void			rrr(t_stack_list **stack, t_stack_list **stack2);

/*----------------sa_sb_ss.c------------*/

void			sa(t_stack_list	**stack);
void			sb(t_stack_list	**stack);
void			ss(t_stack_list	**stack1, t_stack_list **stack2);

/*-------------sorting_utilus.c---------*/

void			check_min_b(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);
void			check_min(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);
void			in_b_dop(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);
void			in_rr(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);
void			in_b_first(t_stack_list **a, t_stack_list **b,
					t_list_param *param_t);

/*-------------hard_sorting.c---------*/

void			in_a(t_stack_list **a, t_stack_list **b, t_list_param *param_t);
void			in_b(t_stack_list **a, t_stack_list **b, t_list_param *param_t);
void			progress_sorting(t_stack_list **a, t_stack_list **b, int count);

/*--------------CHECKER---------------*/

int				get_next_line(char **line);
void			command2(t_stack_list **a, t_stack_list **b, char *str);
void			command(t_stack_list **a, t_stack_list **b, char *str);
void			main_checker(t_stack_list **a, int count, int *arr_int);

/*--------pa_pb_ra_rb_rr_ch.c---------*/

void			pb_com(t_stack_list **a, t_stack_list **b);
void			pa_com(t_stack_list **b, t_stack_list **a);
void			ra_com(t_stack_list **stack);
void			rb_com(t_stack_list **stack);
void			rr_com(t_stack_list **stack, t_stack_list **stack2);

/*--------rra_rrb_rrr_ch.c---------*/

void			rra_com(t_stack_list **stack);
void			rrb_com(t_stack_list **stack);
void			rrr_com(t_stack_list **stack, t_stack_list **stack2);

/*--------sa_sb_ss_ch.c------------*/

void			sa_com(t_stack_list	**stack);
void			sb_com(t_stack_list	**stack);
void			ss_com(t_stack_list	**stack1, t_stack_list **stack2);

/*---------utilites.c--------------*/

void			pa_com2(t_stack_list **b, t_stack_list **a);
void			pb_com2(t_stack_list **a, t_stack_list **b);
void			pa_com_check(t_stack_list **a, t_stack_list **b);

#endif

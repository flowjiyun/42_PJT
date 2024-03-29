/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/16 23:39:43 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tool
{
	t_list_info	*a_info;
	t_list_info	*b_info;
	int			*answer;
}	t_tool;

void	init_list(t_list_info *list_info, int argc, char **argv);
void	init_list_info(t_list_info *a_info, t_list_info *b_info);
int		*init_ordered_array(t_list_info *list_info);
void	parse_list(t_list_info *list_info, int	*arr);
void	init_tool(t_tool *tool, t_list_info *a, t_list_info *b, int *answer);
void	push_swap(t_tool *tool);
void	sort_stack_a(t_tool *tool, int len, int pre_median);
void	sort_stack_b(t_tool *tool, int len, int pre_median);
void	sort_unit_three_a(t_tool *tool, int len);
void	sort_unit_three_b(t_tool *tool, int len);
void	sort_unit_three_a_extra(t_tool *tool, int len);
void	sort_unit_three_b_extra(t_tool *tool, int len);
void	sa(t_tool *tool);
void	sb(t_tool *tool);
void	pa(t_tool *tool);
void	pb(t_tool *tool);
void	ra(t_tool *tool);
void	rb(t_tool *tool);
void	rra(t_tool *tool);
void	rrb(t_tool *tool);
int		get_max_b(t_tool *tool, int len);
int		get_min_b(t_tool *tool, int len);
int		get_max_a(t_tool *tool, int len);
int		get_min_a(t_tool *tool, int len);

#endif

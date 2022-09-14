/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/14 11:24:57 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>

void	init_list(t_list_info *list_info, int argc, char **argv);
void	init_list_info(t_list_info *list_info);
int		*init_ordered_array(t_list_info *list_info);
void	parse_list(t_list_info *list_info, int	*arr);
void	sort_a(t_list_info *a_info, t_list_info *b_info, int median);
void	sa(t_list_info *list_info);
void	sb(t_list_info *list_info);
void	pa(t_list_info *b_info, t_list_info *a_info);
void	pb(t_list_info *a_info, t_list_info *b_info);
void	ra(t_list_info *list_info);
void	rb(t_list_info *list_info);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/08 11:47:05 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>

void	init_list(t_list_info *list_info, int argc, char **argv);
void	init_list_info(t_list_info *list_info);
int		check_valid_input(int argc, char **argv);
void	sa(t_list_info *list_info);
void	sb(t_list_info *list_info);
void	pa(t_list_info *b_info, t_list_info *a_info);
void	pb(t_list_info *a_info, t_list_info *b_info);

#endif

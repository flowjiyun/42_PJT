/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/05 16:07:42 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>

void	init_list(t_list_info *list_info, int argc, char **argv);
int		check_valid_input(int argc, char **argv);
void	sa(t_list_info *list_info);
void	sb(t_list_info *list_info);

#endif

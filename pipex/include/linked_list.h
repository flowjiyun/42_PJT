/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:36:52 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/30 16:10:37 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;	
	void			*content;
}	t_list;

typedef struct s_list_info
{
	struct s_list	*head;
	struct s_list	*tail;
	int				len;
}	t_list_info;

t_list	*make_node(void *content);
void	pop_front(t_list_info *list_info);
void	pop_back(t_list_info *list_info);
void	push_front(t_list_info *list_info, t_list *node);
void	push_back(t_list_info *list_info, t_list *node);
void	clear_list(t_list_info *list_info);
void	swap_node(t_list_info *list_info);

#endif
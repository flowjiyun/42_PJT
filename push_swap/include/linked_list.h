/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:36:52 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/06 15:58:31 by jiyun            ###   ########.fr       */
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
	int				data;
}	t_list;

typedef struct s_list_info
{
	struct s_list	*head;
	struct s_list	*tail;
	int				len;
}	t_list_info;

typedef struct s_node_info
{
	struct s_list	*cursor;
	struct s_list	*cursor_r;
	struct s_list	*cursor_rr;
	struct s_list	*cursor_l;
	struct s_list	*cursor_ll;	
}	t_node_info;

t_list	*make_node(int data);
void	pop_front(t_list_info *list_info);
void	pop_back(t_list_info *list_info);
void	push_front(t_list_info *list_info, t_list *node);
void	push_back(t_list_info *list_info, t_list *node);
void	print_list(t_list_info *list_info);
void	clear_list(t_list_info *list_info);
void	swap_node_right(t_list *node, t_list_info *list_info);
void	swap_node_left(t_list *node, t_list_info *list_info);

#endif
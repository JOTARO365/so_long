/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:32:02 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get_next_line_utils.c — Helper functions สำหรับจัดการ fd node list
**
** find_fd_node(lst, fd):
**   ค้นหา node ที่ตรงกับ fd ใน linked list
**   ถ้าไม่พบ: สร้าง node ใหม่ (malloc) แล้ว prepend ลง list
**   คืน pointer ของ node (ใหม่หรือเก่า)
**
** remove_fd_node(lst, fd):
**   ลบ node ของ fd ออกจาก list และ free memory
**   ใช้เมื่อ fd ปิดหรือ read ถึง EOF
*/

#include "get_next_line.h"

t_gnl_node	*find_fd_node(t_gnl_node **lst, int fd)
{
	t_gnl_node	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = (t_gnl_node *)malloc(sizeof(t_gnl_node));
	if (!cur)
		return (NULL);
	cur->fd = fd;
	cur->buf = NULL;
	cur->next = *lst;
	*lst = cur;
	return (cur);
}

void	remove_fd_node(t_gnl_node **lst, int fd)
{
	t_gnl_node	*prev;
	t_gnl_node	*cur;

	prev = NULL;
	cur = *lst;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				*lst = cur->next;
			free(cur->buf);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

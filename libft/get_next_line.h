/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:48:03 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get_next_line.h — Header สำหรับ get_next_line ที่รวมอยู่ใน libft
**
** ใช้ libft.h แทนการ include stdlib/unistd ซ้ำ
** ft_strlen, ft_strchr, ft_strjoin มาจาก libft โดยตรง
**
** t_gnl_node: linked list เก็บ buffer ของแต่ละ fd
**   .fd   : file descriptor ที่กำลัง track
**   .buf  : leftover buffer หลัง newline ที่ยังไม่ได้ return
**   .next : fd ถัดไปใน list
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_gnl_node
{
	int					fd;
	char				*buf;
	struct s_gnl_node	*next;
}	t_gnl_node;

char		*get_next_line(int fd);
t_gnl_node	*find_fd_node(t_gnl_node **lst, int fd);
void		remove_fd_node(t_gnl_node **lst, int fd);

#endif

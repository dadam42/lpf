/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_out_buffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:30:02 by damouyal          #+#    #+#             */
/*   Updated: 2020/01/21 15:46:42 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OUT_BUFFER_H
# define T_OUT_BUFFER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define T_OUT_BUFFER_ERROR -1
# include <unistd.h>

/*
** Typedef for unistd's write function
*/
typedef ssize_t	(*t_put)(int, void const *, size_t);
typedef struct	s_out_buffer
{
	char	buf[BUFFER_SIZE];
	char	*cur;
	int		fd;
	t_put	put;
	ssize_t	count;
}				t_out_buffer;

/*
** function to bufferize string pointed by src of size size
** returns negative number if a problem occured
** else returns buf->count
*/
ssize_t			bufferize_buf(t_out_buffer *buf, char const *src, size_t size);
/*
** function to bufferize char c count times
** returns negative number if a problem occured
** else returns buf->count
*/
ssize_t			bufferize_char(t_out_buffer *buf, char c, size_t count);
/*
** flush buffer
** returns negative number if a problem occured
** else returns buf->count
*/
ssize_t			t_out_buffer_flush(t_out_buffer *buf);
void			t_out_buffer_init(t_out_buffer *buf, int fd, t_put put);
#endif

#ifndef T_OUT_BUFFER_H
# define T_OUT_BUFFER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define T_OUT_BUFFER_ERROR -1
# include <unistd.h>

typedef ssize_t (*t_put)(int, void const *, size_t);
typedef struct	s_out_buffer
{
	char	buf[BUFFER_SIZE];
	char	*cur;
	int		fd;
	t_put	put;
	ssize_t	count;
}				t_out_buffer;

ssize_t			bufferize_buf(t_out_buffer *buf, char const *src, size_t size);
ssize_t			bufferize_char(t_out_buffer *buf, char c, size_t count);
ssize_t			t_out_buffer_flush(t_out_buffer *);
void			t_out_buffer_init(t_out_buffer *buf, int fd, t_put put);
#endif

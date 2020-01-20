#include "t_out_buffer.h"
#include "libft.h"
#include <unistd.h>

static ssize_t	output(t_out_buffer *buf, char const *src, size_t size)
{
	ssize_t rval;

	while (size > 0)
	{
		if ((rval = buf->put(buf->fd, src, size)) < 0)
			return (T_OUT_BUFFER_ERROR);
		size -= rval;
		src += rval;
		buf->count +=  rval;
	}
	return (buf->count);
}

void			t_out_buffer_init(t_out_buffer *buf, int fd, t_put put)
{
	buf->cur = buf->buf;
	buf->fd = fd;
	buf->put = put;
	buf->count = 0;
}

ssize_t			bufferize_buf(t_out_buffer *buf, char const *src, size_t size)
{
	while (1)
	{
		while ((buf->cur - buf->buf < BUFFER_SIZE) && size > 0)
		{
			*buf->cur++ = *src++;
			size--;
		}
		if (size == 0)
			return (buf->count);
		if (output(buf, buf->buf, BUFFER_SIZE) == T_OUT_BUFFER_ERROR)
			break;
		buf->cur = buf->buf;
		while (size > BUFFER_SIZE)
			if (output(buf, src, BUFFER_SIZE) == T_OUT_BUFFER_ERROR)
				break;
			else
			{
				size -= BUFFER_SIZE;
				src += BUFFER_SIZE;
			}

	}
	return (T_OUT_BUFFER_ERROR);
}

ssize_t			bufferize_char(t_out_buffer *buf, char c, size_t count)
{
	while (1)
	{
		while ((buf->cur - buf->buf < BUFFER_SIZE) && count-- > 0)
			*buf->cur++ = c;
		if (count == 0)
			return (buf->count);
		if (output(buf, buf->buf, BUFFER_SIZE) == T_OUT_BUFFER_ERROR)
			break;
		buf->cur = buf->buf;
	}
	return (T_OUT_BUFFER_ERROR);
}

ssize_t			t_out_buffer_flush(t_out_buffer *buf)
{
	ssize_t	ret;

	ret = output(buf, buf->buf, buf->cur - buf->buf);
	buf->cur = buf->buf;
	return (ret);
}


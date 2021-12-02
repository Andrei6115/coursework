
#include "get_next_line.h"

static int	have_end_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return ((void *)0);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

static char	*read_line(int fd, char *line)
{
	char	*buf;
	int		check;

	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	check = 1;
	while (!have_end_line(line) && check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[check] = '\0';
		line = ft_strjoin(line, buf);
	}
	free (buf);
	return (line);
}

static char	*cut_tail(char *line)
{
	char	*tail;
	int		i;
	int		j;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	tail = malloc(ft_strlen(&line[i]) + 1);
	if (!tail)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		tail[j++] = line[i++];
	tail[j] = '\0';
	free(line);
	return (tail);
}

static char	*before_tail(char *ret)
{
	int		i;
	char	*r;

	i = 0;
	if (!ret)
		return (NULL);
	while (ret[i] != '\n' && ret[i])
		i++;
	//if (ret[i] == '\n')
	//	i++;
	r = malloc(i + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (ret[i] != '\0' && ret[i] != '\n')
	{
		r[i] = ret[i];
		i++;
	}
	//if (ret[i] == '\n')
	//	r[i++] = '\n';
	r[i] = '\0';
	return (r);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*rem_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem_line = read_line(fd, rem_line);
	if (!rem_line)
		return (NULL);
	ret = before_tail(rem_line);
	if (!ret || !*ret)
	{
		free(ret);
		if (rem_line)
		{
			free(rem_line);
			rem_line = NULL;
		}
		return (NULL);
	}
	rem_line = cut_tail(rem_line);
	return (ret);
}

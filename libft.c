#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (dstsize == 0)
		return (l);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

static size_t	countword(const char *s, char c)
{
	int		count;
	int		f;

	count = 0;
	f = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		count++;
	}
	return (count);
}

static char	*createstr(char const *s, char c)
{
	int		size;
	char	*ret;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	ret = malloc(size + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, size + 1);
	return (ret);
}

static void	cleaner(char **ret, int countw)
{
	int	i;

	i = 0;
	while (countw > i)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		countw;

	if (!s)
		return (0);
	countw = countword(s, c);
	i = 0;
	ret = malloc((countw + 1) * sizeof(char *));
	if (!ret)
		return (0);
	while (i < countw)
	{
		while (*s == c && *s)
			s++;
		ret[i] = createstr(s, c);
		if (!ret[i])
		{
			cleaner(ret, countw);
			return (0);
		}
		s += ft_strlen(ret[i++]);
	}
	ret[i] = 0;
	return (ret);
}
#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include "sentence.h"
# include "get_next_line.h"

int	startWorkWithStruct(char *structName);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
#endif
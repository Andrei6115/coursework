#ifndef SENTENCE_H
# define SENTENCE_H
# include "header.h"
typedef struct s_sentence
{
	char				*word;
	struct s_sentence	*next;
} t_sentence;

void sentenceMenu(t_sentence **sentence);
void	sentenceCleaner(t_sentence **begin);
void	sentencePrint(t_sentence **sentence);
void	sentenceAdd(t_sentence **sentence, const char *str);
#endif
#ifndef SENTENCE_H
# define SENTENCE_H
# include "header.h"
typedef struct s_sentence
{
	char				*word;
	struct s_sentence	*next;
	struct s_sentence	*prev;
} t_sentence;

void 	sentenceMenu(t_sentence **sentence);
void	sentenceCleaner(t_sentence **begin);
void	sentenceP(t_sentence **sentence, t_sentence *cursor);
#endif
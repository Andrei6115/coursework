#ifndef SEQUENCE_H
# define SEQUENCE_H
# include "queue.h"

typedef struct s_sequence
{
	struct s_queue		*queue;
	struct s_sequence	*next;
} t_sequence;

void	sequenceMenu();
#endif
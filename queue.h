#ifndef QUEUE_H
# define QUEUE_H
# include "sentence.h"
typedef struct s_queue
{
	struct s_sentence	*data;
	struct s_queue		*next;
	struct s_queue		*prev;
} t_queue;

void	queueMenu(t_queue	**queue);
#endif
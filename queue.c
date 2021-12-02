#include "queue.h"

void	queueCleaner(t_queue **start_list)
{
	if (!start_list)
	{
		printf("NULL POINTER\n");
		return ;
	}
	if (!(*start_list))
	{
		printf("Queue empty\n");
		return ;
	}
	while ((*start_list)->next)
	{
		(*start_list) = (*start_list)->next;
		sentenceCleaner(&(*start_list)->prev->data);
		free((*start_list)->prev);
	}
	sentenceCleaner(&((*start_list)->data));
	free((*start_list));
	*start_list = NULL;
}

void	queuePrint(t_queue **queue)
{
	t_queue	*tmp;

	tmp = *queue;
	if (!tmp)
		printf("Queue empty\n");
	else
		printf("---\n");
	while (tmp)
	{
		sentencePrint(&(tmp->data));
		tmp = tmp->next;
	}
}

t_queue  *queueAddEl()
{
	t_queue	*list;

	list = malloc(sizeof(t_queue));
	if (!list)
	{
		printf("Memory error\n");
		exit(0);
	}
	list->data = NULL;
	list->next = NULL;
	list->prev = NULL;
	return(list);
}

void	queuePush(t_queue **begin_list)
{
	t_queue	*current;

	current = *begin_list;
	if (!current)
	{
		*begin_list = queueAddEl();
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = queueAddEl();
	current->next->prev = current;
}

t_queue	*queueLast(t_queue *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	queueDeleteEl(t_queue **last)
{
		if (!last)
	{
		printf("NULL POINTER\n");
		return ;
	}
	if (!(*last))
	{
		printf("Queue empty\n");
		return ;
	}
	sentenceCleaner(&(*last)->data);
	if ((*last)->prev)
		(*last)->prev->next = NULL;
	free(*last);
	*last = NULL;
}

void	queueMenu(t_queue	**queue)
{
	int		flag;
	char	*str;
	t_queue	*last;
	t_queue	*taked;
	
	if (!startWorkWithStruct("Queue"))
		return ;
	last = queueLast(*queue);
	flag = 1;
	while (flag)
	{
		queuePrint(queue);
		printf("1. Cleaner\n2. Queue clean?\n3. View el\n4. Delete el\n5. Take el\n6. Change el\n7. Add el\n8. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("clear");
		switch (flag)
		{
		case 1:
		if (*queue)
			queueCleaner(queue);
			break;
		case 2:
		if (*queue)
			printf("Queue not clean\n");
		else
			printf("Queue clean\n");
			break;
		case 3:
		if (*queue)
		{
			sentencePrint(&(*queue)->data);
		}
		else
			printf("Queue empty\n");
			break;
		case 4:
		if (*queue)
		{
			queueDeleteEl(&last);
			last = queueLast(*queue);
		}
		else
			printf("Queue empty\n");
			break;
		case 5:
		if (*queue)
		{
			taked = last;
			sentencePrint(&(taked->data));
			queueDeleteEl(&last);
			
			taked = NULL;
		}
		else
			printf("Queue empty\n");
			break;
		case 6:
		if (*queue)
		{
			sentenceMenu(&(*queue)->data);
		}
		else
			printf("Queue empty\n");
			break;
		case 7:
			queuePush(queue);
			last = queueLast(*queue);
			break;
		case 8:
		if (*queue)
		{
			queuePrint(queue);
		}
		else
		printf("Queue empty\n");
			break;
		case 0:
			return;
		default:
		printf("Error\n");
			break;
		}
	}
	
}
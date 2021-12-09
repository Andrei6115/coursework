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
		//printf("Queue empty\n");
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

	if (!*queue)
		return ;
	tmp = *queue;
	printf("---\n");
	while (tmp)
	{
		sentenceP(&(tmp->data), tmp->data);
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
	t_queue *tmp;

	current = *begin_list;
	if (!current)
	{
		*begin_list = queueAddEl();
		return ;
	}
	tmp = queueAddEl();
	tmp->next = current;
	current->prev = tmp;
	(*begin_list) = tmp;
}

t_queue	*queueLast(t_queue *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

int	ft_list_size(t_queue *begin_list)
{
	int		count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

void	queueDeleteEl(t_queue **last)
{
	t_queue *temp;
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
	temp = (*last);
	sentenceCleaner(&temp->data);
	if (temp->prev) {
		(*last) = (*last)->prev;
		(*last)->next = NULL;
	}
	else
		(*last) = NULL;
	free(temp);
}

void	queueMenu(t_queue	**queue)
{
	int		flag;
	char	*str;
	int		size;
	t_queue	*last;
	t_queue	*taked;
	
	if (!startWorkWithStruct("Queue"))
		return ;
	last = queueLast(*queue);
	flag = 1;
	size = ft_list_size(*queue);
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
			if (!*queue)
				queueCleaner(queue);
			size = 0;
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
			sentenceP(&(last)->data, (last)->data);
		}
		else
			printf("Queue empty\n");
			break;
		case 4:
		if (*queue)
		{
			queueDeleteEl(&last);
			size--;
			(*queue) = last;
			if (*queue)
				while ((*queue)->prev)
					(*queue) = (*queue)->prev;
		}
		else
			printf("Queue empty\n");
			break;
		case 5:
		if (*queue)
		{
			taked = last;
			sentenceP(&(taked->data), taked->data);
			queueDeleteEl(&last);
			size--;
			taked = NULL;
		}
		else
			printf("Queue empty\n");
			break;
		case 6:
		if (*queue)
		{
			sentenceMenu(&(last)->data);
		}
		else
			printf("Queue empty\n");
			break;
		case 7:
			if (size == MAXSIZEQUEUE)
			{
				printf("%d el max\n", MAXSIZEQUEUE);
				break;
			}
			queuePush(queue);
			sentenceMenu(&(*queue)->data);
			last = queueLast(*queue);
			size++;
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
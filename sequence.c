#include "sequence.h"
void	sequencePrint(t_sequence **sequence, t_sequence *cursor)
{
	char		readeble;
	t_sequence	*tmp;

	if (!*sequence)
	{
		printf("Sequence clean\n");
		return ;
	}
	readeble = '+';
	tmp = *sequence;
	while (tmp)
	{
		if (!((*sequence) == tmp))
			printf("->");
		printf("[%c]", readeble);
		if (cursor == tmp)
		{
			printf("*");
			readeble = '-';
		}
		tmp = tmp->next;
	}
	printf("\n");
	queuePrint(&(cursor->queue));
}

void	sequenceCleaner(t_sequence **begin)
{
	t_sequence	*tmp;
	t_sequence	*list;

	list = *begin;
	while (list)
	{
		tmp = list->next;
		queueCleaner(&(*begin)->queue);
		free(list);
		list = tmp;
	}
	*begin = NULL;
}

t_sequence	*sequenceNew()
{
	t_sequence	*ret;

	ret = malloc(sizeof(t_sentence));
	if (!ret)
	{
		printf("MEM ERROR\n");
		return (NULL);
	}
	ret->next = NULL;
	ret->queue = NULL;
	return (ret);
}

t_sequence	*sequenceLast(t_sequence *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	sequenceAddInBack(t_sequence **lst, t_sequence *new)
{
	t_sequence	*n;

	if (!(lst))
		return ;
	n = *lst;
	if (n)
	{
		n = sequenceLast(*lst);
		n->next = new;
	}
	else
		*lst = new;
}

void	sequenceMenu()
{
	t_sequence	*sequence;
	t_sequence	*cursor;
	int			flag;

	if (!startWorkWithStruct("Sequence"))
		return;
	flag = 1;
	sequence = NULL;
	cursor = sequence;

	while (flag)
	{
		sequencePrint(&sequence, cursor);
		printf("1. Cleaner\n2. Sequence clean?\n3. View next\n4. Next el\n5. Change el\n6. Add el\n7. Cursor to start\n8. Have non readed el?\n9. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("clear");
		switch (flag)
		{
		case 1:
		if (sequence)
		{
			sequenceCleaner(&sequence);
			cursor = sequence;
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 2:
		if (sequence)
		{
			printf("Sequence not clean\n");
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 3:
		if (sequence)
		{
			queuePrint(&(sequence->queue));
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 4:
		if (sequence)
		{
			if (cursor->next)
				cursor = cursor->next;
			else
				printf("Cursor in end\n");
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 5:
		if (sequence)
		{
			queueMenu(&(cursor->queue));
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 6:
		sequenceAddInBack(&sequence, sequenceNew());
		if (!cursor)
			cursor = sequence;
			break;
		case 7:
		if (sequence)
		{
			cursor = sequence;
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 8:
		if (sequence)
		{
			if (cursor->next)
				printf("Have are unread elements\n");
			else
				printf("No unread elements\n");
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 9:
		if (sequence)
		{
			sequencePrint(&sequence, cursor);
		}
		else
		{
			printf("Sequence clean\n");
		}
			break;
		case 0:
			return;
		default:
		printf("EROR 404");
			break;
		}
	}
	
}
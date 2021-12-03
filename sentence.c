#include "sentence.h"
#include <string.h>

t_sentence	*ft_lstnew(char *word)
{
	t_sentence	*ret;

	ret = malloc(sizeof(t_sentence));
	if (!ret)
	{
		printf("MEM ERROR\n");
		return (NULL);
	}
	ret->word = malloc(strlen(word));
	if (!ret)
	{
		printf("MEM ERROR\n");
		return (NULL);
	}
	strcpy(ret->word, word);
	//ret->word = ;
	ret->next = NULL;
	return (ret);
}

t_sentence	*ft_lstlast(t_sentence *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_sentence **lst, t_sentence *new)
{
	t_sentence	*n;

	if (!(lst))
		return ;
	n = *lst;
	if (*lst)
	{
		n = ft_lstlast(*lst);
		n ->next = new;
	}
	else
		*lst = new;
}

void	sentenceCleaner(t_sentence **begin)
{
	t_sentence	*tmp;
	t_sentence	*list;

	list = *begin;
	while (list)
	{
		tmp = list->next;
		if (list && list->word)
			free(list->word);
		free(list);
		list = tmp;
	}
	*begin = NULL;
}

// void	sentenceAdd(t_sentence **sentence, const char *str)
// {
// 	char	**splited;
// 	int		i;

// 	i = 0;
// 	splited = ft_split(str, ' ');
	
	
// 	while (splited[i])
// 	{
// 		ft_lstadd_back(sentence, ft_lstnew(splited[i]));
// 		i++;
// 	}
// }

void	sentenceP(t_sentence **sentence, t_sentence *cursor)
{
	t_sentence *list;

	list = *sentence;
	if (!list)
		printf("%p", list);
	while (list)
	{
		if (*sentence != list)
			printf("->");
		printf("[%s]", list->word);
		if (list == cursor)
			printf("*");
		list = list->next;
	}
	printf("\n");
}

void	sentenceMenu(t_sentence **sentence)
{
	int			flag;
	char		str[100];
	t_sentence	*cursor;
	t_sentence	*tmp;
	
	if (!startWorkWithStruct("Sentence"))
		return ;
	flag = 1;
	cursor = *sentence;
	while (flag)
	{
		
		sentenceP(sentence, cursor);
		//printf("1. Cleaner\n2. Sentence clean?\n3. Add sentence\n4. Uppdate sentence\n0. Exit\n");
		printf("1. Cleaner\n2. Sentence clean?\n3. Cursor to start\n4. Cursor in end?\n5. Cursor next\n6. View next\n7. Delete next\n8. Take element\n9. Change next\n10. Add next\n11. Print\n0. Exit\n");

		scanf("%d", &flag);
		printf("\n");
		system("clear");
		switch (flag)
		{
		case 1:
		if (*sentence)
			sentenceCleaner(sentence);
		else
			printf("Sentence clean\n");
			break;
		case 2:
			if (*sentence)
				printf("Sentence not clean\n");
			else 
				printf("Sentence clean\n");
			break;
		case 3:
			if (*sentence)
			{
				cursor = *sentence;
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 4:
			if (*sentence)
			{
				if (cursor->next)
					printf("Cursor not in end\n");
				else
					printf("Cursor in end\n");
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 5:
			if (*sentence)
			{
				if (cursor->next)
					cursor = cursor->next;
				else
					printf("Cursor in end\n");
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 6:
			if (*sentence)
			{
				if (cursor->next)
				{
						printf("%s\n", cursor->next->word);
				}
				else
					printf("Cursor in end\n");
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 7:
			if (*sentence)
			{
				if (cursor->next)
				{
					tmp = cursor->next;
					cursor->next = tmp->next;
					free(tmp);
					tmp = NULL;
				}
				else
					printf("Cursor in end\n");
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 8:
			if (*sentence)
			{
				if (cursor->next)
				{
					tmp = cursor->next;
					cursor->next = tmp->next;
					printf("Taked: %s", tmp->word);
					free(tmp);
					tmp = NULL;
				}
				else
					printf("Cursor in end\n");
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 9:
			if (*sentence)
			{
				if (cursor->next)
				{
					printf("Enter word:");
					scanf("%s", cursor->next->word);
				}
				else
					printf("Cursor in end\n");
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 10:
			if (!cursor)
			{
				printf("Enter word:");
				scanf("%s", str);
				ft_lstadd_back(sentence, ft_lstnew(str));
				cursor = *sentence;
			}
			else
			{
				printf("Enter word:");
				scanf("%s", str);
				ft_lstadd_back(&cursor, ft_lstnew(str));
			}
			break;
		case 11:
			if (*sentence)
			{
				sentenceP(sentence, cursor);
			}
			else
			{
				printf("Sentence clean\n");
			}
			break;
		case 0:
			return ;
		default:
			printf("Error\n");
			break;
		}
	}
}
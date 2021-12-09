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
	if (!ret->word)
	{
		printf("MEM ERROR\n");
		return (NULL);
	}
	strcpy(ret->word, word);
	//ret->word = ;
	ret->next = NULL;
	ret->prev = NULL;
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
	{
		printf("%p\n", list);
		return;
	}
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

void	delete_after_pointer(t_sentence **list)
{
	t_sentence	*temp;

	if (!(*list)->next)
		return;
	temp = (*list)->next;
	if (temp->next)
	{
		(*list)->next = temp->next;
		temp->next->prev = *list;
	}
	else
	{
		(*list)->next = NULL;
	}
	free(temp->word);
	free(temp);
}

void	delete_before_pointer(t_sentence **list)
{
	t_sentence	*temp;

	if (!(*list)->prev)
		return;
	temp = (*list)->prev;
	if (temp->prev)
	{
		(*list)->prev = temp->prev;
		temp->prev->next = *list;
	}
	else
	{
		(*list)->prev = NULL;
	}
	free(temp->word);
	free(temp);
}

void	create_after_pointer(t_sentence **list, char *data)
{
	t_sentence	*temp;

	if (!list)
	{
		printf("DELETE NULL POINTER!\n");
		return ;
	}
	temp = ft_lstnew(data);
	if (!*list)
		*list = temp;
	else
	{
		if ((*list)->next)
		{
			temp->next = (*list)->next;
			temp->next->prev = temp;
			(*list)->next = temp;
			temp->prev = (*list);
		}
		else
		{
			(*list)->next = temp;
			temp->prev = (*list);
		}
	}
}

void	create_before_pointer(t_sentence **list, char *data)
{
	t_sentence	*temp;

	if (!list)
	{
		printf("DELETE NULL POINTER!\n");
		return ;
	}
	temp = ft_lstnew(data);
	if (!*list)
		*list = temp;
	else
	{
		if ((*list)->prev)
		{
			temp->prev = (*list)->prev;
			temp->prev->next = temp;
			(*list)->prev = temp;
			temp->next = (*list);
		}
		else
		{
			(*list)->prev = temp;
			temp->next = (*list);
		}
	}
}

void	sentenceMenu(t_sentence **sentence)
{
	int			flag;
	char		str[100];
	t_sentence	*cursor;
	t_sentence	*tmp;
	char		word[100];
	
	if (!startWorkWithStruct("Sentence"))
		return ;
	flag = 1;
	tmp = NULL;
	cursor = *sentence;
	while (flag)
	{
		
		sentenceP(sentence, cursor);
		//printf("1. Cleaner\n2. Sentence clean?\n3. Add sentence\n4. Uppdate sentence\n0. Exit\n");
		//printf("1. Cleaner\n2. Sentence clean?\n3. Cursor to start\n4. Cursor in end?\n5. Cursor next\n6. View next\n7. Delete next\n8. Take element\n9. Change next\n10. Add next\n11. Print\n0. Exit\n");
		printf("1. Cleaner\n2. Sentence clean?\n3. Cursor to start\n4. Cursor to end\n5. Cursor at start?\n6. Cursor at end?\n7. Cursor next\n8. Cursor prev\n9. View after pointer\n10.View before pointer\n11.Delete after pointer\n12.Delete before pointer\n13.Take after pointer\n14.Take before pointer\n15.Change after pointer\n16.Change before pointer\n17.Create after ponter\n18.Create before pointer\n19.Print list\n20.Exit\n\tU entered:");
		scanf("%d", &flag);
		printf("\n");
		system("clear");
		switch (flag)
		{
		case 1:
			if (*sentence)
			{
				sentenceCleaner(sentence);
				(*sentence) = NULL;
				cursor = *sentence;
			}
			else
			{
				printf("List clear\n");
			}
			break;
		case 2:
			if (*sentence == NULL)
				printf("List empty\n");
			else
				printf("List not empty\n");
			break;
		case 3:
			if(*sentence)
			{
				cursor = *sentence;
			}
			else
			{
				printf("List clear\n");
			}
			break;
		case 4:
			if (!(*sentence))
			{
				printf("List clear\n");
			}
			else
			{
				while (cursor->next)
					cursor = cursor->next;
			}
			break;
		case 5:
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else if (!cursor->prev)
					printf("Pointer in start\n");
				else
					printf("Pointer not in start\n");
			break;
		case 6:
			if (!(*sentence))
			{
				printf("List clear\n");
			}
			else if (!cursor->next)
					printf("Pointer in end\n");
				else
					printf("Pointer not in end\n");
			break;
		case 7:	
			if (!(*sentence))
			{
				printf("List clear\n");
			}
			else if (cursor->next)
				cursor=cursor->next;
				else
					printf("No el\n");
			break;
		case 8:
			if (!(*sentence))
			{
				printf("List clear\n");
				
			}	
			else
				if (cursor->prev)
					cursor=cursor->prev;
				else
					printf("no el\n");
			break;
		case 9:
			if (!(*sentence))
			{
				printf("List clear");
			}	
			else if (cursor->next)
				printf("%s", cursor->prev->word);
			else
				printf("No element");
				printf("\n");
			break;
		case 10:
			if (!(*sentence))
			{
				printf("List clear");
			}	
			else if (cursor->prev)
				printf("%s", cursor->prev->word);
			else
				printf("No element");
				printf("\n");
			break;
		case 11:
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else
			{
				delete_after_pointer(&cursor);
				
			}
			break;
		case 12:
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else
			{
				delete_before_pointer(&cursor);
				(*sentence) = cursor;
				while ((*sentence)->prev)
					(*sentence) = (*sentence)->prev;
			}
			break;
		case 13:
			if (tmp)
			{
				free(tmp->word);
				free(tmp);
				tmp = NULL;
			}
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else if(cursor->next)
			{
				tmp = cursor->next;
				if (tmp->next)
				{
					cursor->next = tmp->next;
					tmp->next->prev = cursor;
				}
				else
				{
					cursor->next = NULL;
				}
				printf("Taked el: ");
				printf("%s", tmp->word);
				printf("\n");
			}
			else
			{
				printf("No element\n");
			}
			break;
		case 14:
			if (tmp)
			{
				if (tmp->word)
					free(tmp->word);
				free(tmp);
				tmp = NULL;
			}
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else if (cursor->prev)
			{
				tmp = (cursor)->prev;
				if (tmp->prev)
				{
					cursor->prev = tmp->prev;
					tmp->prev->next = cursor;
				}
				else
				{
					cursor->prev = NULL;
				}
				(*sentence) = cursor;
				while ((*sentence)->prev)
				{
					(*sentence)=(*sentence)->prev;
				}
				printf("Taked el: ");
				printf("%s", tmp->word);
				printf("\n");
			}
			else
			{
				printf("No element\n");
			}
			break;
		case 15:
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else if (cursor->next)
			{
				printf("Enter data for el:");
				scanf("%s", (cursor->next->word));
				printf("\n");
				//cursor->next->word = word;
			}
			else
			{
				printf("no elem\n");
			}
			break;
		case 16:
			if (!(*sentence))
			{
				printf("List clear\n");
			}	
			else if (cursor->prev)
			{
				printf("Enter data for el:");
				scanf("%s", (cursor->prev->word));
				printf("\n");
				//list->prev->data = data;
			}
			else
			{
				printf("No elem\n");
			}
			break;
		case 17:
			printf("Enter data for el:");
			scanf("%s", word);
			printf("\n");
			create_after_pointer(&cursor, word);
			(*sentence) = cursor;
			while ((*sentence)->prev)
			{
				(*sentence)=(*sentence)->prev;
			}
			break;
		case 18:
			printf("Enter data for el:");
			scanf("%s", word);
			printf("\n");
			create_before_pointer(&cursor, word);
			(*sentence) = cursor;
			while ((*sentence)->prev)
			{
				(*sentence)=(*sentence)->prev;
			}
			break;
		case 19:
			//print(start_list, list);
			break;
		case 20:
			//sentenceCleaner(sentence);
			//*sentence = NULL;
			//cursor = NULL;
			return ;	
		default:
			printf("ERROR 404\n");
			break;
		}
	}
}
#include "sentence.h"
#include "header.h"
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
	ret->word = word;
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
		if (list)
			free(list->word);
		free(list);
		list = tmp;
	}
	*begin = NULL;
}

void	sentenceAdd(t_sentence **sentence, const char *str)
{
	char	**splited;
	int		i;

	i = 0;
	splited = ft_split(str, ' ');
	
	
	while (splited[i])
	{
		ft_lstadd_back(sentence, ft_lstnew(splited[i]));
		i++;
	}
}

void	sentencePrint(t_sentence **sentence)
{
	t_sentence *list;

	list = *sentence;
	if (!list)
		printf("%p", list);
	while (list)
	{
		if (*sentence != list)
			printf("->");
		printf("%s", list->word);
		list = list->next;
	}
	printf("\n");
}

void	sentenceMenu(t_sentence **sentence)
{
	int		flag;
	char	*str;
	
	if (!startWorkWithStruct("Sentence"))
		return ;
	flag = 1;
	while (flag)
	{
		
		sentencePrint(sentence);
		printf("1. Cleaner\n2. Sentence clean?\n3. Add sentence\n4. Uppdate sentence\n0. Exit\n");
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
			printf("Enter string:");
			str = get_next_line(1);
			sentenceAdd(sentence, str);
			free(str);
			break;
		case 4:
			sentenceCleaner(sentence);
			printf("Enter string:");
			str = get_next_line(1);
			sentenceAdd(sentence, str);
			free(str);
			str = NULL;
			break;
		case 0:
			return ;
		default:
			printf("Error\n");
			break;
		}
	}
}
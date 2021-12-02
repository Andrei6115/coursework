#include <stdio.h>
#include <stdlib.h>

int	startWorkWithStruct(char *structName)
{
	int	select;
	printf("Start work with \"%s\"\n1\tStart\nAny\tExit\nU enter:", structName);
	scanf("%d", &select);
	system("clear");
	if (select == 1)
		return (1);
	else
		return (0);
}


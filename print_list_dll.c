#include "APC.h"

void print_list(Dlist *head)
{
	// Cheking the list is empty or not if it is print error message
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	//tranverse untill the end of the list
    	while (head != NULL)
    	{
			//print each digit
        	printf("%d", head->data);
			//move to next node
        	head = head->next;
    	}
    printf("\n");
	}

}

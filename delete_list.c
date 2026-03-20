#include "APC.h"

int delete_list(Dlist **head,Dlist **tail)
{
// check if the list is empty or not
if(*head == NULL)
{
    return FAILURE;
}
//create a tempopary variable temp and assign head to it
Dlist *temp = *head;
Dlist *next;
//check the temp is NULL or not
while(temp != NULL)
{
    next = temp->next;
    free(temp);
    temp = next;
}
*head = NULL;
*tail = NULL;
return SUCCESS;
}
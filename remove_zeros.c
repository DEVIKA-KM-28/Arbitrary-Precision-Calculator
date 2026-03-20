#include "APC.h"

void remove_zeros(Dlist **head, Dlist **tail)
{
    while (*head != NULL && (*head)->data == 0)
    {
        //create and temp and assign head to it
        Dlist *temp = *head;
        //move the head to the next node
        *head = (*head)->next;
        //update prev of link with new of head
        if (*head != NULL)
            (*head)->prev = NULL;
        else
            *tail = NULL;
        //free the temp 
        free(temp);
    }

    //if all digits were zero,insert the single zero
    if (*head == NULL)
    {
        insert_first(head, tail, 0); 
    }
}

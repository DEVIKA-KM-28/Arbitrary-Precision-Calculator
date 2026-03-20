#include "APC.h"

int sll_insert_first(Slist **head, int data)
{
    //create new node
    Slist *new = malloc(sizeof(Slist));
    //check if the new == NULL if it is return FAILURE
    if(new == NULL)
        return FAILURE;
    //store data in node
    new->data = data;
    //assign head to new of link
    new->link = *head;
    //update the head with a new node
    *head = new;

    return SUCCESS;
}

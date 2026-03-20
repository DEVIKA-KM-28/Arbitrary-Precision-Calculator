#include "APC.h"

int insert_first(Dlist **head, Dlist **tail, int data)
{
    //create a new node
    Dlist *new = malloc(sizeof(Dlist));
    //check if new == NULL if it is return FAILURE
    if(new == NULL)
    return FAILURE;
    //update node data 
    new->data = data;
    //take two pointers and assign NULL to it
    new-> prev = NULL;
    new->next = NULL;
    // list is empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        //link the new node before the first node
        new->next = *head;
        (*head)->prev = new;
        //update the head
        (*head) = new;
    }
    return SUCCESS;
}
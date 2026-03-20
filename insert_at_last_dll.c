#include "APC.h"

int insert_last(Dlist **head, Dlist **tail, int data)
{
    //create new node
 Dlist *new = malloc(sizeof(Dlist));
 //check new is NULL or not
 if(new == NULL)
 // if new is NULL return FAILURE
 return FAILURE;
 
 // update the data and links
 new->data=data;
 new->prev=NULL;
 new->next=NULL;
 
 //check list is empty or not
 if(*head == NULL)
 {
     *head = new;
     *tail = new;
 }
 else
 {
     (*tail)->next=new;
     new->prev = *tail;
     //update the tail
     *tail = new;
 }
 return SUCCESS;
 
}
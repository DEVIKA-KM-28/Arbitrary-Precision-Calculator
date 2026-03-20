#include "APC.h"

void print_sll(Slist *head)
{
    //traverse untill the end of the list
    while(head != NULL)
    {
        //print each digit
        printf("%d", head->data);
        //move to next node
        head = head->link;
    }
    printf("\n");
}

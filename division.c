#include "APC.h"

int division(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Slist **count_head)
{
    //to store quotient value
    int count = 0;

    Dlist *temp_head = NULL; // temporary  dividend head
    Dlist *temp_tail = NULL; //temporary dividend tail

    // copy dividend  to temporary list
    Dlist *t = head1;
    while(t != NULL)
    {
        insert_last(&temp_head, &temp_tail, t->data);
        t = t->next;
    }

    // repeated subtraction until dividend < divisior
    while(compare_list(temp_head, head2) >= 0)
    {
        Dlist *sub_head = NULL; // to store subtraction result
        Dlist *sub_tail = NULL;
        // subtraction function
        subtraction(temp_tail, tail2, &sub_head, &sub_tail);
        //call remove function to remove the leading zeros from the result
        remove_zeros(&sub_head, &sub_tail);
        delete_list(&temp_head, &temp_tail);
        //update head and tail with new result
        temp_head = sub_head;
        temp_tail = sub_tail;

        count++;
    }

    // store count in SLL 
    if(count == 0)
    {
        sll_insert_first(count_head, 0);
    }
    else
    {
        while(count > 0)
        {
            sll_insert_first(count_head, count % 10);
            count = count / 10;
        }
    }

    delete_list(&temp_head, &temp_tail);

    return SUCCESS;
}

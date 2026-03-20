#include "APC.h"

int addition(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int res = 0;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        // when both digits are present 
        if (temp1 != NULL && temp2 != NULL)
        {
            res = temp1->data + temp2->data + carry;
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        // only when first number 
        else if (temp1 != NULL)
        {
            res = temp1->data + carry;
            temp1 = temp1->prev;
        }
        // only when second number 
        else
        {
            res = temp2->data + carry;
            temp2 = temp2->prev;
        }

        // when there is carry 
        if (res >9)
        {
            res = res % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        // insert result digit 
        insert_first(res_head, res_tail, res);
    }

    // insert remaining carry 
    if (carry == 1)
    {
        insert_first(res_head, res_tail, carry);
    }

    return SUCCESS;
}

#include "APC.h"

int subtraction(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *temp1 = tail1; //pointer for number1
    Dlist *temp2 = tail2; //pointer for number2

    int res = 0; //to store subtraction result
    int borrow = 0;
    //run the loop until first number ends
    while (temp1 != NULL)
    {
        //when both digits are present
        if (temp2 != NULL)
        {
            res = temp1->data - temp2->data - borrow;
            temp2 = temp2->prev;
        }
        else
        {
            res = temp1->data - borrow;
        }
        // to check the borrow condition
        if (res < 0)
        {
            res = res + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        // insert the result
        insert_first(res_head, res_tail, res);
        //move to the next digit
        temp1 = temp1->prev;
    }

    return SUCCESS;
}

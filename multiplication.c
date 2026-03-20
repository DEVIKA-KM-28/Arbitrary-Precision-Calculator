#include "APC.h"

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *temp1; //pointer for 1st number
    Dlist *temp2 = tail2; // pointer for 2nd number

    Dlist *res1 = NULL; //final result 
    Dlist *res2 = NULL; // curent step result

    Dlist *restail1 = NULL; //tail of final result
    Dlist *restail2 = NULL; //tail of current result

    int count = 0;
    int res; //to store the mutilpy result
    int carry; 
    //take each digit from second number
    while (temp2 != NULL)
    {
        temp1 = tail1;
        carry = 0;

        res2 = NULL;
        restail2 = NULL;

        // multiply first digit of number 2 with all digits og number1
        while (temp1 != NULL)
        {
            res = (temp1->data * temp2->data) + carry;

            carry = res / 10;
            res   = res % 10;
            //insert digit in result 
            insert_first(&res2, &restail2, res);

            temp1 = temp1->prev;
        }
        //insert carry if present
        if (carry)
        {
            insert_first(&res2, &restail2, carry);
        }

        //add zeros
        for (int i = 0; i < count; i++)
        {
            insert_last(&res2, &restail2, 0);
        }

        if (count == 0)
        {
            res1 = res2;
            restail1 = restail2;
        }
        else
        {
            *res_head = NULL;
            *res_tail = NULL;

            //add previous result and the new result
            addition(restail1, restail2, res_head, res_tail);
            //delete old lists
            delete_list(&res1, &restail1);
            delete_list(&res2, &restail2);
            //update final result
            res1 = *res_head;
            restail1 = *res_tail;
        }

        count++;
        temp2 = temp2->prev;
    }
    //store final result
    *res_head = res1;
    *res_tail = restail1;

    return SUCCESS;
}

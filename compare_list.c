#include "APC.h"

int compare_list(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *temp;

    // find length of the first number 
    temp = head1;
    while (temp)
    {
        len1++;
        temp = temp->next;
    }
 
    // find length of second number 
    temp = head2;
    while (temp)
    {
        len2++;
        temp = temp->next;
    }

    // compare based on length 
    if (len1 > len2)
        return 1; // first number is greater
    else if (len1 < len2)
        return -1; // second number is greater
        // lengths are equal - compare digit by digit 
    else
    {
        while (head1 && head2)
        {
            if (head1->data > head2->data)
                return 1;
            else if (head1->data < head2->data)
                return -1;
            // move to next digit 
            head1 = head1->next;
            head2 = head2->next;
        }
    }
// both numbers are exactly equal 
    return 0;
}

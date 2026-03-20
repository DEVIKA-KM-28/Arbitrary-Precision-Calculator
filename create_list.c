#include "APC.h"

void create_list(char *str, Dlist **head, Dlist **tail)
{
    // to hold single character as string
    char temp[2];
    int i = 0;
    // make temp a valid string for atoi
    temp[1] = '\0';

    //skip sign if negative
    if (str[0] == '-')
        i = 1;
    // convert each character to node
    while (str[i] != '\0')
    {
        //take one digit
        temp[0] = str[i];
        //convert and insert
        insert_last(head, tail, atoi(temp));
        i++;
    }
}


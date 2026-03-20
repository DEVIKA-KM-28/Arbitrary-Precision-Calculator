#include "APC.h"

int main(int argc, char *argv[])
{
    // Initialize all APC pointers to NULL 
    Dlist *head1 = NULL,*tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *reshead = NULL, *restail = NULL;

    // Check command line arguments 
    if (argc != 4)
    {
        printf("ERROR : Invalid arguments\n");
        printf("INFO  : ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    // Create linked lists for both operands 
    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    // Perform operation based on operator 
    switch (argv[2][0])
    {

    // -------- ADDITION -------- //
    case '+':
        addition(tail1, tail2, &reshead, &restail);
        break;

    // -------- SUBTRACTION -------- //
    
    case '-':
    {
        int res = compare_list(head1, head2);
        int flag = 0;

        if (res == 0)
        {
            insert_first(&reshead, &restail, 0);
        }
        else if (res == 1)
        {
            subtraction(tail1, tail2, &reshead, &restail);
        }
        else
        {
            flag = 1;
            subtraction(tail2, tail1, &reshead, &restail);
        }
        
         remove_zeros(&reshead, &restail);

        printf("Result = ");

        if (flag)
            printf("-");

        print_list(reshead);
        return SUCCESS;
    }

    // -------- MULTIPLICATION -------- //
    case 'x':
    case 'X':
    {
        int sign = 0;

        // Check sign of operands 
        if (argv[1][0] == '-')
            sign++;

        if (argv[3][0] == '-')
            sign++;

        multiplication(tail1, tail2, &reshead, &restail);

        // Remove leading zeros from result 
        remove_zeros(&reshead, &restail);

        printf("Result = ");

        if (sign == 1)
            printf("-");

        print_list(reshead);
        return SUCCESS;
    }

    // -------- DIVISION -------- //
    case '/':
    {
        Slist *qhead = NULL;

        // Division using repeated subtraction 
        division(head1, tail1, head2, tail2, &qhead);

        printf("Result = ");
        print_sll(qhead);

        return SUCCESS;
    }

    // -------- INVALID OPERATOR -------- //
    default:
        printf("ERROR : Invalid operator\n");
        return FAILURE;
    }

    // Display result for addition case 
    printf("Result = ");
    print_list(reshead);

    // Free allocated memory //
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&reshead, &restail);

    return SUCCESS;
}

#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS  0
#define FAILURE -1

// Double linked list for division count //
typedef struct node
{
    int data;              
    struct node *prev;
    struct node *next;
}Dlist;

// Single linked list for division count //
typedef struct snode
{
    int data;
    struct snode *link;
} Slist;
 // APC function prototype
int insert_first(Dlist **head, Dlist **tail, int data);
int insert_last(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
void create_list(char *str, Dlist **head, Dlist **tail);
int compare_list(Dlist *head1, Dlist *head2);
void remove_zeros(Dlist **head, Dlist **tail);
int sll_insert_first(Slist **head, int data);
void print_sll(Slist *head);
// Arithmetic operations //
int addition(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail);
int subtraction(Dlist *tail1,Dlist *tail2, Dlist **res_head, Dlist **res_tail);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail);
int division(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Slist **count_head);
void print_list(Dlist *head);
#endif

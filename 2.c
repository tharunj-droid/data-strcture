#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void display(struct Node *p)
{
    while (p != 0)
    {
        printf("%d->", p->data);
        p = p->next;
    }
}
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int max(struct Node *p)
{
    int m = -32457;
    while (p)
    {
        if (p->data>m)
        {
            m=p->data;
            p=p->next;
        }
    }
    return m;
}
void sortedinsert(struct Node*p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if (first==NULL)
    {
        first=t;
    }
    else
    {
        while (p &&p->data<x)
        {
            q=p;
            p=p->next;
        }
        if (p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}
int main()
{
    int A[] = {1, 3, 4, 5,6};
    create(A, 5);
    /* printf("the max number in the linked list is ");
    printf("%d",max(first)); */
    sortedinsert(first,2);
    display(first);
    return 0;
}
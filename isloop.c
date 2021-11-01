#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
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
void isloop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
    {
        printf("it is a looped linked list\n");
    }
    else
    {
        printf("mot a  loop\n");
    }
}

int main()
{
    int A[] = {5, 15, 25, 35, 45};
    create(A, 5);
    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    isloop(first);
    return 0;
}
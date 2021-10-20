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
int issorted(struct Node *p)
{
    int x = -32700;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return -1;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
void removeduplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
int main()
{
    int A[] = {1, 3,3,3,4, 4, 5, 6};
    create(A, 8);
    display(first);
    printf("\n \n");
    removeduplicate(first);
    display(first);
    return 0;
}
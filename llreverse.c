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
int count(struct Node *p)
{
    int l = 0;
    while (p != 0)
    {
        l++;
        p = p->next;
    }
    return l;
}

void reverse(struct Node *p)
{
    struct Node *q = p;
    int *A, i = 0;
    A = (int *)malloc(sizeof(int) * count(p));
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

int main()
{
    int A[] = {1, 3, 3, 3, 4, 4, 5, 6};
    create(A, 8);
    display(first);
    printf("\n\n");
    reverse(first);
    display(first);
    return 0;
}
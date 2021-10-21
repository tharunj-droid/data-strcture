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

void slidereverse(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main()
{
    int A[] = {1, 3, 3, 3, 4, 4, 5, 6};
    create(A, 8);
    display(first);
    printf("\n\n");
    slidereverse(first);
    display(first);
    return 0;
}
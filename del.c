#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
} * Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}
void display(struct Node *h)
{
    do
    {
        printf("%d->", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

int delete (struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > Length(p))
    {
        return -1;
    }
    if (index == 1)
    {
        p = Head;
        while (p->next != Head)
        {
            p = p->next;
        }
        x = Head->data;
        if (Head == p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        p = Head;
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    // insert(Head, 0, 67);
    // display(Head);
    // printf("length is %d\n", Length(Head));
    // Rdisplay(Head);
    printf("deleted %d\n", delete (Head, 4));
    display(Head);
    return 0;
}
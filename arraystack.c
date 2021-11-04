#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("enter the size\n");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d", st.S[i]);
        printf("\n");
    }
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
    printf("\n");
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index <= 0)
    {
        printf("enter proper index\n");
    }
    x = st.S[st.top - index + 1];
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack st)
{

    return st.top== st.size - 1;
}

int stackTop(struct Stack st)
{
    if (!isEmpty)
    {
        return st.S[st.top];
    }
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60); 
    display(st);
    // printf("%d\n",pop(&st));
    printf("\n");
    /* pop(&st);
    pop(&st); */
    printf("%d",peek(st,3));
    // display(st);
    // printf(" stack is empty %d\n", isEmpty(st));
    // printf("stack is full%d\n", isFull(st));
    // printf("stack is %d\n", stackTop(st));
    return 0;
}
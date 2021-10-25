#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *str;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void preorder(struct node *temp)
{
    if (temp == NULL)
        return;
    printf("%s ", temp->str);
    preorder(temp->left);
    preorder(temp->right);
}

struct node *create(char *str) // Function to create new node
{
    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->str=malloc(strlen(str)+1);
    strcpy(new1->str,str);
    new1->left = NULL;
    new1->right = NULL;
    return new1;
}

struct node *insert(struct node *root, char *str) // Function to insert a node
{
    if (root == NULL)
    {
        root = create(str);
    }
    else if (strcmp(str, root->str) < 0)
    {
        root->left = insert(root->left, str);
    }
    else if (strcmp(str, root->str) > 0)
    {
        root->right = insert(root->right, str);
    }
    return root;
}

int binarySearch(char arr[], char x,int n)
    {
        int l = 0 ;
        int r = n - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
 
        int res = -1000;   //some random value assigned because if res is already 0 then
                             //it will always return 0    
        if (x == (arr[m]))
            res = 0;
             
 
            // Check if x is present at mid
            if (res == 0)
                return m;
 
            // If x greater, ignore left half
            if (x > (arr[m]))
                l = m + 1;
 
            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
 
        return -1;
    }


int main()
{
    char *str;
    while (1)
    {
        printf("Enter SRN of the students: \n");
        printf("enter -1 to end insertion\n");
        scanf("%s", str);
        if (strcmp(str, "-1") == 0)
        {
            break;
        }
        else
        {
            root = insert(root, str);
        }
    }
    printf("\nThe SRN in ascending order is: ");
    preorder(root);
    printf("\n enter a string to search:\n");
    // scanf("%s",&str);
    return 0;
}
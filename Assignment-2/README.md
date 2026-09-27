#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int value)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}


void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int bstSearch(struct Node* root, int key, int *comparisons)
{
    while (root != NULL)
    {
        (*comparisons)++;

        if (key == root->data)
        {
            return 1;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return 0;
}


int linearSearch(int arr[], int n, int key, int *comparisons)
{
    for (int i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] == key)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    struct Node* root = NULL;

    int values[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int n = 9;

    int searchValues[] = {25, 55, 90};

    /* Construct BST */
    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    /* Display traversals */
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n\n");

    /* Searching */
    for (int i = 0; i < 3; i++)
    {
        int key = searchValues[i];

        int bstComparisons = 0;
        int linearComparisons = 0;

        int bstResult = bstSearch(root, key, &bstComparisons);
        int linearResult = linearSearch(values, n, key, &linearComparisons);

        printf("Searching for %d\n", key);

        if (bstResult)
            printf("BST Search: Found\n");
        else
            printf("BST Search: Not Found\n");

        printf("BST Comparisons: %d\n", bstComparisons);

        if (linearResult)
            printf("Linear Search: Found\n");
        else
            printf("Linear Search: Not Found\n");

        printf("Linear Comparisons: %d\n\n", linearComparisons);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

int bstComparisons = 0;
int linearComparisons = 0;

Node* createNode(int key) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int bstSearch(Node *root, int key) {
    bstComparisons = 0;

    while (root != NULL) {
        bstComparisons++;

        if (key == root->key)
            return 1;
        else if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int linearSearch(int arr[], int n, int key) {
    linearComparisons = 0;

    for (int i = 0; i < n; i++) {
        linearComparisons++;

        if (arr[i] == key)
            return 1;
    }

    return 0;
}

void displaySearchResult(Node *root, int arr[], int n, int key) {
    int bstFound = bstSearch(root, key);
    int bstCount = bstComparisons;

    int linearFound = linearSearch(arr, n, key);
    int linearCount = linearComparisons;

    printf("%d\t%s\t\t%d\t\t%s\t\t%d\n",
           key,
           bstFound ? "Found" : "Not Found",
           bstCount,
           linearFound ? "Found" : "Not Found",
           linearCount);
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int keys[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int searchKeys[] = {25, 55, 90};
    int n = sizeof(keys) / sizeof(keys[0]);

    Node *root = NULL;

    printf("DSA ASSIGNMENT 2 - QUESTION 2\n");
    printf("Name: Anirudh J\n");
    printf("Roll No: 10\n\n");

    printf("ISBN keys:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", keys[i]);
        root = insert(root, keys[i]);
    }

    printf("\n\nBST Traversals\n");
    printf("Inorder   : ");
    inorder(root);
    printf("\n");

    printf("Preorder  : ");
    preorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");

    printf("\nBST Structure:\n");
    printf("             45\n");
    printf("           /    \\\n");
    printf("         20      60\n");
    printf("        /  \\    /  \\\n");
    printf("      10   30  50   70\n");
    printf("          /      \\\n");
    printf("         25       55\n");

    printf("\nSearch Results\n");
    printf("Key\tBST Result\tBST Comparisons\tLinear Result\tLinear Comparisons\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++)
        displaySearchResult(root, keys, n, searchKeys[i]);

    printf("\nBST Height: 3 edges (4 levels)\n");

    freeTree(root);
    return 0;
}

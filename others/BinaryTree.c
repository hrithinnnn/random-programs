#include<stdio.h>
#include<malloc.h>

typedef struct {
    int data;
    BinaryTree *left;
    BinaryTree *right;
} BinaryTree;

typedef enum Direction {
    LEFT, RIGHT
} Direction;

BinaryTree* newNode(int data) {
    BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void addNode(BinaryTree**, int, int, Direction);
BinaryTree* search(BinaryTree* root, int data) {
    if(root == NULL) return NULL;
    if(root->data == data) return root;

    BinaryTree* leftScout;
    BinaryTree* rightScout;

    if(root->left != NULL) leftScout = search(root->left, data);
    if(root->right != NULL) rightScout = search(root->right, data);

    return (leftScout != NULL) ? leftScout : rightScout;
}

int main() {
    BinaryTree* root;

    addNode(&root, 5, 6, LEFT);

    addNode(&root, 10, 5, RIGHT);
    
    return 0;
}

void addNode(BinaryTree** root, int data,int dest, Direction dir) {
    if(root == NULL) {
        root = newNode(data);
        return;
    }

    BinaryTree* result = search(*root, dest);

    if(result == NULL) return;

    if(dir == LEFT && result->left == NULL) {
        result->left = newNode(data);
        return;
    } 
    
    if(dir == RIGHT && result->right == NULL) {
        result->right = newNode(data);
        return;
    }

    BinaryTree* temp = (dir == LEFT) ? result->left : result->right;

    if(dir == LEFT) {
        result->left = newNode(data);
        result->left->left = temp;
    } else {
        result->right = newNode(data);
        result->right->right = temp;
    }
}
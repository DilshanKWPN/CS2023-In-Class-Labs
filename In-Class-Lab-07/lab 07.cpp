#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

struct node* New_node(int data) {
    node* temp = new node();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Inorder traversal
void traverseInOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node* insertNode(struct node* node, int key) {

    if (node == NULL) {
        return New_node(key);
    }
    else if (node->key < key)
    {
        node->right = insertNode(node->right, key);
    }
    else
    {
        node->left = insertNode(node->left, key);
    }

    return node;
}

// Deleting a node

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->key < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (root->key > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }
        else if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        else
        {
            struct node* nextNode = root->right;
            while (nextNode != NULL && nextNode->left != NULL)
            {
                nextNode = nextNode->left;
            }

            root->key = nextNode->key;
            root->right = deleteNode(root->right, nextNode->key);

        }
    }
    return root;
}

// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {

        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}
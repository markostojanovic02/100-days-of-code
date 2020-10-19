#include <cstdlib>
#include <iostream>

//Declaring Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

//Creating Node
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

bool CountUnivalTrees(Node *root, int &counter)
{
    //If our tree has no subtrees then it's unival
    if(root == NULL)
        return true;

    //Recursion function
    bool left = CountUnivalTrees(root->left, counter);
    bool right = CountUnivalTrees(root->right, counter);

    //If one of the trees is not unival our current tree can't be unival either
    if(left == false || right == false)
        return false;

    //Checking if left child exists and if data is same as root data
    if(root->left && root->data != root->left->data)
        return false;

    //Checking if right child exists and if data is same as root data
    if(root->right && root->data != root->right->data)
        return false;

    //If all if's are passed increase counter and return true
    ++counter;
    return true;
}

//Function that helps us count all unival nodes
int CounterHelper(Node *root) {
    int counter = 0;

    CountUnivalTrees(root, counter);

    return counter;
}

int main()
{
    //Initalization of tree
    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->right->left = newNode(2);
    root->right->right = newNode(2);
    root->right->left->right = newNode(2);

    //Printing everything out
    std::cout << CounterHelper(root);

    return EXIT_SUCCESS;
}

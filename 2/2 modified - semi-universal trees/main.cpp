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

bool CountUnivalTrees(Node *root, int &unival_counter)
{
    if (root == NULL)
        return true;

    bool left = CountUnivalTrees(root->left, unival_counter);
    bool right = CountUnivalTrees(root->right, unival_counter);

    if(left == false || right == false)
        return false;

    if(root->left && root->data != root->left->data)
        return false;

    if(root->right && root->data != root->right->data)
        return false;

    ++unival_counter;
    return true;
}

int NumberCounter(int first, int second, int third)
{
    int numbers = 1;

    if(first != second)
        ++numbers;

    if(third != second && third != first)
        ++numbers;

    return numbers;
}

bool CountSemiUnivalTrees(Node *root, int &semiunival_counter)
{
    if(root == NULL)
        return true;

    bool left = CountSemiUnivalTrees(root->left, semiunival_counter);
    bool right = CountSemiUnivalTrees(root->right, semiunival_counter);

    if(left == false || right == false)
        return false;

    if(root->left && root->right) {
        if (NumberCounter(root->data, root->left->data, root->right->data) == 2)
            ++semiunival_counter;
    }

    if(root->left == NULL && root->right != NULL)
        ++semiunival_counter;
    if(root->right == NULL && root->left != NULL)
        ++semiunival_counter;

    return true;
}

int UnivalCounterHelper(Node *root) {
    int unival_counter = 0;

    CountUnivalTrees(root, unival_counter);

    return unival_counter;
}

int SemiUnivalCounterHelper(Node *root) {
    int semiunival_counter = 0;

    CountSemiUnivalTrees(root, semiunival_counter);

    return semiunival_counter;
}

int main()
{
    Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(1);
    root->left->left->left = newNode(1);
    root->left->left->right = newNode(2);
    root->right->left = newNode(3);
    root->right->right = newNode(3);

    int universal = UnivalCounterHelper(root);
    int semi = SemiUnivalCounterHelper(root);
    std::cout << "Number of universal value trees: " << universal << "\n";
    std::cout << "Number of semi-universal value trees: " << semi << "\n";
    std::cout << "Total number of universal and semi-universal value trees is: "
    << universal + semi << "\n";

    return EXIT_SUCCESS;
}

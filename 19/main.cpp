#include <bits/stdc++.h>

typedef long long int ll;

//Creating node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->left = tmp->right = NULL;

    return tmp;
}

//Mapping out sum of all levels
std::map<int, ll> pos;
//Function that sums all numbers up
void countingLevels(Node *root, ll currentLevel) {
    pos[currentLevel] += root->data;

    //Recursively make our tree
    if (root->left != NULL)
        countingLevels(root->left, currentLevel+1);
    if (root->right != NULL)
        countingLevels(root->right, currentLevel+1);
}

int main()
{
    //Input of our binary tree
    Node *root = newNode(14);
    root->left = newNode(15);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(2);
    root->right->left = newNode(1);
    root->right->right = newNode(2);
    root->left->left->right = newNode(1);
    root->right->left->left = newNode(1);

    //Calling our function
    countingLevels(root, 0);
    //Getting smallest number and its position (aka index, level)
    ll smallestNumber, index;
    for (auto i : pos) {
        if (i.second < smallestNumber) {
            smallestNumber = i.second;
            index = i.first;
        }
    }
    //Printing level out
    std::cout << index;
    return 0;
}

#include <cstdlib>
#include <iostream>

//Declaring Node
struct Node
{
    int data;
    Node *child1;
    Node *child2;
    Node *child3;
    Node *child4;
    Node *child5;
};

//Creating Node
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->child1 = NULL;
    temp->child2 = NULL;
    temp->child3 = NULL;
    temp->child4 = NULL;
    temp->child5 = NULL;

    return temp;
}

bool CountUnivalTrees(Node *root, int &counter)
{
    //If our tree has no subtrees then it's unival
    if(root == NULL)
        return true;

    //Recursion function
    bool child1 = CountUnivalTrees(root->child1, counter);
    bool child2 = CountUnivalTrees(root->child2, counter);
    bool child3 = CountUnivalTrees(root->child3, counter);
    bool child4 = CountUnivalTrees(root->child4, counter);
    bool child5 = CountUnivalTrees(root->child5, counter);

    //If one of the trees is not unival our current tree can't be unival either
    if(child1 == false || child2 == false || child3 == false || child4 == false || child5 == false)
        return false;

    if(root->child1 && root->data != root->child1->data)
        return false;

    if(root->child2 && root->data != root->child2->data)
        return false;

    if(root->child3 && root->data != root->child3->data)
        return false;

    if(root->child4 && root->data != root->child4->data)
        return false;

    if(root->child5 && root->data != root->child5->data)
        return false;

    ++counter;
    return true;
}

int CounterHelper(Node *root) {
    int counter = 0;

    CountUnivalTrees(root, counter);

    return counter;
}

int main()
{
    Node *root = newNode(1);
    root->child1 = newNode(0);
    root->child2 = newNode(1);
    root->child3 = newNode(0);
    root->child4 = newNode(1);
    root->child5 = newNode(1);
    root->child1->child1 = newNode(0);
    root->child1->child2 = newNode(0);
    root->child2->child1 = newNode(0);
    root->child2->child2 = newNode(1);
    root->child3->child1 = newNode(0);
    root->child3->child2 = newNode(0);
    root->child3->child3 = newNode(0);
    root->child5->child1 = newNode(0);
    root->child5->child2 = newNode(1);
    root->child5->child3 = newNode(1);
    root->child5->child4 = newNode(0);
    root->child5->child5 = newNode(1);


    std::cout << CounterHelper(root);

    return EXIT_SUCCESS;
}

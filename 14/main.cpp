#include<bits/stdc++.h>

typedef std::pair<int, int> p;

//Main structure
struct Stack
{
    int counter = 0;
    //We did this using priority queue
    std::priority_queue<p> pq;

    //Initialization of all functions
    void push(int data);
    void pop();
    void top();
    bool isEmpty();
};

//Pushing item to stack
void Stack::push(int data)
{
    ++counter;
    pq.push(p(counter, data));
}

//Popping item out of stack
void Stack::pop()
{
    //If in here to solve possible errors
    if (!pq.empty()) {
        --counter;
        pq.pop();
    }
}

//If we need to write certain item out of stack
void Stack::top()
{
    //If stack is empty print error
    if (pq.empty()) {
        std::cout << "error\n";
    } else {
        p tmp = pq.top();
        std::cout << tmp.second << " ";
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input of numbers
    int N;
    std::cin >> N;

    //Pushing all numbers into stack
    int k;
    Stack *s = new Stack;
    for (int i = 0; i < N; ++i) {
        std::cin >> k;
        s->push(k);
    }

    /* Printing numbers from stack and popping them, we said i <= N
     so it prints error at the end because stack is empty */
    for (int i = 0; i <= N; ++i) {
        s->top();
        s->pop();
    }

    return 0;
}

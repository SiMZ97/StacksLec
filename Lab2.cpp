// Siavash Mehrabani, Robi Reyes, Sean Earl Tabarejo
// Lab #2 Postfix Stack

#include <iostream> 
#include <sstream> 
using namespace std;

const int MAX_SIZE = 10;

struct Stack {
    int data[MAX_SIZE];
    int top;
};

static void initStack(Stack& s) {
    s.top = -1;
}

static bool isEmpty(const Stack& s) {
    return s.top == -1;
}

static bool isFull(const Stack& s) {
    return s.top == MAX_SIZE - 1;
}

static void push(Stack& s, int item) {
    if (isFull(s)) {
        return;
    }
    else {
        s.data[++(s.top)] = item;
    }
}

static int pop(Stack& s) {
    if (isEmpty(s)) {
        return -1;
    }
    else {
        return s.data[(s.top)--];
    }
}

static bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

static int doOperation(int a, int b, char op) {

    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else if (op == '*') {
        return a * b;
    }
    else if (op == '/') {
        return a / b;
    }
    else {
        return 0;
    }
}

int evaluate(const string & expression) {
    Stack s;
    initStack(s);
    for (char c : expression) {
        if (isdigit(c)) {
            push(s, c - '0');
        }
        if (isOperator(c)) {
            int b = pop(s);
            int a = pop(s);
            push(s, doOperation(a, b, c));
        }
    }
    return pop(s);
}

int main() {

    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    cout << evaluate(expression) << endl;
    return 0;
}
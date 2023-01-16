/*
DSA-PRACTICAL-03

Name:	 Pranav Dighade
Roll No: D48
Subject: DSA

AIM:Implement Stack using a linked list. Use this stack to perform evaluation of a postfix expression.

*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int evaluatePostfix(string exp)
{
    Stack s;
    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
            continue;
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(num);
        }
        else {
            int val1 = s.pop();
            int val2 = s.pop();
            switch (exp[i])
            {
            case '+': s.push(val2 + val1); break;
            case '-': s.push(val2 - val1); break;
            case '*': s.push(val2 * val1); break;
            case '/': s.push(val2 / val1); break;
            }
        }
    }
    return s.pop();
}

int main()
{
    string exp = "10 20 * 30 40 10 / - +";
    cout << "postfix evaluation: " << evaluatePostfix(exp);
    return 0;
}

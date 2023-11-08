/*
 * Author:
 * Date:
 * Name:
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

    Stack() {
        top = nullptr;
    }
    

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        cout << value << " pushed to the stack." << endl;
    }
    
   
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
        } else {
            Node* temp = top;
            top = top->next;
            cout << temp->data << " popped from the stack." << endl;
            delete temp;
        }
    }
    
   
    int topValue() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform top operation." << endl;
            return -1;
        }
        return top->data;
    }
    
    
    bool isEmpty() {
        return top == nullptr;
    }
};


int main() {
    Stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    

    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }
    
  
    cout << "Top element: " << stack.topValue() << endl;
    

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    
    return 0;
}

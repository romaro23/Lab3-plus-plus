
#include <iostream>
using namespace std;
struct Node {
    int n;
    Node* next;
    Node(int _n) : n(_n), next(nullptr){}
};
struct Stack {
    Node* head;
    Stack(): head(nullptr){}
    void push(int _n) {
        Node* node = new Node(_n);
        if (head == nullptr) {
            head = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }
    void pop() {
        Node* current = head;
        head = head->next;
        delete current;
    }
    void swap() {
        Node* current = head;
        Node* temp = head;
        while (current->next->next) {
            current = current->next;
        }
        current->next->next = head->next;
        head = current->next;
        current->next = temp;
        temp->next = nullptr;
    }
    void reverse() {
        Stack temp;
        int length = getLength();
        for (int i = 0; i < length; i++) {
            temp.push(top());
            pop();
        }
        head = temp.head;
    }
    bool ifBelongs(int _n) {
        Node* current = head;
        while (current) {
            if (current->n == _n) {
                cout << _n << " belongs to this stack" << endl;
                return true;
            }
            current = current->next;
        }
        cout << _n << " doesn't belong to this stack" << endl;
        return false;
    }
    void clear() {
        while (head) {
            pop();
        }
    }
    int getLength() {
        Node* current = head;
        int count = 1;
        while (current->next) {
            count++;
            current = current->next;
        }
        return count;
    }
    int top() {
        return head->n;
    }
    void print() {
        Node* current = head;
        while (current) {
            cout << current->n << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack stack;
    stack.push(5);
    stack.push(4);
    stack.push(8);
    stack.push(1);
    stack.print();
    stack.reverse();
    stack.print();
    stack.ifBelongs(7);
    stack.clear();
    stack.print();
}


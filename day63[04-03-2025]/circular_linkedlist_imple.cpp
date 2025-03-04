#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CList {
public:
    Node* head;
    Node* tail;

    CList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LinkedList is empty\n";
            return;
        }
        if (head == tail) { // Only one element
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "LinkedList is empty\n";
            return;
        }
        if (head == tail) { // Only one element
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }

    void printLL() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD\n";
    }

    void insert_pos(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 1) {
            push_front(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    void delete_pos(int pos) {
        if (pos <= 0 || head == NULL) {
            cout << "Invalid position or list empty\n";
            return;
        }
        if (pos == 1) {
            pop_front();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) {
            cout << "Position out of bounds\n";
            return;
        }
        Node* valDel = temp->next;
        temp->next = temp->next->next;
        if (valDel == tail) {
            tail = temp;
        }
        delete valDel;
    }

    int search_key(int key) {
        if (head == NULL) return -1;
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) return pos;
            pos++;
            temp = temp->next;
        } while (temp != head);
        return -1;
    }
};

int main() {
    CList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printLL();
    
    ll.push_front(-1);
    ll.push_front(-2);
    ll.printLL();

    ll.pop_front();
    ll.pop_front();
    ll.printLL();

    ll.pop_back();
    ll.printLL();

    ll.insert_pos(2, 3);
    ll.printLL();

    ll.delete_pos(3);
    ll.printLL();

    cout << "Search 4: " << ll.search_key(4) << endl;

    return 0;
}

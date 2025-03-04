#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

//SINGLY LINKED_LIST

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"linkedlist is empty"<<endl;
            return;
        }else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete(temp);
            return;
        }
    }

    void pop_back(){
        if(tail == NULL){
            cout<<"linkedlist is empty"<<endl;
            return;
        }else{
            Node* temp = head;
            while (temp->next != tail){
                temp = temp->next;
            }

            // Node* last = temp->next;
            // temp->next = NULL;
            // delete(last);
            // return;

            temp->next = NULL;
            delete tail;
            tail = temp;

        }
    }

        void printLL(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
            return;
        }

        void insert_pos(int val , int pos){

            if(pos < 0){
                cout<<"invalid pos\n";
                return;
            }
            
            if(pos == 1){
                push_front(val);
                return;
            }
            Node* newNode =  new Node(val); 

            
            Node* temp = head;
            // int idx = 1;
            // while(temp != NULL){
            //     if(idx == pos-1){
            //       temp->next = newNode;
            //       newNode->next = temp->next;
            //       return;
            //     }

            //     idx++;
            //     temp = temp->next;
            // }

            for(int i = 1 ; i < pos-1 ; i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void delete_pos(int pos){
            
            if(pos == 1){
                pop_front();
                return;
            }
            

            
            Node* temp = head;
            // int idx = 1;
            // while(temp != NULL){
            //     if(idx == pos-1){
            //       temp->next = newNode;
            //       newNode->next = temp->next;
            //       return;
            //     }

            //     idx++;
            //     temp = temp->next;
            // }

            for(int i = 1 ; i < pos-1 ; i++){
                temp = temp->next;
            }

           
            Node* valDel = temp->next;
            temp->next = temp->next->next;
            delete(valDel);
        }

        int search_key(int key){
            Node* temp = head;
            int pos = 1;
            while (temp != NULL)
            {
                if(temp->data == key){
                    return pos;
                }
                pos++;
                temp = temp->next;
            }
            return -1;
            
        }

    
};
int main(){

    List ll;

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
    ll.insert_pos(2 , 3);
    ll.printLL();
    ll.delete_pos(3);
    ll.printLL();
    cout<<ll.search_key(4)<<endl;
    

}


//SOME EDGE CASES

// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class List {
// public:
//     Node* head;
//     Node* tail;

//     List() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node* newNode = new Node(val);
//         if (head == NULL) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     void push_back(int val) {
//         Node* newNode = new Node(val);
//         if (tail == NULL) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop_front() {
//         if (head == NULL) {
//             cout << "Linked list is empty\n";
//             return;
//         }
//         Node* temp = head;
//         head = head->next;
//         if (head == NULL) tail = NULL;
//         delete temp;
//     }

//     void pop_back() {
//         if (head == NULL) {
//             cout << "Linked list is empty\n";
//             return;
//         }
//         if (head == tail) {
//             delete head;
//             head = tail = NULL;
//             return;
//         }
//         Node* temp = head;
//         while (temp->next != tail) {
//             temp = temp->next;
//         }
//         delete tail;
//         temp->next = NULL;
//         tail = temp;
//     }

//     void printLL() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << temp->data << "->";
//             temp = temp->next;
//         }
//         cout << "NULL\n";
//     }

//     void insert_pos(int val, int pos) {
//         if (pos <= 0) {
//             cout << "Invalid position\n";
//             return;
//         }
//         if (pos == 1) {
//             push_front(val);
//             return;
//         }
//         Node* temp = head;
//         for (int i = 1; i < pos - 1 && temp != NULL; i++) {
//             temp = temp->next;
//         }
//         if (temp == NULL) {
//             cout << "Position out of bounds\n";
//             return;
//         }
//         Node* newNode = new Node(val);
//         newNode->next = temp->next;
//         temp->next = newNode;
//         if (newNode->next == NULL) tail = newNode;
//     }

//     void delete_pos(int pos) {
//         if (pos <= 0 || head == NULL) {
//             cout << "Invalid position\n";
//             return;
//         }
//         if (pos == 1) {
//             pop_front();
//             return;
//         }
//         Node* temp = head;
//         for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
//             temp = temp->next;
//         }
//         if (temp->next == NULL) {
//             cout << "Position out of bounds\n";
//             return;
//         }
//         Node* valDel = temp->next;
//         temp->next = temp->next->next;
//         if (temp->next == NULL) tail = temp;
//         delete valDel;
//     }

//     int search_key(int key) {
//         Node* temp = head;
//         int pos = 1;
//         while (temp != NULL) {
//             if (temp->data == key) {
//                 return pos;
//             }
//             pos++;
//             temp = temp->next;
//         }
//         return -1;
//     }
// };

// int main() {
//     List ll;
//     ll.push_back(1);
//     ll.push_back(2);
//     ll.push_back(3);
//     ll.push_back(4);
//     ll.push_back(5);
//     ll.printLL();
    
//     ll.push_front(-1);
//     ll.push_front(-2);
//     ll.printLL();

//     ll.pop_front();
//     ll.pop_front();
//     ll.printLL();

//     ll.pop_back();
//     ll.printLL();

//     ll.insert_pos(2, 3);
//     ll.printLL();

//     ll.delete_pos(3);
//     ll.printLL();

//     cout << ll.search_key(4) << endl;

//     return 0;
// }

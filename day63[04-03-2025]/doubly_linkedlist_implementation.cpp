#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

};

//DOUBLY LINKED_LIST

class DList{
    public:
    Node* head;
    Node* tail;

    DList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head->prev = newNode;
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
            newNode->prev = tail;
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
                cout<<temp->data<<"<=>";
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
            newNode->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
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
            temp->next->next->prev = temp;
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

    DList ll;

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




// Issues in the Code
// pop_front() does not handle the case when head becomes NULL

// After removing the first node, if the list becomes empty, tail should also be set to NULL.
// pop_back() does not update tail->prev correctly

// The tail should be updated correctly when removing the last node.
// insert_pos() might cause segmentation fault

// If pos is greater than the length of the linked list, temp->next will be NULL, causing an error when accessing newNode->next->prev = newNode.
// delete_pos() may cause segmentation fault when deleting the last node

// The line temp->next->next->prev = temp; assumes temp->next->next exists, but if the last node is deleted, it will be NULL.
 


// #include<bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int val) {
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };

// // DOUBLY LINKED LIST
// class DList {
// public:
//     Node* head;
//     Node* tail;

//     DList() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//     }

//     void push_back(int val) {
//         Node* newNode = new Node(val);
//         if (!tail) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     void pop_front() {
//         if (!head) {
//             cout << "Linked list is empty" << endl;
//             return;
//         }
//         Node* temp = head;
//         head = head->next;
//         if (head) head->prev = NULL;
//         else tail = NULL;
//         delete temp;
//     }

//     void pop_back() {
//         if (!tail) {
//             cout << "Linked list is empty" << endl;
//             return;
//         }
//         Node* temp = tail;
//         tail = tail->prev;
//         if (tail) tail->next = NULL;
//         else head = NULL;
//         delete temp;
//     }

//     void printLL() {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data << " <=> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
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

//         Node* newNode = new Node(val);
//         Node* temp = head;

//         for (int i = 1; temp && i < pos - 1; i++) {
//             temp = temp->next;
//         }

//         if (!temp) {
//             cout << "Position out of bounds\n";
//             delete newNode;
//             return;
//         }

//         newNode->next = temp->next;
//         if (temp->next) temp->next->prev = newNode;
//         temp->next = newNode;
//         newNode->prev = temp;

//         if (newNode->next == NULL) tail = newNode; // Update tail if inserted at the end
//     }

//     void delete_pos(int pos) {
//         if (pos <= 0) {
//             cout << "Invalid position\n";
//             return;
//         }

//         if (pos == 1) {
//             pop_front();
//             return;
//         }

//         Node* temp = head;
//         for (int i = 1; temp && i < pos; i++) {
//             temp = temp->next;
//         }

//         if (!temp) {
//             cout << "Position out of bounds\n";
//             return;
//         }

//         if (temp->next) temp->next->prev = temp->prev;
//         if (temp->prev) temp->prev->next = temp->next;

//         if (temp == tail) tail = temp->prev; // Update tail if last node is deleted

//         delete temp;
//     }

//     int search_key(int key) {
//         Node* temp = head;
//         int pos = 1;
//         while (temp) {
//             if (temp->data == key) return pos;
//             pos++;
//             temp = temp->next;
//         }
//         return -1;
//     }
// };

// int main() {
//     DList ll;

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

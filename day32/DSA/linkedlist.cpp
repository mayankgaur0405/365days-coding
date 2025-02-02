#include<bits/stdc++.h>
using namespace std;
class Node{
    public :

    int data;
    Node* next;

    Node(int value){
       data = value;
       next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public :

    List(){
        head = tail = NULL;
    }

    
    //function to push in front of a linkedlist
    void push_front(int x){
      Node* newNode = new Node(x);

      if(head == NULL){
        head = tail = newNode;
      }else{
        newNode->next = head;
        head = newNode;
      }
    }

    //function to print a linkedlist

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    //function to push back in a linkedlist

    void push_back(int x){
        Node* newNode = new Node(x);
        if(tail == NULL){
            head = tail = newNode;
        }else{
          tail->next = newNode;
          tail = tail->next;
        }
        
    }

    void pop_front(){
        if(head == NULL){
            cout<<"No Node is present"<<endl;
            return;
        }else{
            Node* temp = head;
            head = head->next;
            delete(temp);
        }
    }

    void pop_back(){
        if(tail == NULL){
            cout<<"No Node is present"<<endl;
        }else{
            Node* temp = head;

            while(temp->next != tail){
                temp = temp->next;
            }

            Node* last = temp->next;
            temp->next = NULL;
            delete(last);
            tail = temp;
        }
    }

    void insert(double val , int pos){
        if(pos<0){
            cout<<"Invalid position"<<endl;
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        else{
            Node* temp = head;
            for(int i = 0 ; i < pos-1 ; i++){
              temp = temp->next;
            }

            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int search(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }else{
                idx++;
                temp = temp->next;
            }
        }

        return -1;
    }


};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    
    //printing linkedlist
    ll.printLL();
    
    //implementing push_back function
    ll.push_back(6);

    //printing linkedlist
    ll.printLL();

    //implementing pop_front
    ll.pop_front();

    //printing linkedlist
    ll.printLL();

    //implementing pop_back
    ll.pop_back();

    //printing linkedlist
    ll.printLL();

    //implementing insert function
    ll.insert(2.5 , 3);

    //printing linkedlist
    ll.printLL();

    //implementing search function
    int key = 2;
    cout<<key<<" is found at index "<<ll.search(key)<<endl;


    return 0;
}
#include<bits/stdc++.h>
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


Node* reverse(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;

  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
};
int main(){
    list<int> ll;
    int n;
    cout<<"enter the number of nodes you want"<<endl;
    cin>>n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0 ; i < n ; i++){
        int val;
        cout<<"enter " <<i<<"th node"<<endl; 
        cin>>val;

        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        
    }

    Node* headrr = reverse(head);

    while(headrr != NULL){
        cout<<headrr->data<<"->";
        headrr = headrr->next;
    }

    cout<<"NULL"<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//below code is the implementation of stack using linkedlist
class Stack{
  list<int> ll;

  public: 
  
  void push(int x){
        ll.push_front(x);
    }

    void pop(){
       ll.pop_front(); 
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }


};
//Below is the implementation of stack using vector

// class Stack{
//     vector<int> vec;

//     public:


//     void push(int x){
//         vec.push_back(x);
//     }

//     void pop(){
//        vec.pop_back(); 
//     }

//     int top(){
//         return vec[vec.size() - 1];
//     }

//     bool empty(){
//         return vec.size() == 0;
//     }

// };
int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
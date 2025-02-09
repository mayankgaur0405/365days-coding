#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(arr.size());
    stack<int> s;
    for(int i = arr.size() - 1 ; i >= 0 ; i--){
       while(s.size() > 0 && s.top() <= arr[i]){
        s.pop();
       }

       if(s.size() == 0){
           ans[i] = -1;
           s.push(arr[i]);
       }

       if(s.top() > arr[i]){
          ans[i] = s.top();
          s.push(arr[i]);
       }

    }
    
    
       for(auto val : ans){
        cout<<val<<endl;
       }
    return 0;
}
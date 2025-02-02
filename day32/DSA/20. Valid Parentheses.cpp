// class Solution {
// public:
//     bool isValid(string str) {

//         stack<char> s;

//         for(int i = 0 ; i < str.length() ; i++){
//             if(str[i] == '{' || str[i] == '(' || str[i] == '['){
//               s.push(str[i];)
//             }else{
//                 if(s.size() == 0){
//                     return false;
//                 }
//                 if(s.top() == '{' && s[i] == '}'||
//                 s.top() == '[' && s[i] == ']' ||
//                 s.top() == '(' && s[i] == ')' ){
//                     s.pop();
//                 }else{
//                     return false;
//                 }
//             }
//         }

//         return s.size() == 0;
        
//     }
// };
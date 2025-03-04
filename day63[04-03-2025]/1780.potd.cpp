// class Solution {
//     public:
//         bool checkPowersOfThree(int num) {
//             int p = 0;
//             while(pow(3 , p) <= num){
//                 p++;
//             }
    
//             while(num > 0){
//                 if(num >= pow(3 , p)){
//                     num = num - pow(3 , p);
//                 }
    
//                 if(num >= pow(3,p)){
//                     return false;
//                 }
    
//                 p--;
//             }
    
//             return true;
            
//         }
//     };
// class Solution {
//     public:
//        int countDigit(int num){
//         int count = 0;
//         while(num>0){
//             count++;
//             num /= 10;
//         }
//         return count;
//        }
//         int findNumbers(vector<int>& nums) {
//             int evenCount = 0;
//             for(auto n : nums){
//                 if(countDigit(n) % 2 == 0){
//                      evenCount++;
//                 }
//             }
//             return evenCount;
//         }
//     };
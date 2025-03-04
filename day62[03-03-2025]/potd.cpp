// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int less = 0;
//         int equal = 0;
//         int n = nums.size();
//         vector<int> res(n);
        
//         for(int i = 0 ; i < nums.size() ; i++){
//             if(nums[i] < pivot){
//                 less++;
//             }else if(nums[i] == pivot){
//                 equal++;
//             }
//         }

//         int i = 0;
//         int j = less;
//         int k = less + equal;

//         for(int idx = 0 ; idx <  n ; idx++){
//             if(nums[idx] < pivot){
//                 res[i] = nums[idx];
//                 i++;
//             }else if(nums[idx] == pivot){
//                 res[j] = pivot;
//                 j++;
//             }else{
//                 res[k] = nums[idx];
//                 k++;
//             }
//         }
//         return res;
//     }
// };
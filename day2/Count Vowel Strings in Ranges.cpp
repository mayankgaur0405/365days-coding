// class Solution {
// public:
// bool isVowel(char ch){
//     if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
//         return true;
//     }
//     return false;
// }
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

//         int n = words.size();
//         vector<int>currvowel(n);
//         vector<int>result(queries.size());
//         int sum = 0;

//         for(int i = 0 ; i < n ; i++){
//             if(isVowel(words[i][0])  && isVowel(words[i].back())){
//                 sum++;
//                 currvowel[i] = sum; 
//             }else{
//                 currvowel[i] = sum;
//             }
//         }

//         for(int i = 0 ; i < queries.size() ; i++){
//             int l = queries[i][0];
//             int r = queries[i][1];

//             result[i] = currvowel[r] - ((l>0)? currvowel[l-1] : 0);

//         }

//         return result;
        
//     }
// };
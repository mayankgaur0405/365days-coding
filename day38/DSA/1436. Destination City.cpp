// class Solution {
//     public:
//         string destCity(vector<vector<string>>& paths) {
//             unordered_map<string, int> count;
    
//             for (auto& path : paths) {
//                 count[path[0]]++;
//             }
    
//             for (auto& path : paths) {
//                 if (count.find(path[1]) == count.end()) {
//                     return path[1];
//                 }
//             }
    
//             return "";
//         }
//     };
    
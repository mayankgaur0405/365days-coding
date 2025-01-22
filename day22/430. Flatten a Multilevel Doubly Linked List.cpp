// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };
// */


// class Solution {
// public:
//     Node* flatten(Node* head) {
//         if (!head) return head;

//         Node* curr = head;

//         while (curr) {
//             // If the current node has a child
//             if (curr->child) {
//                 Node* nextNode = curr->next; // Save the next node

//                 // Flatten the child list and connect it
//                 Node* childHead = flatten(curr->child);
//                 curr->next = childHead;
//                 childHead->prev = curr;

//                 // Clear the child pointer
//                 curr->child = nullptr;

//                 // Move to the end of the flattened child list
//                 while (curr->next) {
//                     curr = curr->next;
//                 }

//                 // Reconnect the saved next node, if any
//                 if (nextNode) {
//                     curr->next = nextNode;
//                     nextNode->prev = curr;
//                 }
//             }
//             // Move to the next node in the list
//             curr = curr->next;
//         }

//         return head;
//     }
// };

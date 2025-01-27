// 26-01-2025

// QUESTION 1 : (2127. Maximum Employees to Be Invited to a Meeting)

// enum class State { kInit, kVisiting, kVisited };

// class Solution {
//  public:
//   int maximumInvitations(vector<int>& favorite) {
//     const int n = favorite.size();
//     int sumComponentsLength = 0;  // the component: a -> b -> c <-> x <- y
//     vector<vector<int>> graph(n);
//     vector<int> inDegrees(n);
//     vector<int> maxChainLength(n, 1);
//     queue<int> q;

//     // Build the graph.
//     for (int i = 0; i < n; ++i) {
//       graph[i].push_back(favorite[i]);
//       ++inDegrees[favorite[i]];
//     }

//     // Perform topological sorting.
//     for (int i = 0; i < n; ++i)
//       if (inDegrees[i] == 0)
//         q.push(i);

//     while (!q.empty()) {
//       const int u = q.front();
//       q.pop();
//       for (const int v : graph[u]) {
//         if (--inDegrees[v] == 0)
//           q.push(v);
//         maxChainLength[v] = max(maxChainLength[v], 1 + maxChainLength[u]);
//       }
//     }

//     for (int i = 0; i < n; ++i)
//       if (favorite[favorite[i]] == i)
//         // i <-> favorite[i] (the cycle's length = 2)
//         sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]];

//     int maxCycleLength = 0;  // the cycle : a -> b -> c -> a
//     vector<int> parent(n, -1);
//     vector<bool> seen(n);
//     vector<State> states(n);

//     for (int i = 0; i < n; ++i)
//       if (!seen[i])
//         findCycle(graph, i, parent, seen, states, maxCycleLength);

//     return max(sumComponentsLength / 2, maxCycleLength);
//   }

//  private:
//   void findCycle(const vector<vector<int>>& graph, int u, vector<int>& parent,
//                  vector<bool>& seen, vector<State>& states,
//                  int& maxCycleLength) {
//     seen[u] = true;
//     states[u] = State::kVisiting;

//     for (const int v : graph[u]) {
//       if (!seen[v]) {
//         parent[v] = u;
//         findCycle(graph, v, parent, seen, states, maxCycleLength);
//       } else if (states[v] == State::kVisiting) {
//         // Find the cycle's length.
//         int curr = u;
//         int cycleLength = 1;
//         while (curr != v) {
//           curr = parent[curr];
//           ++cycleLength;
//         }
//         maxCycleLength = max(maxCycleLength, cycleLength);
//       }
//     }

//     states[u] = State::kVisited;
//   }
// };


// QUESTION 2 : (138. Copy List with Random Pointer)

// class Solution {
//  public:
//   Node* copyRandomList(Node* head) {
//     if (head == nullptr)
//       return nullptr;
//     if (const auto it = map.find(head); it != map.cend())
//       return it->second;

//     Node* newNode = new Node(head->val);
//     map[head] = newNode;
//     newNode->next = copyRandomList(head->next);
//     newNode->random = copyRandomList(head->random);
//     return newNode;
//   }

//  private:
//   unordered_map<Node*, Node*> map;
// };


// QUESTION 3 : (21. Merge Two Sorted Lists)


// class Solution {
//  public:
//   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     if (!list1 || !list2)
//       return list1 ? list1 : list2;
//     if (list1->val > list2->val)
//       swap(list1, list2);
//     list1->next = mergeTwoLists(list1->next, list2);
//     return list1;
//   }
// };

// ONE OBJECT ORIENTED PROGRAMMING QUESTION FROM CODECHEF


// QUESTION : Write a C++ class that demonstrates defining a class, declaring private and public members, creating an object, and using public member functions and data.


// #include<bits/stdc++.h>
// using namespace std;

// // Step 1: Define the class
// class MyClass {
//     // Step 2: Declare private members (data and functions)
//     private:
//         int privateValue;

//     // Step 3: Declare public members (data and functions)
//     public:
//         int publicValue;

//         // Constructor to initialize privateValue
//         MyClass() {
//             privateValue = 0;
//         }

//         // Getter for privateValue
//         int getPrivateValue() {
//             return privateValue;
//         }

//         // Setter for privateValue
//         void setPrivateValue(int value) {
//             privateValue = value;
//         }

//         // Public function
//         void publicFunction() {
//             cout << "Public value: " << publicValue << endl;
//             cout << "Private value (via getter): " << getPrivateValue() << endl;
//         }
// };

// int main() {
//     // Step 4: Create an object of the class
//     MyClass obj;

//     // Step 5: Accessing and changing the object's public data
//     obj.publicValue = 10;

//     // Changing the privateValue using the setter function
//     obj.setPrivateValue(20);

//     // Step 6: Use the object's public functions
//     obj.publicFunction();

//     return 0;
// }





// ONE DATABASE MANAGEMENT SYSTEM QUESTION

// QUESTION : 177. Nth Highest Salary

// CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
// BEGIN
//   RETURN (
//     WITH
//       RankedEmployees AS (
//         SELECT *, DENSE_RANK() OVER(ORDER BY salary DESC) AS `rank`
//         FROM Employee
//       )
//     SELECT MAX(salary) AS SecondHighestSalary
//     FROM RankedEmployees
//     WHERE `rank` = N
//   );
// END
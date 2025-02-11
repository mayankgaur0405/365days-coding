// class MinStack {
//     public:
//         stack<long long> s;
//         long long minValue;
        
//         MinStack() {}
    
//         void push(int val) {
//             if (s.empty()) {
//                 s.push(val);
//                 minValue = val;
//             } else if (val >= minValue) {
//                 s.push(val);
//             } else {
//                 s.push(2LL * val - minValue); // Encodes the old min value
//                 minValue = val;
//             }
//         }
    
//         void pop() {
//             if (s.top() < minValue) {
//                 minValue = 2 * minValue - s.top(); // Restore previous minValue
//             }
//             s.pop();
//         }
    
//         int top() {
//             return (s.top() < minValue) ? minValue : s.top();
//         }
    
//         int getMin() {
//             return minValue;
//         }
//     };
    
    
//     // Your MinStack implementation is mostly correct but has a couple of issues:
    
//     // Issues:
//     // Incorrect handling of the first push
    
//     // If s.empty() is true, you push val into the stack and set minValue = val.
//     // However, the if-else block after that does not have a return, so if val < minValue, it executes again, leading to incorrect behavior.
//     // Incorrect pop() logic
    
//     // When popping, if s.top() < minValue, you're updating minValue = 2 * minValue - s.top().
//     // However, this should only happen if s.top() is a transformed value (which happens when we push 2 * val - minValue for values less than minValue).
    
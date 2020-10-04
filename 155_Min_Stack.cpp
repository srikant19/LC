/**Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
**/


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk1,stk2;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int x) {
        stk1.push(x);
        if(x <= mn){
            mn = x;
            stk2.push(mn);
        }
    }
    
    void pop() {
        if(stk1.top() == stk2.top())
            stk2.pop();
        stk1.pop();
        if(stk1.empty())
            mn = INT_MAX;
        else
            mn = stk2.top();
        
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
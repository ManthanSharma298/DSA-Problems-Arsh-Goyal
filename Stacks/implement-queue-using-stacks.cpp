

// space complx: O(n+n) -> for both stacks
// top: O(1) Amortized -> sometimes O(1) and sometimes O(n)
// push: O(1)
// pop: O(1) Amortized
class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            // s1 -> s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int elm = s2.top();
        s2.pop();
        return elm;
    }
    
    int peek() {
        if(s2.empty()){
            // s1 -> s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int elm = s2.top();
        return elm;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

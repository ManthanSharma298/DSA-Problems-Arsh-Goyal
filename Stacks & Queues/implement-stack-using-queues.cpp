

// using two queues-> push: O(1), pop: O(n)
class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x){
        if(!q1.empty()) q1.push(x);
        q2.push(x);
    }
    
    int pop() {
        if(q1.empty() && q2.empty()) return -1;
        else if(q2.empty()){
            int tp;
            while(!q1.empty()){
                tp = q1.front();
                q1.pop();
                if(!q1.empty()) q2.push(tp);
            }
            return tp;
        }
        else{
            int tp;
            while(!q2.empty()){
                tp = q2.front();
                q2.pop();
                if(!q2.empty()) q1.push(tp);
            }
            return tp;
        }
    }
    
    int top() {
        if(q1.empty() && q2.empty()) return -1;
        else if(q2.empty()){
            int tp;
            while(!q1.empty()){
                tp = q1.front();
                q1.pop();
                q2.push(tp);
            }
            return tp;
        }
        else{
            int tp;
            while(!q2.empty()){
                tp = q2.front();
                q2.pop();
                q1.push(tp);
            }
            return tp;
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

// using one queue-> push: O(1), pop: O(n)
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    void reverse(){
        int sz = q.size();
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int sz = q.size() - 1;
        int fr;
        while(sz--){
            q.push(q.front());
            q.pop();
        }
        
        if(q.empty()) return -1;
        
        fr = q.front();
        q.pop();
        
        reverse();
        return fr;
    }
    
    int top() {
        int sz = q.size();
        int fr = -1;
        while(sz--){
            fr = q.front();
            q.push(fr);
            q.pop();
        }
        
        reverse();
        return fr;
    }
    
    bool empty() {
        return q.empty();
    }
};
// Day 15 : >

// Problem 1 :  Implement Queue using Stacks

class MyQueue {
private:
      stack<int> input,output;
public:
 
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }

    int pop() {
        int res = peek();
        output.pop();
        return res;
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// Problem 2 : Backspace String Compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {     
        string str1="", str2="";
        
        for(auto i:s){
            if(i=='#' && str1.empty()) continue;
           
            if(i=='#') str1.pop_back();
            else
            str1 += i;
        }
        
        for(auto i:t){
            if(i=='#' && str2.empty()) continue;
            if(i=='#') str2.pop_back();
             else
            str2 += i;
        }
        
        return str1 == str2;
    }
};

// Problem 3 : Implement Stack using Queues

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
       return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// Problem 4 : Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<int> res(n,-1);
        
        stack<int> st;
        unordered_map<int,int> mp;
        
        for(int i=0;i<m;i++){
            int element=nums2[i];
            
            while(!st.empty() && st.top() < element){
                mp[st.top()]=element;
                st.pop();
            }
            st.push(element);
        }
        
        for(int i=0;i<n;i++){
            int ele=nums1[i];
            
            if(mp.find(ele)!=mp.end()){
                res[i]=mp[ele];
            }
        }
       return res;
    }
};




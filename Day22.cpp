
// Day 22 :>

// 1. Implement queue using stack

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int front=0;
    
    MyQueue() {
        
    }
    
    void push(int x) {
//         if(st1.empty()) front=x;
        
//         while(!st1.empty()) 
//             st2.push(st1.top()), st1.pop();
        
//         st2.push(x);
        
//         while(!st2.empty()) st1.push(st2.top()), st2.pop();
        
        
        if(st1.empty()) front = x;
        st1.push(x);
        
        
    }
    
    int pop() {  
        // int x = st1.top();
        // st1.pop();
        // if(!st1.empty()) front = st1.top();
        // return x;
        
        if(st2.empty()){
            while(!st1.empty())
                st2.push(st1.top()), st1.pop();
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        // return front;
        
        if(!st2.empty())
            return st2.top();
        return front;
    }
    
    bool empty() {
        // return st1.empty();
        
        return st1.empty() && st2.empty();
    }
};


//2. Implement stack using queue

class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int size = q1.size();
        
        while(size>1){
            q1.push(q1.front());
            q1.pop();
            size--;
        }
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};



//3. Evaluate postfix expression 

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        int ans=0;
        stack<int> st;
        
        for(int i=0;i<S.size();i++){
            if(isdigit(S[i]))
            st.push(S[i]-'0');
            else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                if(S[i]=='+') ans = y + x;
                else if(S[i]=='-') ans = y-x;
                else if(S[i]=='*') ans = y*x;
                else ans = y/x;
                
                st.push(ans);
            }
            
        }
        return ans;
    }
};


//4. Implement two stacks in an array

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};



int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
            if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends





//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
     if(top1 < top2-1){
         top1++;
         arr[top1]=x;
     }else{
         cout<<"-1";
         exit(1);
     } 
     
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top1<top2-1){
        top2--;
        arr[top2]=x;
    }else{
        cout<<"-1";
         exit(1);
    }
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
     if(top1 >= 0){
         int x = arr[top1];
         top1--;
         return x;
     }else{
        cout<<"-1";
         exit(1);
    }
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2 < size){
         int x = arr[top2];
         top2++;
         return x;
     }else{
        cout<<"-1";
         exit(1);
    }
}


//5. Backspace string compare

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

//6. Next greater element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            
            if(st.empty()) mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(auto i:nums1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
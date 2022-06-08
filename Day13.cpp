// Day 13 :>


// Problem 1 : Word Wrap

lass Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size();
        vector<int> dp(n,-1);
        
        return wrapWord(0, nums,k,dp);
    } 
    
    int wrapWord(int idx, vector<int> &nums, int k, vector<int> &dp) {
        int n = nums.size();
        if(idx == n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int cost = INT_MAX, sum = 0;
        for(int i = idx; i < n; i++) {
            if(i > idx) sum++;
            sum += nums[i]; if(sum > k) break;
            if(i < n-1)
                cost = min(cost, (k-sum) * (k-sum) + wrapWord(i+1, nums, k, dp));
            else
                cost = 0;
        }
        return dp[idx] = cost;
    }

};


// Problem 2 : Basic Calculatro II

class Solution {
public:
    int calculate(string s) {
        int n=s.size(), ans=0;
        if(n==0) return 0;
        stack<char> st;
        char operation = '+';
        int curNum=0;
        
        for(int i=0;i<n;i++){
            char currChar = s[i];
            if(isdigit(currChar)) 
                curNum = curNum*10 + (currChar-'0');
            
        if(!isdigit(currChar) && !iswspace(currChar) || i==n-1)              {
                if(operation == '+')
                    st.push(curNum);
                else if(operation == '-')
                    st.push(-curNum);
                else if(operation == '*'){
                    int num = st.top();
                    st.pop();
                    st.push(num * curNum);
                }else if(operation=='/'){
                    int num = st.top();
                    st.pop();
                    st.push(num / curNum);
                }
                operation = currChar;
                curNum = 0;
            }
        }
        
        while(st.size()!=0){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// Problem 3 : Valid Number

class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        
        for(;s[i]==' ';i++){}
        
        if(s[i]=='+' || s[i]=='-') i++;
        
        int num=0, pt=0;
        
        for(num=0, pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.';i++)
            s[i] == '.' ? pt++ : num++;
        
        if(num<1 || pt>1) return false;
        
        if(s[i]=='e' || s[i]=='E'){
            i++;
            if(s[i]=='+' || s[i]=='-') i++;
            int num=0;
            
            for(; (s[i]>='0' && s[i]<='9');i++,num++){}
            if(num<1) return false;
        }
        
        for(; s[i]==' '; i++){}
        
        return s[i]==0;
    }
};

// Problem 4 : Integer to English Words

class Solution {
public:
   
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six",                                         "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",                                         "Thirteen", "Fourteen", "Fifteen", "Sixteen",                                                 "Seventeen", "Eighteen", "Nineteen"};
        
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty",                                          "Sixty", "Seventy", "Eighty", "Ninety"};
    string int2words(int n){

        if(n >= 1000000000){
            return int2words(n/1000000000) + " Billion" + int2words(n%1000000000);
        }else if(n>=1000000){
            return int2words(n/1000000) + " Million" + int2words(n%1000000);
        }else if(n>=1000){
            return int2words(n/1000) + " Thousand" + int2words(n%1000);
        }else if(n>=100){
            return int2words(n/100) + " Hundred" + int2words(n%100);
        }else if(n>=20){
            return " " + tens[n/10] + int2words(n%10);
        }else if(n>=1){
            return " " + digits[n];
        }else return "";
        
        
    }
    
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string res = int2words(num);
        return res.substr(1, res.size()-1);
    }
};

// Problem 5 : Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        
        if (s.size() == 0 || t.size() == 0) return "";
        
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};


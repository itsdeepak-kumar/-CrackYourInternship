// Day 9 :>

// Problem 1 : Reverse Words in a String

 class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res="";
        
        for(int i=n-1;i>-1;i--){
            if(s[i]==' ') continue;
            int j=i;
            while(i>=0 && s[i]!=' ') i--;
            res.append(s.substr(i+1, j-i) + " ");
        }
        if(res.back() == ' ') res.pop_back();
        return res;
    }
};

// Problem 2 : Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        
        for(auto& s:strs){
            string t=s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        
        for(auto& p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};

// Problem 3 : Basic Calculator II


class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};


// Problem 4 : Smallest window in a string containing all the characters of another string 


class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        string ans="";
        
        if(s.size()<p.size()) return "-1";
        
        unordered_map<char,int> mp1,mp2;
        
        for(auto i:p) mp2[i]++;
        int i = 0, j = 0, matchCount = 0, desireMatchCount = p.size();
        
        while(true){
            bool f1 = false, f2 = false;
            // acquire 
            while(i < s.length() && matchCount < desireMatchCount){
                
                mp1[s[i]]++;
                
                if(mp1[s[i]] <= mp2[s[i]]) matchCount++;
                i++;
                
                f1 = true;
            }
            
            // release and collect answers
            while(j < i && matchCount == desireMatchCount){
                string pans = s.substr(j, j-i);
                if(ans.length() == 0 || pans.length() < ans.length()){
                    ans = pans;
                }
                
                
                if(mp1[s[j]] == 1) mp1.erase(s[j]);
                else mp1[s[j]]--;
                
                if(mp1[s[j]] < mp2[s[j]]) matchCount--;
                j++;
                f2 = true;
            }
            
            if(f1 == false && f2 == false) break;
        }
        
        return ans;
    }
};




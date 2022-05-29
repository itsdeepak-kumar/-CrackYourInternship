
Day 3

// Problem 1 : Move zeroes (arrays) :>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0,j=1,n=nums.size();
        while(i<n && j<n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++,j++;
            }else if(nums[i]!=0){
                i++,j=i+1;
            }else if(nums[j]==0) j++;
        }    
    }
};


//Problem 2 : Best time to sell and buy stock 

class Solution {
public:
    int maxProfit(vector<int>& prices) {    
        int maxpro = 0;
        int buy=prices[0];
        for(auto i:prices){
            if(i<buy)
                buy = i;
            if(i>=buy)
            maxpro = max(maxpro, i-buy);
        }
        return maxpro;
    }
};


//Problem 3 : chocolate distribution problem

class Solution {
public:
    int greatestDifference(vector<int>& arr, int n) {
        
	    sort(arr.begin(),arr.end());
			int ans=INT_MAX;

			for(int i=0;i<arr.size();i++){
				if(i == (arr.size()-n)){
					ans = min(ans, (arr[i+n-1] - arr[i]));
					break;
				}
			    ans = min(ans, (arr[i+n-1] - arr[i]));
		   }
		   return ans;
    }
};

//Problem 4 : Two Sum 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> v;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])){
                v.push_back(mp[target-nums[i]]);
                v.push_back(i);
                break;
            }
            mp[nums[i]]=i;
        }
        return v;
    }
};

//Problem 5 : Valid palindrome II

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return check(s,i+1,j) || check(s,i,j-1);   
            i++;
            j--;
        }
        return true;
    }
    
    bool check(string s, int l, int h){
        while(l<h){
             if(s[l]!=s[h])
               return false;
            l++;
            h--;
        }
        return true;
    }
};

//Problem 6 : Simplifuy path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        
        for(int i=0;i<path.size();i++){
            if(path[i]=='/') continue;
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp += path[i];
                i++;
            }
            
            if(temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }else st.push(temp);
        }
        
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size()==0) return "/";
        
        return res;
    }
};
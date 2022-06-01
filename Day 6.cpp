// Day 6

// Problem 1 : 3sum

 class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int target = -nums[i];
            int front = i+1;
            int back = n-1;
            
            while(front < back){
                int sum = nums[front]+nums[back];
                if(sum < target){
                    front++;
                }else if(sum > target){
                    back--;
                }else{
                    vector<int> v(3);
                    v[0]=nums[i];
                    v[1]=nums[front];
                    v[2]=nums[back];
                    
                    res.push_back(v);
                    
                    while(front<back && nums[front]==v[1]) front++;
                    while(front<back && nums[back]==v[2]) back--;      
                }
            }          
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }         
        
        return res;
    }
 };


// Problem 2 : 4sum 


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = j + 1, r = n - 1;
                int remain = target - nums[i] - nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] == remain) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;r--;
                        while (l < r && nums[l-1] == nums[l]) l++; 
                    } else if (nums[l] + nums[r] > remain) {
                        r--;;
                    } else {
                        l++;
                    }
                }
                while (j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while (i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};



// Problem 3 : container with most water


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1,ans=0;
  
        while(i<j){
            ans = max(ans, min(height[i], height[j])*(j-i));
            
            if(height[i]>height[j]) j--;
            else if(height[i]<height[j]) i++;
            else
                i++,j--;
           
        }
        
        return ans;
    }
};


// Problem 4 : subarray sum equal to k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),ans=0;
        vector<int> prefix(n);
        prefix[0]=nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = nums[i]+prefix[i-1];
        }
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            if(prefix[i]==k) ans++;
            
            if(mp.find(prefix[i]-k)!=mp.end()){
                ans += mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }    
};

// Problem 5 : maximumm points you can obtain from cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(), res=0,sum=0;
        for(int i=n-k;i<n;i++) res += cardPoints[i];
        
        sum = res;
        for(int i=0;i<k;i++){
            sum -= cardPoints[n-k+i];
            sum += cardPoints[i];
            res = max(res,sum);
        }
        return res;
    }
};


// Problem 6 : spiral matrix


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int rbegin=0,rend=n-1, cbegin=0,cend=m-1;
        
        if(n==0 || m==0) return res;
        
        while(rbegin<=rend && cbegin<=cend){
            for(int i=cbegin;i<=cend;i++) res.push_back(matrix[rbegin][i]);
            rbegin++;
            
            for(int i=rbegin;i<=rend;i++) res.push_back(matrix[i][cend]);
            cend--;
            
            if(rbegin<=rend){
                for(int i=cend;i>=cbegin;i--) res.push_back(matrix[rend][i]);
            }
            rend--; 
            
            if(cbegin<=cend){
                for(int i=rend;i>=rbegin;i--) res.push_back(matrix[i][cbegin]);
            }
            cbegin++;  
        }
        return res;
    }
};

// Problem 7 : subarray sum divisible by k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),count=0;
        if(n==0) return 0;
        
        int i=0,curSum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        while(i<n){
            curSum += nums[i++];
            int rem = curSum%k;
            if(rem<0) rem += k;
            
            if(mp.find(rem)!=mp.end()) count += mp[rem];
            
            mp[rem]++;
        }
        
        return count;
    }
};
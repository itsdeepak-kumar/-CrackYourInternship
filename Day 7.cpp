// Day 7 :>


// Problem 1 : Word Search


// Problem 2 : Jump Game 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<i) return false;
            maxi = max(maxi, i+nums[i]);
        }
        return true;
    }
};

// Problem 3 : Merge sorted array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1, k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]=nums2[j--];
        }
        
        while(j>=0) nums1[k--]=nums2[j--];
    }
};

// Problem 4 : Majority element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ans=0,count=0;
        for(auto i:nums){
            if(count==0){
                count++;
                ans=i;
            }else if(ans==i) count++;
            else count--;
        }
        return ans;
    }
};

// Problem 5 : Reverse Pairs



// Problem 6 : Print all possible combinations of r elements in a given array of size n



// Problem 7 : Game of Life



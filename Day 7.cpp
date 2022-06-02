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


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void combination(vector<int>& v, vector<int>& arr, int n, int r, int ind){

    if(v.size()==r){
    	for(auto i:v) cout<<i<<" ";
    	cout<<endl;
       return;
    } 

    if(ind>=n) return;
    
    v.push_back(arr[ind]);  //take
	combination(v,arr,n,r,ind+1);
	v.pop_back();
                     // not take
    combination(v,arr,n,r,ind+1);
}



int main(){

	vector<int> arr = {1,2,3,4,5,6};
	int r=3, n=6;

	cout<<"Cominations are : > "<<endl;
	vector<int> v;
	combination(v,arr,n,r,0);
    
	return 0;
}



// Problem 7 : Game of Life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res=board;
        int n=board.size(), m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count = countNeighbors(board,i,j,n,m);
                if(board[i][j]==0){
                    if(count==3) res[i][j]=1;
        
                }
                
                if(board[i][j]==1){
                    if(count<2 || count>3) res[i][j]=0;
                }
            }
        }
        
       
    
    }
    
    int countNeighbors(vector<vector<int>>& v, int i, int j, int n, int m){
        int ln=0;
        
        if(i>0) if(v[i-1][j]==1) ln++;
        if(i<n-1) if(v[i+1][j]==1) ln++;
        
        if(j>0) if(v[i][j-1]==1) ln++;
        if(j<m-1) if(v[i][j+1]==1) ln++;
        
        if(i>0 && j>0) if(v[i-1][j-1]==1) ln++;
        if(i>0 && j<m-1) if(v[i-1][j+1]==1) ln++;
        if(i<n-1 && j>0) if(v[i+1][j-1]==1) ln++;
        if(i<n-1 && j<m-1) if(v[i+1][j+1]==1) ln++;
        
        return ln;
    }
    
};

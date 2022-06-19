// Day 23 :>

// 1. Check if reversing a sub array make the array sorted

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int& n){
    if(n == 1) return true;
    
    int i=0;
    for(i = 1;i<n && a[i-1]<a[i];i++);
    
    if(i == n) return true;
    
    int j =i;
    while(j<n && a[j]<a[i-1]){
        if(i>1 && a[j]<a[i-2]) return false;
        
        j++;
    }
    
    if(j == n) return true;
    
    int k=j;
    if(a[k]<a[i-1]) return false;
    
    while(k>1 && k<n){
        if(a[k]<a[k-1]) return false;
        k++;
    }
    
    return true;
}

int main() {
	//code
	
	vector<int> a={ 1, 2, 4, 5, 3 };
	int n = a.size();
	
	check(a,n) ? cout<<"YES" : cout<<"NO";
    cout<<endl;
	
	return 0;
}


// 2. Product of Array except itself


class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here     
        vector<long long int> res(n,1);
        if(n==1) return res;
        
        long long int temp=1, i=0;
        for(i=0;i<n;i++){
            res[i] = temp;
            temp *= nums[i];
        }
        
        temp=1;
        long long int j=0;
        for(j=n-1;j>=0;j--){
            res[j] *= temp;
            temp *= nums[j];
        }
        
        return res;
        
    }
};


// 3. Make all array elements equal with minimum cost

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a={ 1, 100, 101 };
    int n = a.size();
    
    int y;
    if(n%2) y=a[n/2];
    else y = a[n/2] + a[(n-2)/2]/2;
    
    int s=0;
    for(auto i:a){
        s += abs(i-y);
    }
    
    cout<<s<<endl;
    
    return 0;
}


// 4.  Find Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) return i;
        }
        return nums.size()-1;
    }
};
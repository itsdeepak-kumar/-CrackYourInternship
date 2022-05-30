Day 4

// Problem 1 : minimum number pf moves to eqaul array elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0,mini=nums[0];
        for(auto i:nums) mini = min(mini,i);
        
        for(auto i:nums)
            ans += i-mini;
        return ans;
    }
};

// Problem 2 : add binary strings 

class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int i = a.size()-1, j = b.size()-1;
        int carry=0,sum=0;
        
        while(i>=0 || j>=0){
            sum = carry;
            if(i>=0) sum += a[i--]-'0';
            if(j>=0) sum += b[j--]-'0';
            
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum%2);
        }
        
        if(carry!=0) res += to_string(carry);
        reverse(res.begin(),res.end());
        
        return res;
    }
};


//  Problem 3 : maximum product of three numbers


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for(auto i:nums){
            if(i<=min1){
                min2 = min1;
                min1 = i;
            }else if(i<=min2){
                min2 = i;
            }
            
            if(i>=max1){
                max3=max2;
                max2=max1;
                max1=i;
            }else if(i>=max2){
                max3=max2;
                max2=i;
            }else if(i>=max3){
                max3=i;
            }
        }
        
        return max(min1*min2*max1, max1*max2*max3);
    }
}; 


//  Problem 4 : excel sheet column title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        char temp;
        while(columnNumber){
            columnNumber--;
            temp = 'A' + columnNumber%26;
            res = temp+res;
            columnNumber /= 26;
        }
        return res;
    }
};

//  Problem 5 : happy number

class Solution {
public:
    bool isHappy(int n) {
       int slow=n,fast=n;
       do{
           slow = nextNumber(slow);
           fast = nextNumber(fast);
           fast = nextNumber(fast);
       }while(slow!=fast);
           
       if(slow==1) return 1;
        else return 0;
    }
    
    int nextNumber(int x){
        int sum=0;
        while(x){
            int r = x%10;
            x/=10;
            sum += r*r;
        }
        return sum;
    }
}; 


//  Problem 6 : Palindrome number

class Solution {
public:
    bool isPalindrome(int x) {        
        if(x<0 || (x!=0 && x%10==0))
            return false;
        int sum=0;
        while(x>sum){
            sum = sum*10 + x%10;
            x/=10;
        }
        
       return (x==sum)||(x==sum/10);
    }
};


//  Problem 7 : missing number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(auto n:nums) ans ^= n;
        for(int i=0;i<=nums.size();i++) ans^=i;
        return ans;
    }
};


//  Problem 8 : reverse number

class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            int pop=x%10;    
            x/=10;
            
            if(res>INT_MAX/10 || (res==INT_MAX/10 && pop>7)) return 0;
            if(res<INT_MIN/10 || (res==INT_MIN/10 && pop>7)) return 0;
            res = res*10 + pop;
        }
        return res;
    }
};


//  Problem 9 : power of two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & n-1);
    }
};


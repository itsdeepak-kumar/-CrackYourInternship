// Day 8 :>

// Problem 1 : Permute two arrays such that sum of every pair is greater or equal to K

class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+n);
        reverse(a, a+n);
        
        if(a[0]+b[0] >= k) return true;
        
        return false;
    }
};


// Problem 2 : Ceiling in a sorted array

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int x = 20, n = sizeof(arr)/sizeof(arr[0]);

    int ans=-1;

    if(x <= arr[0]) ans=0;
    else{
        for(int i=0;i<n;i++){
          if(arr[i]==x) ans=i;

          if(arr[i]<x && arr[i+1]>=x) ans= i+1;
        }
    }
    
    cout<<ans<<endl;
    
	return 0;
}


// Problem 3 : Middle of the Linked List

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
        
       while(fast!=NULL && fast->next!=NULL){
           slow = slow->next;
           fast = fast->next->next;
       }
        return slow;
    }
};

// Problem 4 : Linked List Cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        return false;
    }
};

// Problem 5 : Convert Binary Number in a Linked List to Integer


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string num;
        int ans=head->val;
        
        while(head->next!=NULL){
            ans = (ans << 1) | head->next->val ;
            head = head->next;
        }
        
        return ans;
    }
};
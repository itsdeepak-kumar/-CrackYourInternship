// Day 12 :>

// Problem 1 : Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *p1 = headA, *p2 = headB;
        
        while(p1!=NULL && p2!=NULL && p1!=p2){
           p1 = p1->next;
           p2 = p2->next;
            
           if(p1==p2) return p1;
            
           if(p1==NULL) p1=headB;
           if(p2==NULL) p2=headA;
        }
        return p1;
    }
};


// Problem 2 : Delete without head pointer 



class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       *del = *del->next;
       
    }

};



// Problem 3 : Palindrome Linked List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p){
        if(p==NULL) return true;
        
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp -> next;
        
        return isPal;
    }
};


// Problem 4 :  Reverse Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur, *prev, *temp;
        prev = NULL;
        cur = head;
        
        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};


// Problem 1 : Add two numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        int c=0;
        
        while(l1!=NULL || l2!=NULL || c){
           int sum=0;
            if(l1!=NULL){
                 sum += l1->val;
                 l1 = l1->next;
            }
            
            if(l2!=NULL){
                 sum += l2->val;
                 l2 = l2->next;
            }
            
            sum += c;
            c = sum/10;
            
            ListNode* node = new ListNode(sum%10);
            res->next = node;
            res = res->next;
            
        }    
        return ans->next;
    }
};


// Problem 2 : Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* l1 = head;
        Node* l2 = NULL;
        
        if(head == NULL) return head;
        
        // traveersing and aadding copies in the list
        
        while(l1!=NULL){
            l2 = new Node(0);
            
            l2->val = l1->val;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
        }
        
        // adding random pointers to it
        
        l1=head;
        while(l1!=NULL){
            if(l1->random != NULL){
                l1->next->random = l1->random->next;
            }
            
            l1 = l1->next->next;
        }
        
        
        // now separting lists
        
        l1=head;
        Node* l2_head = l1->next;
        
        while(l1!=NULL){
            l2 = l1->next;
            l1->next = l2->next;
            
            if(l2->next != NULL){
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }
        
       return l2_head; 
    }
};


// Problem 3 :  Reverse Linked List II

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return head;
        
        ListNode *cur = head, *prev = NULL;
        while(left>1){
            prev = cur;
            cur = cur->next;
            left--;
            right--;
        }
        
        ListNode *con = prev, *tail = cur;
        ListNode* temp;
        while(right>0){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            right--;
        }
        
        if(con !=NULL){
            con->next = prev;
        }else head = prev;
        
        tail->next = cur;
        return head;   
    }
};

// Problem 4 :  Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *slow=head;
        
        for(int i=0;i<n;i++) fast = fast->next;
        
        if(!fast) return head->next;
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};

// Problem 5 : Add Two Numbers II

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> st1, st2;
       
       while(l1!=NULL){
           st1.push(l1->val);
           l1 = l1->next;
       }
        
       while(l2!=NULL){
          st2.push(l2->val);
          l2 = l2->next;
       } 
         
        int sum=0;
        ListNode* list = new ListNode(0);
        while(!st1.empty() || !st2.empty()){
            if(!st1.empty()) sum += st1.top(), st1.pop();
            if(!st2.empty()) sum += st2.top(), st2.pop();
            
            list->val = sum%10;
            
            ListNode* head = new ListNode(sum/10);
            head->next = list;
            list = head;
            sum /= 10;
            
        }
        return list->val == 0 ? list->next : list;
    }
};

//Problem 6 :  Reorder List

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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *l1= head;
        int n=0;
        while(l1!=NULL){
            st.push(l1);
            n++;
            l1=l1->next;
        }
        
        l1=head;
        for(int i=0;i<n/2;i++){
            ListNode *node = st.top();
            st.pop();
            node->next = l1->next;
            l1->next = node;
            l1 = l1->next->next;             
        }
        l1->next = NULL;
    }
};

// Problem 7 : Find Pair Given Difference 

bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    int i=0,j=1;
    
    while(i<size && j<size){
        if(i!=j && (arr[j]-arr[i]==n || arr[i]-arr[j]==n)) return true;
        else if(arr[j]-arr[i]<n) j++;
        else i++;
    }
    return false;
}

// Problem 8 : Permutations in array

class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+n);
        reverse(a, a+n);
        for(long long i=0;i<n;i++)
          if(a[0]+b[0] < k) return false;
        
        return true;
    }
};
// Day 10 :>

// Problem 1 : Remove duplicates from the sorted linked list

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node=head;
        
        if(head==NULL || head->next==NULL) return head;
        
        while(head!=NULL && head->next!=NULL){
            if(head->val == head->next->val){
              head->next = head->next->next;
            }else
                head=head->next;
        }
        return node;
    }
};


// Problem 2 : Sort a linked list of 0s, 1s and 2s

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head==NULL || head->next==NULL) return head;
        int zcount=0, ocount=0, tcount=0;
        
        Node* temp=head;
        Node* node=head;
        while(head!=NULL){
            if(head->data == 0) zcount++;
            else if(head->data == 1) ocount++;
            else tcount++;
            
            head = head->next;
        }
        
        while(zcount--){
            temp->data = 0;
            temp = temp->next;
        }
        
        while(ocount--){
            temp->data = 1;
            temp = temp->next;
        }
        
        while(tcount--){
            temp->data =2;
            temp = temp->next;
        }
       
        return node;
    }
};


// Problem 3 : Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL) return NULL;    
    
        while(head!=NULL && head->val == val){
              head = head->next;
        }
        ListNode* node=head, *prev=NULL;
        while(node){
            if(node->val == val){
                prev->next = node->next;
                node = node->next;
            }else{
                prev = node;
                node = node->next;
            }
        }
        
        return head;
    }
};

// Problem 4 : Merge Two Sorted Lists


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};


// Problem 5 : Multiply two numbers represented by Linked Lists

long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long mod=1000000007;
  
  Node *ptr1=l1,*ptr2=l2;
  
  long long first=0,second=0;
  
  while(ptr1)
  {
      first=(first*10)%mod+ptr1->data;
      ptr1=ptr1->next;
  }
  
  while(ptr2)
  {
      second=(second*10)%mod+ptr2->data;
      ptr2=ptr2->next;
  }
  
  long long ans=((first%mod)*(second%mod))%mod;
  
  return ans;
}


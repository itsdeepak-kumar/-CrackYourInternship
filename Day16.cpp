// Day 16 :

// Problem 1 :  Partition List

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0);
        ListNode* before = beforeHead;
        ListNode* afterHead = new ListNode(0);
        ListNode* after = afterHead;
        
        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }else{
                after->next = head;
                after = after->next;
            }
            
            head = head->next;
        }
        after->next = NULL;
        before->next = afterHead->next;
        
        return beforeHead->next;
    }
};

// Problem 2 : Remove Duplicates from Sorted List II

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
        
       ListNode *dummy=new ListNode(0,head);
       ListNode *prev=dummy;
        
        while(head!=NULL){

            if(head->next!=NULL && head->val==head->next->val){
              while(head->next!=NULL && head->val==head->next->val)head=head->next;
              prev->next=head->next;
            }
            else prev=prev->next;

            head=head->next;
        }
        
        return dummy->next;
    }
};

// Problem 3 : Sort List

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
        
       ListNode *dummy=new ListNode(0,head);
       ListNode *prev=dummy;
        
        while(head!=NULL){

            if(head->next!=NULL && head->val==head->next->val){
              while(head->next!=NULL && head->val==head->next->val)head=head->next;
              prev->next=head->next;
            }
            else prev=prev->next;

            head=head->next;
        }
        
        return dummy->next;
    }
};

// Problem 4 : Rearrange a Linked List in Zig-Zag fashion



// Problem 5 : Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* h = head; h; h = h->next)
	{
		if (h->child)
		{
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
    }
};

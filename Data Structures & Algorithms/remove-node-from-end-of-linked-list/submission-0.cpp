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
        // find out size of list
        ListNode* ans = head;
        int size = 0;
        while(head!=NULL){
            head = head->next;
            size++;
        }
        if(size==n){
            return ans->next; 
        }
        int idx = size-n;
        head = ans;
        while(idx>0){
            head = head->next;
            idx--;
        }
        ListNode* curr=ans;
        while(curr->next!=NULL && curr->next!=head){
            curr = curr->next;
        }
        curr->next = head->next;
        return ans;

    }
};

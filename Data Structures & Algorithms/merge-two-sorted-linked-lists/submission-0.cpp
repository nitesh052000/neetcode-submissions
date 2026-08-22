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
        ListNode* merge = new ListNode(0);
        ListNode* ans = merge;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                ListNode* dummy = new ListNode(l1->val);
                merge->next = dummy;
                merge = dummy;
                l1 = l1->next;
            }

            else{
                ListNode* dummy = new ListNode(l2->val);
                merge->next = dummy;
                merge = dummy;

                l2 = l2->next;
            }
        }

        while(l1!=NULL){
            ListNode* dummy = new ListNode(l1->val);
                merge->next = dummy;
                merge = dummy;
                l1 = l1->next;
        }

        while(l2!=NULL){
            ListNode* dummy = new ListNode(l2->val);
                merge->next = dummy;
                merge = dummy;

                l2 = l2->next;
        }
return ans->next;
    }
};

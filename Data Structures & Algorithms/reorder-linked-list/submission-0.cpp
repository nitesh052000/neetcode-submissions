class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the end of first half
        // Example: 1 -> 2 -> 3 -> 4 -> 5
        // slow = 3

        // 2. Reverse the second half
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while (second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // prev is head of reversed second half
        // Example:
        // 1 -> 2 -> 3
        // 5 -> 4

        // 3. Merge both halves
        ListNode* first = head;
        second = prev;

        while (second != nullptr) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

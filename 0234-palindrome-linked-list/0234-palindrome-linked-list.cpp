class Solution {
private:
    ListNode *rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *NewHead = rev(slow->next);
        ListNode *first = head;
        ListNode *second = NewHead;
        while(second!=NULL){
            if(first->val!=second->val){
                rev(NewHead);
                return false;
            }
            else{
                first = first->next;
                second = second->next;
            }
        }
        rev(NewHead);
        return true;
    }
};
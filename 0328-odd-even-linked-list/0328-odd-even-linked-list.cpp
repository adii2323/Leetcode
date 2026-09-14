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
    ListNode* oddEvenList(ListNode* head) {
         if(head==NULL || head->next == nullptr)return head;
        ListNode* temp = head;
        ListNode* ptr = head->next;
        ListNode* evenhead = ptr;
        while(ptr!=nullptr && ptr->next!=nullptr){
            temp->next = ptr->next;
            temp = temp->next;
            ptr->next= temp->next;
            ptr = ptr->next;
        }
        temp->next = evenhead;
        return head;
    }
};
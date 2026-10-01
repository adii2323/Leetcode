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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int len=1;
        ListNode* tail = head;
        ListNode* temp=head;
        int count=0;
        while(tail->next!=nullptr){
            tail = tail->next;
            len++;
        }
        if(k%len==0)return head;
        k=k%len;
        tail->next=head;
        while(temp){
            
            count++;
            if(count==len-k){
                head=temp->next;
                temp->next=nullptr;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
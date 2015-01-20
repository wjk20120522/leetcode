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
        if(headA == NULL || headB == NULL) return NULL;
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        ListNode *ptrA = headA, *ptrB = headB;
        int dis = len1-len2;
        if(dis>0) {
            for(int i=0; i<dis; i++) {
                ptrA = ptrA->next;
            }
        } else {
            for(int i=0; i<-dis; i++) {
                ptrB = ptrB->next;
            }
        }
        while( ptrA != NULL && ptrA != ptrB ) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
    
    int getLength(ListNode *head) {
        if(head == NULL) return 0;
        int count = 0;
        while(head) {
            count ++;
            head = head->next;
        }
        return count;
    }
};
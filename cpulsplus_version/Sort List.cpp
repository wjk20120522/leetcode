/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//merge sort
class Solution {
public:
   ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *p1 = head , *p2 = head->next;
        
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;

        return merge( sortList(head), sortList(p2));
    }

    ListNode* merge(ListNode *p1, ListNode*p2) {
        ListNode *dummpy = new ListNode(1);
        ListNode *cur = dummpy;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else { 
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        while (p1) {
            cur->next = p1;
            p1 = p1->next;
            cur = cur->next;
        }
        while (p2) {
            cur->next = p2;
            p2 = p2->next;
            cur = cur->next;
        }
        return dummpy->next;
    }
};


/*
//quicksort ,有问题
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *header =new ListNode(1);
        header->next = head;
        Qsort(header,NULL);
        
        return header->next;

    }

    void Qsort(ListNode **head, ListNode **tail) {
        if(NULL == *head->next || NULL == *head->next->next) {
            return ;
        }
        
        ListNode * mid = head->next;
        ListNode * p = head;
        ListNode * q = mid;
        ListNode * t = mid->next;
        int pivot = mid->val;
        while(NULL != t) {
            if(t->val < pivot) {
                p = p->next = t;
            } else {
                q = q->next = t;
            }
            t = t->next;
        }
        p->next = mid; 
        q->next = NULL;
        Qsort(head,mid);
        Qsort(mid,NULL);
    }

};
*/
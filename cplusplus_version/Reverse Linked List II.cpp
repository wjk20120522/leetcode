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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        vector<ListNode *> res;
        ListNode *cur = head;
        
        for(int i=1; i<m; i++)
        {
            cur = cur->next;
        }
        int num = n-m+1;
        while( num--)
        {
            res.push_back(cur);
            cur = cur->next;
        }
        
        int first = 0, last = res.size()-1;
        ListNode  *begin, *end;
        
        
        while(first < last)
        {
            begin = res[first];
            end = res[last];
            int tmp = begin->val;
            begin->val = end->val;
            end->val = tmp;
            first++; last--;
            
        }
        
        return head;
    }
};


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *cur = head, *tmp, *pre = NULL;
        ListNode *first = NULL, *last, *next;
        for (int i = 1; i < m; i++) {
            pre = cur;
            cur = cur->next;
        }
        last = cur;
        next = cur->next;
        for (int i = m; i < n; i++) {
            tmp = next->next;
            if (i == n - 1) 
                first = tmp;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        
        if (pre == NULL) {
            head = cur;
        }
        else {
            pre->next = cur;
        }
        if (last != cur)
        last->next = first;
        return head;
    }
};
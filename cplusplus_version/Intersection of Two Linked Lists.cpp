/*
calculate the length of two linklist and make the longer linklist pointer go some steps
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int len1 = getLength(headA), len2 = getLength(headB);
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                headA = headA->next;
            }
        }
        else if (len1 < len2) {
            for (int i = 0; i < len2 - len1; i++) {
                headB = headB->next;
            }
        }
        while (headA != headB) {
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }

    int getLength(ListNode *root) {
        int res = 0;
        while (root) {
            res++; root = root->next;
        }
        return res;
    }
};


/*
short code
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *pa = headA, *pb = headB;
        while (pa && pb && pa != pb) {
            pa = pa->next;
            pb = pb->next;
            if (pa == pb)
                return pa;
            if (pa == NULL) pa = headB;
            if (pb == NULL) pb = headA;
        }
        return pa;
    }
};
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
 public:
	 RandomListNode *copyRandomList(RandomListNode *head) {
		 map<RandomListNode *, RandomListNode*>mp;
		 if (head == NULL) return NULL;
		
		 //first copy as a normal linklist
		 RandomListNode *copy = new RandomListNode(1), *cur = head;
		 RandomListNode *newHead = copy;
		 while (cur) {
			 
			 RandomListNode *newNode = new RandomListNode(cur->label);
			 mp[cur] = newNode;
			 copy->next = newNode;
			 cur = cur->next;
			 copy = copy->next;
		 }
		 newHead = newHead->next;
		 //copy random 
		 cur = head;
		 copy = newHead;

		 while (cur) {
			 if (cur->random) {
				 copy->random = mp[cur->random];
			 }
			 cur = cur->next;
			 copy = copy->next;
		 }
		 return newHead;
	 }

	
 };

 /**
  * easy to understand, but TLE
  *
  * 
  */
 /*
 
 class Solution {
 public:
	 RandomListNode *copyRandomList(RandomListNode *head) {
		 map<RandomListNode *, RandomListNode*>mp;
		 if (head == NULL) return NULL;
		
		 RandomListNode * res = deepcopy(head, mp);
		 
		 return res;
	 }

	 RandomListNode* deepcopy(RandomListNode *head, map<RandomListNode*, RandomListNode*>mp) {
		 if (head == NULL) return NULL;
		 if (mp.find(head) == mp.end()) {   // new node
			 
			 RandomListNode *res = new RandomListNode(head->label);
			 mp.insert(make_pair(head, res));
			 if (head->random) {
				 res->random = deepcopy(head->random, mp);
			 }
			 res->next = deepcopy(head->next, mp);
			 return res;
		 }
		 else {
			 return mp[head];
		 }
	 }
 };
 
  */
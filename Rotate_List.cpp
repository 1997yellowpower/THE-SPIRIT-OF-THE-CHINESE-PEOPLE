// Source : https://leetcode-cn.com/problems/rotate-list/description/
// Number : 61
// Author : HL
// Date   : 2018-09-13
// Kill   : 71.46%

/********************************************************************************** 
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
**********************************************************************************/

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
    ListNode* rotateRightOnce(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *p = head, *q = head->next;
        while (q->next != NULL) {
            p = q;
            q = q->next;
        }
        
        p->next = q->next;
        q->next = head;
        head = q;
        
        return head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        
        int i, nodeNumber = 1;
        ListNode *p = head;
        while (p->next != NULL) {
            p = p->next;
            nodeNumber++;
        }
        for (int i = 0; i < (k % nodeNumber); i++) {
            head = rotateRightOnce(head);
        }
        
        return head;
    }
};


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head, *q = dummy;
        int nodeNumber = 1;
        while (p->next != NULL) {
            p = p->next;
            nodeNumber++;
        }
        p = dummy;
        k = k % nodeNumber;
        if (k == 0)
            return dummy->next;
        for (int i = 0; i < k; i++)
            p = p->next;
        while (p->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        dummy->next = q->next;
        q->next = p->next;
        p->next = head;
        return dummy->next;
    }
};

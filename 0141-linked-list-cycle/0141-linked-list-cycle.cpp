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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> ps;
        while(head){
            if(ps.find(head)!=ps.end()){
                return true;
            }
            ps.insert(head);
            head=head->next;
        }
        return false;
    }
};
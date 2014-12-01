/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *ptr = NULL;
    
public:
    // index trick
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *cur = head;
        ptr = head;
        int count = 0;
        while(cur) { count++; cur = cur->next; }
        return helper(0, count-1);
    }
    
    TreeNode *helper(int lo, int hi){
        if(lo > hi) return NULL;
        int mi = lo + (hi - lo) / 2;
        
        // inorder
        TreeNode *l = helper(lo, mi - 1);
        
        TreeNode *root = new TreeNode(ptr->val);
        ptr = ptr->next;
        root->left = l;
        
        root->right = helper(mi + 1, hi);
        return root;
    }
};
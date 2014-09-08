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
ListNode *listPtr = NULL; // key: it keeps moving to the next element in the linked list.
public:
    // review: convert sorted array to BST: preorder traverse
    // inorder traverse + move linked list
    TreeNode *sortedListToBST(ListNode *head) {
        if(NULL == head) return NULL;
        ListNode *cur = head;
        int count = 0;
        while(NULL != cur){
            cur = cur->next;
            count++;
        }
        listPtr = head;
        return helper(0, count-1);
    }
    TreeNode *helper(int l, int r){
        if(l > r) return NULL;
        int m = (l+r)/2;
        
        TreeNode *left = helper(l, m-1);
        int rootVal = listPtr->val;
        listPtr = listPtr->next;
        TreeNode *root = new TreeNode(rootVal);
        root->left = left;
        root->right = helper(m+1, r);
        return root;
    }
};
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
    // review: convert sorted array to BST: preorder traverse, it has direct access to elements
    // inorder traverse + move linked list
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL){ 
            return NULL;
        }
        int count = countListEle(head);
        listPtr = head;
        return helper(0, count - 1);
    }
    TreeNode *helper(int start, int end){
        if(start > end){ 
            return NULL;
        }
        int mid = (start + end) / 2;
        
        TreeNode *left = helper(start, mid - 1);
        int value = listPtr->val;
        listPtr = listPtr->next;
        TreeNode *root = new TreeNode(value);
        root->left = left;
        root->right = helper(mid + 1, end);
        return root;
    }
    int countListEle(ListNode *node){
        int i = 0;
        while(node != NULL) { node = node->next; i++; }
        return i;
    }
};
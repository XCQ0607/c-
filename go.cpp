#include <vector>
using namespace std;

//--------------------------------------------------------------
//3101
int countAlternatingSubarrays(vector<int>& nums) {
    int n = nums.size();
    int count = n; // 每个单个元素都是一个交替子数组
    int length  = 1;

    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) {
            length++;
            //遇到相邻的不同元素会一直累加。如01，此时count+1,若为010，则在此基础上再加2，子数组为10,010，若为0101，再词基础上再加3，为01.101.0101，向前推
        } else {
            length = 1;
            //遇到相邻的相同元素，length重置为1
        }
        count += length - 1; // length - 1 是因为 length 的初始值是 1，不包括当前单个元素
    }

    return count;
}
//--------------------------------------------------------------
//94
#include <functional>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    function<void(TreeNode*)> dfs = [&](TreeNode* root) {       //function是一种特殊的函数类型，它可以表示一个函数，而不仅仅是一个函数指针。这里的函数名是dfs，它表示一个函数，该函数接受一个TreeNode*类型的参数root
    //[&] 表示捕获外部作用域中的所有变量（包括 ans）并按引用传递。      
    if (!root) {
            return;
        }
        dfs(root->left);    // 递归遍历左子树
        ans.push_back(root->val);       //push_back是vector的成员函数，用于在末尾添加一个元素。类似的函数还有push_front、pop_back、pop_front等函数
        dfs(root->right);       // 递归遍历右子树
    };
    dfs(root);
    return ans;
}
//--------------------------------------------------------------
//235
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
    TreeNode* BSTAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) { // 都在左子树中,通过条件可以知道p和q都在左子树中
             return BSTAncestor(root->left, p, q);
         }
         else if (p->val > root->val && q->val > root->val) {
             return BSTAncestor(root->right, p, q);
         }
         else {
             return root;
         }
    }
    //普通二叉树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: If root is null or root is one of p or q, return root
    if (!root || root == p || root == q) {
        return root;
    }
    // Recursively search left and right subtrees
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    // If both left and right subtrees return non-null, root is the LCA
    if (leftLCA && rightLCA) {
        return root;
    }
    // Otherwise, return non-null subtree result
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}
//--------------------------------------------------------------
//2515
// go.cpp
#include <vector>
#include <string>
#include <algorithm>
int closetTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    int minDistance = n;  // 初始化为一个大数
    bool found = false;
    
    for (int i = 0; i < n; ++i) {
        if (words[i] == target) {
            found = true;
            int distance = min(abs(i - startIndex), n - abs(i - startIndex));   //abs是取绝对值
            minDistance = min(minDistance, distance);
        }
    }
    
    return found ? minDistance : -1;
}
//  (0)->
// X X X
// X   X(target)
// X X X
// 当startIndex为0：
// Index为2时的值为target
// distance为min(abs(2-0),n-abs(2-8))

//--------------------------------------------------------------


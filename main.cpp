#include <iostream>
#include "learn.cpp"
#include "go.cpp"
// #include "all.cpp"


// int main() {
//   // std::cout << "Hello World!\n";
//   go();
//   // X x;
//   // x.hello();
// }
//-----------------------------------------------
//3101
// int main() {
//     vector<int> nums1 = {0,1,1,0,1};
//     vector<int> nums2 = {1, 0, 1, 0};

//     std::cout << "Example 1: " << countAlternatingSubarrays(nums1) << std::endl;
//     std::cout << "Example 2: " << countAlternatingSubarrays(nums2) << std::endl;

//     return 0;
// }
//----------------------------------------------
//94
// int main() {
//     TreeNode* root = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->right->left = new TreeNode(3);
    
//     vector<int> result = inorderTraversal(root);
//     for(int val : result) {   //for的条件：指定一个容器，然后遍历这个容器中的每个元素，val是容器中的每个元素
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }
//----------------------------------------------
//235

// int main() {
//     // Create the binary search tree as described in the example
//     TreeNode* root = new TreeNode(6);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(8);
//     root->left->left = new TreeNode(0);
//     root->left->right = new TreeNode(4);
//     root->right->left = new TreeNode(7);
//     root->right->right = new TreeNode(9);
//     root->left->right->left = new TreeNode(3);
//     root->left->right->right = new TreeNode(5);
//     // Define nodes p and q as described in example 1
//     TreeNode* p = root->right->left;
//     TreeNode* q = root->left->right->right;
//     //5与7的最近公共祖先是6
//     // Call the function lowestCommonAncestor
//     TreeNode* result = BSTAncestor(root, p, q);
//     TreeNode* result1 = lowestCommonAncestor(root, p, q);
//     // Output the result
//     if (result != nullptr) {
//         std::cout << "Lowest Common Ancestor: " << result->val << std::endl;
//         std::cout << "Lowest Common Ancestor: " << result1->val << std::endl;
//     } else {
//         std::cout << "One or both nodes not found in the tree." << std::endl;
//     }
//     return 0;
// }
//----------------------------------------------
//2515
// main.cpp
// int main() {
//     vector<string> words1 = {"hello", "i", "am", "leetcode", "hello"};
//     string target1 = "hello";
//     int startIndex1 = 1;
//     cout << "Example 1: " << closetTarget(words1, target1, startIndex1) << endl;
//
//     vector<string> words2 = {"a", "b", "leetcode"};
//     string target2 = "leetcode";
//     int startIndex2 = 0;
//     cout << "Example 2: " << closetTarget(words2, target2, startIndex2) << endl;
//
//     vector<string> words3 = {"i", "eat", "leetcode"};
//     string target3 = "ate";
//     int startIndex3 = 0;
//     cout << "Example 3: " << closetTarget(words3, target3, startIndex3) << endl;
//
//     return 0;
// }
//----------------------------------------------
//2959
int main() {
    int n = 3;
    int maxDistance = 5;
    vector<vector<int>> roads = {{0,1,2},{1,2,10},{0,2,10}};
    int result = numberOfSets(n, maxDistance, roads);
    cout << "Number of possible sets: " << result << endl;
    return 0;
}
//----------------------------------------------


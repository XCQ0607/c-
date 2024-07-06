#include <iostream>
#include "learn.cpp"
#include "go.cpp"
// #include "all.cpp"


// int main() {
//   // std::cout << "Hello World!\n";
//   //go();
//   X x;
//   x.hello();
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
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> result = inorderTraversal(root);
    for(int val : result) {   //for的条件：指定一个容器，然后遍历这个容器中的每个元素，val是容器中的每个元素
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
//----------------------------------------------



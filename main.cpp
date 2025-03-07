#include <iostream>
#include "go.cpp"
using namespace std;
#include "all.cpp"
#include "learn.cpp"

// int main() {
//   std::cout << "Hello World!\n";
//   go();
//   fun();
// //   X x;
// //   x.hello();
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
// int main() {
//     int n = 3;
//     int maxDistance = 5;
//     vector<vector<int>> roads = {{0,1,2},{1,2,10},{0,2,10}};
//     int result = numberOfSets(n, maxDistance, roads);
//     cout << "Number of possible sets: " << result << endl;
//     return 0;
// }
//----------------------------------------------
//3112
// int main() {
//     Solution solution;
//
//     // Example 1
//     int n1 = 3;
//     vector<vector<int>> edges1 = {{0,1,2},{1,2,1},{0,2,4}}; //这里的vector<vector<int>>表示的是一个二维数组，即一个数组中的每个元素又是一个数组.与int **相比,
//     vector<int> disappear1 = {1,1,5};
//     vector<int> result1 = solution.minimumTime(n1, edges1, disappear1);
//
//     cout << "Example 1 Result:" << endl;
//     for (int i = 0; i < result1.size(); ++i) {
//         cout << "Node " << i << ": " << result1[i] << endl;
//     }
//
//     // Example 2
//     int n2 = 3;
//     vector<vector<int>> edges2 = {{0,1,2},{1,2,1},{0,2,4}};
//     vector<int> disappear2 = {1,3,5};
//     vector<int> result2 = solution.minimumTime(n2, edges2, disappear2);
//
//     cout << "\nExample 2 Result:" << endl;
//     for (int i = 0; i < result2.size(); ++i) {
//         cout << "Node " << i << ": " << result2[i] << endl;
//     }
//
//     // Example 3
//     int n3 = 2;
//     vector<vector<int>> edges3 = {{0,1,1}};
//     vector<int> disappear3 = {1,1};
//     vector<int> result3 = solution.minimumTime(n3, edges3, disappear3);
//
//     cout << "\nExample 3 Result:" << endl;
//     for (int i = 0; i < result3.size(); ++i) {
//         cout << "Node " << i << ": " << result3[i] << endl;
//     }
//
//     return 0;
// }
//------------------------------------------
//2850
// #include <iostream>
// #include <vector>
//
// int main() {
//     vector<vector<int>> grid1 = {{1,1,0},{1,1,1},{1,2,1}};
//     vector<vector<int>> grid2 = {{1,3,0},{1,0,0},{1,0,3}};
//     vector<vector<int>> grid3 = {{1,2,2},{1,1,0},{0,1,1}};
//
//     cout << "Example 1 result: " << minimumMoves(grid1) << endl;
//     cout << "Example 2 result: " << minimumMoves(grid2) << endl;
//     cout << "Example 3 result: " << minimumMoves(grid3) << endl;
//
//     return 0;
// }
//--------------------------------------------
//2850
// #include <iostream>
// #include <vector>
//
// int main() {
//     vector<vector<int>> grid1 = {{1, 1, 0}, {1, 1, 1}, {1, 2, 1}};
//     cout << "Minimum moves for grid1: " << minimumMoves(grid1) << endl;
//
//     vector<vector<int>> grid2 = {{1, 3, 0}, {1, 0, 0}, {1, 0, 3}};
//     cout << "Minimum moves for grid2: " << minimumMoves(grid2) << endl;
//
//     vector<vector<int>> grid3 = {{0, 0, 0}, {0, 9, 0}, {0, 0, 0}};
//     cout << "Minimum moves for grid3: " << minimumMoves(grid3) << endl;
//
//     vector<vector<int>> grid4 = {{0, 0, 0}, {1, 1, 1}, {1, 1, 4}};
//     cout << "Minimum moves for grid4: " << minimumMoves(grid4) << endl;
//
//     return 0;
// }
//----------------------------------------------------------------------------
//2101
// #include <iostream>
// #include <vector>
//
// int main() {
//     vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
//     int result = maximumDetonation(bombs);
//     cout << "Maximum number of bombs that can be detonated: " << result << endl;
//     return 0;
// }
//------------------------------------------------------------------------------
//3098
// int main() {
//     std::vector<int>  nums = {1, 2, 3, 4};
//     int k = 3;
//
//     int result = sumOfPowers(nums, k);
//     std::cout << "Result: " << result << std::endl;
//
//     return 0;
// }
//-------------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// int main() {
//     Solution1 solution;
//
//     vector<int> nums = {1, 6, 7, 8};
//     vector<int> moveFrom = {1, 7, 2};
//     vector<int> moveTo = {2, 9, 5};
//
//     vector<int> result = solution.relocateMarbles(nums, moveFrom, moveTo);
//
//     cout << "Result: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;
//
//     return 0;
// }
//升级
// int main() {
//     // 定义输入
//     vector<int> nums = {1, 1, 3, 3};
//     vector<int> moveFrom = {1, 3, 3};
//     vector<int> moveTo = {2, 2 ,2};
//
//     // 调用函数
//     vector<int> result = relocateMarbles1(nums, moveFrom, moveTo);
//
//     // 输出结果
//     cout << "Final positions of marbles: ";
//     for (int pos : result) {
//         cout << pos << " ";
//     }
//     cout << endl;
//
//     return 0;
// }
//----------------------------
//2844
// #include <iostream>
// #include <string>
//
// int main() {
//     string num;
//     cout << "请输入一个数字字符串: ";
//     cin >> num;
//     int result = minimumOperations(num);
//     cout << "最少需要的操作次数: " << result << endl;
//     return 0;
// }
// int main() {
//     string num = "2245047";
//     int result = minimumOperations(num);
//     cout << "Result: " << result << endl;
//     return 0;
// }
//------------------------------
//3011
// #include <iostream>
// #include <vector>

// int main() {
//     vector<int> nums = {8, 4, 2, 30, 15};
//     bool result = canSortArray(nums);
//     cout << (result ? "true" : "false") << endl;
//     return 0;
// }
//--------------------------------
//3106
// int main() {
//     string s = "zbbz";
//     int k = 3;
//     string result = getSmallestString(s, k);
//     cout << result << endl; // 输出: aaaz
//     return 0;
// }
//-------------------------------------
// 699
// int main() {
//     vector<vector<int>> positions = {{1,2},{2,3},{6,1}};
//     vector<int> result = fallingSquares(positions);
//     cout << "Output: [";
//     for (int i = 0; i < result.size(); ++i) {
//         cout << result[i];
//         if (i < result.size() - 1) cout << ",";
//     }
//     cout << "]" << endl;
//     return 0;
// }
//---------------------------------------
//2961
// int main() {
//     vector<vector<int>> variables = {{2,3,3,10}, {3,3,3,1}, {6,1,1,4}};
//     int target = 2;
//     vector<int> result = getGoodIndices(variables, target);
//     cout << "Good indices: ";
//     for (int index : result) {
//         cout << index << " ";
//     }
//     cout << endl;
//     return 0;
// }
//---------------------------------------
//3111
// int main() {
//     std::vector<std::vector<int>> points = {{2, 1}, {1, 0}, {1, 4}, {1, 8}, {3, 5}, {4, 6}};
//     int w = 1;
//     int result = minRectanglesToCoverPoints(points, w);
//     std::cout << "The minimum number of rectangles needed: " << result << std::endl;
//     return 0;
// }
//--------------------------------------
// 40
// int main()
// {
//     vector<int> cards = {1, 2, 7, 9, 11};
//     int cnt = 3;
//     int result = maxmiumScore(cards, cnt);
//     cout << "Maximum valid score: " << result << endl;
//     return 0;
// }

//--------------------------------------
// 2940
// int main() {
//     vector<int> heights = {6, 4, 8, 5, 2, 7};
//     vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
//
//     vector<int> result = leftmostBuildingQueries(heights, queries);
//
//     for (int res : result) {
//         cout << res << " ";
//     }
//     cout << endl;
//
//     return 0;
// }
//--------------------------------------
//1035
// int main() {
//     vector<int> nums1 = {1,4,2};
//     vector<int> nums2 = {1,2,4};
//
//     int result = maxUncrossedLines(nums1, nums2);
//
//     cout << "Maximum number of uncrossed lines: " << result << endl;
//
//     return 0;
// }
//--------------------------------------
//676
// int main() {
//     MagicDictionary magicDictionary;
//     vector<string> dictionary = {"hello", "leetcode"};
//     magicDictionary.buildDict(dictionary);
//     cout << boolalpha;
//     //boolalpha用于控制输出bool类型时，输出true或false，而不是1或0
//     //类似的，boolalpha也可以用于输入，将输入的true或false转换为bool类型
//     //如:cin >> boolalpha;
//     //当输入true时，cin会将其转换为bool类型的true
//     cout << magicDictionary.search("hello") << endl;    // false
//     cout << magicDictionary.search("hhllo") << endl;    // true
//     cout << magicDictionary.search("hell") << endl;     // false
//     cout << magicDictionary.search("leetcoded") << endl; // false
//     return 0;
// }
//--------------------------------------
//3151
// int main() {
//     std::vector<int> nums = {1};
//     bool result = isArraySpecial(nums);
//     std::cout << (result ? "true" : "false") << std::endl;
//     return 0;
// }
//--------------------------------------
//3152
// int main()
// {
//     vector<int> nums = {4,3,1,6};
//     vector<vector<int>> queries = {{0,2},{2,3}};

//     vector<bool> result = isArraySpecial(nums, queries);

//     for (bool b : result) {
//         cout << (b ? "true" : "false") << " ";
//     }
//     cout << endl;

//     return 0;
// }
//--------------------------------------
//64
// int main() {
//     // Initialize the grid
//     std::vector<std::vector<int>> grid = {  //这里使用std::vector<std::vector<int>>表示一个二维数组，即一个数组中的每个元素又是一个数组
//         {1, 3, 1},
//         {1, 5, 1},
//         {4, 2, 1}
//     };

//     int result = minPathSum(grid);
//     std::cout << "最小路径和是：" << result << std::endl;

//     return 0;
// }
//--------------------------------------
// 63.不同路径 II
// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {}
// int main(){
//         // 创建一个障碍物网格
//     int m = 3, n = 3;
//     int** obstacleGrid = (int**)malloc(m * sizeof(int*));
//     for (int i = 0; i < m; i++) {
//         obstacleGrid[i] = (int*)malloc(n * sizeof(int));
//     }

//     // 初始化网格
//     int tempGrid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             obstacleGrid[i][j] = tempGrid[i][j];
//         }
//     }
//     // 调用函数并输出结果
//     std::vector<std::vector<int>> obstacleGridVec(m, std::vector<int>(n));
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             obstacleGridVec[i][j] = tempGrid[i][j];
//         }
//     }
//     int result = uniquePathsWithObstacles(obstacleGridVec);
//     std::cout << "不同路径的数量是：" << result << std::endl;

//     return 0;
// }

//---------------------------
// 120. 三角形最小路径和
// int main() {
//     // 创建一个三角形
//     std::vector<std::vector<int>> triangle = {
//         {2},
//         {3, 4},
//         {6, 5, 7},
//         {4, 1, 8, 3}
//     };

//     int result = minimumTotal(triangle);
//     std::cout << "三角形的最小路径和是：" << result << std::endl;

//     return 0;
// }
//-------------------------
// 931. 下降路径最小和
// int main() {
//     vector<vector<int>> matrixVec = {
//         {2, 1, 3},
//         {6, 5, 4},
//         {7, 8, 9}
//     };
//     int result = minFallingPathSum(matrixVec);
//     printf("下降路径的最小和是：%d\n", result);
//     return 0;
// }
//----------------------------------------------
// 221. 最大正方形
// int main() {
//     vector<vector<char>> matrix = {
//         {'1', '0', '1', '0', '0'},
//         {'1', '0', '1', '1', '1'},
//         {'1', '1', '1', '1', '1'},
//         {'1', '0', '0', '1', '0'}
//     };
//     int result = maximalSquare(matrix);
//     cout << "最大正方形的面积是：" << result << endl;
//     return 0;
// }
//----------------------------------------------
//5.最长回文子串
// int main() {
//     Solution2 solution1;
    
//     // 测试用例1
//     std::string s1 = "babad";
//     std::string result1 = solution1.longestPalindrome(s1);
//     std::cout << "输入: " << s1 << std::endl;
//     std::cout << "输出: " << result1 << std::endl;
    
//     // 测试用例2
//     std::string s2 = "cbbd";
//     std::string result2 = solution1.longestPalindrome(s2);
//     std::cout << "输入: " << s2 << std::endl;
//     std::cout << "输出: " << result2 << std::endl;
    
//     return 0;
// }
//----------------------------------------------
//139. 单词拆分
// #include <iostream>
// #include <string>
// #include <vector>

// int main() {
    
//     // 测试用例1
//     std::string s1 = "leetcode";
//     std::vector<std::string> wordDict1 = {"leet", "code"};
//     bool result1 = wordBreak(s1, wordDict1);
//     std::cout << "输入: s = \"" << s1 << "\", wordDict = [\"leet\", \"code\"]" << std::endl;
//     std::cout << "输出: " << (result1 ? "true" : "false") << std::endl;
    
//     // 测试用例2
//     std::string s2 = "applepenapple";
//     std::vector<std::string> wordDict2 = {"apple", "pen"};
//     bool result2 = wordBreak(s2, wordDict2);
//     std::cout << "\n输入: s = \"" << s2 << "\", wordDict = [\"apple\", \"pen\"]" << std::endl;
//     std::cout << "输出: " << (result2 ? "true" : "false") << std::endl;
    
//     // 测试用例3
//     std::string s3 = "catsandog";
//     std::vector<std::string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
//     bool result3 = wordBreak(s3, wordDict3);
//     std::cout << "\n输入: s = \"" << s3 << "\", wordDict = [\"cats\", \"dog\", \"sand\", \"and\", \"cat\"]" << std::endl;
//     std::cout << "输出: " << (result3 ? "true" : "false") << std::endl;
    
//     return 0;
// }
//----------------------------------------------
//516. 最长回文子序列
#include <iostream>
#include <string>

int main() {
    
    // 测试用例1
    std::string s1 = "bbbab";
    int result1 = longestPalindromeSubseq(s1);
    std::cout << "输入: s = \"" << s1 << "\"" << std::endl;
    std::cout << "输出: " << result1 << std::endl;
    std::cout << "解释: 一个可能的最长回文子序列为 \"bbbb\"。" << std::endl;
    
    // 测试用例2
    std::string s2 = "cbbd";
    int result2 = longestPalindromeSubseq(s2);
    std::cout << "\n输入: s = \"" << s2 << "\"" << std::endl;
    std::cout << "输出: " << result2 << std::endl;
    std::cout << "解释: 一个可能的最长回文子序列为 \"bb\"。" << std::endl;
    
    return 0;
}
//----------------------------------------------
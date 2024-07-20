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
//2959
#include <cstring>
int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    int ans = 0;
    //主循环讨论情况
    for (int mask = 0; mask < 1 << n; ++mask) { //1<< n表示2的n次方,是因为1向左位移,空的部分用0填充,所以1<<n表示2的n次方
        int g[n][n];
        memset(g, 0x3f, sizeof(g)); //0x3f是一个很大的数，表示无穷大
        for (auto& e : roads) {
            int u = e[0], v = e[1], w = e[2];   //e是roads的元素，提取道路的起点 u，终点 v 和道路长度 w。
            //例如，如果 mask = 001，表示只有分部 2 被关闭。
            if ((mask >> u & 1) & (mask >> v & 1)) {    //这里的mask >> u & 1表示将mask向右移动u位，然后与1进行按位与操作，得到的结果是一个二进制数，如果该二进制数的最低位为1，则表示mask的第u位为1，否则为0。
                g[u][v] = min(g[u][v], w);
                g[v][u] = min(g[v][u], w);
                //矩阵 g 是一个邻接矩阵，用于存储分部之间的最短路径距离。矩阵 g[i][j] 表示分部 i 到分部 j 之间的最短路径距离。
            }
        }
        //计算最短路径,算法为Floyd-Warshall算法,它们可以计算任意两点之间的最短路径。
        //mask=011
        for (int k = 0; k < n; ++k) {
            if (mask >> k & 1) {
                g[k][k] = 0;
                //设置 g[0][0] = 0
                //设置 g[1][1] = 0
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
        int ok = 1;
        for (int i = 0; i < n && ok == 1; ++i) {
            for (int j = 0; j < n && ok == 1; ++j) {
                if ((mask >> i & 1) & (mask >> j & 1) && g[i][j] > maxDistance) {
                    ok = 0;
                }
            }
        }
        ans += ok;
    }
    return ans;
}
//--------------------------------------------------------------------------
//3112
#include <vector>
#include <queue>
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n); // 稀疏图用邻接表
        for (auto& e : edges) {
            int x = e[0], y = e[1], wt = e[2];
            //这里的x, y, wt分别表示道路的起点、终点和道路长度。
            g[x].emplace_back(y, wt);
            //这里的emplace_back()函数用于将一个元素添加到向量的末尾。
            g[y].emplace_back(x, wt);
        }

        vector<int> dis(n, -1);
        dis[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x]) { // x 之前出堆过
                continue;
            }
            for (auto& [y, d] : g[x]) {
                int new_dis = dx + d;
                if (new_dis < disappear[y] && (dis[y] < 0 || new_dis < dis[y])) {
                    dis[y] = new_dis; // 更新 x 的邻居的最短路
                    pq.emplace(new_dis, y);
                }
            }
        }
        return dis;
    }
};
//--------------------------------------------------------------------------
//2850
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> from, to;        //这里的from和to分别表示道路的起点和终点。
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {       //如果gird[i][j]不为0，则表示该道路是通的，将起点和终点分别存入from和to中。
                    for (int k = 1; k < grid[i][j]; k++) {
                        from.emplace_back(i, j);    //emplace_back()函数用于将元素添加到向量的末尾,这里的两个元素i与j
                    }
                } else {
                    to.emplace_back(i, j);
                }
            }
        }

        int ans = INT_MAX;  //INT_MAX指的是 C++ 标准库中的一个宏，表示 int 类型的最大值。它定义在 <climits> 头文件中。通常在 32 位系统上是
        do {
            int total = 0;
            for (int i = 0; i < from.size(); i++) {
                total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            ans = min(ans, total);
        } while (next_permutation(from.begin(), from.end()));
        return ans;
    }
//----------------------------------------------------------------------------



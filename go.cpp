#include <numeric>
#include <vector>
using namespace std;

//--------------------------------------------------------------
//3101
int countAlternatingSubarrays(vector<int>& nums)
{
    int n = nums.size();
    int count = n; // 每个单个元素都是一个交替子数组
    int length = 1;

    for (int i = 1; i < n; ++i)
    {
        if (nums[i] != nums[i - 1])
        {
            length++;
            //遇到相邻的不同元素会一直累加。如01，此时count+1,若为010，则在此基础上再加2，子数组为10,010，若为0101，再词基础上再加3，为01.101.0101，向前推
        }
        else
        {
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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ans;
    function<void(TreeNode*)> dfs = [&](TreeNode* root)
    {
        //function是一种特殊的函数类型，它可以表示一个函数，而不仅仅是一个函数指针。这里的函数名是dfs，它表示一个函数，该函数接受一个TreeNode*类型的参数root
        //[&] 表示捕获外部作用域中的所有变量（包括 ans）并按引用传递。
        if (!root)
        {
            return;
        }
        dfs(root->left); // 递归遍历左子树
        ans.push_back(root->val); //push_back是vector的成员函数，用于在末尾添加一个元素。类似的函数还有push_front、pop_back、pop_front等函数
        dfs(root->right); // 递归遍历右子树
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
TreeNode* BSTAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (p->val < root->val && q->val < root->val)
    {
        // 都在左子树中,通过条件可以知道p和q都在左子树中
        return BSTAncestor(root->left, p, q);
    }
    else if (p->val > root->val && q->val > root->val)
    {
        return BSTAncestor(root->right, p, q);
    }
    else
    {
        return root;
    }
}

//普通二叉树
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // Base case: If root is null or root is one of p or q, return root
    if (!root || root == p || root == q)
    {
        return root;
    }
    // Recursively search left and right subtrees
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    // If both left and right subtrees return non-null, root is the LCA
    if (leftLCA && rightLCA)
    {
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

int closetTarget(vector<string>& words, string target, int startIndex)
{
    int n = words.size();
    int minDistance = n; // 初始化为一个大数
    bool found = false;

    for (int i = 0; i < n; ++i)
    {
        if (words[i] == target)
        {
            found = true;
            int distance = min(abs(i - startIndex), n - abs(i - startIndex)); //abs是取绝对值
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

int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads)
{
    int ans = 0;
    //主循环讨论情况
    for (int mask = 0; mask < 1 << n; ++mask)
    {
        //1<< n表示2的n次方,是因为1向左位移,空的部分用0填充,所以1<<n表示2的n次方
        int g[n][n];
        memset(g, 0x3f, sizeof(g)); //0x3f是一个很大的数，表示无穷大
        for (auto& e : roads)
        {
            int u = e[0], v = e[1], w = e[2]; //e是roads的元素，提取道路的起点 u，终点 v 和道路长度 w。
            //例如，如果 mask = 001，表示只有分部 2 被关闭。
            if ((mask >> u & 1) & (mask >> v & 1))
            {
                //这里的mask >> u & 1表示将mask向右移动u位，然后与1进行按位与操作，得到的结果是一个二进制数，如果该二进制数的最低位为1，则表示mask的第u位为1，否则为0。
                g[u][v] = min(g[u][v], w);
                g[v][u] = min(g[v][u], w);
                //矩阵 g 是一个邻接矩阵，用于存储分部之间的最短路径距离。矩阵 g[i][j] 表示分部 i 到分部 j 之间的最短路径距离。
            }
        }
        //计算最短路径,算法为Floyd-Warshall算法,它们可以计算任意两点之间的最短路径。
        //mask=011
        for (int k = 0; k < n; ++k)
        {
            if (mask >> k & 1)
            {
                g[k][k] = 0;
                //设置 g[0][0] = 0
                //设置 g[1][1] = 0
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
        int ok = 1;
        for (int i = 0; i < n && ok == 1; ++i)
        {
            for (int j = 0; j < n && ok == 1; ++j)
            {
                if ((mask >> i & 1) & (mask >> j & 1) && g[i][j] > maxDistance)
                {
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

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        vector<vector<pair<int, int>>> g(n); // 稀疏图用邻接表
        for (auto& e : edges)
        {
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
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x])
            {
                // x 之前出堆过
                continue;
            }
            for (auto& [y, d] : g[x])
            {
                int new_dis = dx + d;
                if (new_dis < disappear[y] && (dis[y] < 0 || new_dis < dis[y]))
                {
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
int minimumMoves(vector<vector<int>>& grid)
{
    vector<pair<int, int>> from, to; //这里的from和to分别表示道路的起点和终点。
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j])
            {
                //如果gird[i][j]不为0，则表示该道路是通的，将起点和终点分别存入from和to中。
                for (int k = 1; k < grid[i][j]; k++)
                {
                    from.emplace_back(i, j); //emplace_back()函数用于将元素添加到向量的末尾,这里的两个元素i与j
                }
            }
            else
            {
                to.emplace_back(i, j);
            }
        }
    }

    int ans = INT_MAX; //INT_MAX指的是 C++ 标准库中的一个宏，表示 int 类型的最大值。它定义在 <climits> 头文件中。通常在 32 位系统上是
    do
    {
        int total = 0;
        for (int i = 0; i < from.size(); i++)
        {
            total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
        }
        ans = min(ans, total);
    }
    while (next_permutation(from.begin(), from.end()));
    return ans;
}

//----------------------------------------------------------------------------
//2101
#include <vector>
#include <algorithm>

int maximumDetonation(vector<vector<int>>& bombs)
{
    int n = bombs.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        long long x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
        for (int j = 0; j < n; j++)
        {
            long long dx = x - bombs[j][0];
            long long dy = y - bombs[j][1];
            if (j != i && dx * dx + dy * dy <= r * r)
            {
                g[i].push_back(j); // i 可以引爆 j
            }
        }
    }
    int ans = 0;
    vector<int> vis(n);
    function<int(int)> dfs = [&](int x) -> int
    {
        vis[x] = true;
        int cnt = 1;
        for (int y : g[x])
        {
            if (!vis[y])
            {
                cnt += dfs(y);
            }
        }
        return cnt;
    };
    for (int i = 0; i < n; i++)
    {
        fill(vis.begin(), vis.end(), 0);
        ans = max(ans, dfs(i));
    }
    return ans;
}

//-----------------------------------------------------
//3098
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#define MOD 1000000007

void MD(int& x)
{
    if (x >= MOD)
    {
        x -= MOD;
    }
}

int sumOfPowers(std::vector<int>& nums, int k)
{
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::set<int> deltas;

    // Calculate all pairwise absolute differences
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            deltas.insert(nums[j] - nums[i]);
            //insert函数是用来向set中插入元素的函数，如果插入成功，则返回一个pair，pair的first元素是一个迭代器，指向插入的元素，pair的second元素是一个bool值，表示插入是否成功。
        }
    }
    //这段代码将所有可能的差值 nums[j] - nums[i] 插入到 deltas 集合中。如果两个元素的差值相同，std::set 会自动处理，确保集合中没有重复的差值。因此，差值相同的情况不会重复存储。

    constexpr int MAXN = 50;
    static int combs[MAXN + 1][MAXN + 1];
    std::memset(combs, 0, sizeof(combs));

    combs[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        combs[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            combs[i][j] = (combs[i - 1][j - 1] + combs[i - 1][j]) % MOD;
        }
    }

    // dp[i][j]: number of subsequences of length j ending at index i
    static int dp[MAXN][MAXN + 1];

    int last_ans = combs[n][k];
    int ans = 0;

    for (int delta : deltas)
    {
        std::memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 1; i < n; ++i)
        {
            int feasible = i - 1;
            while (feasible >= 0 && nums[i] - nums[feasible] <= delta)
            {
                --feasible;
            }

            for (int j = 0; j <= k; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j > 0 && feasible >= 0)
                {
                    dp[i][j] = (dp[i][j] + dp[feasible][j - 1]) % MOD;
                }
            }
        }

        int this_ans = dp[n - 1][k];
        int this_cnt = (last_ans + MOD - this_ans) % MOD;
        ans = (ans + 1LL * this_cnt * delta % MOD) % MOD;
        last_ans = this_ans;
    }

    return ans;
}

//---------------------------------------------------
//2766
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution1
{
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        //unordered_set 是 C++ 标准库中的一个关联容器，它存储的元素是无序的，并且每个元素都是唯一的。
        for (int i = 0; i < moveFrom.size(); i++)
        {
            st.erase(moveFrom[i]);
            //erase函数是用来从set中删除元素的函数，如果删除成功，则返回一个bool值，表示删除是否成功。
            st.insert(moveTo[i]);
        }
        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//升级题目,只移动一个石块
vector<int> relocateMarbles1(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo)
{
    unordered_map<int, int> stoneCount;
    //unordered_map 是 C++ 标准库中的一个关联容器，它存储的元素是无序的，并且每个元素的键是唯一的。

    // 初始化石块数量
    for (int num : nums)
    {
        stoneCount[num]++;
    }

    // 执行移动操作
    for (int i = 0; i < moveFrom.size(); i++)
    {
        int from = moveFrom[i];
        int to = moveTo[i];

        if (stoneCount[from] > 0)
        {
            stoneCount[from]--;
            stoneCount[to]++;

            if (stoneCount[from] == 0)
            {
                stoneCount.erase(from);
                //erase函数是用来从map中删除元素的函数，如果删除成功，则返回一个bool值，表示删除是否成功。
            }
        }
    }

    // 收集有石块的位置
    vector<int> result;
    for (const auto& pair : stoneCount)
    {
        if (pair.second > 0)
        {
            result.push_back(pair.first);
        }
    }
    // pair 是什么？
    // 在这个上下文中，pair 是 unordered_map 中的一个键值对（key-value pair）。unordered_map 存储的每个元素都是一个 pair。
    //
    // first 和 second 是什么？
    //
    // pair.first 表示键（key）
    // pair.second 表示值（value）
    // 排序结果
    //     sort(result.begin(), result.end());
    //     举个例子：
    //      假设在某一时刻，stoneCount 包含以下内容：
    //      {2: 2, 3: 1, 5: 0}
    //
    //     这表示：
    //
    //     位置 2 有 2 个石块
    //     位置 3 有 1 个石块
    //     位置 5 有 0 个石块
    //     遍历这个 map 时：
    //
    //     对于 {2: 2}，pair.first 是 2，pair.second 是 2
    //     对于 {3: 1}，pair.first 是 3，pair.second 是 1
    //     对于 {5: 0}，pair.first 是 5，pair.second 是 0
    //     最终，result 数组将包含 [2, 3]，因为只有位置 2 和 3 的石块数量大于 0
    return result;
}

//-----------------------------------------------------
//2844
int minimumOperations(string num)
{
    int n = num.length();
    auto f = [&](string tail)
    {
        int i = num.rfind(tail[1]);
        // 在C++中，字符串的索引是从0开始的。也就是说，字符串的第一个字符的索引是0，第二个字符的索引是1，以此类推。
        // 所以，当你使用 rfind 函数从右向左查找字符时，返回的索引也是从0开始的。也就是说，如果 rfind 找到了字符，它返回的索引是字符串中最后一个匹配字符的索引。
        // 例如，对于字符串 "hello"：
        // rfind('o') 返回 4，因为 'o' 是字符串 "hello" 的最后一个字符。
        // rfind('l') 返回 2，因为 'l' 是字符串 "hello" 中从右向左数第二个字符。
        // 所以，rfind 返回的索引是字符串中最后一个匹配字符的位置
        //2245047
        if (i == string::npos || i == 0)
        {
            return n;
        }
        i = num.rfind(tail[0], i - 1);
        return i == string::npos ? n : n - i - 2;
        //对于f("50")而言,去除+保留=n,则去除=n-保留
        // i 是找到的模式（如"50"）中第一个字符的索引。
        // 2 是模式本身的长度（因为我们总是在寻找两位数的模式，如"00", "25", "50", "75"）。
    };
    int zero = n - (num.find('0') != string::npos);
    return min({zero, f("00"), f("25"), f("50"), f("75")});
    // 一个数能被25整除，其末尾必须是 "00", "25", "50", 或 "75"。
}

// 如果字符串中包含 '0'：
// zero = n - 1，即删除 n-1 个字符
// 如果字符串中不包含 '0'：
// zero = n，即删除所有 n 个字符
// 它代表了一个极端情况：如果无法通过删除部分字符使数字变为特殊数字，那么删除所有字符（或除了一个 '0' 之外的所有字符）可能是唯一的选择。
// 在函数的最后，我们比较所有可能的情况：
// return min({zero, f("00"), f("25"), f("50"), f("75")});
// 这里的比较仍然是有效的，因为：
// 如果能找到一种删除方式使得剩下的数字是特殊数字（能被 25 整除），那么这种方式的删除次数一定小于或等于 zero。
// 如果找不到这样的方式，zero 就会成为最小值，表示我们需要删除所有字符。
// 这种处理方式实际上巧妙地处理了无解的情况。当没有办法通过删除部分字符使数字变为特殊数字时，删除所有字符（或除了一个 '0' 之外的所有字符）成为了默认的"解"，尽管这并不会产生一个特殊数字。
//-----------------------------------------------
//3011
bool canSortArray(vector<int>& nums)
{
    for (int i = 0, n = nums.size(); i < n;)
    {
        int start = i;
        int ones = __builtin_popcount(nums[i++]);
        //__builtin_popcount 是 GCC（GNU Compiler Collection）提供的一个内置函数，用于计算一个整数的二进制表示中 1 的个数。
        //__builtin_popcount 函数计算的是二进制表示中 1 的个数。如果你需要计算 0 的个数，你可以使用 __builtin_popcount(~x)，其中 x 是你的整数。~ 是按位取反运算符，它会将 x 的每一位都取反，所以 __builtin_popcount(~x) 计算的是 x 的二进制表示中 0 的个数。
        while (i < n && __builtin_popcount(nums[i]) == ones)
        {
            i++;
        }
        sort(nums.begin() + start, nums.begin() + i);
    }
    return ranges::is_sorted(nums);
    //is_orted 是 C++20 中引入的一个函数，用于检查一个范围（range）是否已经排序。如果范围已经排序，它返回 true；否则，返回 false。
}

//--------------------------------------
//3106
string getSmallestString(string s, int k)
{
    for (char& c : s)
    {
        int dis = min(c - 'a', 'z' - c + 1);
        //dis 代表 "distance"（距离），它表示将当前字符 c 变为 'a' 所需的最小步数
        if (dis > k)
        {
            c -= k;
            break;
        }
        c = 'a';
        k -= dis;
    }
    return s;
}

//-----------------------------
//699
int findSite(vector<int>& site, int M, int tar)
{
    // 二分查找对象tar
    int l = 0, r = M - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (site[mid] == tar) return mid;
        else if (site[mid] > tar) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
    // 初始化左指针 l 为 0，右指针 r 为数组最后一个元素的索引。
    // 当 l <= r 时，重复以下步骤： a. 计算中间索引 mid = (l + r) / 2 b. 如果 site[mid] 等于目标值，返回 mid c. 如果 site[mid] 大于目标值，将 r 设为 mid - 1 d. 如果 site[mid] 小于目标值，将 l 设为 mid + 1
    // 如果循环结束还没找到，返回 -1 表示未找到。
}

vector<int> fallingSquares(vector<vector<int>>& positions)
{
    int N = positions.size(), maxH = 0;
    vector<int> site;
    site.reserve(2 * N);
    //reserve 是 C++ 标准库中的一个成员函数，用于预留空间。它允许你预先分配一定数量的内存，以避免在插入元素时频繁地重新分配内存。
    for (const auto& v : positions)
    {
        // positions = [[1,2],[2,3],[6,1]]
        site.emplace_back(v[0]);
        site.emplace_back(v[0] + v[1]);
        //输出：[1, 3, 2, 5, 6, 7]
        // left：方块的左边界
        // left + sideLength - 1：方块的右边界
    }
    sort(site.begin(), site.end());
    site.erase(unique(site.begin(), site.end()), site.end());
    //unique(site.begin(), site.end())返回一个迭代器new_end，它指向去重后容器中最后一个不重复元素的下一个位置。然后，我们使用erase函数删除从new_end到site.end()之间的所有元素，这些元素都是重复的。
    int M = site.size();
    vector<int> height(M, 0), ans(N, 0);
    //这里的,ans(N)表示同时创建一个大小为N的vector
    for (int i = 0, start, end, len, tmp; i < N; ++i)
    {
        //site = [1 , 2 , 3 , 5 , 6 , 7]
        len = positions[i][1];
        //这是当前方块的边长
        start = findSite(site, M, positions[i][0]);
        //这是在site数组中找到当前方块左边界(1)对应的索引。
        end = positions[i][0] + len;
        //这是计算当前方块右边界在原始坐标系中的位置
        tmp = 0;
        for (int j = start; j < M && site[j] <= end; ++j) tmp = max(tmp, height[j]);    //hight中每一个元素代表正方形边长所占边的高度,如hight[0]是site = [1 , 2 , 3 , 5 , 6 , 7](hight与site的大小相等)中横坐标为1的地方最高hight
        tmp += len; //tmp加上我要掉下来的高度,tmp更新取决于当前正方形宽度导致的上面for循环更新的tmp的值
        for (int j = start; j < M && site[j] <= end; ++j) height[j] = tmp;  //再更新当前正方形覆盖区域的hight大小---注意这里的start是正方形左边对应的hight中的index值
        maxH = max(tmp, maxH);
        //更新maxH
        ans[i] = maxH;
        //每falling一次，更新ans[i]的值
        // len = 2
        // start = findSite(site, 6, 1) = 0 (1在site中的索引是0)
        // end = 1 + 2 - 1 = 2
        // tmp = 0 (初始值)
        // 第一个for循环: tmp 保持为0，因为所有height[j]都是0
        // tmp += len, 所以 tmp = 2
        // 第二个for循环: 更新 height[0] 和 height[1] 为 2 height 变为 [2, 2, 0, 0, 0, 0]
        // maxH = max(2, 0) = 2
        // ans[0] = 2
    }
    return ans;
}
//-----------------------------------
//2961
int pow(int x, int n, int mod){
    //x的n次方再模mod
    int res = 1;
    while(n){
        if(n&1){
            res = res * x % mod;        //在自乘得时候同时mod不影响结果
        }
        x = x * x % mod;                //这里也mod减小运算量
        n >>= 1;
    }
    return res;
}
// 这个函数接受两个参数：base和exponent，都是double类型的。pow函数返回base的exponent次幂。
// 例如，pow(2.0, 3.0)将返回8.0，因为2的3次幂是8。
vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> res;
    for (int i = 0; i < variables.size(); i++){
        auto& v = variables[i];
        if (pow(pow(v[0], v[1], 10), v[2], v[3]) == target) {
            res.push_back(i);
        }
    }
    return res;
}
// ----
//快速幂算法（也称为二进制求幂）
//参考https://leetcode.cn/problems/powx-n/solutions/2858114/tu-jie-yi-zhang-tu-miao-dong-kuai-su-mi-ykp3i/
//如13=1101(2)  x^13=x^8*x^4*x^1     每次当n的最低位为1时，判断&1最低位是否为1,是的话就把当前的x乘到结果中，然后x自乘(每次while都自乘,每次都判断是否要乘以自乘得出的x^2,x^4,x^8等等)，n右移一位
//   1     1   0   1
//   x^8  x^4 x^2  x^1
long long myPow(double x, int N) {
    long long ans = 1;
    long long n = N;
    if (n < 0) { // x^-n = (1/x)^n
        n = -n;
        x = 1 / x;
    }
    while (n) { // 从低到高枚举 n 的每个比特位
        if (n & 1) { // 这个比特位是 1
            ans *= x; // 把 x 乘到 ans 中
        }
        x *= x; // x 自身平方
        n >>= 1; // 继续枚举下一个比特位
    }
    return ans;
}
//---------------------------------------------
//3111
int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    ranges::sort(points, [](const auto& p, const auto& q) {
        return p[0] < q[0];
    });
    //这里的cmp函数是lambda表达式
    // sort(points.begin(), points.end(), [](const auto& p, const auto& q) {
    // return p[0] < q[0];
    // });
    // 第二种写法使用了C++标准库中的std::sort函数，它接受三个参数：要排序的范围的开始和结束迭代器，以及一个比较函数。比较函数接受两个参数，并返回一个布尔值，表示第一个参数是否应该排在第二个参数之前。
    // 第一种写法使用了C++20中引入的ranges库中的ranges::sort函数。这个函数的用法和std::sort类似，但是它使用的是范围（range）而不是迭代器。范围可以是一个容器、一个子范围，或者任何其他可以迭代的对象。
    int ans = 0;
    int x2 = -1;
    for (auto& p : points) {
        if (p[0] > x2) {    //如果p[0]大于x2，说明需要一个新的矩形
            ans++;
            x2 = p[0] + w;      //采用新矩形后更新x2值,之后比较排序后的points中的点的横坐标是否大于x2(矩形左边界放在点上,右边界为x2)
        }
    }
    return ans;
}
//----------------------------------------------
// 40
int maxmiumScore(vector<int>& cards, int cnt) {
    ranges::sort(cards, greater<>());       //可省略模板参数<int>为<>或空       想法就是lesser<>()函数返回一个比较函数，从小到大排序(默认的,所以可以省略)
    int s = reduce(cards.begin(), cards.begin() + cnt, 0); // 最大的 cnt 个数之和
    //reduce是相加函数
    if (s % 2 == 0) { // s 是偶数
        return s;
    }

    auto replace_sum = [&](int x) -> int {
        for (int i = cnt; i < cards.size(); i++) {
            if (cards[i] % 2 != x % 2) { // 找到一个最大的奇偶性和 x 不同的数
                return s - x + cards[i]; // 用 cards[i] 替换 s
            }
        }
        return 0;
    };

    int x = cards[cnt - 1];     //从大到小排列第cnt个数
    int ans = replace_sum(x); // 替换 x
    for (int i = cnt - 2; i >= 0; i--) { // 前 cnt-1 个数
        if (cards[i] % 2 != x % 2) { // 找到一个最小的奇偶性和 x 不同的数      优化计算
            ans = max(ans, replace_sum(cards[i])); // 替换
            break;
        }
    }
    return ans;
}
//----------------------------------------------
// 2940
vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), -1);
    vector<vector<pair<int, int>>> qs(heights.size());
    for (int i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0], b = queries[i][1];
        if (a > b) {
            swap(a, b); // 保证 a <= b
        }
        //swap结束,此时a<=b
        if (a == b || heights[a] < heights[b]) {
            ans[i] = b; // a 直接跳到 b
        } else {
            qs[b].emplace_back(heights[a], i); // 离线询问     储存i是为了在最后更新ans[i]的值
        }
    }
// 0	[ ]
// 1	[(6, 0)]
// 2	[ ]
// 3	[(6, 1)]
// 4	[(8, 2), (5, 3)]
// 5	[ ]
//prior_queue是优先队列，它是一种特殊的队列，它的元素按照一定的优先级进行排序。优先队列中的元素可以按照任意顺序插入，但是每次取出的元素都是优先级最高的元素。
// priority_queue 中的三个参数： priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
// 第一个参数 pair<int, int>：这是队列中存储的元素类型。在这里，每个元素是一个整数对，第一个整数表示建筑高度，第二个整数表示查询索引。
// 第二个参数 vector<pair<int, int>>：这是用于存储元素的底层容器类型。priority_queue 默认使用 vector，但这里显式指定是为了清晰。
// 第三个参数 greater<>：这是比较函数对象，用于决定元素的优先级。使用 greater<> 意味着这是一个小顶堆，即最小的元素会被优先处理。
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;   // pq是一个优先队列，它按照pair的第一个元素进行升序排序
// 其中：
// 第一个 int 是建筑的高度
// 第二个 int 是查询的索引
    //heights = [6, 4, 8, 5, 2, 7] 和 queries = [[0, 1], [0, 3], [2, 4], [3, 4], [2, 2]]
    for (int i = 0; i < heights.size(); i++) {  //遍历hights的索引
        while (!pq.empty() && pq.top().first < heights[i]) {
            // 堆顶的 heights[a] 可以跳到 heights[i]
            ans[pq.top().second] = i;
            pq.pop();   // pq.top()是堆顶元素，pq.pop()是删除堆顶元素
        }
        for (auto& p : qs[i]) {     //处理离线询问,qs[i]即要在该index下处理的询问,存入pq中是a的高度和查询的索引,在i++后while函数会处理这些询问
            pq.emplace(p); // 后面再回答
            //emplace()函数是C++ STL中vector容器的一个成员函数，用于在vector的末尾添加一个元素。与push_back()函数不同的是，emplace()函数可以直接在vector的末尾构造一个元素，而不是先创建一个临时对象再将其复制或移动到vector中。这使得emplace()函数在某些情况下比push_back()函数更高效。
        }
    }
    return ans;
}
//----------------------------------------------
//1035
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int dp[510] = {0};
    for(int i=0;i<nums1.size();i++) {
        for(int j=nums2.size()-1;j>=0;j--) if(nums1[i]==nums2[j]) {
            if(j>=1) dp[j] = max(dp[j],dp[j-1]+1);
            else dp[j] = max(dp[j],1);  //前面有if判断了nums1[i]==nums2[j],所以这里dp[0]一定大于等于1,设置为max(dp[j],1)
        }
// 作用：
// 传播最优解：这个循环确保较小索引处的最优解可以传播到较大的索引。
// 维护单调性：确保dp数组在每一行都是单调非递减的。
// 处理不匹配情况：即使当前元素不匹配，我们也要考虑之前的最优解。
        // 这个步骤很重要，因为它确保了即使我们没有在当前位置找到匹配，我们也能利用之前的最优解。
        for(int j=1;j<nums2.size();j++) {
            dp[j] = max(dp[j], dp[j-1]);
        }
    }
    return dp[nums2.size()-1];
}
// dp[j]表示考虑nums1的前i个元素和nums2的前j个元素时的最大不相交线数量。
// 当nums1[i] == nums2[j]时,我们可以连接这两个数字,所以dp[j]可以更新为dp[j-1] + 1。
// 我们还需要考虑不连接当前数字的情况,所以要取max(dp[j], dp[j-1])。
//----------------------------------------------
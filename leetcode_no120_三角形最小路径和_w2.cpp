/* ------------------------------------------------------------------|
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

 

示例 1：

输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
示例 2：

输入：triangle = [[-10]]
输出：-10
 

提示：

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

进阶：

你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	从上往下两次遍历
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.84%的用户
*	内存消耗：8.5 MB, 在所有 C++ 提交中击败了52.11%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n, 0);
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; j--) {
            dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
        }
        dp[0] += triangle[i][0];
    }
    //min_element()返回的是迭代器，要取其值才能返回int
    return *min_element(dp.begin(),dp.end());
}
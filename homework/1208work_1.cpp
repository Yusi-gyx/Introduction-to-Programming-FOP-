#include <iostream>
#include <vector>
using namespace std;

int maxqueen = 0; // 表示可以放入的最大皇后数
int cnt = 0;      // 用来对放入的皇后进行计数
int n;
void Try(int row , const int k , vector<bool> &col , vector<bool> &zhu , vector<bool> &fu , vector<vector<int>> hole)
{
    // 递归终止条件
    if (row == n + 1)
    {
        if (cnt > maxqueen) maxqueen = cnt;
        return;
    }
    //如果当前的皇后数+剩下的行数小于最大皇后数，可以直接返回(剪枝)
    if(cnt + n - row < maxqueen)  return ;
    // 可以选择跳过这一行
    Try(row + 1 , k , col , zhu , fu , hole);
    //或者放在这一行
    for (int i = 1; i <= n; i++)
    {
        if (!col[i] || !zhu[row + i] || !fu[i - row + k] || !hole[row][i])  continue;
        // 放置皇后
        cnt++;
        // 修改三个方向的安全性标记
        col[i] = false;
        zhu[row + i] = false;
        fu[i - row + k] = false;
        // 递归尝试放下一行
        Try(row + 1 , k , col , zhu , fu , hole);
        // 回溯：恢复三个方向原有安全性
        col[i] = true;
        zhu[i + row] = true;
        fu[i - row + k] = true;
        cnt--;
    }
}

int main()
{
    cin >> n;
    vector<vector<int>> hole(n + 1, vector<int>(n + 1));
    vector<bool> col(n + 1, true);     // 判断当前列是否安全
    vector<bool> zhu(2 * n + 1, true); // 判断主对角线是否安全
    vector<bool> fu(2 * n + 1, true);  // 判断副对角线是否安全
    const int k = n + 1;               // 统一数组下标
    for (int i = 1; i <= n; i++)       // 录入坑的信息
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> hole[i][j];
        }
    }
    Try(1 , k , col , zhu , fu , hole);
    cout << maxqueen;
    return 0;
}
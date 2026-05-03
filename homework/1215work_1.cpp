#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long split(vector<long long> num, int left, int L, vector<long long> &record) // 拆分函数
{
    // 递归结束条件
    int n = num.size();
    if (left == n)
        return 0; 
    
    // 备忘录法储存已计算的划分，判断是否已计算
    if (record[left] != -1)
        return record[left];
    
    // 若没有计算，递归计算当前如何划分
    long long sum_1 = 0;
    for (int i = left; i < n; i++)
        sum_1 += num[i];
    long long min = (sum_1 - L) * (sum_1 - L);
    for (int i = left + 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = left; j < i; j++)
            sum += num[j];
        long long temp = split(num, i, L, record) + (sum - L) * (sum - L);
        if (temp < min)
            min = temp;
    }
    // 返回最大值并改变备忘录的记录
    return record[left] = min;
}

int main()
{
    int n, L;
    cin >> n >> L;
    vector<long long> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    vector<long long> record(n, -1); // 备忘录，记录从一个元素到最后一个元素的总代价
    long long min = split(num, 0, L, record);
    cout << min;
    return 0;
}
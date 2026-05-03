/*
补全代码，求四个整数的最大值、最小值、平均值：
*/

#include <iostream>

#include <algorithm>

#include <cstdio>

using namespace std;



// 计算四个整数参数a,b,c,d中的最大值、最小值、平均值

// 计算结果分别用参数 max, min, avg返回

void calc(int a, int b, int c, int d, int *max_val, int *min_val, double *avg)

{       // 填写代码
    if(a <= b)
    {
        *max_val = b , *min_val = a ;
        if(*max_val <= c)
            *max_val = c ;
        if(*min_val >= c)
            *min_val = c;
        if(*max_val <= d)
            *max_val = d;
        if(*min_val >= d)
            *min_val = d;
    }
    else
    {
        *max_val = a , *min_val = b ;
        if(*max_val <= c)
            *max_val = c ;
        if(*min_val >= c)
            *min_val = c;
        if(*max_val <= d)
            *max_val = d;
        if(*min_val >= d)
            *min_val = d;
    }

    *avg = (a + b + c + d)/4.0 ;
}



int main()

{

    int a, b, c, d, max, min;

    double avg;

   

    cin >> a >> b >> c >> d;

        // 填写代码
    calc(a,b,c,d,&max,&min,&avg);

   

    printf("%d %d %6.4f", max, min, avg);

   

    return 0;

}
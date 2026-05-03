/*
补全代码，按格式要求输出公历某月的日历。格式要求：

1. 一行一个星期（7天）

2. 每个日期占两位，右对齐

3. 日期之间空一格

4. 参数days是该月的天数，week是该月1号是星期几（1~7分别对应周一至周日），week_start是每星期（每行）从星期几开始（为1时，每个星期从周一开始，为7时，从周日开始）

函数要检查参数是否合法，如合法则按以上要求输出，不合法则仅输出"ERROR"（全大写）
*/


#include <iostream>

#include <iomanip>

using namespace std;

void print_calenda(int days, int first_day, int week_start)

{   // 填写代码
    //先判断输入是否正确
    if(days < 28 || days > 31 || first_day < 1 || first_day > 7 || week_start < 1 || week_start >7)
    {
        cout<<"ERROR";
        return;
    }

    int jum = 0;  //第一天跳过的天数
    
    //先找到第一天正确的位置
    if(first_day < week_start)
    {
        for(int i = 1 ; i <= 7 + first_day - week_start ; i ++)
        {
            cout<<"   ";
        }

        jum = 7 + first_day - week_start;
    }
    if(first_day > week_start)
    {
        for(int i = 1 ; i <= first_day - week_start ; i ++)
        {
            cout<<"   ";
        }

        jum = first_day - week_start;
    }

    //枚举每一天
    int sum = 0;   //计数七天

    int num = 0;   //第一天不足7天

    for(int i = 1 ; i <= days ; i ++)
    {
        if(i < 10)
        {   
            cout << 0 << i;
            cout << " ";
            sum ++;
        }
        if(i >= 10)
        {
            cout << i;
            cout << " ";
            sum ++;
        }
        if(((i - (7 - jum)) % 7 == 0) && (num != 0))
            cout << endl ;
        if(jum + i == 7)
        {    
            cout << endl;
            num ++;
        }
         
    }
}



int main()

{

    int days, first_day, week_start;

    cin >> days >> first_day >> week_start;

   

    print_calenda(days, first_day, week_start);

   

    return 0;

}

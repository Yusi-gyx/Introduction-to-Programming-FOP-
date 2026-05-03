#include <iostream>
#include <cstring>
using namespace std;

// 补充结构体类型定义
// 结构体包含两个成员，分别为空格个数和空格位置。
// 空格位置是一个指针，指针指向一个动态分配的数组，数组长度为空格个数，数组元素为空格位置。 

struct SpaceInfo
{
    int space_count ;
    int *space_positions ;
} ;

// 补充函数头和函数体，返回值为结构体类型

SpaceInfo analyze_spaces (char m [])
{
    SpaceInfo x ;
    x.space_count = 0 ;
    for(int i = 0 ; i < 100 ; i ++)
    {
        if(m[i] == '\0') return x ;
        if(m [i] == ' ') 
        {
            x.space_count ++ ;
        }
    }

    x.space_positions = new int [x.space_count] ;

    int cnt = 0 ;
    for(int i = 0 ; i < 100 ; i ++)
    {
        if(m[i] == '\0') return x ;
        if(m [i] == ' ') 
        {
            x.space_positions [cnt] = i ;
            cnt ++ ;
        }
    }

    return x ;
}


int main()
{
    char input_line[100];
    cin.getline(input_line, 100);

    SpaceInfo result = analyze_spaces(input_line);

    cout << result.space_count << endl;
    for (int i = 0; i < result.space_count; ++i)
        cout << result.space_positions[i] << " ";

    delete[] result.space_positions;
    return 0;
}
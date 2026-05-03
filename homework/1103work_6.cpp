//我写的：
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// 补充函数 format_line
char* format_line (char a [])
{
    char* b = new char [strlen(a) + 1] ;
    int cnt = 0 ;
    bool in_word = false ;
    bool need_space = false ;

    for(int i = 0 ; i < strlen(a) ; i ++)
    {
        if(a [i] == ' ')
        {
            in_word = false ;
            need_space = true ;
        }
        else
        {
            if(need_space) 
            {
                if(cnt) b [cnt++] = ' ' ;
                need_space = false ;
            }
            
            if(i == 0) 
            {
                if(a [i] <= 'z' && a [i] >= 'a') 
                b [cnt ++] = a [i] - 32 ;
                else b [cnt ++] = a [i] ;
            }
            else
            {
                if(a [i - 1] != ' ') in_word = true ;  //前面一个字符不是空格说明是在单词中间
                if(in_word)
                {
                    if(a [i] <= 'Z' && a [i] >= 'A') 
                    b [cnt++] = a [i] + 32 ;
                    else b [cnt ++] = a [i] ;
                }
                else
                {
                    if(a [i] <= 'z' && a [i] >= 'a') 
                    b [cnt ++] = a[i] - 32 ;
                    else b [cnt ++] = a [i] ;
                }
            }
            
        }
    }
    b [cnt] = '\0' ;
    return b ;
}



int main()
{
    char input_line[100];
    cin.getline(input_line, 100);

	char* result_str = format_line(input_line);
	cout << result_str << endl;
	
	delete[] result_str;
    return 0;
}



//ds写的：
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* format_line(char a[])
{
    int len = strlen(a);  //定义原长度
    char* result = new char[len + 1]; // 最多不会超过原长度 ！！！留下一个位置给空字符
    int idx = 0;  //result的位数
    int i = 0;
    
    // 跳过开头空格
    while (i < len && a[i] == ' ') i++;
    
    bool in_word = false;
    bool new_word = true;
    
    while (i < len)
    {
        if (a[i] != ' ')
        {
            if (new_word)
            {
                // 单词首字母大写
                result[idx++] = toupper(a[i]);
                new_word = false;
            }
            else
            {
                // 单词其他字母小写
                result[idx++] = tolower(a[i]);
            }
            in_word = true;
        }
        else
        {
            if (in_word)
            {
                // 单词刚结束，加一个空格
                result[idx++] = ' ';
                in_word = false;
                new_word = true;
            }
            // 连续空格则跳过
        }
        i++;  //每进行一次while循环，i代表数组a的位数，即读取一位a
    }
    
    // 如果最后有多加的空格，去掉  （算法在每个单词的末尾添加空格，需要在最后去掉多余的空格）
    if (idx > 0 && result[idx - 1] == ' ')
        idx--;
    
    result[idx] = '\0';  //将最后的空格用空字符覆盖掉
    return result;
}

int main()
{
    char input_line[168];
    cin.getline(input_line, 168);
    
    char* result_str = format_line(input_line);
    cout << result_str << endl;
    delete[] result_str;
    return 0;
}
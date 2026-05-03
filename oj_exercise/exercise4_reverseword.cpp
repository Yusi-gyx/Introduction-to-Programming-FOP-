/*
题目描述
影片《逆世界》是2012年出品的一部科幻爱情片，电影讲述互为颠倒的两个世界仅靠一座巨塔进行有限的沟通，在这个双生世界里，人们像在平行世界里一般各自生活工作，互不干涉。
直到下层世界的男孩亚当（吉姆·斯特吉斯饰）遇到了上层世界的女孩伊达（克尔斯滕·邓斯特饰）。
下层世界和上层世界的语言是相同的，只是每个单词的拼写顺序是相反的。在下层世界里的"Hello, world!"，转到上层世界中，就变成了"olleH, dlrow!"。
今天，处在上层世界的女孩伊达，捡到了一个来自下层世界的男孩亚当的纸飞机。纸飞机上有字，但她看不懂。
于是她给你留下了一份《翻译软件编写指南》，向你请求编写一款翻译软件，以用来翻译上下层世界的语言。
《翻译软件编写指南》
上下层语言翻译方法：将原文中每个单词颠倒顺序后输出。
这里，一个单词定义为一个连续的字母串，例如"I don't like the ice-cream-flavored candy"中的所有单词应该为"I", "don", "t", "like", "the", "ice", "cream", "flavored", "candy"。
对于原文中的所有标点符号、空格等非字母字符，全部照原样输出。

输入描述
输入为一行英文文本，文本长度不超过5000字符。文本由大小写字母、标点符号、空格、数字等ASCII码中的可见字符组成。

输出描述
输出一行，为输入的翻译结果。
*/


#include<iostream>
#include<cstring>
using namespace std ;

char word [100] ;

int reverse (char text [] , int i)
{
    memset (word , '\0' , sizeof(word)) ;
    int cnt = -1 ;
    int n = 0 ;
    while((text [i] >= 'a' && text [i] <= 'z') || (text [i] >= 'A' && text [i] <= 'Z'))
    {
        word [n] = text [i] ;
        n ++ ;
        cnt ++ ;
        i ++ ;
    }
    for(int t = 0 ; t <= (cnt / 2) ; t ++)
    {
        char temp ;
        temp = word [cnt - t] ;
        word [cnt - t] = word [t] ;
        word [t] = temp ;
    }
    cout << word ;
    return i ;
}

int main ()
{
    char text [5001] ;
    cin.getline (text , 5001) ;
    int i = 0 ;
    while(text [i] != '\0')
    {
        if((text [i] >= 'a' && text [i] <= 'z') || (text [i] >= 'A' && text [i] <= 'Z'))
        {
            i = reverse (text , i) ;
        }
        else
        {
            cout << text [i] ;
            i ++ ;
        }
    }
    return 0 ;
}
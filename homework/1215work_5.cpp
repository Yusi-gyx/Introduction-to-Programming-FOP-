#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string text;
    getline(cin, text);
    int len = text.length();
    string temp;
    for (int i = 0; i < len; i++)
    {
        // 跳过非字母字符
        if (!((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')))
        {
            cout << text[i];
            continue;
        }

        // 遇到字母字符之后开始储存单词
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            temp.push_back(text[i]);
        }

        // 若到了单词的末尾，对当前单词进行处理
        if (i + 1 < len)
        {
            if (!((text[i + 1] >= 'A' && text[i + 1] <= 'Z') || (text[i + 1] >= 'a' && text[i + 1] <= 'z')))
            {
                int leng = temp.length();
                for (int j = leng - 1; j >= 0; j--)
                    cout << temp[j];
                temp = ""; // 将temp字符串赋值为空
            }
        }
        else
        {
            int leng = temp.length();
            for (int j = leng - 1; j >= 0; j--)
                cout << temp[j];
            temp = ""; // 将temp字符串赋值为空
        }
    }
    return 0;
}
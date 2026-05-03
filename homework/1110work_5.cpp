#include<iostream>
#include<string>
using namespace std ;

int main ()
{
    string str_1 ;
    getline(cin , str_1) ;
    int len = str_1.length() ;
    if(len == 0)  //空字符直接返回1
    {
        cout << 1 ;
        return 0 ;
    }
    
    if(len == 1 &&((str_1 <= "z" && str_1 >= "a") || (str_1 <= "Z" && str_1 >= "A") || (str_1 <= "9" && str_1 >= "0")))  //单个字符检查是不是数字或者字母
    {
        cout << 1  ;
        return 0 ;
    }
    
    string str_2 ;
    for(int i = 0 ; i < len ; i ++)
    {
        char ch = str_1 [i] ;
        if((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') || (ch <= '9' && ch >= '0'))
        str_2.push_back(ch) ;
    }

    int len_2 = str_2.length() ;
    bool check = true ;

        for(int i = 0 ; i < (len_2 / 2) ; i ++)
        {
            if(str_2 [i] <= 'z' && str_2 [i] >= 'a')
            {
                if(str_2 [len_2 - 1 - i] <= 'z' && str_2 [len_2 - 1 - i] >= 'a')
                {
                    if(str_2 [i] == str_2 [len_2 - 1 - i]) continue ;
                    else 
                    {
                        check = false ;
                        break ;
                    }
                }
                else if(str_2 [len_2 - 1 - i] <= 'Z' && str_2 [len_2 - 1 - i] >= 'A')
                {
                    if(str_2 [i] == str_2 [len_2 - 1 - i] + 32) continue ;
                    else
                    {
                        check = false ;
                        break ;
                    }
                }
                else
                {
                    check = false ;
                    break ;
                }
            }
            else if(str_2 [i] <= 'Z' && str_2 [i] >= 'A')
            {
                if(str_2 [len_2 - 1 - i] <= 'z' && str_2 [len_2 - 1 - i] >= 'a')
                {
                    if(str_2 [i] + 32 == str_2 [len_2 - 1 - i]) continue ;
                    else 
                    {
                        check = false ;
                        break ;
                    }
                }
                else if(str_2 [len_2 - 1 - i] <= 'Z' && str_2 [len_2 - 1 - i] >= 'A')
                {
                    if(str_2 [i] == str_2 [len_2 - 1 - i]) continue ;
                    else
                    {
                        check = false ;
                        break ;
                    }
                }
                else
                {
                    check = false ;
                    break ;
                }
            }
        }

    if(check) cout << 1 ;
    else cout << 0 ;
    return 0 ;
}
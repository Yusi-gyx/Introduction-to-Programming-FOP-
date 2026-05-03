#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std ;

vector<string> num = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen"} ;
vector<int> pin ;

string change(string temp)
{
    int len = temp.length() ;
    for(int i = 0 ; i < len ; i ++)
    {
        if(temp [i] >= 'A' && temp [i] <= 'Z')  temp [i] += 32 ;
    }
    return temp ;
}

bool find (string temp)
{
    string word = change(temp) ;
    for(int i = 0 ; i < 16 ; i ++)
    {
        if(word == num [i]) return true ;
    }
    return false ;
}

int ASCII_count(string temp)
{
    int len = temp.length() ;
    int sum = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        sum += (int)temp [i] ;
    }
    return sum ;
}

bool comparison(int a , int b)
{
    return a < b ;
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
    {
        string temp ;
        cin >> temp ;
        if(find(temp))
        {
            pin.push_back(ASCII_count(temp) % 100) ;
        }
    }
    sort(pin.begin() , pin.end() , comparison) ;
    string code ;
    int len = pin.size() ;
    for(int i = 0 ; i < len ; i ++)
    {
        if(pin [i] < 10)
        {
            code.push_back('0') ;
            code.push_back('0' + pin [i]) ;
        }
        else    //需要对十位和各位数字分别处理
        {
            int a = pin [i] % 10 ;     //个位数字
            int b = pin [i] / 10 ;     //百位数字
            code.push_back('0' + b) ;
            code.push_back('0' + a) ;
        }
    }

    int len_1 = code.length() ;
    int flag = 0 ;
    int cnt = 0 ;
    for(int i = 0 ; i < len_1 ; i ++)
    {
        if(code [i] == '0')
        {
            cnt ++ ;
        }
        else 
        {
            flag = 1 ;
            break ;
        }
    }

    if(!flag)     //若全是0
    {
        cout << "0" ;
        return 0 ;
    }
    else
    {
        for(int i = 0 ; i < cnt ; i ++) code.erase(code.begin()) ;
    }
    cout << code ;
    return 0 ;
}
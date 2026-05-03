#include<cctype>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std ;

struct word_cnt {
    string word ;
    int cnt ;
} ;
vector<word_cnt> a ;

void check_cnt (string text)
{
    int num = text.length() ;
    for(int i = 0 ; i < num ; i ++)          //先将text中的所有非字母内容全部转换成空格
    {
        if((text [i] >= 'a' && text [i] <= 'z') || (text [i] >= 'A' && text [i] <= 'Z')) continue ;
        else
        {
            if(text [i] != ' ') text [i] = ' ' ;
        }
    }
    istringstream ss(text) ;
    string temp ;
    while(ss >> temp)
    {
        //1.先将字符串转换为小写
        for(int i = 0 ; i < temp.length() ; i ++)
        {
            temp [i] = tolower(temp [i]) ;
        }
        //2.将单词与已有的单词进行对比，若无则将单词加入向量，若有则计数加1
        bool iffind = false ;
        int len = a.size() ;
        for(int i = 0 ; i < len ; i ++)
        {
            if(temp == a [i].word)
            {
                a [i].cnt += 1 ;
                iffind = true ;
                break ;
            }
        }
        if(!iffind)  //若没有找到
        {
            word_cnt b = {temp , 1} ;
            a.push_back(b) ;
        }
    }
}

bool comparison(word_cnt m , word_cnt n)
{
    if(m.cnt != n.cnt) return m.cnt > n.cnt ;
    else return m.word < n.word ;
}

int main ()
{
    ifstream fin ;
    fin.open("input.txt") ;
    string text ;
    while(getline(fin , text))
    {
        check_cnt(text) ;
    }
    fin.close() ;
    sort(a.begin() , a.end() , comparison) ;

    ofstream fout ;
    fout.open("output.txt") ;
    int len = a.size() ;
    for(int i = 0 ; i < len ; i ++)
    {
        fout << a [i].word << " " << a [i].cnt << endl ;
    }
    fout.close() ;
    return 0 ;
}
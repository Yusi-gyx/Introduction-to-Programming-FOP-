#include<fstream>
#include<string>
#include<sstream>
#include<iostream>
using namespace std ;

void output (int count)
{
    ofstream fout("output.txt" , ios::app) ;
    if(count >= 10) fout << "@@@@@@@@@@" ;
    else
    {
        for(int i = 0 ; i < count ; i ++)
        {
            fout << "@" ;
        }
        for(int i = 0 ; i < 10 - count ; i ++)
        {
            fout << "." ;
        }
    }
    fout << endl ;
    fout.close() ;
}

int main()
{
    ifstream fin("input.txt") ;
    if(!fin.is_open()) return -1 ;
    int count [10] = {0};
    string grade ;

    while(getline(fin , grade))
    {
        if(grade.empty()) break ;
        int score = -1 ;
        string name ;
        stringstream ss(grade) ;
        if(!(ss >> name >> score)) continue ;
        int i = score / 10 ;
        if(i == 10) count [9] ++ ;
        else count [i] ++ ;
    }
    fin.close() ;
    ofstream clear("output.txt") ;
    clear.close() ;
    for(int i = 0 ; i < 10 ; i ++)
    {
        output(count [i]) ;
    }
    return 0 ;
}
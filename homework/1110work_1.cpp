#include<iostream>  //cout
#include<fstream>  //ifstream , ofstream
#include<iomanip>  //fixed , setpricision
#include<algorithm>  //sort
#include<string>  //string , getline
#include<sstream> //stringstream
using namespace std ;

double mean (double a [] , double length)
{
    double avg = 0 ;
    double sum = 0 ;
    for(int i = 0 ; i < length ; i ++)
    sum += a [i] ;
    avg = sum / length ;
    return avg ;
}

double variance (double a [] , double avg , double length)
{
    double v = 0 ;
    double sum = 0 ;
    for(int i = 0 ; i < length ; i ++)
    sum += (a [i] - avg) * (a [i] - avg) ;
    v = sum / length ;
    return v ;
}


int main ()
{
    ifstream fin ("input.csv") ;
    int row_size = 0 ;
    int column_size = 1 ;
    char ch ;

    while(fin.get(ch))             //先判断学科数目和各学科成绩的个数
    {
        if(ch == '\n') column_size ++ ;
        if(ch == ',') row_size ++ ;
    }
    row_size = row_size / column_size + 1 ;
    cout << row_size << " " << column_size << endl ;
    fin.clear() ;
    fin.seekg(0) ;

    double** grade = new double* [row_size] ;   //动态分配数组，存储各学科成绩
    for(int i = 0 ; i < row_size ; i ++)
    {
        grade [i] = new double [column_size] () ;
    }

    int r = 0 ;
    int c = 0 ;
    string str ;
    int num = 0 ;
    while(getline(fin , str))  //读取并储存数据
    {
        c = 0 ;
        string str1 ;
        stringstream ss(str) ;
        while(getline(ss , str1 , ','))
        {
            num = stoi(str1) ;
            grade [c] [r] = num ;
            c ++ ;
        }
        r ++ ;
    }
    fin.close() ;

    double** calculate = new double* [row_size] ;
    for(int i = 0 ; i < row_size ; i ++)
        calculate [i] = new double [5] () ;

    for(int i = 0 ; i < row_size ; i ++)     
    {    
        calculate [i][0] = mean(grade[i] , column_size) ;  //计算平均值和方差
        calculate [i][4] = variance(grade [i] , calculate [i][0] , column_size) ;
        sort(grade [i] , grade [i] + column_size) ;  //排序+录入最值
        calculate [i][2] = grade [i][column_size - 1] ;
        calculate [i][3] = grade [i][0] ;
        if(column_size % 2 == 0)  //计算中位值
            calculate [i][1] = (grade [i][column_size / 2 - 1] + grade [i][column_size /2]) / 2 ;
        else
            calculate [i][1] = grade [i][(column_size + 1) / 2 - 1] ;
    }
    
    ofstream fout ("output.csv") ;  //向文件中输出
    for(int i = 0 ; i < row_size ; i ++)
    {
        if(i != row_size - 1)
            fout << fixed << setprecision(2) 
                 <<        calculate [i][0] 
                 << ',' << calculate [i][1] 
                 << ',' << calculate [i][2] 
                 << ',' << calculate [i][3] 
                 << ',' << calculate [i][4] << endl ;
        else
            fout << fixed << setprecision(2) 
                 <<        calculate [i][0] 
                 << ',' << calculate [i][1] 
                 << ',' << calculate [i][2] 
                 << ',' << calculate [i][3] 
                 << ',' << calculate [i][4] ;
    }
    fout.close() ;


    for(int i = 0 ; i < row_size ; i ++)  //删除动态分配的内存
        delete [] grade [i] ;
    delete [] grade ;

    for(int i = 0 ; i < row_size ; i ++)
        delete [] calculate [i] ;
    delete [] calculate ;

    return 0 ;
}




//凭自己的努力找到了问题，开心！！！！！
//感觉自己的debug能力更强了！！！！！
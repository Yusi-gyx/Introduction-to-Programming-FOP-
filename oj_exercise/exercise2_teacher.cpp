#include<iostream>    //cout
#include<string>      //string
#include<vector>      //vector
#include<algorithm>   //sort
#include<memory.h>      //memset
using namespace std ;

struct teacher{
    string subject_1 ;
    string subject_2 ;
} ;

vector<teacher> teachers(3) ;
//建立从序号到科目的映射
int assign [6] = {0} ;        //表示六个科目的分配状态
string subject_assign [6] = {"yw" , "ss" , "zz" , "dl" , "yy" , "ms"} ;   //对应的数字是科目

bool comparison(string i , string j)      //对科目的首字母进行排序
{
    return i < j ;
}

void output_subject(teacher m)           //输出一个老师的科目
{
    vector<string> subject(2) ;
    subject [0] = m.subject_1 ;
    subject [1] = m.subject_2 ;
    sort(subject.begin() , subject.end() , comparison) ;
    for(auto x : subject)
    {
        if(x == "yw") cout << "语文" << " " ;
        else if(x == "ss") cout << "算术" << " " ;
        else if(x == "zz") cout << "政治" << " " ;
        else if(x == "dl") cout << "地理" << " " ;
        else if(x == "yy") cout << "音乐" << " " ;
        else cout << "美术" << " " ;
    }
    cout << endl ;
}

bool check ()        //检查分配状态
{
    for(int i = 0 ; i < 6 ; i ++)           //检查所有课程是否已经分配
    {
        if(assign [i] == 0)  return false ;
    }
    if(assign [2] == assign [1]) return false ;
    if(assign [3] == assign [0]) return false ;
    if(assign [3] == 2) return false ;
    if(assign [3] == assign [1]) return false ;
    if(assign [3] == 1 || assign [4] == 1) return false ;
    if(assign [4] == assign [1]) return false ;
    if(assign [4] == 2 || assign [1] == 2) return false ;
    return true ;
}

bool found = false ;
void assigned (int cnt)    //递归，给老师分配课程
{
    if(cnt == 4)
    {
        if(check())
        {
            found = true ;
            return ;
        }
    }

    for(int i = 0 ; i < 6 ; i ++)  //循环两次给老师分配两个课程
    {
        if(! assign [i])           //如果查找到的这一门课程还没有分配
        {
            assign [i] = cnt ;     //先分配第一个课程
            teachers [cnt - 1].subject_1 = subject_assign [i] ;   //分配对应的课程名

            for(int j = 0 ; j < 6 ; j ++)     //从剩下的课程中再选一个
            {
                if(!assign [j]) 
                {
                    assign [j] = cnt ;   //再分配第二个课程
                    teachers [cnt - 1].subject_2 = subject_assign [j] ;

                    //给下一个老师分配课程
                    assigned(cnt + 1) ;

                    //如果在下一个老师分配之后已经找到了正确的分配方法，就返回
                    if(found) return ;    

                    //回溯进行其他排列
                    assign [j] = 0 ;   
                 }
            }
            //回溯进行其他排列
            assign [i] = 0 ;
        }
    }
}

int main ()
{
    assigned(1) ;
    for(auto x : teachers)
    {
        output_subject(x) ;
    }

    return 0 ;
}
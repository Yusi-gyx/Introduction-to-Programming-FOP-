#include<iostream>
using namespace std ;

///1.定义一个结构，储存一个人做两件事的布尔值
struct haoshi {
    int idea1 ;
    int idea2 ;
} ;

char blackboard [] = {'A' , 'B' , 'C' , 'D' , 'E'} ;
char pickpurse [] = {'A' , 'B' , 'C' , 'D' , 'E'} ;

///2.返回一个值的函数，确认是否每个人都只说中了一个
int true_count (char obj , int x , int y)
{   
    haoshi m ;
    ///先判断每个人说的对不对
    if(obj == 'A') 
    {
        if(blackboard [x] != 'A')  m.idea1 = 1 ;
        else m.idea1 = 0 ;
        if(pickpurse [y] == 'C')  m.idea2 = 1 ;
        else m.idea2 = 0 ;
    }
    if(obj == 'B')
    {
        if(blackboard [x] == 'D') m.idea1 = 1 ;
        else m.idea1 = 0 ;
        if(pickpurse [y] != 'E') m.idea2 = 1 ;
        else m.idea2 = 0 ;
    }
    if(obj == 'C')
    {
        if(blackboard [x] == 'B')  m.idea1 = 1 ;
        else m.idea1 = 0 ;
        if(pickpurse [y] != 'A') m.idea2 = 1 ;
        else m.idea2 = 0 ;
    }
    if(obj == 'D')
    {
        if(blackboard [x] != 'A' && blackboard [x] != 'B' && pickpurse [y] != 'A' && pickpurse [y] != 'B')  m.idea1 = 1 ;
        else m.idea1 = 0 ;
        if(blackboard [x] != 'C') m.idea2 = 1 ;
        else m.idea2 = 0 ;
    }
    if(obj == 'E')
    {
        if(blackboard [x] == 'E' || pickpurse [y] == 'D') m.idea1 = 1 ;
        else m.idea1 = 0 ;
        if(blackboard [x] != 'A') m.idea2 = 1 ;
        else m.idea2 = 0 ;
    }
    return m.idea1 + m.idea2 ;
}


int main ()
{
    bool found = false ;
    int sum = 0 ;
    int x = 0 , y = 0 ;
    for( ; x < 5 ; x ++)
    {
        for(y = 0 ; y < 5 ; y ++)
        {
            sum = 0 ;
            if(x == y) continue ;
            for(auto obj : blackboard)
            {
                if(true_count(obj , x , y) != 1)  break ;
                else sum ++ ;
            }
            if(sum == 5) 
            {
                found = true ;
                break ;
            }
        }
        if(found) break ;
    }
    cout << blackboard [x] << endl ;
    cout << pickpurse [y] ;
    return 0 ;
}
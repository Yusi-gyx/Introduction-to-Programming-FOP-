#include<iostream>
#include<vector>
using namespace std ;

struct position {
    int x , y ;
} ;
position dxy [4] = {{1 , 2} , {1 , -2} , {2 , 1} , {2 , -1}} ;
position foot [4] = {{0 , 1} , {0 , -1} , {1 , 0} , {1 , 0}} ;

int num = 0 ;               //表示总的方案数

bool check_chongdie(position a , vector<position> barrier)
{
    for(auto m : barrier)
    {
        if(m.x == a.x && m.y == a.y) return true ;
    }
    return false ;
}

bool check_horse_foot(position a , int choice , vector<position> barrier)
{
    position temp = {a.x + foot [choice].x , a.y + foot [choice].y} ;
    for(auto b : barrier)
    {
        if(b.x == temp.x && b.y == temp.y) return true ;
    }
    return false ;
}

void jump(position curr_pos , int n , int m , vector<position> barrier) //跳马函数
{
    //先判断是否到达终点
    if(curr_pos.x == n && curr_pos.y == m)
    {
        num ++ ;
        return ;
    }

    //枚举四种跳马方式+递归
    for(int i = 0 ; i < 4 ; i ++)
    {
        position new_pos = {curr_pos.x + dxy [i].x , curr_pos.y + dxy [i].y} ;
        if(new_pos.x < 0 || new_pos.x > n || new_pos.y < 0 || new_pos.y > m) continue ;

        //判断踩到己方棋子的情况
        if(check_chongdie(new_pos , barrier)) continue ;
        
        //判断“绊马脚”的情况
        if(check_horse_foot(curr_pos , i , barrier)) continue ;

        //递归剩余的跳马
        jump(new_pos , n , m , barrier) ;
    }

}

int main ()
{
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<position> barrier(k) ;
    for(int i = 0 ; i < k ; i ++)
    {
        cin >> barrier [i].x >> barrier [i].y ;
    }
    jump({0 , 0} , n , m , barrier) ;
    cout << num ;
    return 0 ;
}
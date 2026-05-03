#include<iostream>
#include<vector>
#include<climits>
#include<cassert>
using namespace std ;

struct position {
    int f_x ;   //火行
    int f_y ;   //火列
    int i_x ;   //冰行
    int i_y ;   //冰列
    int cnt ;   //表示当前的步数
} ;

position goal ;             //终点位置
vector<position> state(1) ;
position yidong [25] = {{0 , 0 , 0 , 0} , {0 , 0 , 1 , 0} , {0 , 0 , 0 , 1} , {0 , 0 , -1 , 0} , {0 , 0 , 0 , -1} ,
                        {1 , 0 , 0 , 0} , {1 , 0 , 1 , 0} , {1 , 0 , 0 , 1} , {1 , 0 , -1 , 0} , {1 , 0 , 0 , -1} ,
                        {0 , 1 , 0 , 0} , {0 , 1 , 1 , 0} , {0 , 1 , 0 , 1} , {0 , 1 , -1 , 0} , {0 , 1 , 0 , -1} ,
                        {-1 , 0 , 0 , 0} , {-1 , 0 , 1 , 0} , {-1 , 0 , 0 , 1} , {-1 , 0 , -1 , 0} , {-1 , 0 , 0 , -1} ,
                        {0 , -1 , 0 , 0} , {0 , -1 , 1 , 0} , {0 , -1 , 0 , 1} , {0 , -1 , -1 , 0} , {0 , -1 , 0 , -1}} ;     //移动的方式
int door_cnt = 0 ;          //门的个数
int method = -1 ;            //需要的步骤数
vector<vector<char>> map ;  //地图信息
vector<vector<vector<vector<int>>>> visited ;    //四维数组记录两人的位置情况

bool to_goal(position a)     //判断两人是否都到达终点
{
    if(a.f_x == goal.f_x && a.f_y == goal.f_y && a.i_x == goal.i_x && a.i_y == goal.i_y)  return true ;
    return false ;
}

bool check_door(int x , int y)    //判断当前位置是不是门格
{
    if(map [x][y] >= 'A' && map [x][y] <= 'C')  return true ;
    return false ;
}

bool door_match(char door , int x , int y)   //判断是否有匹配的开关
{
    if(map [x][y] - 32 == door)  return true ;
    return false ;
}

bool switch_done(char door , position a)    //判断此状态下有没有人踩开关
{
    if(door == map [a.f_x][a.f_y] - 32 || door == map [a.i_x][a.i_y] - 32)  return true ;
    return false ;
}

bool door_safe(position step , position last)   //门通行规则
{
    char door ;
    //先找到门
    if(check_door(step.f_x , step.f_y))   door = map [step.f_x][step.f_y] ;
    else if(check_door(step.i_x , step.i_y)) door = map [step.i_x][step.i_y] ;
    else if(check_door(last.f_x , last.f_y)) door = map [last.f_x][last.f_y] ;
    else if(check_door(last.i_x , last.i_y)) door = map [last.i_x][last.i_y] ;
    else return true ;   //如果没有门就返回true，不用判断门的情况

    //判断在这一步至少有一人在对应开关上
    if(!switch_done(door , step)) return false ;

    //判断在上一步中至少有一人在对应开关上
    if(!switch_done(door , last)) return false ;

    return true ;
}

bool switch_safe(position temp , position last_step)    //开关保护规则
{
    //如果火娃在上一步在门格上
    if(check_door(last_step.f_x , last_step.f_y)) 
    {
        if(!door_match(map [last_step.f_x][last_step.f_y] , last_step.i_x , last_step.i_y))  return false ;
        if(temp.i_x != last_step.i_x || temp.i_y != last_step.i_y)  return false ;
    }
    //如果冰娃在上一步在门格上
    else if(check_door(last_step.i_x , last_step.i_y)) 
    {
        if(!door_match(map [last_step.i_x][last_step.i_y] , last_step.f_x , last_step.f_y))  return false ;
        if(temp.f_x != last_step.f_x || temp.f_y != last_step.f_y)  return false ;
    }

    return true ;   //上一步中没有人在门上或者满足开关保护规则
}

bool check_valid(position temp , position last_step)
{
    int R = map.size() ;
    int C = map [0].size() ;
    //1.判断是否走出地图、进入#格子
    if(temp.f_x < 0 || temp.f_x >= R || temp.f_y < 0 || temp.f_y >= C || temp.i_x < 0 || temp.i_x >= R || temp.i_y < 0 || temp.i_y >= C)  return false ;
    if(map [temp.f_x][temp.f_y] == '#' || map [temp.i_x][temp.i_y] == '#' )   return false ;
    //2.判断是否符合门通行规则和开关保护规则（如果当前地图有门）
    if(door_cnt)
    {
        if(check_door(temp.f_x , temp.f_y) && check_door(temp.i_x , temp.i_y)) return false ; //两人不能同时在门格上
        if(!door_safe(temp , last_step)) return false ;
        if(!switch_safe(temp , last_step))  return false ;
    }
    //3.判断是否重复
    if(visited [temp.f_x][temp.f_y][temp.i_x][temp.i_y] != 0)  return false ;
    //4.移动条件均满足
    return true ;
}

void escape ()
{
    do
    {
        position a = state [0] ;
        position temp ;
        for(int i = 1 ; i < 25 ; i ++)     //下一步状态可以有24种
        {
            temp.f_x = a.f_x + yidong [i].f_x ;
            temp.f_y = a.f_y + yidong [i].f_y ;
            temp.i_x = a.i_x + yidong [i].i_x ;
            temp.i_y = a.i_y + yidong [i].i_y ;
            if(check_valid(temp , state [0]))   //如果该步移动合法
            {
                temp.cnt = a.cnt + 1 ;
                if(to_goal(temp))   //判断这一步之后是否到达了终点
                {
                    method = temp.cnt ;
                    return ;      //提前返回，剪枝
                }
                state.push_back(temp) ;   //将这一步的状态存入需要考虑的队列
                visited [temp.f_x][temp.f_y][temp.i_x][temp.i_y] = 1 ;
            }
        }
        state.erase(state.begin()) ;    //将队列的第一个弹出
    }while(state.size() != 0) ;
}

int main ()
{
    int R , C ;
    cin >> R >> C ;
    visited.resize(R , vector<vector<vector<int>>>(C , vector<vector<int>>(R , vector<int>(C , 0)))) ;

    for(int i = 0 ; i < R ; i ++)
    {
        vector<char> z(C) ;
        for(int j = 0 ; j < C ; j ++) 
        {
            cin >> z [j] ;
            //找到初始两人的位置
            if(z[j] == 'F')  state [0].f_x = i , state [0].f_y = j ;
            if(z[j] == 'I')  state [0].i_x = i , state [0].i_y = j ;
            //找到终点的位置
            if(z[j] == 'X') goal = {i , j , i , j} ;
            //判断门的个数
            if(z[j] >= 'A' && z[j] <= 'C')  door_cnt ++ ;
        }
        map.push_back(z) ;
    }
    state [0].cnt = 0 ;
    escape() ;
    cout << method ;
    return 0 ;
}
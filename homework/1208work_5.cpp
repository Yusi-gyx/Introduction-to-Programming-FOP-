#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;

struct netpoint{    //网络节点结构体
    string name ;
    int latency ;
} ;

netpoint innet ;    //接入点
vector<netpoint> circnet ;   //环形网络

void Append ()      //添加
{
    if(circnet.size() == 0) 
    {
        cin >> innet.latency >> innet.name ;
        circnet.push_back(innet) ;
    }
    else
    {
        int cnt = 0 ;
        netpoint temp ;
        cin >> temp.latency >> temp.name ;
        for(int i = 0 ; i < circnet.size() ; i ++)
        {
            if(circnet [i].name == innet.name) 
            {
                cnt = i ;
                break ;     //找到接入点的位置
            }
        }
        circnet.insert(circnet.begin() + cnt , temp) ;
    }
}

void Eliminate ()   //剔除
{
    int m , n ;
    cin >> m >> n ;
    int ptr = 0 ;
    for(int i = 0 ; i < circnet.size() ; i ++)     //找到接入点的位置，将指针ptr首先指向接入点
    {
        if(circnet [i].name == innet.name)
        {
            ptr = i ;
            break ;
        }
    }
    for(int i = 0 ; i < n ; i ++)   //每次循环找出一个剔除点，总共找出n个
    {
        int cnt = 1 ;
        //1.确定当前网络节点的长度，在要超出长度的时候返回第一个
        int len = circnet.size() ;
        //2.开始计数，从ptr的值开始，判断是否越界，删除这个节点
        for(int i = 0 ; i < m ; i ++)
        {
            if(ptr > len - 1) ptr = 0 ;  //将ptr赋值为第一个
            if(cnt == m) 
            {
                //3.判断删除的是不是接入点，若是则将接入点换为下一个（注意这里也要判断越界）
                if(circnet [ptr].name == innet.name) 
                {
                    if(ptr + 1 == len)  innet = circnet [0] ;
                    else  innet = circnet [ptr + 1] ;
                }
                circnet.erase(circnet.begin() + ptr) ;  //这里删除之后ptr指向的元素会自动向后挪一位
                break ;
            }
            cnt ++ ;
            ptr ++ ;
        }
    }
}

void Move()  //移动
{
    int direc ;  //表示移动的方向
    int cnt ;
    cin >> direc >> cnt ;
    int len = circnet.size();
    //1.找到接入点的位置
    int pos;
    for (int i = 0; i < len; i++)
    {
        if (circnet[i].name == innet.name)
        {
            pos = i;
            break;
        }
    }
    if(direc)   //逆时针移动
    {
        //2.进行移动，若超出界限要做判断
        for(int i = 0 ; i < cnt ; i ++)
        {
            if(pos == 0) pos = len - 1 ;   //移动到第一个位置，则回到最后
            else pos -- ;
        }
        //3.将接入点重新赋值
        innet = circnet [pos] ;
    }
    else       
    {
        //2.进行移动，若超出界限要做判断
        for(int i = 0 ; i < cnt ; i ++)
        {
            if(pos == len - 1) pos = 0 ;   //移动到第一个位置，则回到最后
            else pos ++ ;
        }
        //3.将接入点重新赋值
        innet = circnet [pos] ;
    }
}

bool comparison(netpoint a , netpoint b)
{
    if(a.latency != b.latency) return a.latency < b.latency ;
    else return a.name < b.name ;
}

void Sort()  //排序
{
    sort(circnet.begin() , circnet.end() , comparison) ;
}

void Delete()   //删除
{
    //1.先找到这个网络节点，若不存在则不进行操作
    string obj_name ;
    cin >> obj_name ;
    int len = circnet.size() ;
    int obj ;
    bool iffind = false ;
    for(int i = 0 ; i < len ; i ++)
    {
        if(circnet [i].name == obj_name) 
        {
            obj = i ;
            iffind = true ;
            break ;
        }
    }
    if(iffind)
    {
        //2.判断删除的是不是最后一个节点，若是则将innet赋值为新值
        if(len == 1)
        {
            innet.name = "kong" ;
        }
        //3.若删除接入点，先将接入点重新赋值（注意要判断是否越界）
        else
        {
            if(circnet [obj].name == innet.name)
            {
                if(obj == len - 1) innet = circnet [0] ;
                else innet = circnet [obj + 1] ;
            }
            circnet.erase(circnet.begin() + obj) ;
        }
    }
    else return ;
}

int main ()
{
    int T = 0 ;
    cin >> T ;
    for(int i = 0 ; i < T ; i ++)
    {
        string inst ;
        cin >> inst ;
        if(inst == "Append")  Append() ;
        else if(inst == "Eliminate") Eliminate() ;
        else if(inst == "Move") Move() ;
        else if(inst == "Sort") Sort() ;
        else Delete() ;
    }
    string wantfind ;
    cin >> wantfind ;
    if(innet.name == "kong") 
    {
        cout << -1 ;
        return 0 ;
    }
    if(innet.name == wantfind)
    {
        cout << 0 ;
        return 0 ;
    }
    bool iffind = false ;
    for(int i = 0 ; i < circnet.size() ; i ++)
    {
        if(circnet [i].name == wantfind)
        {
            iffind = true ;
            break ;
        }
    }
    if(!iffind)
    {
        cout << -1 ;
        return 0 ;
    }
    else
    {
        //1.找到接入点的位置
        int pos ;
        for(int i = 0 ; i < circnet.size() ; i ++)
        {
            if(circnet [i].name == innet.name)
            {
                pos = i ;
                break ;
            }
        }
        //2.while循环直到找到查询点，同时输出相应的网络节点
        int latencysum = 0 ;
        while(wantfind != circnet [pos].name)
        {
            latencysum += circnet [pos].latency ;
            cout << circnet [pos].name << endl ;
            if(pos == circnet.size() - 1)  pos = 0 ;
            else pos ++ ;
        }
        //3.输出总传输延迟
        cout << latencysum ;
        return 0 ;
    }
}
#include<iostream>    //cin , cout
#include<string>   //string
#include<vector>   //vector
#include<algorithm>  //min
using namespace std ;

//1.定义结构体来储存坦克的数据
struct tank {
    string name ;
    int power ;
    int defense ;
} ;
vector<tank> line ;    //用结构体向量来表示坦克队列


//2.关于指令的函数
void ADD()
{
    tank a ;
    cin >> a.name >> a.power >> a.defense ;
    line.push_back(a) ;
}

void SELECT()
{
    string tank_name ;
    cin >> tank_name ;
    for(int i = 0 ; i < line.size() ; i ++)
    {
        if(line [i].name == tank_name) 
        {
            tank selected = line [i] ;
            line.erase(line.begin() + i) ;    //删除被找到的元素
            line.insert(line.begin() , selected) ;
            return ;
        }
    }
}

void LEAVE ()
{
    string tank_name ;
    cin >> tank_name ;
    int cnt = 0 ;
    for(auto x : line)
    {
        if(x.name == tank_name)
        {
            line.erase(line.begin() + cnt) ;
            break ;
        }
        cnt ++ ;
    }
}

void PROMOTE ()
{
    string tank_name ;
    cin >> tank_name ;
    int power_2 , defense_2 ;
    cin >> power_2 >> defense_2 ;
    for(auto& x : line)
    {
        if(x.name == tank_name)
        {
            x.power = power_2 ;
            x.defense = defense_2 ;
            break ;
        }
    }
}

bool cmp(tank a , tank b)
{
    if(a.power != b.power) return a.power < b.power ;
    else if(a.defense != b.defense) return a.defense < b.defense ;
    else return a.name < b.name ;
}

void ORDER()
{
    sort(line.begin() , line.end() , cmp) ;
}

//3.判断指令的函数
void operation ()
{
    string inst ;
    cin >> inst ;
    if(inst == "ADD") ADD() ;
    else if(inst == "SELECT") SELECT() ;
    else if(inst == "LEAVE") LEAVE() ;
    else if(inst == "PROMOTE") PROMOTE() ;
    else if(inst == "ORDER") ORDER() ;
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
    {
        operation() ;
    }

    for(auto x : line)
    {
        cout << x.name << " " << x.power << " " << x.defense << endl ;
    }
    return 0 ;
}
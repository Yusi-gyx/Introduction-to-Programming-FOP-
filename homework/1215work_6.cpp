#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std ;

struct menu {
    string name ;
    vector<string> inst ;
} ;

int flag = 0 ; //表示一级和二级命令的状态，0表示处于一级命令中，1表示处于二级命令中
string vice_menu  = "none" ;   //表示当前处于的二级菜单(储存的是一级命令的名字)

ofstream fout("output.txt") ;

void main_menu_output(vector<menu> a)
{
    int len = a.size() ;
    for(int i = 0 ; i < len ; i ++)
    {
        fout << "[" << i + 1 << "] " << a[i].name << endl ;
    }
    fout << endl ;
}

void vice_menu_output(vector<menu> a , int num)
{
    int len = a [num].inst.size() ;
    for(int i = 0 ; i < len ; i ++)
    {
        fout << "[" << i + 1 << "] " << a [num].inst [i] << endl ;
    }
    fout << "[#] BACK" << endl << endl ;
}

void op_num(vector<menu> a , int num)   //运行用户的数字指令
{
    int len = a.size() ;
    if(flag == 0)     //处于一级命令下
    {
        if(num > len)
        {
            fout << "Invalid input!" << endl ;
            main_menu_output(a) ;
        }
        else
        {
            int len_2 = a [num - 1].inst.size() ;
            if(len_2 > 0)      //一级命令下有二级命令
            {
                vice_menu_output(a, num - 1);
                flag = 1; // 模式切换
                vice_menu = a[num - 1].name;
            }
            else        //一级命令下无二级命令
            {
                fout << "Running <" << a [num - 1].name << ">" << endl ;
                main_menu_output(a) ;
            }
        }
    }
    else              //处于二级命令下
    {
        //先找到当前处于的二级命令
        int main_menu = 0 ;
        for(int i = 0 ; i < len ; i ++)
        {
            if(a [i].name == vice_menu)
            {
                main_menu = i ;
                break ;
            }
        }
        int len_1 = a [main_menu].inst.size() ;
        if(num > len_1) 
        {
            fout << "Invalid input!" << endl ;
            vice_menu_output(a , main_menu) ;
        }
        else
        {
            fout << "Running <" << a [main_menu].name << "/" << a [main_menu].inst[num - 1] << ">" << endl ;
            vice_menu_output(a , main_menu) ;
        }
    }
}

void op_sig(vector<menu> a)         //运行用户的井号指令
{
    if(flag == 0)       //处于主菜单下
    {
        fout << "Invalid input!" << endl ;
        main_menu_output(a) ;
    }
    else    //执行返回操作，输出主菜单
    {
        main_menu_output(a) ;
        flag = 0 ;
    }
}

int main ()
{
    ifstream fin ;
    fin.open("config.txt") ;
    int n = 0 ;
    string temp_1 ;
    getline(fin , temp_1) ;
    if(temp_1.back() == '\r')  temp_1.pop_back() ;
    n = stoi(temp_1) ;
    vector<menu> a ;
    for(int i = 0 ; i < n ; i ++)
    {
        int cnt = 0 ;
        string temp ;
        getline(fin , temp) ;
        if(temp.back() == '\r')  temp.pop_back() ;
        if(temp.back() == '\n')  temp.pop_back() ;
        for(int j = 0 ; j < temp.length() ; j ++)
        {
            if(temp [j] == '#') 
            {
                cnt ++ ;
                temp [j] = ' ' ;
            }
        }
        if(cnt == 1)    //1级指令
        {
            menu k ;
            stringstream ss(temp) ;
            ss >> k.name ;
            a.push_back(k) ;
        }
        else
        {
            int len = a.size() ;
            stringstream ss(temp) ;
            string c ;
            ss >> c ;
            a [len - 1].inst.push_back(c) ;
        }
    }
    string input_inst ;
    getline(fin , input_inst) ;

    fin.close() ;

    //下面执行用户的指令
    main_menu_output(a) ;
    int len = input_inst.length() ;
    for(int i = 0 ; i < len ; i ++)
    {
        //处理数字类指令
        if(input_inst [i] >= '1' && input_inst [i] <= '9')
        {
            int num = input_inst [i] - '0' ;
            op_num(a , num) ;
        }
        //处理井号指令
        else if(input_inst [i] == '#')
        {
            op_sig(a) ;
        }
        // 处理非法操作
        else
        {
            if(flag == 0)    //非法操作时处于一级命令下
            {
                fout << "Invalid input!" << endl ;
                main_menu_output(a) ;
            }
            else             //非法操作时处于二级指令
            {
                //先找到当前处于的二级命令
                int main_menu = 0;
                for (int i = 0; i < len; i++)
                {
                    if (a[i].name == vice_menu)
                    {
                        main_menu = i;
                        break;
                    }
                }
                fout << "Invalid input!" << endl ;
                vice_menu_output(a , main_menu) ;
            }
        }
    }

    fout.close() ;
    return 0 ;
}
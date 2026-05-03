#include <iostream> //cin , cout
#include <fstream>  //ifstream , ofstream
#include <vector>   //vector
#include <string>   //string
#include <limits>   //cin.ignore
#include <sstream>  //istringstream
#include <chrono>   //时间单位
#include <thread>   //sleep_for
using namespace std;

void output_levelinfo(bool lf[4]) // 输出当前关卡信息
{
    cout << "欢迎!" << endl
         << endl;
    cout << "指令及效果：" << endl
         << "inbox       : 机器人拿起输入传送带的第一个积木（成为当前积木）。原有当前积木被舍弃。当输入传送带上没有积木时，游戏结束。" << endl
         << "outbox      : 将当前积木摆在输出传送带上（机器人不再拥有当前积木）。" << endl
         << "add X       : 将当前机器人手中积木的数字加上 X 号空地上的积木。 X 号空地上的积木保持不变，机器人手中积木的数字替换成加完的结果。" << endl
         << "sub X       : 将当前积木的数字减去 X 号空地上的积木。X 号空地上的积木保持不变，机器人手中积木的数字替换成减完的结果。" << endl
         << "copyto X    : 复制当前积木到 X 号空地。若 X 空地上有积木则舍弃原有积木。" << endl
         << "copyfrom X  : 复制 X 号空地上的积木到当前积木，即把机器人手中积木的数字替换成 X 号空地上的积木的数字。若存在当前积木,则舍弃原有当前积木。" << endl
         << "jump X      : 改变机器人接下来执行的指令，跳转至第X条指令并从该指令开始继续向后依次执行每条指令（这里的第 X 条是指原始输入程中的第 X 条，不会受到程序执行的影响） 。" << endl
         << "jumpifzero X: 如果当前积木为 0，则改变机器人接下来执行的指令，跳转至第X条指令并从该指令开始继续向后依次执行每条指令；如果当前积木不为 0，则不做任何操作。" << endl
         << endl;
    cout << "已通过的关卡：";
    for (int i = 0; i < 4; i++)
        if (lf[i] == 1)
            cout << i + 1 << " ";
    cout << endl
         << "未通过的关卡：";
    for (int i = 0; i < 4; i++)
        if (lf[i] == 0)
            cout << i + 1 << " ";
    cout << endl
         << "请选择一个关卡(输入1-4的正整数):" << endl;
}

bool check_choice(double level_choice, bool lf[4]) // 检查用户选择的关卡是否正确
{
    if (level_choice <= 0 || level_choice >= 5)
        return 0;
    if ((int)level_choice != level_choice)
        return 0;
    if (level_choice >= 2)
    {
        if (lf[(int)level_choice - 2] == 0)
            return 0;
    }
    if (cin.peek() != '\n')
        return 0;
    return 1;
}

// 下面是和游戏操作有关的函数及定义变量
int hand = 114514;           // hand表示机器人手中的数，初始化为一个随便的数
vector<int> input_arr;       // 每一关的输入传送带，定义为全局变量，但是每一关开始时记得用clear清除
vector<int> output_arr;      // 输出传送带，用push_back函数向输出传送带中添加元素,但是每一关开始时记得用clear清除
vector<string> input_inst;   // 用户输入的指令集
vector<string> allowed_inst; // 每一关允许的指令
vector<int> correct_ans;     // 每一关正确的答案
vector<int> empty_land;      // 每一关的空地
int curr_inst = 0;           // current_instruction表示当前的指令在指令vector中的位置
int K, M, N;                 // K表示用户输入的指令的个数，M表示允许使用的指令的个数，N表示每一关的空地个数
int real_place = 1, g = 0;   // 标记机器人位置,标记初始状态
int flag_inbox = 0;          // 标记inbox是否处理到最后一个数字，没有了就赋值1
int jump_cnt = 0;            // 跳转次数，记录总跳转次数，如果超过1000次，说明无限循环
int inst_cnt = 0 ;           //每一关总共执行的指令数

void clearScreen() //  清屏动画
{
    cout << "\033[2J\033[H";
    cout.flush();
}

void waitForEnter(const string &message = "按回车键继续...")
{
    cout << endl
         << message
         << endl
         << endl;
    // 确保输入缓冲区是干净的
    cin.peek();
    string dummy;
    getline(cin, dummy);
}

void real(int n)
{
    if (n >= 10)
    {
        cout << ' ' << n;
    }
    else if (n >= 0)
    {
        cout << ' ' << n << ' ';
    }
    else if (n > -10)
    {
        cout << n << ' ';
    }
    else
        cout << n;
}
void input(int n) // 输出
{
    if (n < input_arr.size())
    {
        real(input_arr[n]);
        return;
    }
    cout << "   ";
}
void output(int n)
{
    if (n < output_arr.size())
    {
        real(output_arr[output_arr.size() - n - 1]);
        return;
    }
    cout << "   ";
}
void empty(int n)
{
    if (n < empty_land.size())
    {
        if (empty_land[n] != 114514)
        {
            real(empty_land[n]);
            return;
        }
    }
    cout << "   ";
}
void realhand(int n)
{
    if (n == 114514)
    {
        cout << "   ";
        return;
    }
    real(n);
}
void instruct(int n)
{
    if (n == curr_inst)
        cout << " >";
    else
        cout << "  ";
    if (n < input_inst.size())
    {
        cout << input_inst[n];
        for (int i = 0; i < 12 - input_inst[n].size(); i++)
        {
            cout << ' ';
        }
    }
}
void land_situ(int n) // 情况
{
    {
        do
        {
            if (real_place != n)
                real_place < n ? real_place++ : real_place--;
            if (g != 0)
            {
                this_thread::sleep_for(chrono::milliseconds(800));
                clearScreen();
            }
            cout << endl
                 << endl;
            switch (real_place)
            {
            case 1:
            {
                cout << "IN  + - - +                                                 + - - +  OUT||       CODE" << endl
                     << "    | ";
                input(0);
                cout << " |                                                 | ";
                output(0);
                cout << " |     || ";
                instruct(0);
                instruct(17);
                instruct(34);
                cout << endl
                     << "    + - - +         + --- +                                 + - - +     || ";
                instruct(1);
                instruct(18);
                instruct(35);
                cout << endl
                     << "                    | ";
                realhand(hand);
                cout << " |                                             || ";
                instruct(2);
                instruct(19);
                instruct(36);
                cout << endl
                     << "    + - - +         + - - +                                 + - - +     || ";
                instruct(3);
                instruct(20);
                instruct(37);
                cout << endl
                     << "    | ";
                input(1);
                cout << " |          @   @                                  | ";
                output(1);
                cout << " |     || ";
                instruct(4);
                instruct(21);
                instruct(38);
                cout << endl
                     << "    + - - +          -----                                  + - - +     || ";
                instruct(5);
                instruct(22);
                instruct(39);
                cout << endl
                     << "                     |@ @|                                              || ";
                instruct(6);
                instruct(23);
                instruct(40);
                cout << endl
                     << "    + - - +            +                                    + - - +     || ";
                instruct(7);
                instruct(24);
                instruct(41);
                cout << endl
                     << "    | ";
                input(2);
                cout << " |          /   \\                                  | ";
                output(2);
                cout << " |     || ";
                instruct(8);
                instruct(25);
                instruct(42);
                cout << endl
                     << "    + - - +           | |                                   + - - +     || ";
                instruct(9);
                instruct(26);
                instruct(43);
                cout << endl
                     << "                                                                        || ";
                instruct(10);
                instruct(27);
                instruct(44);
                cout << endl
                     << "    + - - +         + - - +     + - - +     + - - +         + - - +     || ";
                instruct(11);
                instruct(28);
                instruct(45);
                cout << endl
                     << "    | ";
                input(3);
                cout << " |         | ";
                empty(0);
                cout << " |     | ";
                empty(1);
                cout << " |     | ";
                empty(2);
                cout << " |         | ";
                output(3);
                cout << " |     || ";
                instruct(12);
                instruct(29);
                instruct(46);
                cout << endl
                     << "    + - - +         + - - +     + - - +     + - - +         + - - +     || ";
                instruct(13);
                instruct(30);
                instruct(47);
                cout << endl
                     << "                       0           1           2                        || ";
                instruct(14);
                instruct(31);
                instruct(48);
                cout << endl
                     << "    + - - +                                                 + - - +     || ";
                instruct(15);
                instruct(32);
                instruct(49);
                cout << endl
                     << "    | ";
                input(4);
                cout << " |                                                 | ";
                output(4);
                cout << " |     || ";
                instruct(16);
                instruct(33);
                instruct(50);
                cout << endl
                     << "    + - - +                                                 + - - +     ||" << endl;
                break;
            }
            case 2:
            {
                cout << "IN  + - - +                                                 + - - +  OUT||       CODE" << endl
                     << "    | ";
                input(0);
                cout << " |                                                 | ";
                output(0);
                cout << " |     || ";
                instruct(0);
                instruct(17);
                instruct(34);
                cout << endl
                     << "    + - - +                     + --- +                     + - - +     || ";
                instruct(1);
                instruct(18);
                instruct(35);
                cout << endl
                     << "                                | ";
                realhand(hand);
                cout << " |                                 || ";
                instruct(2);
                instruct(19);
                instruct(36);
                cout << endl
                     << "    + - - +                     + - - +                     + - - +     || ";
                instruct(3);
                instruct(20);
                instruct(37);
                cout << endl
                     << "    | ";
                input(1);
                cout << " |                      @   @                      | ";
                output(1);
                cout << " |     || ";
                instruct(4);
                instruct(21);
                instruct(38);
                cout << endl
                     << "    + - - +                      -----                      + - - +     || ";
                instruct(5);
                instruct(22);
                instruct(39);
                cout << endl
                     << "                                 |@ @|                                  || ";
                instruct(6);
                instruct(23);
                instruct(40);
                cout << endl
                     << "    + - - +                        +                        + - - +     || ";
                instruct(7);
                instruct(24);
                instruct(41);
                cout << endl
                     << "    | ";
                input(2);
                cout << " |                      /   \\                      | ";
                output(2);
                cout << " |     || ";
                instruct(8);
                instruct(25);
                instruct(42);
                cout << endl
                     << "    + - - +                       | |                       + - - +     || ";
                instruct(9);
                instruct(26);
                instruct(43);
                cout << endl
                     << "                                                                        || ";
                instruct(10);
                instruct(27);
                instruct(44);
                cout << endl
                     << "    + - - +         + - - +     + - - +     + - - +         + - - +     || ";
                instruct(11);
                instruct(28);
                instruct(45);
                cout << endl
                     << "    | ";
                input(3);
                cout << " |         | ";
                empty(0);
                cout << " |     | ";
                empty(1);
                cout << " |     | ";
                empty(2);
                cout << " |         | ";
                output(3);
                cout << " |     || ";
                instruct(12);
                instruct(29);
                instruct(46);
                cout << endl
                     << "    + - - +         + - - +     + - - +     + - - +         + - - +     || ";
                instruct(13);
                instruct(30);
                instruct(47);
                cout << endl
                     << "                       0           1           2                        || ";
                instruct(14);
                instruct(31);
                instruct(48);
                cout << endl
                     << "    + - - +                                                 + - - +     || ";
                instruct(15);
                instruct(32);
                instruct(49);
                cout << endl
                     << "    | ";
                input(4);
                cout << " |                                                 | ";
                output(4);
                cout << " |     || ";
                instruct(16);
                instruct(33);
                instruct(50);
                cout << endl
                     << "    + - - +                                                 + - - +     ||" << endl;
                break;
            }
            case 3:
            {
                cout << "IN  + - - +                                                 + - - +  OUT||       CODE" << endl
                     << "    | ";
                input(0);
                cout << " |                                                 | ";
                output(0);
                cout << " |     || ";
                instruct(0);
                instruct(17);
                instruct(34);
                cout << endl
                     << "    + - - +                                 + --- +         + - - +     || ";
                instruct(1);
                instruct(18);
                instruct(35);
                cout << endl
                     << "                                            | ";
                realhand(hand);
                cout << " |                     || ";
                instruct(2);
                instruct(19);
                instruct(36);
                cout << endl
                     << "    + - - +                                 + - - +         + - - +     || ";
                instruct(3);
                instruct(20);
                instruct(37);
                cout << endl
                     << "    | ";
                input(1);
                cout << " |                                  @   @          | ";
                output(1);
                cout << " |     || ";
                instruct(4);
                instruct(21);
                instruct(38);
                cout << endl
                     << "    + - - +                                  -----          + - - +     || ";
                instruct(5);
                instruct(22);
                instruct(39);
                cout << endl
                     << "                                             |@ @|                      || ";
                instruct(6);
                instruct(23);
                instruct(40);
                cout << endl
                     << "    + - - +                                    +            + - - +     || ";
                instruct(7);
                instruct(24);
                instruct(41);
                cout << endl
                     << "    | ";
                input(2);
                cout << " |                                  /   \\          | ";
                output(2);
                cout << " |     || ";
                instruct(8);
                instruct(25);
                instruct(42);
                cout << endl
                     << "    + - - +                                   | |           + - - +     || ";
                instruct(9);
                instruct(26);
                instruct(43);
                cout << endl
                     << "                                                                        || ";
                instruct(10);
                instruct(27);
                instruct(44);
                cout << endl
                     << "    + - - +         + - - +     + - - +     + - - +         + - - +     || ";
                instruct(11);
                instruct(28);
                instruct(45);
                cout << endl
                     << "    | ";
                input(3);
                cout << " |         | ";
                empty(0);
                cout << " |     | ";
                empty(1);
                cout << " |     | ";
                empty(2);
                cout << " |         | ";
                output(3);
                cout << " |     || ";
                instruct(12);
                instruct(29);
                instruct(46);
                cout << endl
                     << "    + - - +         + - - +     + - - +     + - - +         + - - +     || ";
                instruct(13);
                instruct(30);
                instruct(47);
                cout << endl
                     << "                       0           1           2                        || ";
                instruct(14);
                instruct(31);
                instruct(48);
                cout << endl
                     << "    + - - +                                                 + - - +     || ";
                instruct(15);
                instruct(32);
                instruct(49);
                cout << endl
                     << "    | ";
                input(4);
                cout << " |                                                 | ";
                output(4);
                cout << " |     || ";
                instruct(16);
                instruct(33);
                instruct(50);
                cout << endl
                     << "    + - - +                                                 + - - +     ||";
                cout << endl;
                break;
            }
            }
        } while (real_place != n);
    }
}

void describe(int n)
{
    switch (n)
    {
    case 1:
    {
        cout << "关卡要求：取出输入序列上的每个积木，并放入输出序列中。" << endl;
        break ;
    }
    case 2:
    {
        cout << "对于输入序列中的每两个东西，先把第一个减去第二个，并把结果放在输出序列中" << endl
             << "然后把第二个减去第一个，并把结果放在输出序列中，重复。" << endl;
        break ;
    }
    case 3:
    {
        cout << "从输入序列中依次取 2 个数字，如果相等则将其中一个输出，否则扔掉。" << endl
             << "重复这个过程直到输入传送带为空" << endl;
        break ;
    }
    case 4:
    {
        cout << "处理输入传送带上的数字序列。每次取三个连续的数字A、B、C，然后计算并输出三个结果：" << endl
             << "1. A和B的和（A + B）" << endl
             << "2. B和C的和（B + C）" << endl
             << "3. C和A的和（C + A）" << endl
             << "重复这个过程直到输入传送带为空。如果最后剩余的数字不足三个，则舍弃剩余数字。" << endl;
        break ;
    }
    }
}
void game_start(int n)
{
    inst_cnt = 0 ;
    clearScreen();
    describe(n);
    cout << endl
         << endl
         << "本关可用空地数：" << N << endl
         << "本关可用指令：";
    for (const auto &step : allowed_inst)
    {
        cout << step << " ";
    }
    cout << endl
         << "本关输入传送带：";
    for (const auto &step : input_arr)
    {
        cout << step << " ";
    }
    cout << endl
         << "本关正确输出：";
    for (const auto &step : correct_ans)
    {
        cout << step << " ";
    }
    cout << endl;
    land_situ(1);
    cout << "请选择输入方式：键盘输入or文件输入（键盘输入请按1，文件输入请按2）" << endl;
    int input_choice = 0;
    cin >> input_choice;
    bool input_choice_check = false ;
    while (!input_choice_check) // 非法输入处理
    {
        if (cin.fail())
        {
            cout << "输入内容无效，请重新输入：" << endl;
            cin.clear();                                         // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的无效内容
            cin >> input_choice;
        }
        else
        {
            if(input_choice != 1 && input_choice != 2)
            {
                cout << "输入内容无效，请重新输入：" << endl;
                cin.clear();                                         // 清除错误状态
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的无效内容
                cin >> input_choice;
            }
            else
            {
                if(cin.peek() != '\n')
                {
                    cout << "输入内容无效，请重新输入：" << endl;
                    cin.clear();                                         // 清除错误状态
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的无效内容
                    cin >> input_choice;
                }
                else input_choice_check = true ;
            }
        }
    }
    if (input_choice == 1) // 键盘输入
    {
        cout << "请输入您的指令数：" << endl;
        cin >> K; // K表示用户输入的指令的总个数
        bool instnum_check = false ;
        while (!instnum_check)
        {
            if (cin.fail())
            {
                cout << "输入内容无效，请重新输入指令数：" << endl;
                cin.clear();                                         // 清除错误状态
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的无效内容
                cin >> K;
            }
            else
            {
                if(cin.peek() != '\n')
                {
                    cout << "输入内容无效，请重新输入指令数：" << endl;
                    cin.clear();                                         // 清除错误状态
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区中的无效内容
                    cin >> K;
                }
                else  instnum_check = true ;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "请输入 " << K << " 条指令，每条指令占据 1 行：" << endl;
        for (int i = 0; i < K; i++)
        {
            string tmp;
            getline(cin, tmp);
            input_inst.push_back(tmp);
        }
    }
    else if (input_choice == 2)
    {
        string filename;
        cout << "请输入你的输入文件名：" << endl;
        cout << "（提示：在输入文件名之前请确保你的文件格式为：第一行是指令数K，后面K+1行是你的指令，若输入格式不对游戏将按错误处理）" << endl;
        cin >> filename;
        ifstream filein;
        filein.open(filename);
        while (!filein.is_open())
        {
            cout << "无法打开文件，请检查文件名是否正确" << endl;
            cout << "请重新输入文件名：" << endl;
            cin >> filename;
            filein.open(filename);
        }
        if (filein.is_open())
            cout << "文件输入成功，正在读取指令......" << endl;
        filein >> K;
        filein.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除换行符
        for (int i = 0; i < K; i++)
        {
            string tmp;
            getline(filein, tmp);
            input_inst.push_back(tmp);
        }
    }
    g = 1;
    waitForEnter();
}

void inbox()
{
    if (flag_inbox == 1)
    {
        return;
    }
    land_situ(1);
    hand = input_arr[0];
    input_arr.erase(input_arr.begin());
    inst_cnt ++ ;
    land_situ(1);
}

void outbox()
{
    land_situ(3);
    output_arr.push_back(hand);
    inst_cnt ++ ;
    hand = 114514;
    land_situ(3);
}

void add(int x)
{
    hand += empty_land[x];
    inst_cnt ++ ;
    land_situ(x + 1);
}

void sub(int x)
{
    hand -= empty_land[x];
    inst_cnt ++ ;
    land_situ(x + 1);
}

void copyto(int x)
{
    empty_land[x] = hand;
    inst_cnt ++ ;
    land_situ(x + 1);
}

void copyfrom(int x)
{
    hand = empty_land[x];
    inst_cnt ++ ;
    land_situ(x + 1);
}

void jump(int x)
{
    land_situ(x + 1);
    curr_inst = x - 1;
    inst_cnt ++ ;
    jump_cnt++;
}

void jumpifzero(int x)
{
    if (hand == 0)
    {
        curr_inst = x - 1; // 注意指令是从1开始的，这里要减去1才对应数组中的位置
        inst_cnt ++ ;
        jump_cnt++;
    }
    else
    {
        curr_inst++;
        inst_cnt ++ ;
    }
}

bool check_inst_1() // check_inst_1函数用来做语法的检查
{
    string str_1;
    istringstream iss(input_inst[curr_inst]);
    iss >> str_1;
    double num = -1;

    int ifinclude = 1; // 先判断指令是否包含
    for (int i = 0; i < M; i++)
    {
        ifinclude = str_1.compare(allowed_inst[i]); // 如果相等就返回0
        if (!ifinclude)
            break;
    }
    if (ifinclude)
        return false;

    if (str_1 == "inbox" || str_1 == "outbox") // 不能有指令数字的指令
    {
        string str_2;
        if (iss >> str_2)
            return false;
        return true;
    }

    if (str_1 == "add" || str_1 == "sub" || str_1 == "copyto" || str_1 == "copyfrom") // 指令数字是空地的指令
    {
        if (!(iss >> num))
            return false; // 需要指令数字但是没有
        if ((int)num != num)
            return false; // 数字不是整数
        if (num < 0 || num >= N)
            return false; // 空地超出界限
        double num_2 = 0;
        if (iss >> num_2)
            return false; // 指令数超过1
        return true;
    }

    if (str_1 == "jump" || str_1 == "jumpifzero")
    {
        if (!(iss >> num))
            return false; // 需要指令数字但是没有
        if ((int)num != num)
            return false; // 数字不是整数
        if (num < 1 || num > K)
            return false; // 指令数超出界限
        double num_2 = 0;
        if (iss >> num_2)
            return false; // 指令数超过1
        return true;
    }

    return false; // 默认返回false，处理其他情况
}

bool check_inst_2() // check_inst_2函数用来检查指令是否可执行
{
    istringstream ss(input_inst[curr_inst]);
    string str;
    ss >> str;
    int x;
    if (str == "inbox")
    {
        if (input_arr.size() == 0)
            flag_inbox = 1; // 如果输入传送带中已无数字，结束游戏
        return true;
    }
    else if (str == "outbox")
    {
        if (hand == 114514)
            return false;
        else
            return true;
    }
    else if (str == "add" || str == "sub")
    {
        ss >> x;
        if (hand == 114514 || empty_land[x] == 114514)
            return false;
        else
            return true;
    }
    else if (str == "copyto")
    {
        if (hand == 114514)
            return false;
        else
            return true;
    }
    else if (str == "copyfrom")
    {
        ss >> x;
        if (empty_land[x] == 114514)
            return false;
        else
            return true;
    }
    else if (str == "jump")
    {
        return true;
    }
    else if (str == "jumpifzero")
    {
        if (hand == 114514)
            return false;
        else
            return true;
    }
    return false;
}

bool output_error() // 错误情况下输出
{
    if (!check_inst_1())
    {
        cout << "Error on instruction " << curr_inst + 1 << endl
             << "很遗憾,通关失败,请再接再厉." << endl;
        return false;
    }
    else if (!check_inst_2())
    {
        cout << "Error on instruction " << curr_inst + 1 << endl
             << "很遗憾,通关失败,请再接再厉." << endl;
        return false;
    }
    else
        return true;
}

void operation() // 指令执行函数，执行指令时直接调用operation即可
{
    istringstream ss(input_inst[curr_inst]);
    string str;
    ss >> str;
    int x;
    if (str == "inbox")
        inbox();
    else if (str == "outbox")
        outbox();
    else if (str == "add")
    {
        ss >> x;
        add(x);
    }
    else if (str == "sub")
    {
        ss >> x;
        sub(x);
    }
    else if (str == "copyto")
    {
        ss >> x;
        copyto(x);
    }
    else if (str == "copyfrom")
    {
        ss >> x;
        copyfrom(x);
    }
    else if (str == "jump")
    {
        ss >> x;
        jump(x);
        return;
    }
    else if (str == "jumpifzero")
    {
        ss >> x;
        jumpifzero(x);
        return;
    }
    curr_inst++;
}

bool check_result() // 检查输出传送带和答案是否相同
{
    int len_1 = output_arr.size(), len_2 = correct_ans.size();
    if (len_1 != len_2)
        return false;
    else
        for (int i = 0; i < len_1; i++)
            if (output_arr[i] != correct_ans[i])
                return false;
    return true; // 如果最后没有返回false，则完全正确返回true
}

void output_result() // 用来输出关卡最后的结果
{
    if (check_result())
        cout << "Success" << endl
             << "恭喜您,成功通关!" << endl
             << "本关卡总执行命令数：" << inst_cnt << endl ;
    else
        cout << "Fail" << endl
             << "很遗憾,通关失败,请再接再厉." << endl
             << "本关卡总执行命令数：" << inst_cnt << endl ;
}

void level_1() // 第一关
{
    M = 2, N = 0;
    input_arr = {1, 2};
    correct_ans = {1, 2};
    allowed_inst = {"inbox", "outbox"};
    game_start(1);

    while (flag_inbox == 0 && curr_inst < K)
    {
        if (jump_cnt >= 50)
            break;
        if (!output_error())
        {
            return;
        }
        else
        {
            operation();
        }
    }
    output_result();
}
void level_2() // 第二关
{
    M = 8, N = 3;
    empty_land = vector<int>(N, 114514);
    input_arr = {3, 9, 5, 1, -2, -2, 9, -9};
    correct_ans = {-6, 6, 4, -4, 0, 0, 18, -18};
    allowed_inst = {"inbox", "outbox", "copyfrom", "copyto", "add", "sub", "jump", "jumpifzero"};
    game_start(2);

    while (flag_inbox == 0 && curr_inst < K)
    {
        if (jump_cnt >= 50)
            break;
        if (!output_error())
        {
            return;
        }
        else
        {
            operation();
        }
    }
    output_result();
}
void level_3() // 第三关
{
    M = 8, N = 3;
    empty_land = vector<int>(N, 114514);
    input_arr = {6, 2, 7, 7, -9, 3, -3, -3};
    correct_ans = {7, -3};
    allowed_inst = {"inbox", "outbox", "add", "sub", "copyto", "copyfrom", "jump", "jumpifzero"};
    game_start(3);

    while (flag_inbox == 0 && curr_inst < K)
    {
        if (jump_cnt >= 50)
            break;
        if (!output_error())
        {
            return;
        }
        else
        {
            operation();
        }
    }
    output_result();
}
void level_4() // 第四关
{
    M = 8, N = 3;
    empty_land = vector<int>(N, 114514);
    input_arr = {10, -3, 7, -8, 2, 0, 5, -6, 4, 9, -1, 12};
    correct_ans = {7, 4, 17, -6, 2, -8, -1, -2, 9, 8, 11, 21};
    allowed_inst = {"inbox", "outbox", "add", "sub", "copyto", "copyfrom", "jump", "jumpifzero"};
    game_start(4);

    while (flag_inbox == 0 && curr_inst < K)
    {
        if (jump_cnt >= 50)
            break;
        if (!output_error())
        {
            return;
        }
        else
        {
            operation();
        }
    }
    output_result();
}

int main()
{
    int flag_exit = 0; // 玩家推出的标志，每结束一关（无论成功或者失败）询问玩家是否退出

    while (!flag_exit)
    {
        input_arr.clear(), output_arr.clear(), input_inst.clear(), allowed_inst.clear(), correct_ans.clear(), empty_land.clear();
        curr_inst = 0, flag_inbox = 0, hand = 114514, jump_cnt = 0; // 对数据重新“初始化”
        real_place = 1, g = 0;                                      // 每一关开始时初始化
        // 第一步：读取现在的关卡信息，输出选择关卡的内容
        ifstream fin;
        fin.open("levelinfo.txt");
        bool lf[4]; // 记录四个关卡是否通过的布尔值
        fin >> lf[0] >> lf[1] >> lf[2] >> lf[3];
        fin.close();
        output_levelinfo(lf);
        double level_choice;
        bool ch_le_ch = 0;
        while (ch_le_ch == 0)
        {
            cin >> level_choice;
            if (cin.fail())
            {
                cout << "选择的关卡不存在，请重新选择：" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入的缓冲区
                continue;
            }
            else
            {
                bool ch_le_ch2 = check_choice(level_choice, lf);
                if (ch_le_ch2 == 0)
                {
                    cout << "选择的关卡不存在，请重新选择：" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入的缓冲区
                    continue;
                }
                else
                    break;
            }
        }

        // 第二步：跳转用户选择的关卡
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入的缓冲区
        switch ((int)level_choice)
        {
        // 第一关
        case 1:
        {
            level_1();
            break;
        }

        // 第二关
        case 2:
        {
            level_2();
            break;
        }

        // 第三关：
        case 3:
        {
            level_3();
            break;
        }

        // 第四关：
        case 4:
        {
            level_4();
            break;
        }
        }
        // 第三步：关卡完成信息的记录
        ofstream fout;
        fout.open("levelinfo.txt");
        for (int i = 0; i < 4; i++)
        {
            if (i == level_choice - 1)
            {
                if (lf[i] == 0)
                {
                    if (check_result())
                        fout << 1 << " ";
                    else
                        fout << 0 << " ";
                }
                else if (lf[i] == 1)
                    fout << 1 << " ";
            }
            else
                fout << lf[i] << " ";
        }
        fout.close();

        // 第四步：返回关卡选择界面
        cout << "是否要退出游戏？（退出游戏请按1，继续游戏请按2）" << endl;
        int exit_choice = 0;
        cin >> exit_choice;
        bool check_exit = false ;
        while (!check_exit) // 判断非法输入
        {
            if (cin.fail())
            {
                cin.clear();                                                   // 清除错误状态
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区
                cout << "输入内容无效，请重新输入" << endl;
                cin >> exit_choice;
            }
            else 
            {
                if(cin.peek() != '\n')
                {
                    cin.clear();                                                   // 清除错误状态
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区
                    cout << "输入内容无效，请重新输入" << endl;
                    cin >> exit_choice;
                }
                else
                {
                    if(exit_choice != 1 && exit_choice != 2)
                    {
                        cin.clear();                                                   // 清除错误状态
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区
                        cout << "输入内容无效，请重新输入" << endl;
                        cin >> exit_choice;
                    }
                    else check_exit = true ;
                }
            }
        }

        if (exit_choice == 1)
            flag_exit = 1;
        else if (exit_choice == 2)
            flag_exit = 0;
    }

    cout << "感谢游玩本游戏，小明欢迎您的下次启动！！！ByeBye！！！" << endl; // 结束处理
    return 0;
}
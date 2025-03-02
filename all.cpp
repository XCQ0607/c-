#include <iostream>
#include <string>
//可以用std::string代替
using namespace std;
//常量定义区(先定义后使用)
//符号常量，定义在代码头部，不需要分号，不需要管数据类型
//常量建议全部大写
#define YEAR 2006


class Basic{
	//方法声明区(不以数字开头)
    //void方法是静态方法，没有返回值。
    public:
	void a();
	unsigned int a1(unsigned int shift);	//这里a1方法的返回值类型是unsigned int，如果使用int，那么a方法中传入的test_1与test_2。就为-50和-70
    void b();
    void c();
    void d();
    };

//方法定义区
void Basic::a(){
	//若出现输出中文乱码，可通过以下方法解决
	/*
	1.引入windows.h库解决
	头部写#include <windows.h>
	方法内写    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为UTF-8编码
	2.方法内写一段代码
	system("chcp 65001");
	*/
	//常量声明
	const float month_day=6.7;
	//变量声明，声明字符串要双引号
	string day="2024.6.15";
	cout << "我的出生年是" << YEAR << "\n" << "月和日是" << month_day << endl;//符号常量，定义在代码头部，不需要分号"endl;
	cout << "我开始学习c++的时间是" << day << endl;
	
	//变量修改
	string x = "indifferent";
	cout << "我小时候对编程的态度:" << x << endl;
	x = "love";
	cout << "现在对编程的态度:" << x << endl;
	
	//system("pause");
	//这个应该写在main方法中，要不然运行到a就结束了
	cout << "------------------" << endl << "signed数与unsigned数的区别" << endl;
	//signed与unsigned数字
	/*
	对于整数数据而言，有符号区分
	对于实型(float-4字节-6~7位准确-单精度浮点数，double-8字节-15~16位准确-双精度浮点数，long double-16字节-18~19位准确-多精度浮点数)而言，都有符号。
	有符号的可以不写signed
	无符号的要写unsigned
	*这里的符号是正负号
	   无符号的快速写法u_short,u_int,u_long,u_char,u_long long
	使用sizeof(<变量名>)查看变量占用的字节
	*/
	signed int shift_1 = -100;
	unsigned int shift_2 = 100;
	int shift_3 = -200;
	unsigned int test_1 = 50;
	unsigned long long test_2 = 70;
	cout << "我是位移1: signed:" << shift_1 << "\n" ;
	cout << "我是位移2: unsigned:" << shift_2 << "\n" ;
	cout << "我是位移3: none:" << shift_3 << "/" << shift_3*-1 << "\n" ;
	cout << "使用u_int:" << "<正确储存> " << test_1 << " / <错误储存> " << a1(test_1) << endl;
	cout << "使用u_long long:" << "<正确储存> " << test_2 << " / <错误储存> " << a1(test_2) << endl;
	//如果将一个负数赋值给一个无符号整数类型的变量，C++ 会将这个负数转换为一个无符号整数，这个过程称为“模运算”或“环绕”。
    //例如，如果你有一个u_sign类型的变量，并且你将 -50 赋值给它，C++ 会将 -50 转换为一个无符号整数。具体来说，它会将 -50 加上无符号整数类型的最大值加（对于 32 位无符号整数，这个值是 2^32），然后取模运算的结果。
    //这里就是2^32-50
    
    //实型数据
    float a = 123456789.123;
    //默认使用科学计数法输出


    cout << "float科学计数法:" << a << endl;   //只提供前7位的准确数据
    cout << fixed;    //不使用科学计数法控制台输出,使用小数格式输出
    //cout.width(wide:20);  //输出的最大宽度(最大位数)为20
    cout << "float非科学计数法:" << a << endl;	//这里会出错因为float的精度为6~7位，而123456789.123有9位
    double b = 1234567890.1234567890;
    cout << "double非科学计数法:" << b << endl;	//double的精度为15~16位，1234567890.1234567890有15位
    
	}
//这里要注意返回值类型，这里是u_int，如果使用int，那么a方法中传入的test_1与test_2。就为-50和-70
//使用int时，这里的number会被解释为有符号整数，这样的话，因为int的number赋值超出了它的范围，控制台输出的就是有符号的
/*
具体来说，2^32-50=4294967246 是一个 32 位的无符号整数（unsigned int），其二进制表示为 11111111111111111111111111001110。当这个值被解释为有符号整数（int）时，最高位（符号位）为 1，表示这是一个负数。其实际值可以通过计算补码来确定，结果是 -50。
计算机使用补码来表示有符号整数，这样可以简化加减运算。
负数补码的计算方法是:
1.对该值的绝对值(正数)的二进制取反（即将所有位取反）
2.结果加 1

负数补码转换为原码的步骤
要将补码转换为原码，可以按照以下步骤进行：
判断符号位：
如果补码的最高位（符号位）是 0，表示该数是正数，原码与补码相同。
如果补码的最高位是 1，表示该数是负数，需要进行转换。
取反加一：
对于负数的补码，先对其进行逐位取反（0变1，1变0），然后再加1，得到原码。

计算机中存储正数时，通常使用的是原码或补码形式，但在实际操作中，正数的补码和原码是相同的。以下是详细说明：
正数的存储方式：
原码：
原码是最直接的表示方式，正数的原码就是其二进制表示。例如，+5 的原码是 0000 0101（假设使用 8 位表示）。
补码：
对于正数，补码的表示与原码相同。补码的计算方式是：
对于正数，补码 = 原码。
例如，+5 的补码也是 0000 0101。

存储方式：
int（有符号整数）：
使用补码表示法来存储正数和负数。
例如，-5 的补码存储为 1111 1011（假设使用 8 位表示）。
unsigned int（无符号整数）：
只存储非负数（0及正数），不使用补码。
直接使用其二进制表示。例如，5 的存储为 0000 0101，而 -5 是不允许的。

如果你将负数赋值给 unsigned int（无符号整数），计算机会将这个负数的二进制表示直接存储在 unsigned int 中，但它会被解释为一个非常大的正数。这是因为 unsigned int 只允许存储非负数（0及正数），并且不使用补码。
在 32 位系统中，-1 的二进制表示是 1111 1111 1111 1111 1111 1111 1111 1111。当这个值被存储在 unsigned int 中时，它会被解释为 4294967295（即 2^32 - 1）。
*/
//传入一个负数计算机时，将会将它转化为具有对应无符号整数值，即负数在计算机内部表示为二进制补码形式，它会将这个补码形式解释为无符号整数，即上面的-50的补码
unsigned int Basic::a1(unsigned int shift){
	unsigned int number = shift*-1;
//	cout << number ;
	return number;
	}

void Basic::b(){
	//计算 + - * /
	int day = 1949;
	cout << "新中国成立在" << day << "年" << endl;
	cout << "开国100周年在" << day+100 << "年" << endl;
	cout << "1949÷9=" << day/9 << endl;
	//连续赋值
	int  chinese =120 , math = 140 ,english = 145;
	cout << "这次期末成绩:" << "\n" << "语文" << chinese << endl << "数学" << math << endl << "英语" << english << endl;
	//如果最后一行没有加endl，那么英语就不会被打印。因为endl与\n是用来刷新缓冲区的。
    }
void Basic::c(){
	//用户输入cin
	string user_input;
	cout << "请输入想被打印的内容" << endl;
	cin >> user_input;     //接受输入
	cout << "你输入的是" << user_input << endl;
	//连续输入
	int firstInput , secondInput;
	cout << "请先后输入你的年级与班级:" << endl;
	cin >> firstInput >> secondInput;
	cout << "你所在的教室为" << firstInput << "年级" << "(" << secondInput << ")" << "班" << endl; 
	//命名变量规则:对于多 单词/含义 变量，我们可以使用下划线_或者首字母大写(第1个单词首字母小写叫做小驼峰法，都大写叫大驼峰法)的方法命名。
	//下划线与小驼峰一般用于变量命名，小驼峰还可用于方法命名，而大驼峰一般用于类命名。
	}
void Basic::d(){
	
	}



//main方法，它不属于任何一个类。
void fun(){
	//非常重要，实例化对象，将Basic实例化为对象basic，调用使用basic
	//在游戏开发中，每个角色、敌人、道具等都可以是一个对象。通过实例化多个对象，可以独立管理每个实体的状态和行为
	Basic basic;
	basic.a();
	basic.b();
	basic.c();
    // basic.d();
	}


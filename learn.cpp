#include <iostream>
using namespace std;
//--------------------------------
class X {
public:
    static int class_var;
    void hello();
    void data();
};
int X::class_var = 3;  // 在类的外部初始化静态成员变量
// 方法定义区--------------------------------
// void c();       //这种声明再调用也可以
#include <thread>
void X::hello() {       //X 类的对象的方法
    cout << "hello" << endl;
    cout << "Hello\b\b\tWorld!\n\n";
    int $a=0x99;
    printf("%d\n",$a);
    cout << $a << endl;

    // 输出并立即刷新缓冲区，确保 "Processing..." 可见
    cout << "Processing..." << flush;
    // 等待 2 秒钟，让 "Processing..." 可见
    this_thread::sleep_for(chrono::seconds(2));
    // 使用回车符返回行首并清空行尾内容
    cout << "\rDone!       " << endl;

    // 动态显示 "Processing."
        cout << "\rProcessing." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\rProcessing.." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\rProcessing..." << flush;
        this_thread::sleep_for(chrono::milliseconds(2500));
    // 显示 "Done!" 并覆盖之前的内容
    cout << "\rDone!       " << endl;
}
#include <limits>
void X::data(){
        cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
    cout << "\t最大值：" << (numeric_limits<bool>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << (numeric_limits<char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);  
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);  
    cout << "\t最大值：" << (numeric_limits<short>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);  
    cout << "\t最大值：" << (numeric_limits<int>::max)();  
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);  
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);  
    cout << "\t最大值：" << (numeric_limits<long>::max)();  
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t" << "所占字节数：" << sizeof(double);  
    cout << "\t最大值：" << (numeric_limits<double>::max)();  
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    cout << "\t最大值：" << (numeric_limits<long double>::max)();  
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);  
    cout << "\t最大值：" << (numeric_limits<float>::max)();  
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);  
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();  
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;  
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************"<< endl;  
}
//-------------------------------
//局变量从定义处开始至程序结束起作用，即全局变量存在有效作用域。
static int allrange = 1;    //static 变量在整个程序运行期间都存在，直到程序结束，表示该变量只会初始化一次，且不会被销毁。
int a = 4;  //全局变量和和局部变量同名时，可通过域名在函数中引用到全局变量，不加域名解析则引用局部变量
void range(){
    cout << "全局变量:" << allrange << endl;
    // 局部变量声明
    int a = 10;
     cout << "a-局部变量(外部变量): " << a << endl;
     {
         int a = 20;  // 块作用域变量
         cout << "a-块变量: " << a << endl;
    }
     cout << "a-全局变量: " << ::a << endl;
     cout << "class_var类变量: " << X::class_var << endl;
     cout << "---range函数内修改全局变量+5--- " << endl;
     allrange+=5;
     //全局变量的值可以在局部函数内重新赋值。
     extern int worknow;        // 声明外部变量，没有该行这一函数无法调用worknow
     cout << "extern调用worknow:" << worknow << endl;
}
int worknow = 9;        // 定义外部变量，此后函数可调用
void range1(){
    cout << "range1中调用此时的a-全局变量:" << allrange << endl;
    cout << "正常调用worknow : " << worknow << endl;
}
//-------------------------------
// 全局变量，具有外部链接，默认存储类为extern
int globalVar;
void function1() {
    // 静态变量，具有静态存储期，生命周期贯穿整个程序
    static int staticVar = 20;
    const int constVar = 30; // const变量默认具有static存储期
    // 尝试修改const变量，编译错误
    // constVar = 40;
    // mutable成员变量，可以在const成员函数中修改
    class MyClass {
    public:
        mutable int mutableVar;

        void constMemberFunc() const {
            mutableVar = 50; // 允许修改mutable成员变量
        }
    };
    // 线程局部变量，每个线程有自己的独立副本
    thread_local int threadVar = 60;
}

void main0() {
    extern int externalVar; // 声明具有外部链接的变量
    function1();
}

//--------------------------------
class MyType {
public:
    MyType(int value) : data(value){}
    int getData() const { return data; }
    // 这里加 const，表示这个转型操作符函数不会修改对象的状态，即它是一个常量成员函数
    operator int() const { return data; }       
private:
    int data;
};
void gogo() {
    // 直接初始化
    MyType obj1(42);    //调用构造函数
    // 复制初始化
    MyType obj2 = 42;
    int hh = obj2;  //调用类的operator int()
    // 调用成员函数获取数据
    std::cout << "obj1 data: " << obj1.getData() << std::endl;
    std::cout << "obj2 data: " << obj2.getData() << std::endl;
}
//--------------------------------
void go() {
    // c();       
    //  X x;
    //  x.hello();
    // x.data();
    //range();    range1();
    main0();
    gogo();
}
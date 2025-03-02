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
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t) << endl;  
    // cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
    // cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
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
int worknow = 9;        // 定义外部变量，此后函数可调用，此前函数想要调用worknow需要在函数内声明extern
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
    //将const修饰的“成员函数”称为const成员函数，const修饰类成员函数，实际修饰该成员函数隐含的this指针，表明在该成员函数中不能对类的任何成员进行修改
    // 作用：const成员函数保证在函数体内不会修改任何成员变量。（除非这些成员变量被声明为mutable）
    class MyClass {
    public:
        mutable int mutableVar; // mutable成员变量不仅可以在const成员函数中被修改，也可以在非const成员函数中被修改。
        void constMemberFunc() const{
            mutableVar = 50; // 允许修改mutable成员变量
        }
    };
    // 线程局部变量，每个线程有自己的独立副本
    thread_local int threadVar = 60;
}


// int d1,d2,d3,d4;
// const int* p1; //修饰的是*p1指向的对象
// //*p1=1;//不行,因为*p1是const的
// //p1=&d1;//可以
// int const* p2; //修饰的是*p2指向的对象
// //*p2=2;//不行，因为*p2是const的
// //p2=&d2;//可以
// int* const p3; //修饰的是p3指向的内容（p3指向的地址）
// //*p3=3;//可以
// //p3=&d3;//不行，因为p3是const的
// const int* const p4;//既修饰*p4指向的对象，又修饰p4指向的内容
// //*p4=4；//不行，因为*p4是const的

// 1. const int* p1
// p1 是一个指针，它指向一个 const int 类型的对象。即p1指向的对象（*p1）是const的，这意味着你不能通过 p1 修改它所指向的 int 对象的内容。但是，可以改变 p1 本身的值，让它指向另一个 int 对象（或 const int 对象）。

// 2. int const* p2
// 与第一行完全相同。在C++中，const 关键字的位置在类型名和*之间或之后是等价的，所以 int const* 和 const int* 都表示指针指向的对象是 const 的。p2 同样不能用来修改它所指向对象的内容，但 p2 本身的值（即它所指向的地址）是可以改变的。

// 3. int* const p3
// p3 是一个 const 指针，它指向一个 int 类型的对象。即p3指针本身是const的，这意味着 p3 指向的地址是固定的，你不能改变 p3 让它指向另一个对象。但是，可以通过 p3 修改它所指向的 int 对象的内容（除非该对象本身也是 const 的）。

// 4.const int* const p4
// p4是一个const指针，它指向一个const int类型的对象。即p4指向的对象是const的，p4指针本身也是const的，这意呀着既不能改变指针的指向，也不能通过该指针修改对象的内容。




void main0() {
    extern int externalVar; // 声明具有外部链接的变量
    function1();    //调用function1函数，function1函数中定义了static变量staticVar，const变量constVar，mutable变量mutableVar，thread_local变量threadVar
}

//--------------------------------
// 这个类 MyType 用于封装一个整数数据，并提供一些操作该数据的方法。
class MyType {
public:
    // 构造函数，接受一个整数值并将其赋值给成员变量 data
    MyType(int value) : data(value) {}  //这里的:表示初始化列表，data(value)表示将value的值赋给data，{}表示初始化列表结束
    //也可以写成
    // MyType(int value){
    //     data = value;
    // }
    
    // 成员函数 getData，返回 data 的值，const 表示该函数不会修改对象的状态
    int getData() const { return data; }
    
    // 转型操作符函数，将 MyType 对象转换为 int 类型
    // const 表示这个函数不会修改对象的状态
    operator int() const { return data; }       
private:
    int data; // 私有成员变量，用于存储整数数据
};

void gogo() {
    // 直接初始化 MyType 对象 obj1，调用构造函数并传入 42
    MyType obj1(42);    
    // 复制初始化 MyType 对象 obj2，使用整数 42
    MyType obj2 = 42;
    
    // 将 obj2 转换为 int 类型，调用类的 operator int() 函数
    int hh = obj2;  
    
    // 输出 obj1 和 obj2 的数据
    std::cout << "obj1 data: " << obj1.getData() << std::endl;
    std::cout << "obj2 data: " << obj2.getData() << std::endl;
}
//--------------------------------
void go() {     
    X x;
    x.hello();
    x.data();
    range();    range1();
    main0();
    gogo();
}
#include <iostream>
#include <wchar.h>
using namespace std;
int g_Arr[2][3];

int (*func(int arg))[2][3]{
    for (int i = 0; i <2 ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            g_Arr[i][j] = arg;
        }
    }
    return &g_Arr;
}

class Header{
    public:
        void _319_1();
        void _319_2();
        void _319_3();
        void _319_4();
        void _319_5();
        void _319_6();
        void _319_7();
        void _319_8();
        void _319_9();
        void _319_10();
        void _319_11();
        void _319_12();
        void _319_13();
        void _319_14();
                
};

void _319_1(){
        cout << fixed;
    cout.precision(4);
    float f1= 8388608.0;
    cout<<f1<<endl;
    float f2 = 8388608.5;
    cout<< f2<<endl;
    float f3 = 8388608.6;
    cout<<f3<<endl;
    float f4 = 8388609.0;
    cout<<f4<<endl;
}

void _319_2(){
        cout << fixed;
    cout.precision(4);
    float f1 = 1.0;
    cout << f1 << endl;
    float f2 = 1.5;
    cout << f2 << endl;
    //1.6 2.0
    float f3 = 1.6;
    cout << f3 << endl;
    float f4 = 2.0;
    cout << f4 << endl;
}

void _319_3(){
        cout << fixed;
    cout.precision(0);
    for(size_t i = 0; i < 10; i++)
    {
        //why?
        float f = 67108864+i;
        cout << f << endl;
    }
}

void _319_4(){
        cout << fixed;
    cout.precision(0);
    cout<<fixed;
    cout.precision(0);
    //float int
    float f = 67108864+4;
    cout << f << endl;
    __int64_t i64 = 67108864 + 4;
    cout << i64 << endl;

}

void _319_5(){

    char c1 = 'A';
    char c2 = 65;
    char c3 = 'A' + 1;
    char c4 = 66;

    cout << c1 << c2 << c3 << c4 << endl;

}

void _319_6(){
    char str[8];
    memset(str,'A',8);

    str[0] = 'C';
    str[1] = '+';
    str[2] = '+';

    cout << str << endl;
}

void _319_7(){
    char str1[8] = "c++";
    char str2[] = "c++";
    char str3[8];
    //str3 = "c++";

    cout << str1 << str2 << str3 << endl;
}

void _319_8(){
    wchar_t str[] = L"C++";
    wcout << str << endl;
}

void _319_9(){
    
    char str[] = "대한민국";
    int length = sizeof(str);
    cout << str << length << endl;

    wchar_t wstr[] = L"대한민국";
    int wlength = sizeof(wstr);
     
    wcout<< wstr << wlength << endl;

}

void _319_10(){

    int a = 3;
    int *pa = &a;

    cout << pa << endl
         << *pa << endl;
}
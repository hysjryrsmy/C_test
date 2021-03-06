#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//sqrt开平方根的函数，可以使用O(1)的算法去实现
//简单查找的时间复杂度是O(n)；二分查找的时间复杂度是O(log2 n)。
//异或运算符的运算规则是对应二进制位相同为0，不同为1
//移位运算左移低位补0，右移高位补符号位
//变参函数的实现，参数列表中至少有一个确定的参数
//对数函数中，我们只需要知道一种函数，就可以求以任何数字底的对数值
//宏比函数的执行效率更高
//工程开发中，我们只需要对方源文件的动态或者静态链接库与相关的头文件，就可以拿来使用了
//用memset(arr, -1, sizeof(arr)); 可以将整型数组的每一位初始化为-1
//B函数strcmp("hello", "hallo")；的返回值为1
//可以通过使用%[ ^\n]s实现读入带空格的字符串
//计算机的小端是将数据的低位存在低地址位中
//结构体的对齐方式可以人为设置
//减少if语句的使用，会使我们程序在实际运行中变快
//在同一个操作系统下，指针变量可以存储得下任何类型的地址
//printf函数的返回值表示成功打印字符的个数
//n%2等价于n&1，n%4等价于n&3；
//不同类型的指针变量，在同一个操作系统中，所占空间大小是相同的
//线性筛算法的时间复杂度和空间复杂度都是O(N)的
/*
给定两个整数m和n，需要输出从m到n之间（包括m和n）每一个数字的因子个数。(1 <= m <= n  <= 1,000,000)
输入两个整数m和n。
（1 <= m <= n <= 1,000,000）
输出共 (n - m + 1)行，分别代表从m到n之间每一个数字的因子个数
*/


/*
给出两个整数a，b，求这两个数字的最小公倍数的值（1 <= a <= 10000, 1 <= b <= 10000）
输入一行，两个整数a，b
1 <= a <= 10000, 1 <= b <= 10000）
输出一行，为a和b的最小公倍数的值
*/

/*
#include<stdio.h>
int gcd(int m, int n) {
    if (n) return gcd(n, m % n);
    else  return m;
}
int lcm(int m, int n) {
    return m / gcd(m, n) * n; // 这样写防止数据溢出
}
int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        printf("gcd(%d, %d)) = %d\n", a, b, gcd(a, b));
        int temp = gcd(a, b);
        printf("lcm(%d, %d) = %d\n", a, b, lcm(a, b));
    }
    return 0;
}

*/





/*
题目描述

给定一个合法的日期，求 X 天后的日期

输入

第一行输入一个整数 ??，表示天数。

第二行输入三个整数 y,m,d，分别表示当前日期的年月日。（1≤x≤500,日期一定合法）

输出

输出为一行，共三个整数，分别表示 x 天后日期的年月日。
*/
#include<stdio.h>
int mont(int n) {
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) return 0;
    else return 1;
}
int main() {
    int n;
    scanf("%d\n", &n);
    int y, m, d;
    int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31 };
    scanf("%d %d %d", &y, &m, &d);
    if (mont(y)) mon[2] = 28;
    else mon[2] = 29;
    for (int i = 1; i <= n; i++) {
        d += 1;
        if (d > mon[m]) {
            d = d - mon[m];
            m++;
            if (m > 12) {
                y++;
                m = 1;
                if (mont(y)) continue;
                mon[2] = 29;
            }
        }
    }
    printf("%d %d %d", y, m, d);
    return 0;
}

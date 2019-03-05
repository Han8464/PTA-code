#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

//字符转化为数字
int charToInt(char ch)
{
    int rs= 0;
    if(ch >= '0' && ch <= '9')
    {
        rs = ch - '0';
    }

    if(ch >= 'a' && ch <= 'z')
    {
        rs = ch - 'a' + 10;
    }

    return rs;
}

//化为十进制数
long long changeToDecimal(string s,long long radix)
{
    long long result = 0;
    for(int i = 0;i < s.length();i++)
    {
        result = result*radix + charToInt(s[i]);
    }

    return result;
}

//比较n1与n2在十进制下的大小，此函数可避免运行超时
int compare(long long n1, string n2, long long radix)
{
    long long sum = 0;
    for (int i = 0; i < n2.length();i++)
    {
        sum = sum * radix + charToInt(n2[i]);
        if (sum > n1) //重点，避免运行超时
        {
            return 1;
        }
    }
    if (sum > n1)// n1 < n2
    {
        return 1;
    }
    else if (sum < n1) // n1 > n2
    {
        return -1;
    }
    else //相等
    {
        return 0;
    }
 
}

//二分查找，十进制数与未知进制数相等时的进制
long long Binary_Search(long long n,string p)
{
    //step1:未知进制数的进制下界（每个位置数字的最大值+1）
    //      进制上界（数d1和数b最大符号代表的数的最大值加上1,n>最小进制时，则为n+1；否则为最小进制，可以设为low+1）

    int max = 0;
    for(int i = 0;i < p.length();i++)//从末位开始
    {
        if(max < charToInt(p[i])) //不为空
        {
            max = charToInt(p[i]);
        }
    }

    long long low = (long long)max + 1;//记录最小的进制；
    long long high;//记录最大进制；
    if(n > low)
    {
        high = n + 1;  
    }
    else
    {
        high = low + 1;
    }
    long long mid;//中间数

    //step2:二分查找
    while(low < high)
    {
        mid = (low + high)/2;
        if(compare(n,p,mid) == 0)//(n == changeToDecimal(p,mid))
        {
            return mid;
        }
        else if(compare(n,p,mid) == 1)//(n < changeToDecimal(p,mid))
        {
            high = mid;   //while中是low <= high时，为mid-1；此处是low < high；但按照书中一模一样的写法，只能得24分
        }
        else
        {
            low = mid;    //while中是low <= high时，为mid+1；此处是low < high
        }
    }

    return -1;
}

int main()
{
    string N1,N2;
    int tag;
    long long radix;
    cin >> N1;
    cin >> N2;
    cin >> tag;
    cin >> radix;

    //全部化为10进制比较
    long long d1,d2;//N1和N2化为十进制的值
    if(tag == 1)
    {
        d1 = changeToDecimal(N1,radix);
        if(Binary_Search(d1,N2) == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << Binary_Search(d1,N2) << endl;
        }
    }

    if(tag == 2)
    {
        d2 = changeToDecimal(N2,radix);
        if(Binary_Search(d2,N1) == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << Binary_Search(d2,N1) << endl;
        }
    }

    return 0;
}
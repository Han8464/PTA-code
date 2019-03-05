#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

//�ַ�ת��Ϊ����
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

//��Ϊʮ������
long long changeToDecimal(string s,long long radix)
{
    long long result = 0;
    for(int i = 0;i < s.length();i++)
    {
        result = result*radix + charToInt(s[i]);
    }

    return result;
}

//�Ƚ�n1��n2��ʮ�����µĴ�С���˺����ɱ������г�ʱ
int compare(long long n1, string n2, long long radix)
{
    long long sum = 0;
    for (int i = 0; i < n2.length();i++)
    {
        sum = sum * radix + charToInt(n2[i]);
        if (sum > n1) //�ص㣬�������г�ʱ
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
    else //���
    {
        return 0;
    }
 
}

//���ֲ��ң�ʮ��������δ֪���������ʱ�Ľ���
long long Binary_Search(long long n,string p)
{
    //step1:δ֪�������Ľ����½磨ÿ��λ�����ֵ����ֵ+1��
    //      �����Ͻ磨��d1����b�����Ŵ�����������ֵ����1,n>��С����ʱ����Ϊn+1������Ϊ��С���ƣ�������Ϊlow+1��

    int max = 0;
    for(int i = 0;i < p.length();i++)//��ĩλ��ʼ
    {
        if(max < charToInt(p[i])) //��Ϊ��
        {
            max = charToInt(p[i]);
        }
    }

    long long low = (long long)max + 1;//��¼��С�Ľ��ƣ�
    long long high;//��¼�����ƣ�
    if(n > low)
    {
        high = n + 1;  
    }
    else
    {
        high = low + 1;
    }
    long long mid;//�м���

    //step2:���ֲ���
    while(low < high)
    {
        mid = (low + high)/2;
        if(compare(n,p,mid) == 0)//(n == changeToDecimal(p,mid))
        {
            return mid;
        }
        else if(compare(n,p,mid) == 1)//(n < changeToDecimal(p,mid))
        {
            high = mid;   //while����low <= highʱ��Ϊmid-1���˴���low < high������������һģһ����д����ֻ�ܵ�24��
        }
        else
        {
            low = mid;    //while����low <= highʱ��Ϊmid+1���˴���low < high
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

    //ȫ����Ϊ10���ƱȽ�
    long long d1,d2;//N1��N2��Ϊʮ���Ƶ�ֵ
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
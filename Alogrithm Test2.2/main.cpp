//
//  main.cpp
//  Alogrithm Test2.2
//
//  Created by 黄沐 on 2016/10/18.
//  Copyright © 2016年 Hm. All rights reserved.
//

#include <iostream>
using namespace std;
//采用动态规划法求解最长公共子序列问题
//注意最长公共子串（Longest CommonSubstring）和最长公共子序列（LongestCommon Subsequence, LCS）的区别：
//子串（Substring）是串的一个续的部分，子序列（Subsequence）则是从不改变序列的顺序，而从序列中去掉任意的元素而获得的新序列；
//更简略地说，前者（子串）的字符的位置必须连续，后者（子序列LCS）则不必。
//比如字符串acdfg同akdfc的最长公共子串为df，而他们的最长公共子序列是adf。
string A,B;
string A_test="AGGTAB",B_test="GXTXAYB";
int c[100][100]; // c[i][j]表示序列S1前i个元素和S2的前j个元素的LCS
int b[100][100]; //便于求解最优解
int Max( int a, int b);
void LCS( string A, string B, int m, int n);
void Print_LCS( string A, int i, int j);
void Test();
int main( int argc, const char * argv[])
{
    Test();
    cout<<"请分别输入 A B字符串 "<<endl;
    cin>>A>>B;
    cout<<"最长公共子序列是:";
    LCS(A,B,A.length(),B.length());
    Print_LCS(A,A.length(), B.length());
    return 0;
}
int Max( int a, int b)
{
    return (a>b)?a:b;
}
void LCS( string A, string B, int m, int n)
{
    for ( int i=0; i<=m; i++)
        c[i][0]=0;
    for ( int i=0; i<=n; i++)
        c[0][i]=0;
    for ( int i=0; i<m; i++)
    {
        for ( int j=0; j<n; j++)
        {
            if (A[i]==B[j])
            {
                c[i+1][j+1]=c[i][j]+1;
                b[i+1][j+1]=0;
            }
            else if (c[i][j+1]>=c[i+1][j])
            {
                c[i+1][j+1]=c[i][j+1];
                b[i+1][j+1]=1;
            }
            else
            {
                c[i+1][j+1]=c[i+1][j];
                b[i+1][j+1]=2;
            }
        }
    }
}
void Print_LCS (string A, int i, int j)
{
    if ((i == 0) || (j == 0))
        return ;
    if (b[i][j] == 0)
    {
        Print_LCS (A, i - 1, j - 1);
        cout << A[i - 1];
    }
    else if (b[i][j] == 1)
        Print_LCS (A, i -1, j);
    else
        Print_LCS (A, i, j - 1);
}
void Test()
{
    cout<<"以下为测试代码"<<endl;
    cout<<"字符串A为:"<<A_test<<endl<<"字符串B为:"<<B_test<<endl;
    LCS(A_test,B_test,A_test.length(),B_test.length());
    cout<<"它们的最长公共子序列为:";
    Print_LCS(A_test,A_test.length(),B_test.length());
    cout<<endl<<"以上为测试代码"<<endl<<endl;
    
}

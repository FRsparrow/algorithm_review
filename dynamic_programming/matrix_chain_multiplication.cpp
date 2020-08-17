#include <iostream>

#define INF 1 << 30

using namespace std;

const int n = 6;
int a[] = {30, 35, 15, 5, 10, 20, 25};
// int a[] = {35,15,5,10,20};
int m[n][n];    // m[i][j]表示矩阵i到矩阵j连乘所需最小乘法次数
int s[n][n];    // s[i][j]表示矩阵i到矩阵j连乘具有所需最小乘法次数的的分隔位置
int temp;

void get_min_multiplication_time()
{
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;    // 单个矩阵不需要乘
    }
    for (int i = 0; i < n-1; i++)
    {
        s[i][i+1] = i;
    }
    
    for (int l = 1; l < n; l++)    // l为矩阵链的长度-1
    {
        for (int i = 0; i < n-l; i++)
        {
            m[i][i+l] = INF;
            for (int k = i; k < i+l; k++)
            {
                temp = m[i][k] + m[k+1][i+l] + a[i]*a[k+1]*a[i+l+1];
                if (m[i][i+l] > temp)
                {
                    m[i][i+l] = temp;
                    s[i][i+l] = k;
                }
            }
        }
    }
}

void show(int start=0, int end=n-1)
{
    if (end == start)
    {
        cout << "A" << end;
        return;
    }
    cout << "(";
    show(start, s[start][end]);
    show(s[start][end]+1, end);
    cout << ")";
}

int main()
{
    get_min_multiplication_time();
    cout << m[0][n-1] << endl;
    show();
    cout << endl;
    

    system("pause");
    return 0;
}
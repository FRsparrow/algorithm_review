#include <iostream>

using namespace std;

const int n = 4+1, W = 5+1;
int w[] = {2,1,3,2};
int v[] = {12,10,20,15};
int c[n][W];    // c[i][j]表示在前i个物品中拿若干物品，其总重量不超过W，能达到的最大的总价值

void get_max_value()
{
    for (int i = 0; i < W; i++)
    {
        c[0][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j < w[i-1] || c[i-1][j-w[i-1]] + v[i-1] <= c[i-1][j])
            {
                c[i][j] = c[i-1][j];    // 不拿第i个物品
            }
            else
            {
                c[i][j] = c[i-1][j-w[i-1]] + v[i-1];     // 拿第i个物品
            }
        }
    }
}

void show()
{
    int i = n-1, j = W-1;
    while (c[i][j])
    {
        if (c[i][j] > c[i-1][j])
        {
            cout << i << " ";
            j -= w[i-1];
        }
        i--;
    }
    cout << endl;
}

int main()
{
    get_max_value();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    show();

    system("pause");
    return 0;
}
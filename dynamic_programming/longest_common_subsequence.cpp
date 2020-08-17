/* 最长公共子序列问题
   子序列为从一个序列中从左到右取出若干个元素按原来的顺序组成的序列，在原序列中可以不连续
*/
#include <iostream>

using namespace std;

const int n = 7+1, m = 6+1;
char x[] = {'A','B','C','B','D','A','B'};
char y[] = {'B','D','C','A','B','A'};
int c[n][m];    // c[i][j]表示x中前i个元素和y中前j个元素的最长公共子序列长度
int s[n][m];    // s[i][j]表示x中前i个元素和y中前j个元素的最长公共子序列依赖于哪种情况，三种情况对应0，1，2三种取值

void count_LCS()
{
    for (int i = 0; i < n; i++)
    {
        c[i][0] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        c[0][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                s[n][m] = 0;
            }
            else if (c[i-1][j] > c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                s[i][j] = 1;
            }
            else            
            {
                c[i][j] = c[i][j-1];
                s[i][j] = 2;
            }
        }
    }
}

void show()
{
    string lcs = "";
    int i = n-1, j = m-1;
    while (c[i][j])
    {
        switch (s[i][j])
        {
        case 0:
            lcs = x[i-1] + lcs;
            --i;
            --j;
            break;
        case 1:
            --i;
            break;
        case 2:
            --j;
            break;
        default:
            break;
        }
    }
    cout << lcs << endl;
}

int main()
{
    count_LCS();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    show();

    system("pause");
    return 0;
}
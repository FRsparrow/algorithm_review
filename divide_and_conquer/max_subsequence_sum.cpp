#include <iostream>

using namespace std;

const int n = 6;
// int a[] = {1,3,-3,4,-6,-1};  //max_sum=5
int a[] = {4,-3,5,-2,6,-7}; // max_sum=10
int max_sum = a[0];

// 线性算法(最大和序列前缀和不会是非正值，除非序列全为非正值)
void get_max_subsequence_sum_linear()
{
    int current_sequence_sum = a[0];
    for (int i = 1; i < n; i++)
    {
        if (current_sequence_sum <= 0)
        {
            current_sequence_sum = a[i];	// 从下一个元素开始累加
        }
        else
        {
            current_sequence_sum += a[i];
        }
        if (max_sum < current_sequence_sum)
        {
            max_sum = current_sequence_sum;
        }
    }
}

// 动规
void get_max_subsequence_sum_dp()
{
    int p[n];   // p[i]表示序列a[0]...a[i]包括a[i]在内的最大子序列和
    p[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (p[i-1] > 0)
        {
            p[i] = p[i-1] + a[i];
        }
        else
        {
            p[i] = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (max_sum < p[i])
        {
            max_sum = p[i];
        }   
    }
}

// 分治
int get_max_subsequence_sum_divide(int low=0, int high=n)
{
    if (low == high - 1)
    {
        return a[low];
    }
    
    int mid = (low + high) / 2;
    
    int max_left_sum = a[mid], max_right_sum = 0;
    int left_sum = a[mid], right_sum = 0;
    for (int i = mid+1; i < high; i++)
    {
        right_sum += a[i];
        if (max_right_sum < right_sum)
        {
            max_right_sum = right_sum;
        }
    }
    for (int i = mid-1; i >= low; i--)
    {
        left_sum += a[i];
        if (max_left_sum < left_sum)
        {
            max_left_sum = left_sum;
        }
    }
    int res = max_left_sum + max_right_sum;
    int ls = get_max_subsequence_sum_divide(low, mid);
    if (mid + 1 == high)
    {
        return max(res, ls);
    }
    else
    {
        int rs = get_max_subsequence_sum_divide(mid+1, high);
        return max(max(res, ls), rs);
    }
}

// 暴力1
void get_max_subsequence_sum_brute1()
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
}

// 暴力2
void get_max_subsequence_sum_brute2()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
}

int main()
{
    get_max_subsequence_sum_brute1();
    cout << max_sum << endl;

    system("pause");
    return 0;
}
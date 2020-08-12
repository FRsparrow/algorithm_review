#include <iostream>
#include <algorithm>

using namespace std;

const int n = 9;
int a[] = {3,4,1,7,8,5,7,2,4};
int low, high, le, he;

// 在数组a中查找和为sum的两个元素le和he，查找成功返回true，否则返回false
bool exist_sum_of_2_elements(int sum)
{
    low = 0;
    high = n - 1;
    sort(a, a + n);
    while (low < high)
    {
        if (a[low] + a[high] < sum)
        {
            ++low;
        }
        else if (a[low] + a[high] > sum)
        {
            --high;
        }
        else
        {
            le = a[low];
            he = a[high];
            return true;
        }
    }
    return false;
}

int main()
{
    int sum = 1;
    if (exist_sum_of_2_elements(sum))
    {
        cout << "The two elements whose sum is " << sum << " are " << le << " and " << he << endl;
    }
    else
    {
        cout << "There are not two elements whose sum is " << sum << endl;
    }
    

    system("pause");
    return 0;
}
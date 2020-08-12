#include <iostream>

using namespace std;

template<class E>
void merge(E* source, E* target,int block_size, int len, int& count)
{
    int j,k,jmax,kmax,base;
    // 对每两个块(0和1，2和3...)进行合并,j,k分别指向前后块的当前比较元素，小者填入temp
    for (int i = 0; i < len; i += 2*block_size)
    {
        j = i;
        k = i + block_size;
        jmax = k < len ? k : len;
        kmax = k + block_size < len ? k + block_size : len;
        base = i + block_size;  // i+(j-i)+[k-(i+block_size)]=j+k-i-block_size才是当前元素在temp中对应元素的下标
        while (j < jmax && k < kmax)
        {
            if (source[j] <= source[k])
            {
                target[j+k-base] = source[j];
                ++j;
            }
            else
            {
                target[j+k-base] = source[k];
                ++k;
                ++count;
            }
        }
        if (j == jmax)  // 前一块先放完
        {
            while (k < kmax)    // 后一块存在则将剩余元素移入temp（k>=kmax表示后一块不存在）
            {
                target[j+k-base] = source[k];
                ++k;
            }
        }
        else    // 后一块先放完
        {
            base = k > kmax ? 0 : base - k; // 后一块不存在则直接将前一块依次填入temp，即base为0
            // 后一块存在时当前j指向的元素已经比较过，而j之后所有(jmax-j-1)个元素和后一块中所有(kmax-i-block_size)元素构成逆序对
            count += i + block_size > kmax ? 0 : (kmax - i - block_size) * (jmax - j - 1);
            while (j < jmax)
            {
                target[j-base] = source[j];
                ++j;
            }
        }
    }
}

template<class E>
void reversepair_count(E *start, E *end, int& count)
{
    count = 0;
    bool flag = true;
    int len = end - start;
    E *temp = new E[len];
    for (int block_size = 1; block_size < len; block_size *= 2)
    {
        if (flag)
        {
            merge(start, temp, block_size, len, count);
        }
        else
        {
            merge(temp, start, block_size, len, count);
        }
        flag = !flag;
    }
    if (!flag)
    {
        for (int i = 0; i < len; i++)
        {
            start[i] = temp[i];
        }
    }
    
    delete[] temp;
}


int main()
{
    const int n = 10;
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    // int a[] = {1,0,2,3,4,5,6,7,8,9};
    int count;
    reversepair_count(a, a + n, count);
    cout << count << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
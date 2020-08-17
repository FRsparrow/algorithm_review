#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 10;
int a[n];

int generate_random_sequence()
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    srand((int)time(0));
    int temp, rand_index;
    for (int i = 0; i < n; i++)
    {
        rand_index = i + rand() % (n-i);
        temp = a[i];
        a[i] = a[rand_index];
        a[rand_index] = temp;
    }
}

int main()
{
    generate_random_sequence();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
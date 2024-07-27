#include <iostream>
#include <string>
#include <algorithm> // max 함수를 사용하기 위해 추가
using namespace std;

int main()
{
    string A_string, B_string;

    cin >> A_string;
    cin >> B_string;

    int a_len = A_string.length();
    int b_len = B_string.length();

    int** count_string = new int* [a_len + 1];
    for (int i = 0; i <= a_len; i++)
    {
        count_string[i] = new int[b_len + 1];
    }

    for (int i = 0; i <= a_len; i++)
    {
        for (int j = 0; j <= b_len; j++)
        {
            count_string[i][j] = 0;
        }
    }

    for (int i = 1; i <= a_len; i++)
    {
        for (int j = 1; j <= b_len; j++)
        {
            if (A_string[i - 1] == B_string[j - 1])
                count_string[i][j] = count_string[i - 1][j - 1] ;
            else
                count_string[i][j] = min(count_string[i][j - 1], count_string[i - 1][j]) + 2;
        }
    }

    cout << count_string[a_len][b_len] << endl;

    for (int i = 0; i <= a_len; i++)
    {
        delete[] count_string[i];
    }
    delete[] count_string;

    return 0;
}
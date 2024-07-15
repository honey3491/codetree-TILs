#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    return 0;
}#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> selected_nums;

void PrintPermutation() {
    for (int i = 0; i < (int)selected_nums.size(); i++)
        cout << selected_nums[i] << " ";
    cout << endl;
}

void FindPermutations(int cnt) {
    if (selected_nums.size() == n) {
        PrintPermutation();
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (selected_nums.empty() || i > selected_nums.back())
        {
            selected_nums.push_back(i);
            FindPermutations(cnt + 1);
            selected_nums.pop_back();
        }
    }

    return;
}

int main() {
    cin >> m >> n;

    FindPermutations(0);
    return 0;
}
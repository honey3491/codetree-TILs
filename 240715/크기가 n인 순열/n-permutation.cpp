#include <iostream>
#include <vector>

using namespace std;

int N, visited[9] = { 0, };
vector<int> selected_nums;

void PrintPermutation() {
    for (int i = 0; i < (int)selected_nums.size(); i++)
        cout << selected_nums[i] << " ";
    cout << endl;
}

void FindPermutations(int cnt) {
    if (cnt == N) {
        PrintPermutation();
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            selected_nums.push_back(i);
            visited[i] = 1;
            FindPermutations(cnt + 1);
            selected_nums.pop_back();
            visited[i] = 0;
        }
    }

    return;
}

int main() {
    cin >> N;

    FindPermutations(0);
    return 0;
}
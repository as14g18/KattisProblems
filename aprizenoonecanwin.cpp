#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("C:\\Users\\Akhilesh\\Desktop\\input.txt", "r", stdin);

    int N, T;
    cin >> N >> T;

    // Edge cases
    if (N == 0) {
        cout << 0;
        return 0;
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    vector<int> A (N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int output = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] + A[i+1] <= T) {
            output++;
        } else {
            break;
        }
    }

    cout << output + 1;

    return 0;
}

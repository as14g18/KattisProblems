#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> M;
    int N;
    cin >> N;

    int best = N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (M.count(x)) {
            best = min(best, i - M[x]);
        }

        if (best == 1) break;

        M[x] = i;
    }

    cout << best;

    return 0;
}

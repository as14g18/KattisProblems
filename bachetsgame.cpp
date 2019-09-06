#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        // get input
        int M;
        cin >> M;
        vector<int> stones (M);
        for (int i = 0; i < M; i++) {
            cin >> stones[i];
        }


        // solve
        N++;
        vector<int> DP (N, -1);
        DP[0] = 0;
        DP[1] = 1;

        for (int i = 2; i < N; i++) {
            bool winningState = false;
            for (auto s : stones) {
                if (i - s >= 0 && DP[i - s] == 0) {
                    winningState = true;
                    break;
                }
            }

            DP[i] = winningState;
        }

        if (DP[N-1]) {
            cout << "Stan wins\n";
        } else {
            cout << "Ollie wins\n";
        }
    }

    return 0;
}

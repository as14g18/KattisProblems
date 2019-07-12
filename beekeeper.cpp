#include <iostream>

using namespace std;

char VOWELS[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

int main()
{
    freopen("C:\\Users\\Akhilesh\\Desktop\\input.txt", "r", stdin);

    int N;
    cin >> N;

    while (N != 0) {
        string bestString = "";
        int best = 0;

        for (int i = 0; i < N; i++) {
            string S;
            cin >> S;

            if (bestString.size() == 0)
                bestString = S;

            int current = 0;
            for (int j = 0; j < S.size() - 1; j++) {
                for (char v : VOWELS) {
                    if (S[j] == v && S[j+1] == v)
                        current++;
                }
            }

            if (current > best) {
                best = current;
                bestString = S;
            }
        }

        cout << bestString << "\n";
        cin >> N;
    }

    return 0;
}

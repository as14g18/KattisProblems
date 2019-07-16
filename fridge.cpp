#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int,int> PI;

void addChar(priority_queue<PI, vector<PI>, greater<PI> > &PQ, string &S) {
    PI P = PQ.top();
    S += (char)P.second+'0';
    PQ.pop();
    PQ.push({P.first-1, P.second});
}

int main()
{
    unordered_map<int, int> M;

    string S;
    cin >> S;

    for (auto c : S) {
        M[c-'0']++;
    }

    priority_queue<PI, vector<PI>, greater<PI> > PQ;

    for (int i = 0; i <= 9; i++) {
        PQ.push({M[i], i});
    }

    string output = "";

    PI zero;
    bool zeroed = false;
    if (PQ.top().second == 0) {
        zero = PQ.top();
        zeroed = true;
    }

    if (zeroed) {
        PQ.pop();
        addChar(PQ, output);
        PQ.push(zero);
    }

    while (PQ.top().first >= 0) {
        addChar(PQ, output);
    }

    cout << output;

    return 0;
}

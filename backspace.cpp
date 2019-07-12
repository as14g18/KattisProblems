#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string S;
    cin >> S;

    stack<char> A;

    for (char c : S) {
        if (c == '<' && !A.empty()) {
            A.pop();
        } else {
            A.push(c);
        }
    }

    stack<char> R;

    while (!A.empty()) {
        R.push(A.top());
        A.pop();
    }

    while (!R.empty()) {
        cout << R.top();
        R.pop();
    }


    return 0;
}

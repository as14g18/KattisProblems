#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("C:\\Users\\Akhilesh\\Desktop\\input.txt", "r", stdin);

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

        // cout << DP[N-1] << "\n";


    }

    return 0;
}
/*
#include<cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    int a[10];
    vector<int> dp (30, -1);

    while(scanf("%d %d",&n,&m)==2){
        for(int i=0;i<m;i++) scanf("%d",&a[i]);

        dp[0]=false;
        for(int i=1;i<=n;i++){
            dp[i]=false;

            for(int j=0;j<m;j++)
                if(i>=a[j] && !dp[i-a[j]]){
                    dp[i]=true;
                    break;
                }
        }

        for (auto x : dp) {
            cout << x << " ";
        }
        cout << "\n";

        if(dp[n]) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }

    return 0;
}
*/

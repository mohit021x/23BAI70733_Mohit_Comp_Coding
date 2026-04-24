#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    
    double totalB = 0;
    for(int i = 0; i < n; i++) totalB += b[i];
    
    int maxA = 0;
    for(int i = 0; i < n; i++) maxA += a[i];
    
    vector<vector<long long>> dp(n+1, vector<long long>(maxA+1, -1));
    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++){
        for(int k = min(i, n-1); k >= 0; k--){
            for(int sa = 0; sa + a[i] <= maxA; sa++){
                if(dp[k][sa] < 0) continue;
                dp[k+1][sa+a[i]] = max(dp[k+1][sa+a[i]], dp[k][sa] + b[i]);
            }
        }
    }
    
    cout << fixed << setprecision(9);
    for(int k = 1; k <= n; k++){
        double best = 0;
        for(int sa = 0; sa <= maxA; sa++){
            if(dp[k][sa] < 0) continue;
            double water = min((double)sa, totalB/2.0 + dp[k][sa]/2.0);
            best = max(best, water);
        }
        cout << best;
        if(k < n) cout << " ";
    }
    cout << "\n";
}
#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& h, long long H){
    long long need_odd = 0, need_even = 0;
    for(auto x : h){
        long long diff = H - x;
        need_odd += diff % 2;
        need_even += diff / 2;
    }
    long long lo = 0, hi = 3e14;
    while(lo < hi){
        long long mid = (lo + hi) / 2;
        long long odd_days = (mid + 1) / 2;
        long long even_days = mid / 2;
        if(odd_days >= need_odd && even_days + (odd_days - need_odd) / 2 >= need_even)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<long long> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        long long mx = *max_element(h.begin(), h.end());
        cout << min(solve(h, mx), solve(h, mx + 1)) << "\n";
    }
}
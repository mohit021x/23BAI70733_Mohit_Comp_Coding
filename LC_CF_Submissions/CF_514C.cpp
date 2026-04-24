#include<bits/stdc++.h>
using namespace std;

const long long MOD1 = 1e9+7;
const long long MOD2 = 1e9+9;
const long long BASE1 = 131;
const long long BASE2 = 137;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    set<pair<long long,long long>> st;
    
    vector<string> strs(n);
    for(int i = 0; i < n; i++){
        cin >> strs[i];
        long long h1 = 0, h2 = 0;
        for(char c : strs[i]){
            h1 = (h1 * BASE1 + c) % MOD1;
            h2 = (h2 * BASE2 + c) % MOD2;
        }
        st.insert({h1, h2});
    }
    
    vector<long long> pw1(600001), pw2(600001);
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i <= 600000; i++){
        pw1[i] = pw1[i-1] * BASE1 % MOD1;
        pw2[i] = pw2[i-1] * BASE2 % MOD2;
    }
    
    while(m--){
        string s;
        cin >> s;
        int len = s.size();
        
        long long h1 = 0, h2 = 0;
        for(char c : s){
            h1 = (h1 * BASE1 + c) % MOD1;
            h2 = (h2 * BASE2 + c) % MOD2;
        }
        
        bool found = false;
        for(int i = 0; i < len && !found; i++){
            for(char c = 'a'; c <= 'c' && !found; c++){
                if(c == s[i]) continue;
                long long nh1 = (h1 - (long long)s[i] * pw1[len-1-i] % MOD1 + MOD1) % MOD1;
                long long nh2 = (h2 - (long long)s[i] * pw2[len-1-i] % MOD2 + MOD2) % MOD2;
                nh1 = (nh1 + (long long)c * pw1[len-1-i]) % MOD1;
                nh2 = (nh2 + (long long)c * pw2[len-1-i]) % MOD2;
                if(st.count({nh1, nh2})) found = true;
            }
        }
        
        cout << (found ? "YES" : "NO") << "\n";
    }
}
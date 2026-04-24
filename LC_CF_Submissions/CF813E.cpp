#include<bits/stdc++.h>
using namespace std;

const int MAXNODES = 30*100000+30;
int lc[MAXNODES], rc[MAXNODES], cnt[MAXNODES];
int roots[100002];
int node_cnt = 1;

int update(int prev, int l, int r, int val){
    int cur = node_cnt++;
    lc[cur] = lc[prev];
    rc[cur] = rc[prev];
    cnt[cur] = cnt[prev] + 1;
    if(l == r) return cur;
    int mid = (l+r)/2;
    if(val <= mid) lc[cur] = update(lc[prev], l, mid, val);
    else rc[cur] = update(rc[prev], mid+1, r, val);
    return cur;
}

int query(int node, int l, int r, int ql, int qr){
    if(!node || ql > qr) return 0;
    if(ql <= l && r <= qr) return cnt[node];
    int mid = (l+r)/2;
    int res = 0;
    if(ql <= mid) res += query(lc[node], l, mid, ql, qr);
    if(qr > mid) res += query(rc[node], mid+1, r, ql, qr);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n+1);
    map<int, vector<int>> pos;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    vector<int> prev_k(n+1, 0);
    for(auto& [type, vec] : pos){
        for(int j = 0; j < (int)vec.size(); j++){
            if(j >= k) prev_k[vec[j]] = vec[j-k];
        }
    }
    
    int MAXV = n+1;
    roots[0] = 0;
    for(int i = 1; i <= n; i++){
        roots[i] = update(roots[i-1], 0, MAXV, prev_k[i]);
    }
    
    int q;
    cin >> q;
    
    long long last = 0;
    while(q--){
        long long x, y;
        cin >> x >> y;
        int l = (x + last) % n + 1;
        int r = (y + last) % n + 1;
        if(l > r) swap(l, r);
        int ans = query(roots[r], 0, MAXV, 0, l-1) - query(roots[l-1], 0, MAXV, 0, l-1);
        last = ans;
        cout << ans << "\n";
    }
}
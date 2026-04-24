#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<pair<long long,int>> events;
    
    for(int i=0;i<n;i++){
        long long l,r;
        cin>>l>>r;
        events.push_back({l,1});
        events.push_back({r+1,-1});
    }
    
    sort(events.begin(),events.end());
    
    vector<long long> ans(n+1,0);
    
    long long prev_x=0;
    int cur=0;
    bool first=true;
    
    for(int i=0;i<(int)events.size();){
        long long x=events[i].first;
        
        if(!first && cur>=1 && cur<=n){
            ans[cur]+=x-prev_x;
        }
        
        while(i<(int)events.size() && events[i].first==x){
            cur+=events[i].second;
            i++;
        }
        
        prev_x=x;
        first=false;
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i];
        if(i<n) cout<<" ";
    }
    cout<<"\n";
}
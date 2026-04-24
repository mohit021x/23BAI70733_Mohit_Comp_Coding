#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
        
        bool special[8001]={};
        
        for(int l=0;l<n;l++){
            for(int r=l+1;r<n;r++){
                int s=pre[r+1]-pre[l];
                if(s>n) break;
                special[s]=true;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(special[a[i]]) ans++;
        }
        cout<<ans<<"\n";
    }
}
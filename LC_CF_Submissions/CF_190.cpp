#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> words;
    string w;
    while(cin>>w) words.push_back(w);
    
    int idx=0;
    string result="";
    
    function<bool()> parse=[&]()->bool{
        if(idx>=(int)words.size()) return false;
        string cur=words[idx++];
        if(cur=="int"){
            result+="int";
            return true;
        } else if(cur=="pair"){
            result+="pair<";
            if(!parse()) return false;
            result+=",";
            if(!parse()) return false;
            result+=">";
            return true;
        }
        return false;
    };
    
    if(!parse() || idx!=(int)words.size()){
        cout<<"Error occurred\n";
    } else {
        int cnt=0;
        for(auto& s:words) if(s=="int") cnt++;
        if(cnt!=n) cout<<"Error occurred\n";
        else cout<<result<<"\n";
    }
}
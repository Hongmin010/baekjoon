#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
void check();
using namespace std;
string s,b,ans;
stack<char> st;
int main(void){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>s>>b;
    for(int i=0;i<s.size();i++){
        st.push(s.at(i));
        if(st.size()>=b.size()){
            if(st.top()==b.at(b.size()-1)) check();
        }
    }
    if(st.empty()) cout<<"FRULA";
    else{
        int t=st.size();
        for(int i=0;i<t;i++){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
    return 0;
}

void check(){
    string tmp;
    bool s=true;
    for(int i=0;i<b.size();i++){
                tmp.push_back(st.top());
                st.pop();
                if(tmp.at(tmp.size()-1)!=b.at(b.size()-1-i)){
                    s=false;
                    break;
                }   
            }
    if(s) return;
    for(int i=(tmp.size()-1);i>-1;i--){
        st.push(tmp.at(i));
    }
}
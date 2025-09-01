#include<iostream>
#include<string>
#include<sstream>
#include<deque>
using namespace std;
void test(void);
int T,n;
bool q=true;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin>>T;
    for(int i=0;i<T;i++){
        test();
        q=true;
    }
    return 0;
}

void test(void){
    deque<int> deq;
    string S,arr;
        cin>>S>>n>>arr;
        string t;
        int N;
        arr=arr.substr(1);
        stringstream ss(arr);
        while(getline(ss,t,',')){
            stringstream s(t);
            while(s>>N) deq.push_back(N);
        }
        cin.ignore();
        for(int i=0;i<S.size();i++){
            if(S[i]=='R') q=!q;
            else if(q){
                if(deq.empty()) {cout<<"error"<<endl; return;}
                else deq.pop_front();
            }
            else{
                if(deq.empty()) {cout<<"error"<<endl; return;}
                else deq.pop_back();
            }
        }
        if(deq.empty()){
            cout<<"[]"<<endl;
            return;
        }
        cout<<"[";
        if(q){
            cout<<deq.front();
            deq.pop_front();
            while(!deq.empty()){
            cout<<","<<deq.front();
            deq.pop_front();
            }}
        else{
            cout<<deq.back();
            deq.pop_back();
            while(!deq.empty()){
                cout<<","<<deq.back();
                deq.pop_back();
            }}
        cout<<"]"<<endl;
    }
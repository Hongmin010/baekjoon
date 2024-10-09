#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(void){
    priority_queue <int,vector<int>,greater<int>> pq;
    int N,tmp,a,b,ans=0;
    cin>>N;
    if(N==1) {cout<<0; return 0;}
    for(int i=0;i<N;i++){
        cin>>tmp;
        pq.push(tmp);
    }
    while(1){
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        tmp=a+b;
        ans+=tmp;
        pq.push(tmp);
        if(pq.size()==1) {
            cout<<ans;
            return 0;
        }
    }
    



    return 0;
}



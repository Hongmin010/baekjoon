#include<iostream>
using namespace std;

int N;
long long dpl[100001];
long long dpr[100001];
long long ndp[100001];
int main(void){
    cin>>N;
    dpl[1]=1;
    dpr[1]=1;
    ndp[1]=1;
    dpl[2]=2;
    dpr[2]=2;
    ndp[2]=3;
    for(int i=3;i<=N;i++){
        dpl[i]=dpr[i-1]+ndp[i-1];
        dpr[i]=dpl[i-1]+ndp[i-1];
        ndp[i]=dpr[i-1]+dpl[i-1]+ndp[i-1];
        dpl[i]=dpl[i]%9901;
        ndp[i]=ndp[i]%9901;
        dpr[i]=dpr[i]%9901;
    }
    cout<<(dpr[N]+ndp[N]+dpl[N])%9901;

    return 0;
}



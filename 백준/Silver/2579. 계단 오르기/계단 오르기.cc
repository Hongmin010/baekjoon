#include<iostream>
using namespace std;

int num[301];
int sel[301];
int nsel[301];
int main(void){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num[N-i];
    }
    if(N<3){
        int k=0;
        for(int i=1;i<=N;i++) k+=num[i];
        cout<<k;
        return 0;
    }
    sel[1]=num[1];
    sel[2]=sel[1]+num[2];
    nsel[2]=sel[1];
    sel[3]=sel[1]+num[3];
    nsel[3]=max(sel[2],nsel[2]);
    for(int i=4;i<=N;i++){
        nsel[i]=sel[i-1];
        sel[i]=max(nsel[i-1]+num[i],nsel[i-2]+num[i-1]+num[i]);
    }
    cout<<max(sel[N],nsel[N]);
   return 0;
}
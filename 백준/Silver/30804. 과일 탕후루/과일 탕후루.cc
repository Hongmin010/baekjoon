#include<iostream>
#include<algorithm>
using namespace std;
int arr[200000];

int main(void) {
    int f=-1,s,n=1,num=0,N,t=1;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    s=arr[0];
    for(int i=1;i<N;i++){
        if(arr[i]!=f and arr[i]!=s){
            f=arr[i-1];
            s=arr[i];
            if(n>num) num=n;
            if(t>1) n=t+1;
            else n=2;
        }
        else n++;
        if(arr[i]==arr[i-1]) t++;
        else t=1;
    }
    if(n>num) num=n;
    cout<<num;


    return 0;
}




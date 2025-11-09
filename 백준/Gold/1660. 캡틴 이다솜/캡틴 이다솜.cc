#include <iostream>
using namespace std;
int N,k;
int a[121];
int arr[300001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<=N;i++){
        arr[i]=1000000;
    }
    for(int i=1;i<122;i++){
        a[i]=i*(i+1)*(i+2)/6;
        arr[a[i]]=1;
        if(a[i]>N){
            k=i-1;
            break;
        }
    }
    for(int i=0;i<N+1;i++){
        for(int j=0;j<=k;j++){
            if(a[j]>i) break;
            arr[i]=min(arr[i],arr[i-a[j]]+1);
        }
    }
    cout<<arr[N];

    return 0;
}


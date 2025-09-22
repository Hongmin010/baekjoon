#include<iostream>
using namespace std;
int T,n;
int arr[2][100000];
int udp[100000];
int ddp[100000];
int ndp[100000];
int     main(void){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[0][j];
        }
        for(int j=0;j<n;j++){
            cin>>arr[1][j];
        }
        udp[0]=arr[0][0];
        ddp[0]=arr[1][0];
        for(int i=1;i<n;i++){
            udp[i]=max(ddp[i-1],ndp[i-1])+arr[0][i];
            ddp[i]=max(udp[i-1],ndp[i-1])+arr[1][i];
            ndp[i]=max(ddp[i-1],udp[i-1]);
        }
        cout<<max(ddp[n-1],max(udp[n-1],ndp[n-1]))<<"\n";
    }

    return 0;
}


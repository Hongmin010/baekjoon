#include<iostream>
#include<algorithm>
using namespace std;
int N,c,minn=10000000,minC;
pair<int,int> hotel[21];
int money[1100];
int main(void){
    cin>>c>>N;
    for(int i=0;i<N;i++){
        cin>>hotel[i].second>>hotel[i].first;
    }
    sort(hotel,hotel+N);
    for(int i=1;i<c+100;i++){
        minC=10000000;
        for(int j=0;j<N;j++){
            if(i-hotel[j].first<0) break;
            if(minC>money[i-hotel[j].first]+hotel[j].second) minC=money[i-hotel[j].first]+hotel[j].second;
        }
        money[i]=minC;
    }
    for(int i=c;i<c+100;i++){
        if(minn>money[i]) minn=money[i];
    }
    cout<<minn;
    return 0;
}







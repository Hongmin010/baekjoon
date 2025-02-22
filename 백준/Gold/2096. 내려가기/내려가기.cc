#include<iostream>
using namespace std;

int N;
int mn[3];
int tmp[3];
int mx[3];
int a,b,c;
int main(void){
    cin>>N;
    cin>>mn[0]>>mn[1]>>mn[2];
    mx[0]=mn[0];
    mx[1]=mn[1];
    mx[2]=mn[2];
    for(int i=0;i<N-1;i++){
        cin>>a>>b>>c;
        tmp[0]=max(mx[0],mx[1]);
        tmp[1]=max(tmp[0],mx[2]);
        tmp[2]=max(mx[1],mx[2]);
        mx[0]=tmp[0]+a;
        mx[1]=tmp[1]+b;
        mx[2]=tmp[2]+c;
        tmp[0]=min(mn[0],mn[1]);
        tmp[1]=min(tmp[0],mn[2]);
        tmp[2]=min(mn[1],mn[2]);
        mn[0]=tmp[0]+a;
        mn[1]=tmp[1]+b;
        mn[2]=tmp[2]+c;
    }
    cout<<max(max(mx[0],mx[1]),mx[2])<<" "<<min(min(mn[0],mn[1]),mn[2]);
    return 0;
}






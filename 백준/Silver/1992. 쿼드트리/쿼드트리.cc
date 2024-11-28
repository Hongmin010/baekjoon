#include<iostream>
#include<math.h>
using namespace std;

void quad(int,int,int,int,int);
char **a;
int main(void){
    int N;
    cin>>N;
    a= new char *[N];
    for(int i=0;i<N;i++) a[i]=new char[N];
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            cin>>a[i][j];
        }
    }
   
    quad(N,0,N-1,0,N-1);
}

void quad(int N,int x1,int x2,int y1,int y2){
    int b=0,w=0;
    for(int i=y1;i<=y2;i++){
        for(int j=x1;j<=x2;j++){
            if(a[i][j]=='1'){
                b++;
            }
            else{
                w++;
            }
        }
    }
    if(b==0 or w==0){
         if(!b){
            cout<<"0";
            return;
         }
         else{
            cout<<"1";
            return;
         }
    }
    cout<<"(";
    quad(N/2,x1,x1+N/2-1,y1,y1+N/2-1);
    quad(N/2,x1+N/2,x2,y1,y1+N/2-1);
    quad(N/2,x1,x1+N/2-1,y1+N/2,y2);
    quad(N/2,x1+N/2,x2,y1+N/2,y2);
    cout<<")";
    return;
}

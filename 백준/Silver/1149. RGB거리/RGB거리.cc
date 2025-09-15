    #include<iostream>
    using namespace std;
    int arr[1000][3];
    int N;
    int rdp[1000];
    int gdp[1000];
    int bdp[1000];
    int main(void){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        rdp[0]=arr[0][0];
        gdp[0]=arr[0][1];
        bdp[0]=arr[0][2];
        for(int i=1;i<N;i++){
            rdp[i]=min(gdp[i-1],bdp[i-1])+arr[i][0];
            gdp[i]=min(rdp[i-1],bdp[i-1])+arr[i][1];
            bdp[i]=min(rdp[i-1],gdp[i-1])+arr[i][2];
        }
        cout<<min(min(rdp[N-1],gdp[N-1]),bdp[N-1]);
        return 0;
    }

    

    #include<iostream>
    using namespace std;
    int arr[1000][3];
    int N,m,m1,m2,m3;
    int rdp[1000][3];
    int gdp[1000][3];
    int bdp[1000][3];
    int main(void){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        rdp[0][0]=arr[0][0];
        gdp[0][0]=100000000;
        bdp[0][0]=100000000;
        rdp[0][1]=100000000;
        gdp[0][1]=arr[0][1];
        bdp[0][1]=100000000;
        rdp[0][2]=100000000;
        gdp[0][2]=100000000;
        bdp[0][2]=arr[0][2];
        for(int i=1;i<N;i++){
            rdp[i][0]=min(gdp[i-1][0],bdp[i-1][0])+arr[i][0];
            gdp[i][0]=min(rdp[i-1][0],bdp[i-1][0])+arr[i][1];
            bdp[i][0]=min(rdp[i-1][0],gdp[i-1][0])+arr[i][2];
            rdp[i][1]=min(gdp[i-1][1],bdp[i-1][1])+arr[i][0];
            gdp[i][1]=min(rdp[i-1][1],bdp[i-1][1])+arr[i][1];
            bdp[i][1]=min(rdp[i-1][1],gdp[i-1][1])+arr[i][2];
            rdp[i][2]=min(gdp[i-1][2],bdp[i-1][2])+arr[i][0];
            gdp[i][2]=min(rdp[i-1][2],bdp[i-1][2])+arr[i][1];
            bdp[i][2]=min(rdp[i-1][2],gdp[i-1][2])+arr[i][2];
        }
        m1=min(bdp[N-1][0],gdp[N-1][0]);
        m2=min(rdp[N-1][1],bdp[N-1][1]);
        m3=min(rdp[N-1][2],gdp[N-1][2]);
        m=min(min(m1,m2),m3);
        cout<<m;
        return 0;
    }

    
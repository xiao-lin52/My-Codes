#include<bits/stdc++.h>
using namespace std;
int n;
string a,num[10];
int main()
{
    num[0]="XXXX.XX.XX.XXXX";
    num[1]="..X..X..X..X..X";
    num[2]="XXX..XXXXX..XXX";
    num[3]="XXX..XXXX..XXXX";
    num[4]="X.XX.XXXX..X..X";
    num[5]="XXXX..XXX..XXXX";
    num[6]="XXXX..XXXX.XXXX";
    num[7]="XXX..X..X..X..X";
    num[8]="XXXX.XXXXX.XXXX";
    num[9]="XXXX.XXXX..XXXX";
    cin>>n>>a;
    for(int i=1;i<=5;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=(i-1)*3;k<=i*3-1;k++)
                cout<<num[a[j]-'0'][k];
            if(j!=n-1)
                cout<<".";
        }
        cout<<endl;
    }
    return 0;
}

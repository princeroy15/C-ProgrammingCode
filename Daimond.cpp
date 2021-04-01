#include<iostream>
using namespace std;

int main()
    {
        int n,i,j;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=2*n-1;j++)
            {
                if(j>=n-(i-1) && j<=n+(i-1))
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<endl;
        }
        for(i=n-1;i>=1;i--)
        {
            for(j=1;j<=2*n-1;j++)
            {
                if(j>=n-(i-1) && j<=n+(i-1))
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<endl;
        }
        return 0;
    }

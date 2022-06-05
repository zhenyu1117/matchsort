#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000 
int dp[N][N];
char a[N],b[N];
void match(char *s,char *s1,int lena,int lenb)
{
    int i,j,inserts,deletes,replaces;
    for(i=1;i<=lena;i++)
    {
        dp[i][0]=i;
    }
    for(j=1;j<=lenb;j++)
    {
        dp[0][j]=j;
    }
    for(i=1;i<=lena;i++)
    {
        for(j=1;j<=lenb;j++)
        {
            inserts=dp[i][j-1]+1;
            deletes=dp[i-1][j]+1;
            replaces;
            if(s[i-1]==s1[j-1])
            {
                replaces=dp[i-1][j-1];
            }
            else
            {
                replaces=dp[i-1][j-1]+1;
            }
            dp[i][j]=min(min(inserts,deletes),replaces);
        }
    }
    cout<<dp[lena][lenb]<<endl;
}
int main()
{
    int la,lb;
    while(cin>>la>>a)
    {
        cin>>lb>>b;
        match(a,b,la,lb);
    }
    return 0;
}

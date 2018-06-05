#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
long long int bottom_top();
int s[500005],k[30];
long long int dp[15][500005];
int n,m;
int main(){
    long long int x=1,r,res;
    int c,i,j,count,y;
      char a[500005];
      scanf("%s",a);
    for(i=0;a[i];i++){
        s[i]=a[i]-'0';    
    }  
    n=i;
    res=0;
    k[0]=1;
    m=1;
    res=bottom_top();   
    for(i=1;i<=32;i++){
        x=x*2;
        r=x;
        count=0;
        for(j=0;j<10;j++){
            y=r%10;
            k[j]=y;
            r-=y;
            r=r/10;
            count++;
            if(r==0)
                break;
        }
        k[j+1]='\0';
        reverse(k,k+count);
        m=count;
        res=(res+bottom_top())%1000000007;
    }
    printf("%lld\n",res);
     return 0;
}


long long int bottom_top(){
    int i,j;
    for(i=0;i<=m;i++)
            dp[i][n]=0;
    for(i=0;i<=n;i++)
            dp[m][i]=1;
    for(i=m-1;i>=0;i--){
        for(j=n-1;j>=0;j--){
            if(s[j]!=k[i])
                dp[i][j]=dp[i][j+1];
            else
                dp[i][j]=(dp[i+1][j+1]+dp[i][j+1])%1000000007;
        }
    }
    return dp[0][0];
}

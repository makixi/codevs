#include<cstdio>
int n,max=0,s1,s2,f[510][510];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
			scanf("%d",&f[i][j]);
			f[j][i]=f[i][j];
		}
    for(int i=1;i<=n;i++){
        s1=s2=0;
        for(int j=1;j<=n;j++)
            if(f[i][j]>s1){ 
				s2=s1; 
				s1=f[i][j]; 
			}
            else if(f[i][j]>s2) s2=f[i][j];
        if(s2>max) max=s2;
    }
    printf("1\n%d",max);
    return 0;
}

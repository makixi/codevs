#include<cstdio>
#include<cstring>
int main(){
	char c,s[2000003],sk[2000003];
	int N,i;
	scanf("%d\n",&N);
	while(N--){
		scanf("%s",s);
		int l=strlen(s),top=0;
		sk[top]='A';
		for(i=0;i<l;){
			if((s[i]==sk[top]+1||s[i]==sk[top]+2)&&top){
				top--;i++;
			}else if((s[i]==sk[top]+1||s[i]==sk[top]+2)&&top==0){
				sk[top]='A';i++;
			}else if(sk[top]=='A'){
				sk[top]=s[i];
				i++;
			}else {
				top++;
				sk[top]=s[i];
				i++;
			}
		}
		if(sk[top]=='A')printf("TRUE\n");else printf("FALSE\n");
	}
	return 0;
}

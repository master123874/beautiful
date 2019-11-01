#include <stdio.h>
#include <string.h>
int main(){
	int n,i,j;
	int len,flagA,flagB;
	int count,pos;
	char s[101];
	scanf("%d",&n);
	getchar();	
	for(i=0;i<n;i++){
		len=0,flagA=0,flagB=0,count=0;
		gets(s);
		len=strlen(s);	
		for(j=0;j<len;j++){
			if(s[j]==','&&s[j-3]=='o'&&s[j-2]=='n'&&s[j-1]=='g')
				flagA=1;
			if(s[j]=='.'&&s[j-3]=='o'&&s[j-2]=='n'&&s[j-1]=='g')
				flagB=1;
		}
		if(flagA==1&&flagB==1){
			for(j=len-1;j>=0;j--){	
				if(s[j]==' ')	
					count++;
				if(count==3){
					pos=j;	
					break;
				}
			}
			for(j=0;j<=pos;j++){
				printf("%c",s[j]);
			}
			printf("qiao ben zhong.\n");
		}else{
			printf("Skipped\n");
		}
	}
	return 0;
} 


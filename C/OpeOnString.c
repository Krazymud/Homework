#include <stdio.h>
#include <string.h>
int split(char ret[][100], const char str[], const char del);
void lstrip(char str[], const char del);
void rstrip(char str[], const char del);
void strip(char str[], const char del);
int main(){
  	int n,j;
  	char deli;
	char split_string[100];
  	scanf("%s",split_string);getchar();
  	deli=getchar();getchar();
  	
  	char string_f[20][100];
  	j=split(string_f, split_string, deli);
  	for(n=0; n<=j; n++)
      	printf("%s\n",string_f[n]);
  	char strip_0[100];
    char ch;
    scanf("%[^\n]",strip_0);getchar();
    scanf("%c",&ch);getchar();
    lstrip(strip_0,ch);
  	rstrip(strip_0,ch);
    char strip_1[100];
    char cha;
    scanf("%[^\n]",strip_1);getchar();
  	scanf("%c",&cha);
    strip(strip_1,cha);
}
int split(char ret[][100], const char str[], const char del){
  	int n,j=0,h=0,i,x;
  	for(n=0; n<strlen(str); n++)
    {
      	if(str[n]==del){
          	for(i=h,x=0; i<n;x++,i++)
              	ret[j][x]=str[i];
          	h=n+1;
          	j++;
        }
      	else if(n==strlen(str)-1)
						for(i=h,x=0; i<=n;x++,i++)
              	ret[j][x]=str[i];
        
    }
  	return j;
}
void lstrip(char str[], const char del){
  	int n,i,j;
  	for(n=0; n<strlen(str); n++)
      	if(str[n]!=del){
          	i=n;
  					break;
        }
  	for(n=0,j=i; n<strlen(str)-i; j++,n++){
      	str[n]=str[j];
  			printf("%c",str[n]);
    }
  	printf("\n");
}
void rstrip(char str[], const char del){
		int n,i;
  	for(n=0; n<strlen(str); n++)
      	if(str[n] != del)
          	i=n;
  	for(n=0; n<=i; n++)
  			printf("%c",str[n]);
  	printf("\n");
}
void strip(char str[], const char del){
  	int n,i,j;
  	for(n=0; n<strlen(str); n++)
      	if(str[n] != del){
          	i=n;
          	break;
        }
 		for(n=0; n<strlen(str); n++)
      	if(str[n] != del)
  					j=n;
  	for(n=i; n<=j; n++)
      	printf("%c",str[n]);
  	printf("\n");
}

#include <stdio.h>
void output(int n){ //������� 
	if(n>=0 && n<=9)
		printf("%d",n);
	else if(n<0 && n>=-9)
		printf("%d",n); 
	else{
		switch(n)
		{
			case 10: printf("A");break;
			case 11: printf("B");break;
			case 12: printf("C");break;
			case 13: printf("D");break;
			case 14: printf("E");break;
			case 15: printf("F");break;
			case -10: printf("-A");break;
			case -11: printf("-B");break;
			case -12: printf("-C");break;
			case -13: printf("-D");break;
			case -14: printf("-E");break;
			case -15: printf("-F");break;
		}
	}
}
int change(int number){//תΪ16���Ʋ���� 
	int quotient, remainder, i, count_l=0;
	int count[50]={0};
	quotient=number/16;
	remainder=number%16;
	count[0]=remainder;
	if(quotient==0)
		output(remainder);
	else{
		for(i=1; quotient!=0; i++){
			remainder=quotient%16;
			quotient=quotient/16;
			count[i]=remainder;
			count_l++;
		}
		for(i=count_l; i>=0; i--)
			output(count[i]);
	}
}
int main (){//��ȡ���� 
	int number;
	scanf("%d",&number);
	change(number);
}

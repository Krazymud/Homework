#include <stdio.h>
int main (void)
{
	int n=0,j=0,i=0,max=0,words=0,string[123]={0};	
	char letter;
	while((letter=getchar())!=EOF)//count letters,words
	{
			string[letter]++;
			max = (max<string[letter]) ? string[letter]: max;
			if(letter== ' '||letter== '\n')
				i=0;
			else if(i==0){
				i=1;
				words++;
				max=(max<words)? words:max;
				}		
	}
	for(n=max;n>0;n--)//the histogram
	{
		printf("%d\t",n);
			for(j=97;j<123;j++)
			{
				if(string[j]>0)
				{
					if(string[j]>=n)
						printf("*");
					else
						printf(" ");
				}
			}
		if(words >=n)
			printf("*");
		else
			printf(" ");
		printf("\n");
	}
	printf(" \t");
	for(n=97;n<123;n++)
	{
		if(string[n] !=0)
			printf("%c",n);
	}
	printf("W\n");
}

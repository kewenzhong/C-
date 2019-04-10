#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int next[20] ;

void getNext(char * p, int * next)
{
	next[0] = -1;
	int i = 0, j = -1;
 
	while (i < strlen(p))
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}


int KMP(char * t, char * p) 
{
	int i = 0; 
	int j = 0;
 
	while (i < strlen(t) && j < strlen(p))
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
           	j++;
		}
	 	else 
           	j = next[j];
    }
 
    if (j == strlen(p))
       return i - j ;
    else 
       return -1 ;
}

int main(){
	char t[20],p[20] ;

	scanf("%s",t) ;
	scanf("%s",p) ;

	getNext(p,next) ;
	int res = KMP(t,p) ;
	printf("%d",res) ;
	return 0;
}

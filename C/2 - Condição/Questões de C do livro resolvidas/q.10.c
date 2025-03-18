#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	struct tm *dha;
	time_t s;
	time (&s);
	dha = localtime(&s);
	int d,m,a;
	printf("insira um dia entre 1 a 31:");
	scanf("%d",&d);
	printf("insira um mes entre 1 a 12:");
	scanf("%d",&m);
	printf("insira um ano:");
	scanf("%d",&a);
	
	if(dha->tm_year+1900 > a){
		printf("%d/%d/%d",dha->tm_mday,dha->tm_mon+1,dha->tm_year+1900);
	}
	else{
		if(dha->tm_year+1900 < a){
			printf("%d/%d/%d",d,m,a);
		}
		else{
			if(dha->tm_mon+1 > m){
				printf("%d/%d/%d",dha->tm_mday,dha->tm_mon+1,dha->tm_year+1900);
			}
			else{
				if(dha->tm_mon+1 < m){
					printf("%d/%d/%d",d,m,a);
				}
				else{
					if(dha->tm_mday > d){
						printf("%d/%d/%d",dha->tm_mday,dha->tm_mon+1,dha->tm_year+1900);
					}
					else{
						printf("%d/%d/%d",d,m,a);
					}
				}
			}
		}
	}
	return 0;
}

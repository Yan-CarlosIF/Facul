#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	struct tm *dha;
	time_t s;
	time (&s);
	dha = localtime(&s);
	int d,m,a,h,mi;
	d = dha->tm_mday;
	m = dha->tm_mon+1;
	a = dha->tm_year+1900;
	h = dha->tm_hour;
	mi = dha->tm_min;
	
	switch(m){
		case 1:
			printf("%d/Janeiro/%d",d,a);
			break;
		case 2:
			printf("%d/Fevereiro/%d",d,a);
			break;
		case 3:
			printf("%d/Marco/%d",d,a);
			break;
		case 4:
			printf("%d/Abril/%d",d,a);
			break;
		case 5:
			printf("%d/Maio/%d",d,a);
			break;
		case 6:
			printf("%d/Junho/%d",d,a);
			break;
		case 7:
			printf("%d/Julho/%d",d,a);
			break;
		case 8:
			printf("%d/Agosto/%d",d,a);
			break;
		case 9:
			printf("%d/Setembro/%d",d,a);
			break;
		case 10:
			printf("%d/Outubro/%d",d,a);
			break;
		case 11:
			printf("%d/Novembro/%d",d,a);
			break;
		case 12:
			printf("%d/Dezembro/%d",d,a);
			break;
			
	default:printf("mes invalido!");
}
	printf("\nHora %d:%d",h,mi);
	return 0;
}

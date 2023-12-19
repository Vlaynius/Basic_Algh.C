#include <stdio.h>

int main(){
float A,pi = 1;
int taban = 3;
int N =10;
int i;

for(i=1; i<N ; i++)
{
	A = -1 * (1/taban);
	pi= pi + A;
	taban= taban +2;
}
printf("\n pi =  %d");


pi = 4 * pi;

return 0;
}

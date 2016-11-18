#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void myqsort(int k[], int s, int t);

int main() {

	int k[MAX];
	srand(time(NULL));
	int i;
	/*k[0] = 12;*/
	/*k[1] = 12;*/
	/*k[2] = 1;*/
	/*k[3] = 2;*/
	/*k[4] = 4;*/
	/*k[5] = 62;*/
	/*k[6] = 13;*/
	/*k[7] = 32;*/
	/*k[8] = 42;*/
	/*k[9] = 92;*/
	for (i = 0; i < MAX; i++) {
		k[i] = rand()%MAX +1;
	}
	myqsort(k,0,MAX-1);
	for (i = 0; i < MAX; i++) {
		printf("%d ",k[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void myqsort(int k[], int s, int t)
{
	int i,j;
	if(s < t)
	{
		i = s;
		j = t+1;
		while(1)
		{
			do i++;
			while( !(k[s] <= k[i] || i == t) );
			do j--;
			while( !(k[s] >= k[j] || j == s) );
			if(i < j)
				swap(&k[i],&k[j]);
			else
				break;
		}
		swap(&k[s],&k[j]);
		myqsort(k,s,j-1);
		myqsort(k,j+1,t);
	}
}

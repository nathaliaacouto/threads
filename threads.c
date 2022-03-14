#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int average = 0, minimum = 0, maximum = 0;

void *max(void *input)
{
	int i = 0, aux = 0;
    	sleep(1);
	
    	for (i = 0; i < 10; i++) {
	   	if (aux > i) {
			maximum = aux;
		}  
		aux = i;
    	}
	
    	return NULL;
}

void *min(void *input)
{
	int i = 0, aux = 0;
    	sleep(1);
	
    	for (i = 0; i < 10; i++) {
	   	if (aux < i) {
			minimum = aux;
		}  
		aux = i;
    	}
	
    	return NULL;
}

void *aver(void *input)
{
	int i = 0, aux = 0;
    	sleep(1);
	
    	for (i = 0; i < 10; i++) {
		aux += i;
    	}
	average = (aux/10);
	
    	return NULL;
}
   
int main()
{
	//create thread
	pthread_t thread[3];
	
	for (int i = 0; i < 3; i++) {
        	pthread_join(thread[i], NULL);
    	}
	
	int i = 0, numbers = 0;
	scanf("%d", &numbers);
	int input[numbers];
	for (i = 0; i < numbers; i++) {
		scanf("%d", &input[i]);
	}
	

	//thread 1
    	pthread_create(&thread[0], NULL, aver, NULL);
	printf("The average value is ");
	aver(input);

	//thread 2
    	pthread_create(&thread[1], NULL, min, NULL);
	printf("The minimum value is ");
	min(input);

	//thread 3
    	pthread_create(&thread[2], NULL, max, NULL);
	printf("The maximum value is ");
	max(input);
	
	
    	exit(0);
}
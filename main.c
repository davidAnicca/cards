#include <stdio.h>
#include <stdlib.h>

struct Queue{
	char q[100];
	int start;
	int end;
};

struct Array{
	char* elements;
	int lenght;
};

void AddToQueue(char elem, struct Queue* queue)
{
	queue->end++;
	queue->q[queue->end] = elem;
}

char PopFromQueue(struct Queue* queue)
{
	if(queue->start > queue->end) return 'a';
	char elem = queue->q[queue->start];
	queue->start++;
	return elem;
}

void IsValidArray(struct Array* array)
{
	struct Queue queue;
	queue.start = 0;
	queue.end = -1;
	for(int i = 0; i < array->lenght; i++){
		AddToQueue(array->elements[i], &queue);
	}

	int i = 1;
	while(queue.start <= queue.end){
		char card = PopFromQueue(&queue);
		if(i%2==1){
			printf("%c ", card);
		}else{
			AddToQueue(card, &queue);
		}
		i++;
	}
}



int main(){

	char cards[5] = "9966";
	struct Array array;
	array.elements = cards;
	array.lenght = 4;

	IsValidArray(&array);
	return 0;
}

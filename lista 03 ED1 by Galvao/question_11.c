#include <stdio.h>
#include <stdlib.h>

void heapsort(int *heap, int n);

int main(void) {
	int i, n = 8;
	int heap[8] = {10, 5, 20, 6, 1, 35, 50, 12};
	printf("Vetor: ");
	for (i=0; i<n; i++){
		printf("%d ", heap[i]);
	}
	printf("\n");
	heapsort (heap, n);
	printf("HeapSort: ");
	for (i=0; i<n; i++){
		printf("%d ", heap[i]);
	}
	return 0;
}

void heapsort(int *heap, int n) {
	int i, j, aux;
	for (i = n; i > 0; i--) {
		for (j = i; j > 1; j--) {
			if (heap[(j / 2)-1] < heap[j-1]) {
				aux = heap[(j / 2)-1];
				heap[(j / 2)-1] = heap[j-1];
				heap[j-1] = aux;
			}
		}
		i = i / 2;
	}
	aux = heap[0];
	heap[0] = heap[n-1];
	heap[n-1] = aux;
	if (n>1){
		heapsort(heap, n-1);
	}
}

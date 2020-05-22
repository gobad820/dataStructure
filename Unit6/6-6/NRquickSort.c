#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.c"
#define swap(type, x , y) do{ \
	type t = x; \
	x = y; \
	y = t; \
}while(0) \

void InsertionSort(int* arr, int size);
void NRquick(int* arr, int left, int right);
int main(void){
	srand((unsigned)time(NULL));	
	int size;
	puts("퀵 정렬 (비재귀적) ");
	printf("요소 개수 : ");
	scanf("%d",&size);
	int* arr = (int*)malloc(sizeof(int)*size);
	
	int i;
	for(i = 0 ; i < size ; i++){
		arr[i] = rand()%100;
		printf("x[%d] : %d\n", i , arr[i]);
}
	NRquick(arr,0,size-1);
	puts("오름차순으로 정렬했습니다");
	
	for(i = 0 ; i < size ; i++)
		printf("x[%d] : %d\n", i , arr[i]);

	free(arr);
	return 0;

}

void NRquick(int* arr, int left, int right){

	Stack lstack;
	Stack rstack;

	Initialize(&lstack, right-left+1);	
	Initialize(&rstack, right-left+1);
	
	Push(&lstack,left);
	printf("%d is Pushed to lstack", left);
	
	Push(&rstack,right);
	printf("\n%d is Pushed to rstack", right);
	
	
	while(!isEmpty(&lstack)){
	int pl = (Pop(&lstack,&left), left);
	printf("\n%d is Poped from lstack",pl);
	int pr = (Pop(&rstack,&right), right);
	printf("\n%d is Popped from rstack",pr);
	int pivot = arr[(left+right)/2];

	do{
		while(arr[pl] < pivot) pl++;
		while(arr[pr] > pivot) pr--;
		if(pl <= pr){
			swap(int, arr[pl], arr[pr]);
			pl++;
			pr--;}
	}while(pl <= pr);

	if(pr-left <= 9 && right - pl <= 9)
	{
		InsertionSort(arr,right-left+1);
		break;
	}	
	//left<pr 이고 pl < right 이거나 이지 않거나 작은 그룹이거나 큰 그룹이거나
	if(left< pr){
		if(pr-left < right-pl){
		Push(&lstack,left);
		printf("\n%d is Pushed to lstack",left);
		Push(&rstack,pr);
		printf("\n%d is Pushed to rstack",pr); }
		else{
		if(right != pl){
		Push(&lstack,pl);
		Push(&rstack,right);
		}}
	} 
	if(pl < right){
		if(right-pl < pr-left){
		Push(&lstack,pl);
		printf("\n%d is Pushed to lstack",pl);
		Push(&rstack,right);
		printf("\n%d is Pushed to rstack\n",right);}
		else{
		if( left != pr){
			Push(&lstack,left);
			Push(&rstack,pr);}
	}
	}

}
	Terminate(&lstack);
	Terminate(&rstack);	
}

void InsertionSort(int* arr, int size){
	int i,j;
	for(i = 1 ; i < size ; i++){
		int tmp = arr[i];
		for(j = i ; j > 0 && arr[j-1] > tmp ; j--)
			arr[j] = arr[j-1];
		arr[j] = tmp;
	}
}  

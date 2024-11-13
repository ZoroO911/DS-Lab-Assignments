#include<stdio.h>
void bubble_sort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
		}
		}
	}
	printf("The sorted array is:");
	for(i=0;i<8;i++){
	printf("%d",arr[i]);
	}
}
int main(){
	int i;
	int arr[8]={3,6,2,4,1,5,8,7};
	bubble_sort(arr,8);
	return 0;
}

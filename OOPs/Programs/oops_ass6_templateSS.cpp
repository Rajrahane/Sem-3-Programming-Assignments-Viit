#include<iostream>
using namespace std;
template<class T>
void printArray(T* arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
template<class T>
void selectionSort(T*arr,int size,bool ascendingOrder){
	T temp;
	int i,j,maxElementIndex;
	for(i=size-1;i>0;i--){
		maxElementIndex=0;
		for(j=1;j<=i;j++){
			if(ascendingOrder){
				if(arr[maxElementIndex]-arr[j]<0){
					maxElementIndex=j;
				}
			}else{
				if(arr[maxElementIndex]-arr[j]>0){
					maxElementIndex=j;
				}
			}
		}
		temp=arr[maxElementIndex];
		arr[maxElementIndex]=arr[i];
		arr[i]=temp;
		cout<<"Iteration"<<size-i<<" ";printArray(arr,size);
	}
}
void printMenu(){
	cout<<"1)Int Array\t";
	cout<<"2)Float Array\t";
	cout<<"3)Exit\tChoice : ";
}
int main(){
	int choice,size,i;
	cout<<"Selection Sort in Descending Order\n";
	printMenu();
	do{
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"Size : ";cin>>size;
				int arr[size];
				for(i=0;i<size;i++){
					cin>>arr[i];				
				}
				selectionSort(arr,size,false);
				break;
			}
			case 2:{	
				cout<<"Size : ";cin>>size;
				float arr[size];
				for(i=0;i<size;i++){
					cin>>arr[i];				
				}
				selectionSort(arr,size,false);
				break;		
			}
		}
	}while(choice!=3);
	return 0;
}

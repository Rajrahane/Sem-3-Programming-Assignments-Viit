#include<iostream>
#include<exception>
using namespace std;
class FullQueueException:public exception{
	public:
		const char* what()const throw(){
			return "FullQueueException";
		}
};
class EmptyQueueException:public exception{
	public:
		const char*what()const throw(){
			return "EmptyQueueException";
		}
};
#define DEFAULT_QUEUE_SIZE 5
template<class T>
class Queue{
	private:
		T *arr;
		int elements,queue_size,head,tail;
	public:
		Queue(int size=DEFAULT_QUEUE_SIZE){
			if(size<0)	
				throw std::bad_array_new_length();
			arr=new T[size];
			queue_size=size;
			elements=0;
			head=tail=0;
		}~Queue(){
			delete []arr;arr=NULL;
			cout<<"Queue Destructed\n";
		}
		bool isEmpty(){
			return elements==0;
		}
		bool isFull(){
			return elements==queue_size;
		}
		T deQueue();
		void enQueue(T element);
		void printQueue(string separator);
};
template<class T>
void Queue<T>::enQueue(T element){
	if(!isFull()){
		arr[tail]=element;
		tail=(tail+1)%queue_size;
		elements++;
	}else throw FullQueueException();	
}
template<class T>
T Queue<T>::deQueue(){
	if(!isEmpty()){
		T element=arr[head];	
		head=(head+1)%queue_size;
		elements--;
		return element;
	}else throw EmptyQueueException();
}
template<class T>
void Queue<T>::printQueue(string separator){
	int printer=head,iterations=elements;
	if(iterations!=0)
		while(iterations--){
			cout<<arr[printer]<<separator;
			printer=(printer+1)%queue_size;
		}
	else cout<<"Empty Queue";
	cout<<endl;
}

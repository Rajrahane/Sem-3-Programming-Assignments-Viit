#include<exception>
#include<iostream>
using namespace std;
class FullVectorException:public exception{
	public:
		const char*what()const throw(){
			return "FullVectorException";
		}
};
template<class T>
class MyVectorClass{
	T* arr;
	int size,elements;
	public:	
	MyVectorClass(int size=10){		//create vector
		if(size<=0)
			throw std::bad_array_new_length();		
		arr=new T[size];
		this->size=size;
		elements=0;
	}
	void push_back(T element){
		if(elements==size)
			throw FullVectorException();
		arr[elements++]=element;
	}
	T& operator[](int i){
		if(i<0 ||i>=elements)
			throw std::out_of_range("Index out of Bounds:");
		return arr[i];
	}
	void operator*(T element){
		for(int i=0;i<elements;i++){
			arr[i]*=element;
		}
	}
	void display(){
		for(int i=0;i<elements;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	MyVectorClass<int> iVector(10);
	try{
		for(int i=4;i<=14;i++)
			iVector.push_back(i);
	}catch(FullVectorException &e){
		cout<<e.what()<<endl;		
	}iVector.display();
	iVector[4]=42;
	iVector.display();
	iVector*-2;
	iVector.display();
	return 0;
}

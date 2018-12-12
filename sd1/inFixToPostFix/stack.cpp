#include<iostream>
#include<exception>
using namespace std;

class EmptyStackException:public exception{
	public:
		const char*what()const throw(){
			return "EmptyStackException";
		}
};

class FullStackException:public exception{
	public:
		const char*what()const throw(){
			return "FullStackException";		
		}
};
template<class T>
class Stack{
	private:
		T *stk;
		int stk_size;
		int tos;
	public:
		Stack(int stk_size=10){
			if(stk_size<0)
				throw std::bad_array_new_length();
			stk=new T[stk_size];
			this->stk_size=stk_size;			
			tos=-1;
		}
		void push(T element);
		T pop();
		T peek();
		void printStack();
		bool isFull(){
			return tos==stk_size-1;
		}
		bool isEmpty(){
			return tos==-1;
		}
		~Stack(){
			delete stk;
			cout<<"Stack Destructed\n";
		}
};
template<class T>
void Stack<T>::push(T element){
	if(isFull()){
		throw FullStackException();
	}
	else{
		*(stk+(++tos))=element;
	}
}
template<class T>
T Stack<T>::pop(){
	if(isEmpty()){
		throw EmptyStackException();
	}
	return *(stk+(tos--));
}
template<class T>
T Stack<T>::peek(){
	if(isEmpty()){
		throw EmptyStackException();
	}
	return *(stk+(tos));
}
template<class T>
void Stack<T>::printStack(){
	int tempTos=tos;
	while(tempTos>-1){
		cout<<*(stk+(tempTos--))<<" ";
	}
	cout<<endl;
}

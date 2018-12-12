/*
*
*@Rajvaibhav Rahane
*
*/

#include<iostream>
using namespace std;
int main(){
	int age;float salary;
	try{
		cin>>age;
		if(age<18||age>55)
			throw age;		//throws int type
		cin>>salary;
		if(salary<50000|| salary>100000)
			throw salary;		//throws float type
		cout<<"all conditions met\n";
	}catch(int e){
		cout<<e<<" age condition not met\n";
	}catch(float e){
		cout<<e<<" salary condition not met\n";
	}
	return 0;
}

/*
*@Rajvaibhav Rahane
*/

/*
*	Program to create structure Doctor
*
*	implements functions-
*		overloads >> and << operator functions
*/

#include<iostream>
using namespace std;

typedef struct Doctor{
	int experience;
	string name;
	string specialisation;

} Doctor;

istream & operator>>(istream &in,Doctor &doctor){
	
	cout<<"Enter Name\t";
	//getline(in,doctor.name);
	in>>doctor.name;
	cout<<"Enter experience";
	in>>doctor.experience;
	//scanf("%d%*c",&doctor.experience);
	cout<<"Enter Specialisation\t";
	in>>doctor.specialisation;
	//getch();
	//getline(in,doctor.specialisation);
	return in;
}

ostream & operator<<(ostream &out,Doctor doctor){
	out<<doctor.name<<"\t"<<doctor.specialisation<<" "<<doctor.experience<<endl;
	return out;
}

int main(){
	Doctor doc[5];
	for(int i=0;i<5;i++){		
		cin>>doc[i];
		cout<<doc[i];
	}
	return 0;
}

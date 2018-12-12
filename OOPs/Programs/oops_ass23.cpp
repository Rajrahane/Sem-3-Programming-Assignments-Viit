#include<bits/stdc++.h>
using namespace std;
class Student{
		static int objCount;
		char *name;
		int rollNo;
		char *year;
		char division;
		int dd,mm,yy;
	
		char *address;
		char *phone;
	public:
		static int getObjectCount(){
			return objCount;
		}
		Student(Student &s){
			cout<<"Copy Constructor called\n";	
			name=year=address=phone=NULL;rollNo=dd=mm=yy=-1;
			
		}
		//int calculateLength(char *str);	
		Student(char *name,int rollNo,char *year,char division,int dd,int mm,int yy,char *address,char *phone){
			//Parameterised Constructor;
			cout<<"Parameterised Constructor called\n";
			this->name=name;		//use of this pointer
			this->rollNo=rollNo;
			this->year=year;
			this->division=division;	
			this->dd=dd;this->mm=mm;this->yy=yy;
			this->address=address;
			this->phone=phone;	
		}
		Student(){	//Empty Constructor
			cout<<"Default Constructor called\n";
			name=year=address=phone=NULL;rollNo=dd=mm=yy=-1;objCount++;	
		}
		~Student(){		//destructor;
			if(name!=NULL){delete name;name=NULL;}
			if(year!=NULL){delete year;year=NULL;}
			if(address!=NULL){delete address;address=NULL;}
			if(phone!=NULL){delete phone;phone=NULL;}
			cout<<"Destructing Student\n";
		}
		friend istream & operator>>(istream &in,Student&);		//friend fx
		friend ostream & operator<<(ostream &,const Student&);		
};
int Student::objCount=0;
int calculateLength(char *str){
	int i=0;	
	if(str!=NULL){
		for(i=0;str[i]!='\0';i++);
	}
	return i;
}
istream & operator>>(istream &in,Student & s){
	s.name=new char[16];s.year=new char[3];s.address=new char[41];s.phone=new char[11];
	cout<<"Name(15) : ";scanf("%[^\n]%*c",s.name);
	s.name[calculateLength(s.name)]='\0';
	cout<<"PRN No : ";scanf("%d%*c",&s.rollNo);
	cout<<"Year(2) : ";scanf("%[^\n]%*c",s.year);s.year[calculateLength(s.year)]='\0';
	cout<<"Div(1) : ";scanf("%c%*c",&s.division);
	cout<<"DOB : ";scanf("%d%d%d%*c",&s.dd,&s.mm,&s.yy);
	cout<<"Address(40) : ";scanf("%[^\n]%*c",s.address);s.address[calculateLength(s.address)]='\0';
	cout<<"Phone(10) : ";scanf("%[^\n]%*c",s.phone);s.phone[calculateLength(s.phone)]='\0';
	return in;
}
ostream & operator<<(ostream &out,const Student& s){
	if(s.name!=NULL)
		out<<s.name<<endl;
	else
		out<<"NULL Name";
	out<<s.rollNo<<" ";
	if(s.year!=NULL)
		out<<s.year<<"\t";
	else
		out<<"NULL Year";
	
	out<<s.division<<endl;
	if(s.address!=NULL)
		out<<s.address<<endl;
	else 
		out<<"NULL Address";
	out<<s.dd<<" "<<s.mm<<" "<<s.yy<<" ";
	if(s.phone!=NULL)
		out<<s.phone<<endl;
	else
		out<<"NULL Phone";
	return out;
}
void createStudent(){
	char *name=new char[16],*year=new char[3],*address=new char[41],*phone=new char[11];
	int rollNo,dd,mm,yy;char division;
	
	cout<<"Name(15) : ";scanf("%[^\n]%*c",name);
	name[calculateLength(name)]='\0';
	cout<<"PRN No : ";scanf("%d%*c",&rollNo);
	cout<<"Year(2) : ";scanf("%[^\n]%*c",year);year[calculateLength(year)]='\0';
	cout<<"Div(1) : ";scanf("%c%*c",&division);
	cout<<"DOB : ";scanf("%d%d%d%*c",&dd,&mm,&yy);
	cout<<"Address(40) : ";scanf("%[^\n]%*c",address);address[calculateLength(address)]='\0';
	cout<<"Phone(10) : ";scanf("%[^\n]%*c",phone);phone[calculateLength(phone)]='\0';
	
	{cout<<"Creating parameterised object\n";Student parameterised(name,rollNo,year,division,dd,mm,yy,address,phone);}
	cout<<"Leaving createStudent()\n";
}
void printMenu(){
	cout<<"1)Create Student\t";
	cout<<"2)End\tChoice? : ";
}
int main(){
	int choice;
	createStudent();
	{cout<<"Creating simple object\n";Student s2;cout<<endl;cout<<"Creating copy\n";Student s1(s2);cout<<endl;}
	printMenu();
	do{	
		scanf("%d%*c",&choice);
		switch(choice){
			case 1:{
				Student s;//=createStudent();
				cout<<"Object No : "<<Student::getObjectCount()<<endl;
				cin>>s;
				cout<<s<<endl;
				break;
			}
			case 2:{break;}
		}
	}while(choice!=2);
	cout<<"Total Students : "<<Student::getObjectCount()<<endl;
	return 0;
}

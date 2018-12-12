#include<iostream>
using namespace std;
class  PersonalData {
	protected:
		string name,address,mobNo,bloodGroup,gender,dob;
		int age;
		void setPersonalData()
		{
			cout<<"___________________________________"<<endl;
			cout<<"\tPersonal Data "<<endl;
			cout<<"\tName: ";
			cin>>name;
			cout<<"\tMobile No : ";
			cin>>mobNo;
			cout<<"\tAge : ";
			cin>>age;
			cout<<"\tGender : ";
			cin>>gender;
			cout<<"\tDate of Birth : ";
			cin>>dob;
			cout<<"\tBlood Group : ";
			cin>>bloodGroup;
		}
			
		void getPersonalData(){
			cout<<"________________PERSONAL DATA___________________"<<endl;
			cout<<"\tPersonal Data"<<endl;
			cout<<"\tName: "<<name<<endl;
			cout<<"\tMobile No : "<<mobNo<<endl;
			cout<<"\tAge : "<<age<<endl;
			cout<<"\tGender : "<<gender<<endl;
			cout<<"\tDate of Birth : "<<dob<<endl;
			cout<<"\tBlood Group : "<<bloodGroup<<endl;		
		}
		
};

class ProfessionalData {
	int salary;
	string name,empId,currComp,earlyExp,post;
	protected:
	void setProfessionalData(){
		cout<<"______________________________________"<<endl;
		cout<<"\tProfessional Data"<<endl;
		cout<<"\tName: ";
		cin>>name;
		cout<<"\tEmployee ID :  ";
		cin>>empId;
		cout<<"\tCurrent Company : ";
		cin>>currComp;
		cout<<"\tCurrent Post : ";
		cin>>post;
		cout<<"\tSalary : ";
		cin>>salary;
		cin.ignore();
		cout<<"\tEarly Experience : ";
		cin>>earlyExp;
			
	}
	void getProfessionalData(){
		cout<<"_________________PROFESSIONAL DATA_________________________"<<endl;
		cout<<"\tProfessional Data"<<endl;
		cout<<"\tName: "<<name<<endl;
		cout<<"\tEmployee ID : "<<empId<<endl;
		cout<<"\tCurrent Company : "<<currComp<<endl;
		cout<<"\tCurrent Post : "<<post<<endl;
		cout<<"\tSalary : "<<salary<<endl;
		cout<<"\tEarly Experience : "<<earlyExp<<endl;
	}
};

class AcedemicData{
	int hscMarks,sscMarks;
	float finalCgpa;
	string deg,name,yog;
	protected:
	void setAcedemicData(){
		cout<<"_____________________________________"<<endl;
		cout<<"\tAcedemic Data"<<endl;
		cout<<"\tName: ";
		cin>>name;
		cout<<"\tDegree : ";
		cin>>deg;
		cout<<"\tHSC score : ";
		cin>>hscMarks;
		cout<<"\tSSC score :";
		cin>>sscMarks;
		cout<<"\tFinal CGPA : ";
		cin>>finalCgpa;
		cin.ignore();
		cout<<"\tYear of Graduation: ";
		cin>>yog;
			
	}
	void getAcedemicData(){
		cout<<"______________________ACADEMIC DATA_________________________"<<endl;
		cout<<"\tAcedemic Data"<<endl;
		cout<<"\tName: "<<name<<endl;
		cout<<"\tDegree : "<<deg<<endl;
		cout<<"\tHSC score : "<<hscMarks<<endl;
		cout<<"\tSSC score :"<<sscMarks<<endl;
		cout<<"\tYear of Graduation : "<<yog<<endl;
			
	}

};

class Employee : protected PersonalData,protected ProfessionalData,protected AcedemicData{
	public:
		void setBiodata(){
			setPersonalData();
			setProfessionalData();
			setAcedemicData();
			
		}

		void showBiodata(){
			getPersonalData();
			getProfessionalData();
			getAcedemicData();			
		}
};

int main(){
	Employee e1;
	e1.setBiodata();
	e1.showBiodata();

	return 0;
}

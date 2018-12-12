#include<iostream>
using namespace std;
int main(){
	string cityName;char hasVehicle;bool vehicleCondition,cityNameCondition=vehicleCondition=true;
	cout<<"Enter Your City Name\t";
	try{
		try{
			cin>>cityName;
			if(!(cityName=="Mumbai"||cityName=="Pune" || cityName=="Bangalore" || cityName=="Chennai"))
				throw cityName;
			cout<<"Your City is present in the list\n";
		}catch(string cityName){
			cout<<"City absent in City List\n";
			cityNameCondition=false;
		}
		cout<<"Do you own a 4 Wheeler(y/n)\t";
		try{
			cin>>hasVehicle;
			if(hasVehicle!='y')
				throw hasVehicle;
			cout<<"Congo!\n";
		}catch(char hasVehicle){
			cout<<"Its Okay\n";vehicleCondition=false;
		}
		if(!cityNameCondition)throw cityName;
		if(!vehicleCondition)throw hasVehicle;
		cout<<"You Drive In a Smart City\n";
	}catch(...){
		cout<<"You can't Drive In our City\n";		
	}
	return 0;
}

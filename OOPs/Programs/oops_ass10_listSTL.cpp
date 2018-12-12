#include<list>
#include<iostream>
using namespace std;
void printMenu(){
	cout<<"1)Insert Element in List\t";
	cout<<"2)Check if List Empty?\t";
	cout<<"3)Reverse List\t";
	cout<<"4)Sort List\t";
	cout<<"5)Delete Multiple Copies of an Element(Unique)\t";
	cout<<"6)Print List\t";
	cout<<"7)Clear List\n";
	cout<<"8)Exit\tChoice ? ";	
}
int main(){
	list<float> floatList;
	list<float>::iterator it;
	int choice;float element;
	
	if(floatList.empty())cout<<"ListEmpty\n";
	
	for(int i=0;i<5;i++)floatList.push_back(42);
	
	it=floatList.begin();it++;it++;floatList.insert(it,45);
	printMenu();
	do{
		cin>>choice;
		switch(choice){
			case 1:{
				it=floatList.end();
				cin>>element;floatList.insert(it,element);break;	
			}
			case 2:{
				if(floatList.empty())cout<<"ListEmpty\n";
				else cout<<"Size"<<floatList.size();
				break;
			}
			case 3:{
				floatList.reverse();break;
			}
			case 4:{
				floatList.sort();					
				break;
			}
			case 5:{floatList.unique();break;}
			case 6:{
				for(it=floatList.begin();it!=floatList.end();it++)cout<<*it<<" ";
				cout<<endl;				
				break;			
			}
			case 7:floatList.clear();
			case 8:break;
		}
	}while(choice!=8);
	return 0;
}

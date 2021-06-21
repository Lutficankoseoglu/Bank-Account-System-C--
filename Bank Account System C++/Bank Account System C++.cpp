#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>

#include <direct.h> 



using namespace std;

class Account{
	public : 
	char* accountNumber;
	int deposit;
	char type;
	char* accNo;
	
	public : 
	Account(char* acNo, int depo, char typ){
		accountNumber=acNo;
		deposit=depo;
		type=typ;
	}
	
	void setAccountNumber(char* acNo){
		accountNumber=acNo;
	}
	
	char* getAccountNumber(){
		return accountNumber;
	}
	
	void setDeposit(int depo){
		deposit=depo;
	}
	
	int getDeposit(){
		return deposit;
	}
	
	void setType(char typ){
		typ=toupper(typ);
		type=typ;
	}
	
	char getType(){
		return type;
	}
	
	void depos(int x){
		deposit+=x;
	}
	
	void withdraw(int x){
		deposit-=x;
	}
	
	void report(){
		cout<<accountNumber<<" "<<deposit<<" "<<type<<endl;
	}
	
	
		 
	void addAccount();
	void deleteAccount();
		
	void showAccount();
	void writeAccount();
	
};

class User{
	public :
		char* userIDNumber;
		string userName;
		
	public:
		User(char* UID, string Uname){
			userIDNumber=UID;
			userName=Uname;
		}
		
	void setUserID(char* UID){
		userIDNumber=UID;
	}
	
	char* getUserID(){
		return userIDNumber;
	}
	
	void setUserName(string Uname){
		userName=Uname;
	}
	
	string getUserName(){
		return userName;
	}
	
//	vector <Account> myAccounts;
	
	void addUser();
	void deleteUser();
	void writeUser();


};

class Bank{
	public : 
	vector <User> user1;
	vector <Account> account1;
	
	void addUserFile(char* x);
	void addUser(User u);
	void deleteUser(User u);
	void writeUser(User u);
	
	void addAccountFile(char* x);
	void addAccount(Account a);
	void deleteAccount(Account a);
	void showAccount(int acno,int depo, char typ);
	void writeAccount(Account a);
	
	void removeAccountVector(Account a);
	void removeUserVector(User u);
	void Deposit(Account a,char* acno, int depo, char typ);
	void withDraw(Account a,char* acno, int depo, char typ);
	void showAccount(char* acno);	
	int removeAccount(char* acno);
	void modif(Account a,char* acno, int depo, char typ);

};

void Bank::addUserFile(char* x){
	mkdir(x);
}
void Bank::addUser(User u){
	user1.push_back(u);
}

void Bank::deleteUser(User u){
	ofstream FileS{"UserFile.txt",ios::out};
if (FileS.is_open()) 
{
	user1.pop_back();
}
	else {
		cout << "Could not open file"; 	
	}     
}

void Bank::writeUser(User u){
	ofstream FileB{"UserFile.txt",ios::out};
	for(int i=0; i<user1.size(); i++){
		FileB<<user1[i].userIDNumber<<" "<<user1[i].userName<<"\n"<<endl;
	}
	FileB.close();
}

void Bank::removeUserVector(User u){
	user1.pop_back();
}



void Bank::addAccount(Account a){
	account1.push_back(a);
}

void Bank::addAccountFile(char* x){
	mkdir(x);
}

void Bank::deleteAccount(Account a){
		ofstream FileB{"AccountFile.txt",ios::out};
	if (FileB.is_open()) 
	{
	account1.pop_back();}
		else {
			cout << "Could not open file"; 	
	}   

}

void Bank::Deposit(Account a,char* acno, int depo, char typ){
			
			chdir(acno);
			ifstream infile;
			ofstream outfile;
			
			cout << "\t\t ------ Deposit Amount Value ------\n" << endl;
			
			string accountNumber;
			int deposit;
			char type;
						
			infile.open("AccountFile.txt", ios::in);
			outfile.open("AccountsEdited.txt", ios::app|ios::out);
			
			if(!infile){
				cout << "\t\t File is not found." << endl;
			}
			else{
				infile>>accountNumber>>deposit>>type;
				typ=type;
				
				int found = 0;
				
				while(!infile.eof()){
					if (acno == accountNumber){
						cout << "\t\t Account Found!\n" << endl;
						
						cout << "\tAccount Number : " << accountNumber << endl;
						cout << "\tDeposit Value : " << deposit << endl;
						cout << "\tAccount Type : " << type << endl;
						cout << endl;
						

						cout << "\tAccount No " << acno << endl;
						cout << "\tNew Deposit Value: " << depo+deposit << endl;
						cout << "\tNew Type of Account: " << typ << endl;
						cout << endl;
						
						char choice;
						cout << "\n\tIs these true ? (Y/N): ";
						cin >> choice;
						
						if (choice == 'y' || choice == 'Y'){
							depo+=deposit;
							type=typ;
							
							outfile<< acno<<" "<<depo<<" "<<typ<<endl;
							
							found = 1;
						}
						else if (choice == 'n' || choice == 'N'){
							cout << "\t\t Reverting changes." << endl;
							cout << "\t\t Reverted changes." << endl;
						}
						else{
							cout << "\t\t You have entered invalid choice." <<endl;
							
							cout << "\t\t Reverting changes." << endl;
							cout << "\t\t Reverted changes." << endl;
						}
					}
					else{
						outfile<<acno<<" "<<depo<<" "<<typ<< endl;
					}
					infile>>accountNumber>>deposit>>type;	
				

				}
				
				if (found == 0){
					cout << "\t\t Account No Not Found." << endl;
				}
			}
			
				infile.close();
				outfile.close();
						remove("AccountFile.txt");
						rename("AccountsEdited.txt", "AccountFile.txt");		
		}
				
void Bank::withDraw(Account a,char* acno, int depo, char typ){
			
			chdir(acno);
			ifstream infile;
			ofstream outfile;
			
			cout << "\t\t ------ Withdraw Amount Value ------\n" << endl;
			
			string accountNumber;
			int deposit;
			char type;
						
			infile.open("AccountFile.txt", ios::in);
			outfile.open("AccountsEdited.txt", ios::app|ios::out);

			if(!infile){
				cout << "\t\t File is not found." << endl;
			}
			else{
				infile>>accountNumber>>deposit>>type;
				if(deposit>=depo){
				typ=type;
				int found = 0;
				
				while(!infile.eof()){
					if (acno == accountNumber){					
						cout << "\t\t Account Found!\n" << endl;
						
						cout << "\tAccount Number : " << accountNumber << endl;
						cout << "\tDeposit Value : " << deposit << endl;
						cout << "\tAccount Type : " << type << endl;
						cout << endl;
						

						cout << "\tAccount No " << acno << endl;
						cout << "\tNew Deposit Value: " << deposit-depo << endl;
						cout << "\tNew Type of Account: " << typ << endl;
						cout << endl;
						
						char choice;
						cout << "\n\tIs these true ? (Y/N): ";
						cin >> choice;
						
						if (choice == 'y' || choice == 'Y'){
							depo=deposit-depo;
							type=typ;
							
							outfile<< acno<<" "<<depo<<" "<<typ<<endl;
							
							found = 1;
						}
						else if (choice == 'n' || choice == 'N'){
							cout << "\t\t Reverting changes." << endl;
							cout << "\t\t Reverted changes." << endl;
						}
						else{
							cout << "\t\t You have entered invalid choice." <<endl;
							
							cout << "\t\t Reverting changes." <<endl;
							cout << "\t\t Reverted changes." <<endl;
						}
				}
					else{
						outfile<<acno<<" "<<depo<<" "<<typ<<endl;
					}
					infile>>accountNumber>>deposit>>type;	
				

				}
				
				if (found == 0){
					cout << "\t\t Account No Not Found." <<endl;
				}
			}
			else{
				cout<<"You don't have enought money.";
				outfile<<accountNumber<<" "<<deposit<<" "<<type<<endl;
				cout<<"Please enter a character to return login screen.";
				char x;
				cin>>x;
			}
		}
				infile.close();
				outfile.close();
						remove("AccountFile.txt");
						rename("AccountsEdited.txt", "AccountFile.txt");
	 	
		
		}
		
void Bank::showAccount(char* acno){
			
			if(chdir(acno)!=0){
				cout<<" You entered a wrong Account Number. Please try again.";
			}
					
			else{
			chdir(acno);
			ifstream infile;
			
			cout << "\n\n\t\t ------ Show Amount Value ------\n" << endl;
			
			string accountNumber;
			int deposit;
			char type;
						
			infile.open("AccountFile.txt", ios::in);
			
				if(!infile){
					cout << "\t\t You don't have an Account with this Account Number." << endl;
				}			
				else{				
									
						infile>>accountNumber>>deposit>>type;

						cout << "\tAccount Number : " << accountNumber << endl;
						cout << "\tDeposit Value : " << deposit << endl;
						cout << "\tAccount Type : " << type << endl;
						cout << endl;
					}
				
		infile.close();	
					
				
				
			}
		}		
			
		
		

void Bank::writeAccount(Account a){
	ofstream FileB{"AccountFile.txt",ios::app};
	for(int i=0; i<account1.size(); i++){
		FileB<<account1[i].accountNumber<<" "<<account1[i].deposit<<" "<<account1[i].type<<""<<endl;
	}
	FileB.close();
}


void Bank::removeAccountVector(Account a){
	account1.pop_back();
}

int Bank::removeAccount(char* acno){
	if(chdir(acno)!=0){
		cout<<"You don't have an account with this Account Number already.";
	}
	else{
		chdir(acno);
		remove("AccountFile.txt");
		chdir("D:/Proje");
	}
}

void Bank::modif(Account a,char* acno, int depo, char typ){
			
			chdir(acno);
			ifstream infile;
			ofstream outfile;
			
			cout << "\t\t ------ Modify Your Account Type ------\n" << endl;
			
			string accountNumber;
			int deposit;
			char type;
						
			infile.open("AccountFile.txt", ios::in);
			outfile.open("AccountsEdited.txt", ios::app|ios::out);
			
			if(!infile){
				cout << "\t\t File is not found." << endl;
			}
			else{
				infile>>accountNumber>>deposit>>type;
				depo=deposit;
				int found = 0;
				
				while(!infile.eof()){
					if (acno != 0){
						
						cout << "\t\t Account Found!\n" << endl;
						
						cout << "\tAccount Number : " << accountNumber << endl;
						cout << "\tDeposit Value : " << deposit << endl;
						cout << "\tAccount Type : " << type << endl;
						cout << endl;
						

						cout << "\tAccount No " << acno << endl;
						cout << "\tNew Deposit Value: " << depo << endl;
						cout << "\tNew Type of Account: " << typ << endl;
						cout << endl;
						
						char choice;
						cout << "\n\tIs these true ? (Y/N): ";
						cin >> choice;
						
						if (choice == 'y' || choice == 'Y'){
							depo=deposit;

							
							outfile<<accountNumber<<" "<<depo<<" "<<typ<<endl;
							
							found = 1;
						}
						else if (choice == 'n' || choice == 'N'){
							cout << "\t\t Reverting changes." << endl;
							cout << "\t\t Reverted changes." << endl;
						}
						else{
							cout << "\t\t You have entered invalid choice." <<endl;
							
							cout << "\t\t Reverting changes." << endl;
							cout << "\t\t Reverted changes." << endl;
						}

			}
			else{
			
						outfile<<accountNumber<<" "<<depo<<" "<<typ<< endl;
			}
					infile>>accountNumber>>deposit>>type;	
				

				}
				
				if (found == 0){
					cout << "\t\t Account No Not Found." << endl;
				}
			}
			
				infile.close();
				outfile.close();
						remove("AccountFile.txt");
						rename("AccountsEdited.txt", "AccountFile.txt");
			
		
		}



void introduction(){
	
	cout<<"\n\n\t\t\t Bank Management System"<<endl;
	cout<<"\t\t\t\tMade by : LCK";
	
}



string PassCheck(char* ar,string p){
	chdir(ar);
			string x;		
			string line;
							
				fstream FileB("Password.txt",ios::in);							
			if(FileB.is_open()){
					while(!FileB.eof()){
						FileB>>line;					
					}
		}
		FileB.close();
					if(line==p){						

						x="Ok...";
					}
	return x;
}





int main(int argc, char* argv) {
	Bank b1; 

	system("cls");

		
	introduction();
	char choi;
	string pas;
	string name;


	cout<<"\n\n\n";
	cout<<" 1-Register New User"<<endl;
	cout<<" 2-Remove A User"<<endl;
	cout<<" 3-User Log-in"<<endl;
	cout<<"  Your Choice : ";
	cin>>choi;

		
	

		if(choi == '1'){
		
			system("cls");
			
		cout<<"Please enter your 'USER ID CARD NUMBER' : ";
		cin>>argv;
		
		if(chdir(argv)!=0){
		

		cout<<"Please enter your 'Name' : ";
		cin>>name;
		
		User u1(argv,name);
		
		
		int pass;
		cout<<"Please enter your password : ";
		cin>>pass;
		if(chdir(argv)!=0){	
			b1.addUserFile(argv);
			chdir(argv);		
		}
		else{
		chdir(argv);
		}
		
		b1.addUser(u1);
		b1.writeUser(u1);

		
		ofstream FileB{"Password.txt",ios::app};
		FileB<<pass<<endl;
		FileB.close();			
		}
	
		else{
			cout<<"You have already registered to system. Please Log-in.";
			return 0;
		}
		goto Accounts;
		}
		
		if(choi == '2'){
		
			system("cls");

			cout<<"Please enter your 'USER ID CARD NUMBER' : ";
			cin>>argv;
			
			if(chdir(argv)==0){				
			cout<<"Please enter your password : ";
			cin>>pas;
			
			if(PassCheck(argv,pas)=="Ok..."){
				remove("UserFile.txt");
				remove("Password.txt");
				chdir("D:/Proje");
				}
				
			else{
				cout<<"You entered a wrong password. Please check it.";
				return 0;
				}
			}
			
			else{
				cout<<"You have not a register.You should have to a register for use this function.";
				return 0;
			}
			return 0;
		}
		
		if(choi == '3'){
		
UserLogin :			
			system("cls");
			cout<<"Please enter your 'USER ID CARD NUMBER' : ";
			cin>>argv;
			cout<<"Please enter your password : ";
			cin>>pas;
			if(PassCheck(argv,pas)=="Ok..."){
				cout<<"Password is true. You are redirecting to your accounts...";
				chdir(argv);
				goto Accounts;
			}
			else{
				cout<<"You entered a wrong Password or wrong ID Num. Please check it.";
				return 0;
			}
			
			return 0;
	
	}
		else{
			cout<<"You made a wrong choice.";
			return 0;
		}
	
		
	
	char input;
	int dep,acno;
	char ty,inf;

Accounts :		

		
			system("cls");
			
			cout<<" \n\n Menu\n"<<endl;
			cout<<"1- Register New Account "<<endl;
			cout<<"2- Deposit Amount"<<endl;
			cout<<"3- Withdraw Amount"<<endl;
			cout<<"4- Show Amount"<<endl;
			cout<<"5- Remove an Account from List"<<endl;
			cout<<"6- Modify an Account"<<endl;
			cout<<"7- Exit"<<endl;
			cout<<"Please enter your choice (1-7) : ";
			cin>>input;
	
	
		
			
		if (input == '1'){
		system("cls");
					

		
		cout<<"Please enter your Account Number : ";
		cin>>argv;
		if(chdir(argv)!=0){
		cout<<"Please enter your Deposit Value : ";
		cin>>dep;
		
		cout<<"Please enter your Account Type 'C'redit or 'S'aving (C/S) : ";
		cin>>ty;
		ty=toupper(ty);
		Account a1(argv,dep,ty);
		
	
		
		
		cout<<"---------------------------------------------------------"<<endl;
		cout<<a1.getAccountNumber()<<" "<<a1.getDeposit()<<" "<<a1.getType();
		cout<<"\nAre this informations true ? (Y/N) : ";
		cin>>inf;
		
		if(inf == 'Y' || inf == 'y'){
			b1.addAccountFile(argv);
			chdir(argv);
			b1.addAccount(a1);
			b1.writeAccount(a1);
			b1.removeAccountVector(a1);
			chdir("D:/Proje");
			goto UserLogin;
			}	
		}
		else{
			cout<<"You have already account with this number.";
			return 0;
		}
	}
	
		else if(input == '2'){
			cout<<"Please enter your Account No. : ";
			cin>>argv;
			cout<<"Please enter deposit value : ";
			cin>>dep;
			ty=0;
			ty=toupper(ty);
			Account a1(argv,dep,ty);
			b1.Deposit(a1,argv,dep,ty);
			chdir("D:/Proje");
			goto UserLogin;
		}
	
	
			
			

			
		if(input == '3'){ 
			cout<<"Please enter your Account No. : ";
			cin>>argv;
			cout<<"Please enter deposit value : ";
			cin>>dep;
			ty=0;
			ty=toupper(ty);
			Account a1(argv,dep,ty);
			b1.withDraw(a1,argv,dep,ty);
			chdir("D:/Proje");
			goto UserLogin;
		
		}	

		if(input == '4'){ 
		char ent;
			cout<<"Please enter your Account No. : ";
			cin>>argv;;
			b1.showAccount(argv);
			chdir("D:/Proje");
			cout<<"Please enter a character to return login screen.";
			cin>>ent;
			goto UserLogin;
			
		}
			
		if(input == '5'){

			cout<<"Please enter your Account No. : ";
			cin>>argv;
			b1.removeAccount(argv);
			goto UserLogin;

		}
			
		if(input == '6'){
			cout<<"Please enter your Account No. : ";
			cin>>argv;
			dep=0;
			cout<<"Please enter New Type of your account. (C/S) : ";
			cin>>ty;
			ty=toupper(ty);
			Account a1(argv,dep,ty);
			b1.modif(a1,argv,dep,ty);
			chdir("D:/Proje");
			goto UserLogin;	
		}

		if(input == '7'){
			cout<<"\n\n\tThanks for using bank managemnt system.";
			
		}

	
	return 0;
}


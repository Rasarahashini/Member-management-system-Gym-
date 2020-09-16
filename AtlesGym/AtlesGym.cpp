// AtlesGym.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"   // to precompiled 
#include <iostream>  //stream to input and output data
#include <string>   //stream to include string values 
#include <fstream>  // include input and output mode of files
#include <stdlib.h>

using namespace std;

//A member adding function
void add(string id, string fname, string sname, string address, string cnumber, int age) {
    ofstream f;
    f.open(id); // open a file to save that details of members 
    f << "Membership ID \t:" << id << endl;
    f << "First name    \t:" << fname << endl;
    f << "Surname       \t:" << sname << endl;
    f << "Address       \t:" << address << endl;
    f << "Contact number\t:" << cnumber << endl;
    f << "Age           \t:" << age << endl;
    f.close();
    cout << "Successfully saved..\n" <<endl;

}

//A member details editing function
void edit(string id) {
    remove(id.c_str());
}

// A member deleting function
void Delete(string id) {
	ifstream f;
    f.open(id);
    if (f.is_open()) {
		remove(id.c_str());
		cout << "Successfully deleted... " <<endl;
		} else {
        cout<<"This membership Id is not available !\n";
    }
		
}

// A member searching function
void search(string id) {
    string line;
    ifstream f;
    f.open(id);
    if (f.is_open()) {
        cout << "Successfully searched \n" <<endl;
		cout << "" <<endl;
        cout << "You searched member details are.......\n";
		cout<<"";
        while (!f.eof()) {
            getline(f, line);
            cout << line << endl;
        }
        getchar();
    } else {
        cout<<"This membership Id is not available !\n";
    }
}

int _tmain(int argc, _TCHAR* argv[])
 {
    {   // login of the system
		system("color 5E");
		
		cout << "" << endl;
		cout << "               *****************************************************************************" << endl;
		cout << "                                    ATLAS GYM member management system" << endl;
		cout << "                    *******************************************************************" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "                             Enter User name and Password to login..\n" << endl;
        
		string username, userpassword;  // variables to entering user name and password 
		int loginAttempt = 0;          // variable to count login attemps

           while (loginAttempt < 3){ // Login 
            cout << "                                   Username :";
            cin >> username;
            cout << "                                   Password :";
            cin >> userpassword; 
            cout << endl;
            
			if (username == "user" && userpassword == "pass") { // ckecking the user name and password
				cout <<"                                  Access granted !!!"<< endl;
				cout << endl;

                
				string op; // variable to hold entering option number
                string in; // varible to continue or stop the options  
                string id, fname, sname, address, cnumber; // variables to user entering details
                int age;

				// Menu of the system
                cout << " ****************  The Menu of the system *****************\n" << endl;
                do {
                    cout << "1) Add a new member \n2) Edit a member details \n3) Search a member \n4) Delete a member \n5) Help \n6) Exit \n"<<endl;// Options
                    cout << "Enter an option number : ";
                    cin>>op;  // intaking the option number of user enter
                    cout<< endl;
                    getchar();

                    if (op == "1") { // checking the option number
                        cout << "********** Adding a new member **********" << endl;
						cout << "" << endl;
						cout << "Input your Details" << endl;
                        cout << "    Membership ID  \t:";
                        cin>>id;    //intake Id
                        getchar();
                        cout << "    First name  \t:";
                        cin>>fname; //intake Firstname
                        getchar();
                        cout << "    Surname     \t:";
                        cin>>sname; //intake surname
                        getchar();
                        cout << "    Living Address  \t:";
                        cin>>address; //intake address
                        getchar();
                        cout << "    Contact number  \t:";
                        cin>>cnumber; //intake contact number
                        getchar();
                        cout << "    Age             \t:";
                        cin>>age;    //intake age
                        getchar();
                        add(id, fname, sname, address, cnumber, age); // parameter passing to Add function
                    
					} else if (op == "2") {
						cout << "********** Editing a member **********" << endl;
						 cout << "" << endl;
                            
                            cout << "Input Details to edit," << endl;
							cout << "" << endl;
							cout << " Membership ID \t:";
							cin>>id;  //intake Id
                            cout << " First name \t:";
                            cin>>fname; //intake edited Firstname
                            getchar();
                            cout << " Surname  \t:";
                            cin>>sname;  //intake edited surname
                            getchar();
                            cout << " Address  \t:";
                            cin>>address; //intake edited address
                            getchar();
                            cout << " Contact number\t:";
                            cin>>cnumber; //intake edited contact number
                            getchar();
                            cout << " Age    \t:";
                            cin>>age;  //intake age

							edit(id); // send user input id to Edit function
                            add(id, fname, sname, address, cnumber, age); // parameter passing to Add function
							getchar();
                        
                    } else if (op == "3") {
						cout << "********** Searching a member **********" << endl;
						 cout << "" << endl;
                        cout << "Search member's membership ID \t:";
                        cin>>id; //intake Id
                        search(id); // parameter passing to search function

                    } else if (op == "4") {
						cout << "********** Deleting a member **********" << endl; 
						 cout << "" << endl;
                        cout << "Input membership ID to delete \t:";
                        cin>>id; // intake Id
                        getchar();
                        Delete(id); // parameter passing to Delete function
                        getchar();

} else if (op == "5") {
  cout<< " ************ Help ************\n"<<endl; // help option of the system
  cout<< " This system gives you six options to do."<<endl;
  cout<< " "<<endl;
  cout<<"   The First option 'Add a nw member'.\n   In the first option you can add a new member with input the system asking details.\n   If correctly added to the system. It display 'successfully added'.\n"<<endl;
  cout<<"   Th second option is 'Edit a member details'.\n   In the second option you can edit a member details with input new details. If correctly\n   edited the member details. It display 'successfully added'\n"<<endl;
  cout<<"   The third option is 'search a member'.\n   In the third option you can search a member for know about the member details by input\n   member membership Id. The system display you searched member details.\n"<<endl;
  cout<<"   The fourth option is 'Delete a member'.\n   In the fourth option you can delete a member with input membership Id. if delete success\n   the system display 'Successfuly deleted'."<<endl;
  cout<< " "<<endl;
  cout<<"   The fifth option is 'Help'. In the fifth option you can know about the system how to work\n   with it. it display details of the system"<<endl;
  cout<< " "<<endl;
  cout<<"   The sixth option is 'Exit'. If you select sixth option you can exite from the system."<<endl;

					} else if (op == "6") {
						cout<<"";
						cout << "  You are going to exite from the ATLAS GYM member management System !!!";
						getchar();
						return 0; // Exit

                    } else {
                        cout << "Unable to open file ! \n"; 
                        getchar();
                    }

                    cout <<endl << "\nDo you want to restore(y/n)? :"; //asking to restore the menu
					cout<<"";
                    cin>>in;
					cout<<"";
                    getchar();
                } while (in == "y");
				cout<<"";
                cout << "  You are going to exite from the ATLAS GYM management System !!!";
                getchar();
                return 0;

            } else
                 cout << "                             Invalid login. Please try again.\n" << '\n';
            loginAttempt++;
        }
		if (loginAttempt == 3) // check the login attemps are complete 
		{
		getchar();
        cout << "                      Too many login attempts! The program will now terminate.";
		getchar();
        return 0;
		getchar();
		}
		return 0;
	}
}




#include <iostream>
#include <map>
using namespace std;


/*
This map will have the command as the key, and the
function to run on that particular command as the value.
*/
typedef void (*function_ptr)(void);
map<string, function_ptr> commands;


/*
Function Prototypes
*/

void displayWelcomeMenu();
void displayCommands();
void processCommand();
void createAccount();

/****************************/


/*
Menu Functions
*/
void displayWelcomeMenu(){

    cout << endl << "Welcome!" << endl;
    displayCommands();
}

void displayCommands(){
    cout << "*************" << endl;
    cout << "Commands:" << endl;
    cout << "Create Account: create-account" << endl;
    cout << "*************" << endl << endl;
}


/*
Command Functions
*/

void start(){

    /*
    Fill map with commands and their corresponding function
    to run on that command.
    */
    commands["create-account"] = &createAccount;

    processCommand();
}

void processCommand(){
    string input;
    
    //Get input
    cout << "cmd> ";
    getline(cin, input); 

    /* 
    Loop through map and find the function for that corresponding command.
    it->first: the command
    it->second: the function to run on that command
    */
    for(map<string, function_ptr>::iterator it = commands.begin(); it != commands.end(); ++it){
        if(input == it->first){
            it->second();
            break;
        }
    }
}

void createAccount(){
    cout << "Creating account...." << endl;
}

int main(){

    displayWelcomeMenu();
    start();
}
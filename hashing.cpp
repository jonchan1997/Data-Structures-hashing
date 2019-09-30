#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <bits/stdc++.h> 
#include "TimeInterval.h"

using namespace std;

struct Book {
  vector <string> word;
 
};

int main(int argc, char* argv[]) {
	//checks outer loop
	int outerL = 1;
	// response
	int response = 0;
	//maximum options
	// Read board size from user
	int a = 26;
	int b = 27;

	// Dynamically allocate array of arrays for dictionary words
	Book** board = new Book*[a];
	for (int i = 0; i < b; i++) {
		board[i] = new Book[b];
	}
	while(outerL == 1){
		
		cout << endl;
		cout << "1. Load Data (From File)" << endl;
		cout << "2. Exit Program" << endl;
		cout << "Please enter your selection:" << endl;
		cout << endl;
		// user input
		cin >> response;
		cout << endl;
		if( response == 1){
			// loads txt file
			int len = 0;
			string line;
			stringstream ss;
			ifstream inputText ("Dictionary.txt");
			if (inputText.is_open()){
				// reads in each line to lower case then to asci
				while( getline(inputText, line)){
					int first = 0;
					int second = 0;
					ss.str(line);
					string str; 
					ss >> str;
					transform(str.begin(), str.end(), str.begin(), ::tolower); 
					ss.str("");
					ss.str( std::string() );
					ss.clear();
					if(str.length() >= 2){
						first = (int(str.at(0)))- 97;
						second = (int(str.at(1))) -97;
						board[first][second].word.push_back(str);
					} else if(str.length() < 2){
						first = (int(str.at(0)))- 97;
						board[first][26].word.push_back(str);
					}
					len++;
				}
				inputText.close();
				cout<< "Dictionary Imported!"<<endl;
			}
			//saving text
			//outputting
			// check inner loop
			int innerL = 1;
			response = 0;
			while (innerL == 1){
				cout << endl;
				cout << "1. Spell Check" << endl;
				cout << "2. Exit Program" << endl;
				cout << "Please enter your selection:" << endl;
				cout << endl;
				//user input
				cin >> response;
				cout << endl;
				if( response == 1){
					int first = 0;
					int second = 0;
					cout<<endl;
					cout<<"Enter word for search:"<<endl;
					string input = "";
					cin>>input;
					cout<<endl;
					transform(input.begin(), input.end(), input.begin(), ::tolower); 
					first = int(input.at(0))- 97;
					if(input.length()<1){
						second = 26;
					}else{
						second = int(input.at(1)) -97;
					}
					int tru= 0;
					for (int i=0; i< board[first][second].word.size(); i++){     
						if(input == board[first][second].word[i]){
							tru=1;
							cout<<"Word does exist!"<<endl;
							
						}
						
						
					}
					if (tru == 0){
						cout<<"Word  does not exist!"<<endl;
						
					}
					if(tru == 1){
						TimeInterval* timer = new TimeInterval();
						timer->start();
						cout << "suggestion(s):"<<endl;
						for (int i=0; i< board[first][second].word.size(); i++){ 
							cout<< board[first][second].word[i]<<endl;
						
						
						}
						timer->stop();
						cout<<endl;
						cout<<timer->GetInterval();
						cout<<" micro-sec"<<endl;
						delete timer;
					}
					
					
				} else if( response == 2){
					//exit program
					innerL = 0;
					outerL = 0;
					// Free chess board arrays...MUST use array form "delete[]"!
					for (int i = 0; i < a; i++) {
						delete[] board[i];
					}
					delete[] board;
					break;
			
				} else {
					response = 0;
					continue;
				}
			}
			
		
		} else if( response == 2){
			//exit program
			outerL = 0;
			// Free dictionary
			for (int i = 0; i < a; i++) {
				delete[] board[i];
			}
			delete[] board;
			break;
		} else {
			response = 0;
			continue;
		}
		
	}
	
	return 0;
}

 
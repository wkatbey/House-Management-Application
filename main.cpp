//
//  main.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "houseType.h"
#include <fstream>
#include <map>

void houseMenu();
void primaryMenu();

void keyMenu();
void manual();

bool isEmpty(ifstream& inputFile);

void openSpace();
void closeSpace();


int main() {

	//Menu Variables
	char pMenu;
	char hMenu;
	char aMenu;
	string appMenu;

	//User input: Appliances
	int doorNum;
	int lightNum;
	int conditionerNum;
	double temperature;

	//General indexing variables
	map<string, houseType>::iterator itr;
	int aIndex;
	int counter;

	//Fstream variables
	ofstream writeHouse; //File output, uses stream insertion operator <<
	ifstream readHouse; //File input, uses stream extration operator >>
	
	ofstream writeSize;
	ifstream readSize;

	//Variables used in creation of a new house object
	int houseMapSize;
	string houseName;
	map<string, houseType> houseMap;
	houseType *tempHouse;


	//Opens file "size.txt" and extracts the number
	//of houses stored in the previous session
	
	readSize.open("size.txt");
	if (!readSize.eof())
	readSize >> houseMapSize;
	else
		houseMapSize = 0;
	readSize.close();

	readHouse.open("house.txt");
	int c = 0;
	while (!readHouse.eof() && c < houseMapSize) {
		tempHouse = new houseType;
		readHouse >> *tempHouse;
		houseMap.insert(pair<string, houseType>(tempHouse->getHouseName(), *tempHouse));
		c++;
	}
	readHouse.close();
	
	//Primary menu
	do {
		cin.clear();
		primaryMenu();
		cin >> pMenu;
	} while (!cin);
		
	while (pMenu != '3') {
		try {
			switch (pMenu) {
			case '1': //Option to access a house
				counter = 0;

				cout << "Enter House Name (Q to return): ";
				cin.ignore();
				getline(cin, houseName);

				if (houseName == "Q")
					throw string("Requested to return");

				itr = houseMap.find(houseName);

				while (itr == houseMap.end()) {
					cout << "House doesn't exist. Try again." << endl;
					
					cout << "Enter House Name (Q to return): ";
					//cin.ignore();
					getline(cin, houseName);

					if (houseName == "Q")
						throw string("Requested to return");

					itr = houseMap.find(houseName);

					if (++counter > 2)
						throw string("Too many login attempts");
				} 

				openSpace();
			
				cout << "Signed into '" << houseMap[houseName].getHouseName() << "'" << endl;
				cout << "Session has begun" << endl;

				houseMenu();
				cin.clear();

				cin >> hMenu;
				if (hMenu == '+' || hMenu == '-')
					cin >> aMenu >> aIndex;
				else if (hMenu == '#')
					cin >> aMenu >> aIndex >> temperature;

				while (hMenu != 'Q') {

					try {

						switch (hMenu) {
						case '+':
							switch (aMenu) {
							case 'd':
								if (houseMap[houseName].openDoor(aIndex))
									cout << "Opened Door " << aIndex << "." << endl;
								else
									cout << "Door " << aIndex << " does not exist" << endl;

								if (houseMap[houseName].isAlarmRinging()) {
									cout << "Alarm was armed when you opened the door" << endl;
									cout << "Alarm is currently ringing. Disarm" << endl;
								}
								break;
							case 'l':
								if (houseMap[houseName].lightSwitchOn(aIndex))
									cout << "Switched light " << aIndex << " on." << endl;
								else
									cout << "Light " << aIndex << " does not exist" << endl;
								break;
							case 'c':
								if (houseMap[houseName].conditionerSwitchOn(aIndex))
									cout << "Switched air conditioner " << aIndex << " on." << endl;
								else
									cout << "Conditioner " << aIndex << " does not exist" << endl;
								break;
							case 'a':
								houseMap[houseName].alarmSwitchOn();
								cout << "Alarm is turned on" << endl;
								break;
							}
							break;
						
						case '-':
							switch (aMenu) {
							case 'd':
								if (houseMap[houseName].closeDoor(aIndex))
									cout << "Closed door " << aIndex << "." << endl;
								else
									cout << "Door " << aIndex << " does not exist" << endl;
								break;
							case 'l':
								if (houseMap[houseName].lightSwitchOff(aIndex))
									cout << "Switched light " << aIndex << " off." << endl;
								else
									cout << "Light " << aIndex << " does not exist" << endl;
								break;
							case 'c':
								if (houseMap[houseName].conditionerSwitchOff(aIndex))
									cout << "Switched air conditioner " << aIndex << " off." << endl;
								else
									cout << "Conditioner " << aIndex << " does not exist" << endl;
								break;
							case 'a':
								houseMap[houseName].alarmSwitchOff();
								cout << "Alarm is turned off" << endl;
								break;
							
							}
							break;
						case '#':
							switch (aMenu) {
							case 'c':
							
								houseMap[houseName].conditionerSwitchOn(aIndex);
										
								if (houseMap[houseName].setConditionerTemperature(aIndex, temperature))
									cout << "Air Conditioner " << aIndex << " is set to "
										<< temperature << "F" << endl;
								else
									cout << "Conditioner " << aIndex << " does not exist" << endl;
								
								break;
							}
							break;
						case 'A':
							houseMap[houseName].armAlarm();
							cout << "Alarm is armed" << endl;
							break;
						case 'D':
							houseMap[houseName].disarmAlarm();
							cout << "Alarm is disarmed" << endl;
							break;
						case 's':
							cout << endl;
							cout << "House Information: " << endl
								<< endl;
							houseMap[houseName].houseInformation();
							break;
						case 'M':
							cout << endl;
							houseMenu();
							break;
						case 'K':
							cout << endl;
							keyMenu();
							break;
						case 'H':
							cout << endl;
							manual();
							break;
						case 'C':
							cin.clear();
							break;
						} //end switch hMenu
						
						
						if (!cin) {

						}
							throw string("Wrong input, try again");
					}
					catch (string str) {
					
						cout << "Exception caught in case 1 of switch statement 1: "
							<< str << endl;
						
						cin.clear();   
						cin.ignore(cin.rdbuf()->in_avail(), '\n');
						cin.rdbuf()->in_avail(); 
					}
					catch (...) {
						cout << "Exception caught in main, no paramater" << endl;
					}
					


					cin.ignore();
					cin >> hMenu;
					
					if (hMenu == '+' || hMenu == '-')
						cin >> aMenu >> aIndex;
					else if (hMenu == '#')
						cin >> aMenu >> aIndex >> temperature;

				} //end while

				closeSpace();
				break;

			case '2': //Option to create a house
				
				openSpace();

				cout << "Creating a new House." << endl;
				
				cin.ignore();

				do {
					cout << "Enter House Name (Q to return): ";
					
					getline(cin, houseName);

					if (houseName == "Q") throw string("Requested to return");
					
					itr = houseMap.find(houseName);

					if (itr != houseMap.end()) cout << "Name taken, use another name" << endl;

				} while (itr != houseMap.end());
				
				cout << "Enter the Number of: " << endl;
				
				cout << "Doors: ";
				cin >> doorNum;
				if (!cin)
					throw string("Input stream in fail state");
				
				cout << "Lights: ";
				cin >> lightNum;
				if (!cin)
					throw string("Input stream in fail state");
				
				cout << "Air Conditioners: ";
				cin >> conditionerNum;
				if (!cin)
					throw string("Input stream in fail state");

				cout << endl;

				tempHouse = new houseType(houseName, doorNum, lightNum, conditionerNum);

				cout << "Created House with name: '" << tempHouse->getHouseName() << "'"
					<< endl << "Access '"
					<< tempHouse->getHouseName() << "' through 'My House' " << endl;
				cout << "Returning to Primary Menu.. " << endl;
				closeSpace();

				houseMap.insert(pair<string, houseType>(tempHouse->getHouseName(),*tempHouse));
				break;
			} //end switch
		} //end try
		catch (string str) {
			openSpace();
			cout << str << endl << "Returning to main menu" << endl;
			closeSpace();
			cin.clear();    //clear errors/bad flags on cin

			cin.ignore(cin.rdbuf()->in_avail(), '\n');//precise amount of ignoring
			cin.rdbuf()->in_avail(); //returns the exact number of characters in the cin buffer.
		}

		primaryMenu();
		cin >> pMenu;

	}//end while 
	
	writeHouse.open("house.txt");
	for (itr = houseMap.begin(); itr != houseMap.end(); itr++)
			writeHouse << itr->second; 
	writeHouse.close();

	writeSize.open("size.txt");
	writeSize << houseMap.size();
	writeSize.close();
	

	return 0;
}

void primaryMenu() {
	cout << "Primary Menu" << endl;
	cout << "1 - My House" << endl;
	cout << "2 - Connect My House" << endl;
	cout << "3 - Exit" << endl;
	cout << "Enter an option: ";
}

void houseMenu() {
	cout << "House Menu:" << endl;
	
	cout << "+ \tOpen/Turn On" << endl;
	cout << "- \tClose/Turn Off" << endl;
	cout << "# \tSet Value" << endl;
	cout << "A \tArm Alarm" << endl;
	cout << "D \tDisarm Alarm" << endl;
	cout << "s \tHouse Information" << endl;

	cout << endl;

	cout << "K \tAppliance Code" << endl;
	cout << "M \tDisplay Menu" << endl;
	cout << "H \tManual" << endl;
	cout << "C \tClear Input Buffer" << endl;
	cout << "Q \tReturn" << endl;

	cout << "Enter command below" << endl;
}

void keyMenu() {
	cout << "Appliance Codes: " << endl;
	cout << "d - Door" << endl;
	cout << "l - Light" << endl;
	cout << "c - Air Conditioner" << endl;
}

void manual() {
	cout << "Manual: " << endl;
	cout << "To manipulate an appliance, input an operator " << endl
		<< "followed by its appliance code, followed by " << endl
		<< "the index of the appliance" << endl;
	cout << "+d0 = 'Open Door 0" << endl
		<< "-d0 = 'Close Door 0' " << endl
		<< "+l0 = 'Turn light on" << endl
		<< "-l0 = 'Turn light off" << endl;

	cout << "Warning: Opening the door whilst the alarm" << endl
		<< "is armed will activate the alarm's ring, disarm " << endl
		<< "to deactivate the ring." << endl;

	cout << "You can enter your commands in chains" << endl; 
	cout << "E.g. +d0-d1 = 'Open Door 0 and Close Door 1'" << endl;

	cout << "Enter all commands where the cursor is located" << endl;

}

/*void applianceMenu(string str) {
	cout << "Enter " << str << "name: ";
}

void doorMenu() {
	cout << "1 - Open Door" << endl;
	cout << "2 - Close Door" << endl;
	cout << "Enter an option: ";
}

void lightMenu() {
	cout << "1 - Turn Light On" << endl;
	cout << "2 - Turn Light Off" << endl;
	cout << "Enter an option: ";
}

void conditionerMenu() {
	cout << "1 - Turn Conditioner On" << endl;
	cout << "2 - Turn Conditioner Off" << endl;
	cout << "3 - Set Temperature" << endl;
	cout << "Enter an option: ";
}

void alarmMenu() {
	cout << "1 - Set Alarm On" << endl;
	cout << "2 - Set Alarm Off" << endl;
	cout << "3 - Arm" << endl;
	cout << "4 - Disarm" << endl;
	cout << "Enter an option: ";
}*/


bool isEmpty(ifstream& inputFile)
{
	return inputFile.peek() == ifstream::traits_type::eof();
}

void openSpace() {
	cout << endl;
	cout << "=======================================" << endl;
}

void closeSpace() {
	cout << "=======================================" << endl;
	cout << endl;
}
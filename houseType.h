//
//  houseType.hpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef houseType_h
#define houseType_h

#include "doorType.h"
#include "conditionerType.h"
#include "alarmType.h"
#include "lightType.h"
//#include <map>
#include "Sorting.cpp"

class houseType {

	friend ostream& operator<<(ostream& osObject, houseType& house);
	friend istream& operator>>(istream& isObject, houseType& house);

public:

	houseType(string name, int d, int l, int c);
	houseType();

	void setHouseName(string name);

	void setNumOfDoors(int);
	void setNumOfLights(int);
	void setNumOfConditioners(int);

	//Return house details
	unsigned long getNumOfDoors() const;
	unsigned long getNumOfLights() const;
	unsigned long getNumOfConditioners() const;
	string getHouseName() const;

	//Operations on Appliances
	bool openDoor(int i);
	bool closeDoor(int i);

	bool lightSwitchOn(int i);
	bool lightSwitchOff(int i);

	bool conditionerSwitchOn(int i);
	bool conditionerSwitchOff(int i);
	bool setConditionerTemperature(int i, double x);

	void alarmSwitchOn();
	void alarmSwitchOff();

	void armAlarm();
	void disarmAlarm();

	//Accessor Functions 
	bool isDoorOpen(int i) const;
	bool isLightOn(int i) const;
	bool isConditionerOn(int i) const;
	bool isAlarmOn() const;
	bool isAlarmArmed() const;
	bool isAlarmRinging() const;
	

	//House Information -- not for storage
	void houseInformation();
	void doorStatus();
	void lightStatus();
	void alarmStatus();
	void conditionerStatus();

	

protected:

	/*map<string, doorType> doorMap;
	map<string, lightType> lightMap;
	alarmType alarm;
	map<string, doorType> conditionerMap;*/

	vector<doorType> doorIndex;
	vector<lightType> lightIndex;
	alarmType alarm;
	vector<conditionerType> conditionerIndex;

	string houseName;
	bool cannotArm;
	int index;
};

#endif /* houseType_hpp */


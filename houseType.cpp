//
//  houseType.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "houseType.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

houseType::houseType(string name, int numOfDoors, int numOfLights, int numOfConditioners) {

	setHouseName(name);
	doorIndex.resize(numOfDoors);
	lightIndex.resize(numOfLights);
	conditionerIndex.resize(numOfConditioners);
	cannotArm = false;
}

houseType::houseType() {
	setHouseName("");
	doorIndex.resize(0);
	lightIndex.resize(0);
	conditionerIndex.resize(0);
	cannotArm = false;
}

ostream& operator<<(ostream& osObject, houseType& house) {


	osObject << house.getHouseName() << endl
		<< house.getNumOfDoors() << " "
		<< house.getNumOfLights() << " "
		<< house.getNumOfConditioners() << " "
		<< house.alarm << house.cannotArm << " ";
	
	osObject << endl;
	
	for (int c = 0; c < house.doorIndex.size(); c++)
		osObject << house.doorIndex[c] << endl;

	for (int c = 0; c < house.lightIndex.size(); c++)
		osObject << house.lightIndex[c] << endl;

	for (int c = 0; c < house.conditionerIndex.size(); c++)
		osObject << house.conditionerIndex[c] << endl;

	return osObject;
}

istream& operator>>(istream& isObject, houseType& house) {
	
	int doorSize, lightSize, condSize;
	
	isObject >> house.houseName;

	isObject >> doorSize
		>> lightSize
		>> condSize
		>> house.alarm >> house.cannotArm;

	house.doorIndex.resize(doorSize);
	house.lightIndex.resize(lightSize);
	house.conditionerIndex.resize(condSize);

	for (int c = 0; c < house.doorIndex.size(); c++)
		isObject >> house.doorIndex[c];
	
	for (int c = 0; c < house.lightIndex.size(); c++) 
		isObject >> house.lightIndex[c];

	for (int c = 0; c < house.conditionerIndex.size(); c++)
		isObject >> house.conditionerIndex[c];
	
	return isObject;
}

void houseType::setHouseName(string name) {
	houseName = name;
}

void houseType::setNumOfDoors(int num) {
	doorIndex.resize(num);
}

void houseType::setNumOfLights(int num) {
	lightIndex.resize(num);
}

void houseType::setNumOfConditioners(int num) {
	conditionerIndex.resize(num);
}


unsigned long houseType::getNumOfDoors() const {
	return doorIndex.size();
}
unsigned long houseType::getNumOfLights() const {
	return lightIndex.size();
}
unsigned long houseType::getNumOfConditioners() const {
	return conditionerIndex.size();
}

string houseType::getHouseName() const {
	return houseName;
}

/*void houseType::applianceMenu(string str) {
	cout << "Input the " << str << " name: ";
}*/

bool houseType::openDoor(int i) {
	if (i < 0 || doorIndex.size() <= i)
		return false;
	else {
		doorIndex[i].open();
		if (alarm.isAlarmArmed()) {
			alarm.ringAlarm();
		}
		return true;
	}
}

bool houseType::closeDoor(int i) {
	if (i < 0 || doorIndex.size() <= i)
		return false;
	else {
		doorIndex[i].close();
		return true;
	}
		
}

bool houseType::lightSwitchOn(int i) {
	if (i < 0 || lightIndex.size() <= i)
		return false;
	else {
		lightIndex[i].setLightOn();
		return true;
	}
		
}

bool houseType::lightSwitchOff(int i) {
	if (i < 0 || lightIndex.size() <= i)
		return false;
	else {
		lightIndex[i].setLightOff();
		return true;
	}
	
}

void houseType::alarmSwitchOn() {
	alarm.setAlarmOn();
}

void houseType::alarmSwitchOff() {
	alarm.setAlarmOff();
}

void houseType::armAlarm() {
	int j = 0;
	
	while (j < doorIndex.size() && cannotArm == false) {
		if (doorIndex[j++].isDoorOpen())
			cannotArm = true;
	}
	
	if (cannotArm)
		cout << "Invalid: Cannot arm with doors open. Close all doors." << endl;
	else
		alarm.arm();
}

void houseType::disarmAlarm() {
	if (alarm.isAlarmArmed())
		alarm.disarm();
}

bool houseType::conditionerSwitchOn(int i) {
	if (i < 0 || conditionerIndex.size() <= i)
		return false;
	else {
		conditionerIndex[i].setConditionerOn();
		return true;
	}
		
}

bool houseType::conditionerSwitchOff(int i) {
	if (i < 0 || conditionerIndex.size() <= i)
		return false;
	else {
		conditionerIndex[i].setConditionerOff();
		return true;
	}
		
}

bool houseType::isDoorOpen(int i) const {
	return (doorIndex[i].isDoorOpen());
}

bool houseType::isLightOn(int i) const {
	return (lightIndex[i].isLightOn());
}

bool houseType::isConditionerOn(int i) const {
	return (conditionerIndex[i].isConditionerOn());
}

bool houseType::isAlarmOn() const {
	return (alarm.isAlarmOn());
}
bool houseType::isAlarmArmed() const {
	return (alarm.isAlarmArmed());
}
bool houseType::isAlarmRinging() const {
	return (alarm.isAlarmRinging());
}

bool houseType::setConditionerTemperature(int i, double x) {
	
	if (i < 0 || conditionerIndex.size() <= i)
		return false;
	else {
		conditionerIndex[i].setTemperature(x);
		return true;
	}
}

void houseType::houseInformation() {
	alarmStatus();
	cout << endl;
	doorStatus();
	cout << endl;
	lightStatus();
	cout << endl;
	conditionerStatus();
}

void houseType::doorStatus() {
	for (unsigned long i = 0; i < doorIndex.size(); i++) {
		if (doorIndex[i].isDoorOpen())
			cout << "Door [" << i << "] open." << endl;
		else
			cout << "Door [" << i << "] closed." << endl;
	}
}


void houseType::lightStatus() {
	for (unsigned long i = 0; i < lightIndex.size(); i++) {
		if (lightIndex[i].isLightOn())
			cout << "Light [" << i << "] is on." << endl;
		else
			cout << "Light [" << i << "] is off." << endl;
	}
}

void houseType::alarmStatus() {
	if (alarm.isAlarmOn()) {
		cout << "Alarm is on ";
		if (alarm.isAlarmArmed())
			cout << "and armed" << endl;
		else
			cout << "and disarmed" << endl;
	}
	else
		cout << "Alarm is off." << endl;
}

void houseType::conditionerStatus() {
	for (unsigned long i = 0; i < conditionerIndex.size(); i++) {
		if (conditionerIndex[i].isConditionerOn()) {
			cout << "Conditioner [" << i << "] is on." << endl;

			if (conditionerIndex[i].getTemperature() > -1)
				cout << "Temperature: " << conditionerIndex[i].getTemperature() << "F." << endl;
			else
				cout << "Temperature is not properly set" << endl;
		}
		else
			cout << "Conditioner [" << i << "] is off." << endl;
	}
}









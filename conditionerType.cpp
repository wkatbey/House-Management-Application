//
//  conditionerType.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "conditionerType.h"

conditionerType::conditionerType(bool isOn, double temper)
	:conditionerOn(isOn), temperature(temper) {}

ostream& operator<<(ostream& osObject, conditionerType& cond) {
	osObject << cond.conditionerOn << " " << cond.temperature << " ";
	return osObject;
}

istream& operator>>(istream& isObject, conditionerType& cond) {
	isObject >> cond.conditionerOn >> cond.temperature;
	return isObject;
}


void conditionerType::setTemperature(double x) {
	if (isConditionerOn())
		temperature = x;
	else
		throw string("Cannot set temperature, conditioner is off");
}

double conditionerType::getTemperature() const {
	if (conditionerOn)
		return temperature;
	else
		return -1;
}

void conditionerType::setConditionerOn() {
	conditionerOn = true;	
}

void conditionerType::setConditionerOff() {
	conditionerOn = false;
}

bool conditionerType::isConditionerOn() const {
	return (conditionerOn);
}

bool conditionerType::isConditionerOff() const {
	return (!conditionerOn);
}


/*ostream& operator<<(ostream& osObject, conditionerType& cond) {
	osObject << cond.applianceName;
	osObject << cond.conditionerOn;

	if (cond.conditionerOn)
		osObject << cond.temperature;

	return osObject;
}

istream& operator>>(istream& isObject, conditionerType& cond) {

	isObject.ignore();
	getline(isObject, cond.applianceName);

	isObject >> cond.conditionerOn;

	if (cond.conditionerOn)
		isObject >> cond.temperature;

	return isObject;
}*/
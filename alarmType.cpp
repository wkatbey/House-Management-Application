//
//  alarmType.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "alarmType.h"

ostream& operator<<(ostream& osObject, alarmType& alarm) {
	osObject << alarm.alarmOn << " " << alarm.alarmArmed << " " << alarm.alarmRinging << " ";
	return osObject;
 }


 istream& operator>>(istream& isObject, alarmType& alarm) {
	 isObject >> alarm.alarmOn >> alarm.alarmArmed >> alarm.alarmRinging;
	 return isObject;
}

alarmType::alarmType(bool on, bool arm, bool ring) 
	:alarmOn(on), alarmArmed(arm), 
	alarmRinging(ring){}

void alarmType::setAlarmOn() {
	alarmOn = true;
}

void alarmType::setAlarmOff() {
	alarmOn = false;
}

void alarmType::arm() {
	alarmArmed = true;
}

void alarmType::disarm() {
	alarmArmed = false;
	alarmRinging = false;
}

void alarmType::ringAlarm() {
	alarmRinging = true;
}

bool alarmType::isAlarmOn() const {
	return (alarmOn);
}

bool alarmType::isAlarmArmed() const {
	return (alarmArmed);
}

bool alarmType::isAlarmRinging() const {
	return (alarmRinging);
}

/*ostream& operator<<(ostream& osObject, alarmType& alarm) {

osObject << alarm.alarmOn;
osObject << alarm.alarmArmed;

return osObject;
}

istream& operator>>(istream& isObject, alarmType& alarm) {

isObject >> alarm.alarmOn;
isObject >> alarm.alarmArmed;

return isObject;
}*/

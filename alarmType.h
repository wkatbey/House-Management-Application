//
//  alarmType.hpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef alarmType_h
#define alarmType_h

#include "applianceType.h"

class alarmType {

	friend ostream& operator<<(ostream& osObject, alarmType& alarm);
	friend istream& operator>>(istream& isObject, alarmType& alarm);

public:

	alarmType(bool = false, bool = false, 
		bool = false);

	void setAlarmOn();
	void setAlarmOff();

	void arm();
	void disarm();
	void ringAlarm();

	bool isAlarmOn() const;
	bool isAlarmArmed() const;
	bool isAlarmRinging() const;

private:
	bool alarmOn;
	bool alarmArmed;
	bool alarmRinging;

};


#endif /* alarmType_hpp */


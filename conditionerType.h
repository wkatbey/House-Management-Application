//
//  conditionerType.hpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef conditionerType_h
#define conditionerType_h

#include "applianceType.h"

class conditionerType : public applianceType {

	friend ostream& operator<<(ostream& osObject, conditionerType& cond);
	friend istream& operator>>(istream& isObject, conditionerType& cond);

public:

	conditionerType(bool = false, double = 60);
	

	void setTemperature(double x = 60);
	double getTemperature() const;

	void setConditionerOn();
	void setConditionerOff();

	bool isConditionerOn() const;
	bool isConditionerOff() const;

private:
	bool conditionerOn;
	double temperature;
};


#endif /* conditionerType_hpp */

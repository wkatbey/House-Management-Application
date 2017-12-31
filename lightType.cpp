//
//  lightType.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "lightType.h"

ostream& operator<<(ostream& osObject, lightType& light) {
	
	osObject << light.lightOn << " ";
	return osObject;
}

istream& operator>>(istream& isObject, lightType& light) {

	isObject >> light.lightOn;
	return isObject;
}

void lightType::setLightOn() {
	lightOn = true;
}

void lightType::setLightOff() {
	lightOn = false;
}

bool lightType::isLightOn() const {
	return (lightOn);
}

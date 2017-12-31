//
//  doorType.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "doorType.h"

ostream& operator<<(ostream& osObject, doorType& door) {

	osObject << door.doorOpen << " ";

	return osObject;
}

istream& operator>>(istream& isObject, doorType& door) {

	isObject >> door.doorOpen;

	return isObject;
}

void doorType::open() {
	doorOpen = true;
}

void doorType::close() {
	doorOpen = false;
}

bool doorType::isDoorOpen() const {
	return (doorOpen);
}

bool doorType::isDoorClosed() const {
	return (!doorOpen);
}

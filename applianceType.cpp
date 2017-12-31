//
//  applianceType.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "applianceType.h"


istream& operator>>(istream& isObject, applianceType& app) {




	return isObject;
}


void applianceType::setName(string name) {
	applianceName = name;
}

string applianceType::getName() const {
	return applianceName;
}

void applianceType::setID(int i) {
	id = i;
}

int applianceType::getID() const {
	return id;
}
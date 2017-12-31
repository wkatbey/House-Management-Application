//
//  lightType.hpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef lightType_h
#define lightType_h

#include "applianceType.h"

class lightType : public applianceType {

	friend ostream& operator<<(ostream& osObject, lightType& light);
	friend istream& operator>>(istream& isObject, lightType& light);

public:
	void setLightOn();
	void setLightOff();

	bool isLightOn() const;

private:
	bool lightOn;
};

#endif /* lightType_hpp */

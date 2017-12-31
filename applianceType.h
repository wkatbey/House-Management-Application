//
//  applianceType.hpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef applianceType_h
#define applianceType_h

#include <string>
#include <iostream>
using namespace std;

class applianceType {

	friend istream& operator>>(istream& isObject, applianceType& app);

public:
	virtual void setName(string);
	virtual string getName() const;

	virtual void setID(int);
	virtual int getID() const;

protected:
	string applianceName;
	int id;
};



#endif /* applianceType_hpp */

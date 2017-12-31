//
//  doorType.hpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#ifndef doorType_h
#define doorType_h

#include "applianceType.h"

class doorType : public applianceType {
	friend ostream& operator<<(ostream& os, doorType& door);
	friend istream& operator>>(istream& is, doorType& door);
public:
	void open();
	void close();

	bool isDoorOpen() const;
	bool isDoorClosed() const;

private:
	bool doorOpen;

};



#endif /* doorType_hpp */

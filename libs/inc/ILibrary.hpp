//
// Created by Kyle GANI on 2017/06/08.
//

#ifndef NIBBLER_ILIBRARY_HPP
#define NIBBLER_ILIBRARY_HPP

class ILibrary{
public:
	virtual int keyhook() = 0;
	virtual void print() = 0;
	virtual ~ILibrary(){};
};

typedef ILibrary* createLib_t(int, int);
typedef void destroyLib_t(ILibrary *library);

#endif //NIBBLER_ILIBRARY_HPP

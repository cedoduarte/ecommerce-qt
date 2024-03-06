#ifndef STORE_H
#define STORE_H

#include "interfaces.h"

class Store
{
public:
    Store() = delete;

    static IUserViewModel currentUser;
};

#endif // STORE_H

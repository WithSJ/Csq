#if !defined(CLASSCSQ_H)
#define CLASSCSQ_H

#include <functional>
#include <map>
#include "memory.h"

/*
This in every case will be representing a class
*/
class Class {
public:
    string name;
    map<string, function<void(vector<Cell>&)>> methods;
    map<string, Cell&> methods;
};

#endif // CLASSCSQ_H

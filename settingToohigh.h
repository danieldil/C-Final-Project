#ifndef SETTINGTOOHIGH_H
#define SETTINGTOOHIGH_H
#include<stdexcept>
//#include<string>
//#include<iostream>
using namespace std;
class settingToohigh : public runtime_error
{public:
settingToohigh();
};
#endif SETTINGTOOHIGH_H
#ifndef SETTINGNEGATIVE_H
#define SETTINGNEGATIVE_H
#include<stdexcept>
//#include<string>
//#include<iostream>
using namespace std;
class settingNegative : public runtime_error
{public:
settingNegative();
};
#endif SETTINGNEGATIVE_H
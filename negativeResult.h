#ifndef NEGATIVERESULT_H
#define NEGATIVERESULT_H
#include<stdexcept>
//#include<string>
//#include<iostream>
using namespace std;
class negativeResult : public runtime_error
{public:
negativeResult();
};
#endif NEGATIVERESULT_H
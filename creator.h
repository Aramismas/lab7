#ifndef creator_h
#define creator_h
#include "base.hpp" 
#include<iostream>

class Creator{

private:
  Base* val;
public:

  Creator(Base* temp) : temp(val); 
  Base* parse(char** input, int length); 

}; 

#endif //add_h

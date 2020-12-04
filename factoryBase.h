#ifndef factorybase_h
#define factorybase_h
#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include <iostream>
#include <stack>

class Factory{

private:
  
   

public:
  Factory(); 
  Base* parse(char** input, int length); 

}; 

#endif //add_h

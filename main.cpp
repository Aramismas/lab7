#include <iostream>
#include <math.h>
#include "base.hpp"
#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "factoryBase.h"
int main(int argc, char** argv) {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
	
       Factory* f = new Factory(); 


       Base* ptr = f->parse(argv, argc);
std::cout << ptr->stringify() << " = " << ptr->evaluate() << '\n' ; 
 
    	
    return 0; 

}   

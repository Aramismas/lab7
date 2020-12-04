#include "factoryBase.h"
#include <stdio.h>	
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <cctype>

using namespace std; 

Factory::Factory()
{

}


Base* Factory::parse(char** input, int length)
{
 Base* firstval;
 Base* secondval; 
 char temp  = *input[1];
 char temp1 = *input[2]; 
 char temp2 = *input[3]; 
 char temp3;
 Base* current;
 int i = 4; 
	if (length <= 1) {
	    cout << "Invalid Input" << endl;
	    return nullptr;
	}	
	if(isdigit(temp) )
	{   

		firstval = new Op(stod(input[1])); 
       	
	
		 if(temp1 =='*')
	      { 
		 if(*input[3] == '*')
                {

                  temp3 = *input[4];

                 if(isdigit(temp3))
                {
                  secondval = new Op(stod(input[4]));
                  current = new Pow(firstval, secondval);
                  i++;
                }


                else
                {
                        cout << "Invalid input " << endl;
                        return nullptr;

                }
               }
		else
		{
		
		if(isdigit(temp2))
		{
		
		  secondval = new Op(stod(input[3])); 
		  current = new Mult(firstval, secondval);
		}

			
		else
		{
			cout << "Invalid input" << endl;
                        return nullptr;
		
	        }
		}
		}

		
	 	else if(temp1 == '/')
              {
	       
		if(isdigit(temp2))
                {
                  secondval = new Op(stod(input[3]));

                  current = new Div(firstval, secondval);
                }

                else
                {
                        cout << "Invalid input" << endl;
                        return nullptr;	   
                }	
	
	     }
	 	else if(temp1 == '+')
            {
		 if(isdigit(temp2))
                {
                  secondval = new Op(stod(input[3]));
                  current = new Add(firstval, secondval);
                }

               else
                {
                        cout << "Invalid input  " << endl;
                        return nullptr;
		}
	
	   }
	 	else if(temp1 == '-')
              {
		   if(isdigit(temp2))
                {
                  secondval = new Op(stod(input[3]));
                  current = new Sub(firstval, secondval);
                }


                else
                {
                        cout << "Invalid input " << endl;
                        return nullptr;
                }	
	     
		}	
	
	
	else 
	{
	 cout << " Invalid input " << endl; 
	return nullptr;
	}
            
	Base* first = current; 	
	if(length <  i) 
	{ 
	return first; 
	}	
	 	
	for(i;  i  < length  ; i+= 2) 
	{
	   temp = *input[i];		 
	 	
		 if(temp == '*')
	      { 
		  if(*input[i + 1] == '*')
                {

                  temp1 = *input[i+2];

                 if(isdigit(temp1))
                {
                  secondval = new Op(stod(input[i+2]));
                  current = new Pow(first, secondval) ;
                  i++;
                }

		
                else
                {
                        cout << "Invalid input  " << endl;
                        return nullptr;

                }
             }
		else
		{
		  
  			
                temp1 = *input[i + 1];

                if(isdigit(temp1))
                {
                  secondval = new Op(stod(input[i+1]));
                  current = new Mult(first, secondval);
                }
                else
                {
                        cout << "Invalid input  " << endl;
                        return nullptr;

                }
		}

	}		
	 	else if(temp == '/')
              {
	       temp1 = *input[i + 1]; 
		if(isdigit(temp1))
                {
                  secondval = new Op(stod(input[i+1]));

                  current = new Div(first, secondval);
                }

                else
                {
                        cout << "Invalid input" << endl;
                        return nullptr;	   
                }	

	 	}
		else if(temp == '+')
		{	 temp1 = *input[i + 1];
 
			if(isdigit(temp1))
                {
                  secondval = new Op(stod(input[i+1]));
                  current = new Add(first, secondval);
                }
		
               else
                {
                        cout << "Invalid input" << endl;
                        return nullptr;
		}
	      }
	 	else if(temp == '-')
              {		temp1 = *input[i + 1]; 
		   if(isdigit(temp1))
                {
                  secondval = new Op(stod(input[i+1]));
                  current = new Sub(first, secondval);
                }


                else
                {
                        cout << "Invalid input " << endl;
                        return nullptr;
                }	
	     
		}	
	
	
	else 
	{
	 cout << " Invalid input " << endl; 
	


	return nullptr; 		 
	}
     first = current;
    }
}

return current; 
}

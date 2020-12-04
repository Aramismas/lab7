#include "factoryBase.h"
#include <stdio.h>	
#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using namespace std; 

Factory::Factory()
{

}


Base* Factory::parse(char** input, int length)
{
 Base* ch; 
 Base* firstval; 
 Base* secondval;
 char temp  = *input[1];
 char temp1 = *input[2]; 
 char temp2 = *input[3]; 
 char temp3;
 Base* current;
 int i = 3; 
	
	if(isdigit(temp) )
	{
		
		firstval = new Op(temp - '0'); 
       	
	
		 if(temp1 =='*')
	      { 

		if(isdigit(temp2))
		{
		  secondval = new Op(temp2 -'0'); 
		  current = new Mult(firstval, secondval);
		}
		 if(*input[3] == '*')
		{ 
		  
		  temp3 = *input[4]; 
		 
		 if(isdigit(temp3))
		{
		  secondval = new Op(temp3 - '0');
		  current = new Pow(temp3 - '0'); 
	     	  i++; 
		}

	
		else
		{
			cout << "Invalid in first " << endl;
                        return nullptr;
		
		}			      
	  
	       }		
	     }
		
	 	else if(temp1 == '/')
              {
	       
		if(isdigit(temp2))
                {
                  secondval = new Op(temp2 - '0');

                  current = new Div(firstval, secondval);
                }

                else
                {
                        cout << "Invalid in first " << endl;
                        return nullptr;	   
                }	

	 	else if(temp1 == '+')
            {
		 if(isdigit(temp2))
                {
                  secondval = new Op(temp2 - '0');
                  current = new Add(firstval, secondval);
                }

               else
                {
                        cout << "Invalid in first " << endl;
                        return nullptr;
		}
	   }
	 	else if(temp1 == '-')
              {
		   if(isdigit(temp2))
                {
                  secondval = new Op(temp2 - '0');
                  current = new Sub(firstval, secondval);
                }


                else
                {
                        cout << "Invalid in first " << endl;
                        return nullptr;
                }	
	     
		}	
	
	
	else 
	{
	 cout << " Invalid in first " << endl; 
	return nullptr
	}

	Base* first = current; 
	
	if(length =< i) 
	{ 
	return first; 
	}
	
	for(i;  i  < length; i++) 
	{
		 
	
	}
}
/* 
	 for(int j = 0; j < length; j++) 
	{
	 ch = *input[j]; 
	
	if(isdigit(ch[j]) && isdigit(ch[j + 2])) 
	{ 
		double value = atof(ch[j]); 
	 	s.push(Base* val = new Op(value )); 
	}
	
	else if (ch == "**") &&(lasttop == '*' && (lastop == '+' || lastop == '-')) 
         { 
  	   if(s.peek() == 1)
		s.push(ch);
	else {
	   lastval = s.pop(); 
	   lasttop = s.pop(); 
	   
 		if ((ch == '*' || ch == '/') 
                    && (lastop == '+' || lastop == '-')) 
		{ 
  
                  
              s.push(lastop); 
              s.push(lastval); 
                                                         } 
		} 
	
        else{
	 	
	switch(lastop){
	  case '+':
		Add* a = new Add(s.pop(), lastval); 
		s.push(a); 
 	
		break; 
	  case '-':
	 	Sub* temp = new Sub(s.pop(), lastval); 
		s.push(temp); 
	  case '*':
		Mult* m = new Mult(s.pop(), lastval); 
		s.push(m); 
	  case '/': 
		Div* d = new Div(s.pop(), lastval); 
		s.push(d)
		}        
           } */

#pragma once
#include <iostream>
#include <string>

// Forward declare CoffeeBuilder class here to avoid compilation errors
class CoffeeBuilder;

// Coffee class declaration
class Coffee {
	std::string requestorName;

	public:
		bool isHot;
		bool hasMilk;
		bool hasSugar;
		double cost;

		Coffee(std::string requestorName) : requestorName(requestorName) {}

	  /*We have declared the CoffeeBuilder Class as a friend.
		A friend class can access private and protected members of other class 
		in which it is declared as friend.
		This allows a CoffeeBuilder object to peek into 
		the internals of the coffee it creates.*/
		friend class CoffeeBuilder;
		
		/*
		The static member function create() which will return an instance 
		of a CoffeeBuilder - the class that encapsulates all of the logic 
		for the step-by-step workflow we want to implement"
		*/ 
		static CoffeeBuilder create(std::string requestorName);
		/*
		Note:
		1)
		A non-static member function can be called only after instantiating 
		the class as an object. 
		This is not the case with static member functions. 
		A static member function can be called, 
		even when a class is not instantiated.
		2)
		A static member function cannot have access to the this pointer 
		of the class.
		3)
		A non-static member function can be declared as virtual 
		but care must be taken not to declare a static member function 
		as virtual.
		4)
		A static member function can only access static member data,
		static member functions and data and functions outside the class. 
		5)
		It is possible to declare a data member of a class as static irrespective
		of it being a public or a private type in class definition.
		If a data is declared as static, then the static data is created 
		and initialized only once.  
		*/
};

// CoffeeBuilder class declaration - responsible for building a Coffee
class CoffeeBuilder {
    //CoffeeBuilder creates a basic coffee object.
	Coffee coffee;

	public:
		CoffeeBuilder(std::string requestorName) : coffee(Coffee(requestorName)) {}

		/* This operator allows us to convert from a CoffeeBuilder to a Coffee 
		Function Call Operator () Overloading in C++
		The operator that will allow for an easy conversion between 
		the CoffeeBuilder class to the Coffee class.
		*/
		
		/* This will allow us to use the CoffeeBuilder type to build 
		the Coffee class while hiding away the "CoffeeBuilder" class from
		the client.
		*/
		operator Coffee() const { return std::move(coffee); }

		CoffeeBuilder&  makeHot();
		CoffeeBuilder&  addMilk();
		CoffeeBuilder&  addSugar();
		CoffeeBuilder&  costs(double cost);
};

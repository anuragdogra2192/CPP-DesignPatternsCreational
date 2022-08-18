#include "builder.h"
#include <iostream>
#include <string>

// Implement the Coffee classes "create" method
// This method returns an instance of a CoffeeBuilder, which will
// allow us to build coffees step by step. 

// And below this, we implement all of the buildr methods for each part
//of the API. Here, we have four methods.
CoffeeBuilder Coffee::create(std::string requestorName) {
	return CoffeeBuilder{requestorName};
}

// Builder methods
CoffeeBuilder&  CoffeeBuilder::makeHot() {
	coffee.isHot = true;
	return *this;
};

CoffeeBuilder&  CoffeeBuilder::addSugar() {
	coffee.hasSugar = true;
	return *this;
};

CoffeeBuilder&  CoffeeBuilder::addMilk() {
	coffee.hasMilk = true;
    return *this;
};

CoffeeBuilder&  CoffeeBuilder::costs(double cost) {
    coffee.cost = cost; 
    return *this;
};


int main() { 
	//Here we are building two coffees. 
	//First, we call this "static create" method with the name
	//of the person who requested the coffee. From there, we can 
	//easily chain our builder methods, one on top of the other,
	//stoping when we are done building our coffee. 

	//BECAUSE of the Operator() overloading we added inside the 
	//CoffeeBuilder class, we can easily assign the CoffeeBuilder object
	//returned by any of these methods to the "coffee" variable here. 

	//A static member function can be called, 
	//even when a class is not instantiated.


//node 
//parent
//left




class SweetWhiteBuilder : public CoffeeBuilder
{
SweetWhiteBuilder(std::string requestorName) : CoffeeBuilder(requestorName) 
{
	addSugar();
	addMilk();
}
}

	SweetWhiteBuilder  builder("Olaf");
	class cappucino : public Coffee;

	Coffee coffee = builder;
    
	Coffee coffee = Coffee::create("Zachary")
							  .makeHot()
							  .addSugar()
							  .addMilk()
							  .costs(4.00);

    Coffee coffee2 = Coffee::create("Jennifer")
							  .makeHot()
							  .costs(3.50);

    std::cout << coffee.cost << std::endl;
    std::cout << coffee2.cost << std::endl;

    return 0;
}

/*
The builder pattern simplifies object creation while providing
a very user-friendly API.
*/

#pragma once

#include <memory>
#include "icoffee-service.h"

class CoffeeMachine {
	public:
	/*Step 1
	In this header file, we have declared the CoffeeMachine class. 
	This class has a public constructor 
	that expects a reference to a CoffeeService interface. 
	More on that later. 
	This constructor takes advantage of "move" semantics 
	to set the private internal reference of this dependency.
	*/
		CoffeeMachine(std::unique_ptr<ICoffeeService>&& coffeeSvc) : coffeeService(std::move(coffeeSvc)) {}

		void brew();

	private:
		std::unique_ptr<ICoffeeService> coffeeService;
};

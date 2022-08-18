#pragma once

#include <memory>
//Step 3
/*
Our interface for defining a coffee service. 
This is our example struct, which exists as a dependency to the CoffeeMachine class. 
This struct defines a simple interface, which can be implemented by more specific types. 
These types must implement a sendMetrics method
*/

// Interface for defining a CoffeeService type
struct ICoffeeService {
	virtual void sendMetrics() = 0;
	virtual ~ICoffeeService() = default;
};

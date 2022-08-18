#include <iostream>

#include "coffee-machine.h"
#include "icoffee-service.h"

//Step 5
/*
Now let's see a simple example of dependency injection over in the main.cpp file.
This is an example of how to use our simple API. 

In this example, a client wants to test the CoffeeMachine class. 
Knowing that the CoffeeMachine class depends upon a coffee service, 
the client creates a stub class MockCoffeeService, which implements the required interface.
*/
class MockCoffeeService : public ICoffeeService {
	void sendMetrics() override {
		std::cout << "Sending mock metrics!\n";
	}
};

/*
With that complete, down in the main function, a new machine is instantiated 
by passing in a smart pointer to a MockCoffeeService. 

This is an example of constructor injection. 
To keep things simple, we're not using an injector class, 
although very sophisticated dependency injection frameworks or 
systems have a separate injector or dependency injection container 
that handles this constructor injection for you. 

We then call the brew method on the CoffeeMachine. 

If we compile all this code and run the resulting executable, 
we can see that the coffee was brewed and the mock metrics were sent. 

This is a simple example, but it's a very powerful thing to be able to pass 
in the coffee service dependency into the CoffeeMachine class constructor. 
This ultimately means that coffee machines are decoupled from coffee services, 
which makes the coffee machine code much easier to test, maintain, and extend. 

I hope that this example has shown you how powerful dependency injection can be. 
In the real world, there are many libraries or frameworks that exist, 
which handle dependency injection for you via a dependency injection container or injector. 

This is a very popular pattern that is used throughout the world's code,
and it's also a pattern that you very rarely need to implement yourself.
Go ahead and have a look for yourself by searching for dependency injection framework for C++.

Congratulations on completing the last demo within this course on creational design patterns 
in C++.
*/

// Example of simple "constructor injection" using interfaces
int main() {
	CoffeeMachine myMachine(std::make_unique<MockCoffeeService>());

	// Test my machine with a mock coffee service
	myMachine.brew();
}

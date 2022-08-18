#include <iostream>
#include <memory>

//This is the Abstract base class.
class CoffeeMachine {
	public:
		virtual void brew() = 0;
};
 
class SimpleCoffeeMachine: public CoffeeMachine {
	public:
		void brew() {
			std::cout << "Brewing simple coffee \n";
		}
};
 
class RobustCoffeeMachine: public CoffeeMachine  {
	public:
		void brew() {
			std::cout << "Brewing robust coffee \n";
		}
};

/*
 This CoffeeMachineFactory class provides our factory method for creating coffee machines.
*/

// This factory class simply encapsulates the factory method for a CoffeeMachine type.
class CoffeeMachineFactory {
	public:
/*
This method is called createMachine, and it accepts an integer which corresponds to the type
of coffee machine you want to create. 

This integer is then fed into a switch statement, which then returns a SMART pointer 
to the created machine. 

There are several ways to implement a factory method function.

Instead of using a switch statement, for instance, you could use C++ templates 
alongside a static factory method.Or We can ensure that each type contains its own factory
method. But the key takeaway here is that the factory method pattern is all about
providing a single method which is used to create objects.

This method encapsulates the logic for creating new objects, 
such that the objects in question are NOT created directly 
by the CLIENT via a CONSTRUCTOR.
*/
		std::unique_ptr<CoffeeMachine> createMachine(int machineType) {
			switch(machineType) {
				case 1:
					return std::make_unique<SimpleCoffeeMachine>();
				case 2:
					return std::make_unique<RobustCoffeeMachine>();
				default:
					return std::make_unique<SimpleCoffeeMachine>();
			}
		}
};

/*
In the main function, we can see how to use this implementation of the factory method pattern.
First, we create a factory, which contains our factory method. 
Again, it's not required to create a factory class in order to implement this pattern, 
although you can do this. 
It's also possible to put a factory method on the abstract base class itself.

This factory method is then implemented by the concrete classes.
For example, our CoffeeMachine base class might have the create method, 
and this method could then be implemented by both the Simple and RobustCoffeeMachine classes. 

Now that we have access to our factory method, we then use this method 
to create the coffee machines we want. 

This is the simplest of the more advanced creational design patterns. 

*/
int main()
{
	std::unique_ptr<CoffeeMachineFactory> factory = std::make_unique<CoffeeMachineFactory>();

	auto machineOne = factory->createMachine(1);
	auto machineTwo = factory->createMachine(2);

	machineOne->brew();
	machineTwo->brew();

	return 0;
}

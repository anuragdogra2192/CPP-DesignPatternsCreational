#include <iostream>
#include <memory>

//Base Abstract Class
class CoffeeMachine {
	public:
		virtual void brew() = 0;
};
 
//Concrete Class 
class SimpleCoffeeMachine: public CoffeeMachine {
	public:
		void brew() {
			std::cout << "Brewing simple coffee \n";
		}
};

//Concrete class
class RobustCoffeeMachine: public CoffeeMachine  {
	public:
		void brew() {
			std::cout << "Brewing robust coffee \n";
		}
};

//Here we then have three more classes, which define a different family of objects. 
//In practice, a coffee machine would probably create a coffee type, maybe even via a factory
// of its own.

/*
Maybe even via a factory of its own, and so they wouldn't really be brother or sister objects
created by the same factory. 
But for the purpose of this demonstration, 
we're going to pretend that that relationship doesn't exist.
*/
class Coffee {
	public:
		virtual void stir() = 0;
};
 
class SimpleCoffee: public Coffee {
	public:
		void stir() {
			std::cout << "Stirring simple coffee \n";
		}
};
 
class RobustCoffee: public Coffee  {
	public:
		void stir() {
			std::cout << "Stirring robust coffee \n";
		}
};

// This is our abstract factory class
/*
First up, we have our abstract base class, CoffeeFactory. 

It has two virtual methods on it, one for each type of object 
this factory can create, createMachine() and createCoffee(). 

And then, taking some inspiration from the last clip, we have two concrete factory 
implementations. 

We have a SimpleCoffeeFactory and a RobustCoffeeFactory. 

Each of these factories implements the virtual methods of the base class in its own unique way.

The SimpleCoffeeFactory returns a smart pointer to a SimpleCoffeeMachine and 
a SimpleCoffee depending upon the method called, while the RobustCoffeeFactory 
returns the robust equivalent
*/

class CoffeeFactory {
	public:
		virtual std::unique_ptr<CoffeeMachine> createMachine() = 0;
		virtual std::unique_ptr<Coffee> createCoffee() = 0;
};

// We can implement individual factories which include factory methods for a family of objects 
class SimpleCoffeeFactory : public CoffeeFactory {
	public:
		std::unique_ptr<CoffeeMachine> createMachine() {
			return std::make_unique<SimpleCoffeeMachine>();
		}

		std::unique_ptr<Coffee> createCoffee() {
			return std::make_unique<SimpleCoffee>();
		}
};
 
class RobustCoffeeFactory : public CoffeeFactory {
	public:
		std::unique_ptr<CoffeeMachine> createMachine() {
			return std::make_unique<RobustCoffeeMachine>();
		}

		std::unique_ptr<Coffee> createCoffee() {
			return std::make_unique<RobustCoffee>();
		}
};

/*
Let's jump into the main function to see how this code can be used. 
These three lines here first create a SimpleCoffeeFactory. 
From this factory, a coffeeMachine and a coffee are created. 
Next, the RobustCoffeeFactory is instantiated, and its two factory methods are called. 
We then test out each object to see what was created. 
If I compile and then run this code, 
I can see that the different factories created different object families based on their 
different implementations of the methods.

As mentioned in the previous clip, this pattern is popular, 
and odds are you have either already run into it or you will run into it out in the real world. 
 
"Smart pointers also make the abstract factory pattern a joy to work with in C++. 
It's recommended that you return a unique smart pointer every time your factories 
create an object so that C++ can properly manage the created object's lifetime."
 
That's it for the abstract factory pattern.
*/

int main()
{
	// We can use the abstract factory pattern to create families of related objects
	std::unique_ptr<CoffeeFactory> factoryOne = std::make_unique<SimpleCoffeeFactory>();
	auto coffeeMachineOne = factoryOne->createMachine();
	auto coffeeOne = factoryOne->createCoffee();

	auto factoryTwo = std::make_unique<RobustCoffeeFactory>();
	auto coffeeMachineTwo = factoryTwo->createMachine();
	auto coffeeTwo = factoryTwo->createCoffee();


	coffeeMachineOne->brew();
	coffeeOne->stir();

	coffeeMachineTwo->brew();
	coffeeTwo->stir();

	return 0;
}
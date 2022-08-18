#include <iostream>
#include <vector>

// Abstract base class - This is our prototype which contains a "clone" method
class CoffeeMachine {
	public:
	//Important to observe the Abstract contains the clone() method.
	//This clone method along with brew method need to be implemented by derived classes.
		virtual CoffeeMachine* clone() = 0;
		virtual void brew() = 0;
};

// Concrete implementations of the prototype - in practice, these would be "complex" objects that cost a lot to instantiate
class SimpleCoffeeMachine : public CoffeeMachine {
	public:
		CoffeeMachine*   clone() {
			return new SimpleCoffeeMachine;
		}

		void brew() {
			std::cout << "Brewing simple coffee!\n";
		}
};

class ComplexCoffeeMachine : public CoffeeMachine {
	public:
		CoffeeMachine*   clone() {
			return new ComplexCoffeeMachine; 
		}

		void brew() {
			std::cout << "Brewing complex coffee!\n";
		}
};

class EspressoMachine : public CoffeeMachine {
	public:
		CoffeeMachine*   clone() {
			return new EspressoMachine;
		}

		void brew() {
			std::cout << "Brewing espresso!\n";
		}
};
/** 
 * For the above implementations, the clone method of each class creates a brand new machine of that type
 * on the heap using the new keyword.
 * This is the function where you can add your own flavour as to how you want objects to be cloned
 * according to the pattern.
 * For this simple example, we simply use the new keyword to allocate memory for these objects on the heap.
 */

// Helper, management class which can abstract the creation of objects via their type.

/*
Further down below, we have our CoffeeMachineManager class. 
Although not necessarily required to implement this pattern, it often becomes necessary 
in order to successfully create the abstraction around creating objects irrespective of type. 
This class provides a static method for creating new coffee machines in a generic way. 
This simple version simply uses an integer to select the right type, although templates and/or enums 
in combination with the switch statement are also good choices. 
*/
class CoffeeMachineManager {
	public:
		static CoffeeMachine* createMachine( int machineType );
		~CoffeeMachineManager(){}

	private:
		static CoffeeMachine* machines[3];
};

// The management class contains already instantiated objects so that new objects requested are simply cloned!

//The magic here is in the statically allocated machines field. 
//A bit further down, we populated this static array with one of 
//each of our concrete prototype classes.
CoffeeMachine* CoffeeMachineManager::machines[] =  {
	new SimpleCoffeeMachine, new ComplexCoffeeMachine, new EspressoMachine
};

//The createMachine method then becomes our one‑stop‑shop in 
//terms of creating objects from our prototype.

// This helper method will ensure that new machines are not created from scratch but are simply cloned instead
CoffeeMachine* CoffeeMachineManager::createMachine( int machineType ) 
{
   return machines[machineType]->clone();
}
/*
From the foundation of these three objects that have already been instantiated,
we are simply cloning here. This really helps when your objects are big and contain lots of data,
or maybe you require a lot of CPU in order to instantiate. 
*/
int main() {
	// Each call to the "createMachine" method clones the right CoffeeMachine object
	std::vector<CoffeeMachine*> myMachines(3);
	CoffeeMachine* simpleMachine = CoffeeMachineManager::createMachine(0);
	CoffeeMachine* complexMachine = CoffeeMachineManager::createMachine(1);
	CoffeeMachine* espressoMachine = CoffeeMachineManager::createMachine(2);

	myMachines[0] = simpleMachine;
	myMachines[1] = complexMachine;
	myMachines[2] = espressoMachine;

   for (int i = 0; i < myMachines.size(); i++) {
		myMachines[i]->brew();
   }

   // Easily create a copy! 
   CoffeeMachine* clonedMachine = simpleMachine->clone();
   clonedMachine->brew();

	// Clean up!
	for (int i = 0; i < myMachines.size(); i++) {
		delete myMachines[i];
	}

	delete clonedMachine;
/*
I hope that this example has shown you how valuable the 
prototype design pattern can be.
It's often overlooked, but can provide a great benefit when dealing with 
large objects that are created or reconfigured quite often.
*/
   return 0;

}

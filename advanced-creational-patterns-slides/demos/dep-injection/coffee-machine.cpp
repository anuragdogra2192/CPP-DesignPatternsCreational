#include <iostream>
#include "coffee-machine.h"

/*Step 2
We define the brew method, which simply writes to the console and 
then calls the sendMetrics function located on the CoffeeService reference 
that is available to the class.
*/

void CoffeeMachine::brew() {
	std::cout << "Brewing coffee!\n";

	coffeeService->sendMetrics();
}
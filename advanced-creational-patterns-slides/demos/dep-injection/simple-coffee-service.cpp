#include <iostream>
#include <memory>
#include "icoffee-service.h"

/*Step 4
Over in the simple‑coffee‑service.cpp file, 
we've implemented a coffee service type here. 
This class derives from the icoffee‑service interface 
and implements the sendMetrics method. 
*/

// Specific implementation of a CoffeeService
class SimpleCoffeeService : public ICoffeeService {
	void sendMetrics() override {
		std::cout << "Sending metrics!\n";
	}
};


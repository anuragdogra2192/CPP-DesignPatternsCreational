#include <map>
#include <string>

class GlobalCoffeeConfig {
    std::map<std::string, std::string>  coffeeState;

	//Step 1:
	//The first part in any Singleton in C++ is the private constructor. 	
	// Private constructor. 
    GlobalCoffeeConfig() {}
	// Here we mark a single constructor private as we will not use it
	// to instantiate new objects.
	// This is crucial in order to prevent client code from 
	// creating new objects.

	public:
		//Step 2:
		//The next few things we do are to inactivate the copy constructor.
		//as well as the copy assignment operator.
		//We need to delete these functions in order to avoid creating
		//copies of our Singleton.

		// Remove ability to use the copy constructor
		GlobalCoffeeConfig(GlobalCoffeeConfig const&) = delete;

		// Remove ability top use the copy assignment operator
		GlobalCoffeeConfig &operator=(GlobalCoffeeConfig const&) = delete;

		//Step 3:
		//The final portion of any singleton is to provide
		//a single static method for retrieving the singleton instance.

		// Provide a single, static method for retriving the singleton instance
		//Here we define a static method, get() that returns a reference to
		//to our GlobalCoffeeConfig object.

		static GlobalCoffeeConfig &get() {
			static GlobalCoffeeConfig config;
			return config;
		}

		//These are the crucial aspects of the singleton class.
		//Below them. We implement two simple methods. setState and getState,
		//that set and retrieve state within the singleton.
		
		//In complex example the singleton may contain mutexes in order
		//to properly log shared resources.

		void setState(const std::string &key, const std::string &value) {
			coffeeState.insert({ key, value });
		}

		std::string getState(const std::string &key) {
			auto iterator = coffeeState.find(key);
			return iterator->second;
		}
};

int main() {
	// Can't compile this line because the constructor is private
	// GlobalCoffeeConfig configObj = GlobalCoffeeConfig();

	// The "get" method is the only way to retrive the static, singleton instance
	// This line doesn't compile, because the copy constructor has been removed - a new instance cannot be created
	// GlobalCoffeeConfig configObj = GlobalCoffeeConfig::get();


	//We are only able to collect a reference 
	//to the already created singleton object, not copy of it.
	GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();


    configObj.setState("COFFEE_STATUS", "ON");
    configObj.setState("COFFEE_HEALTH_URL", "./health");

	printf("COFFEE_STATUS: %s\n", configObj.getState("COFFEE_STATUS").c_str());
	printf("COFFEE_HEALTH_URL: %s\n", configObj.getState("COFFEE_HEALTH_URL").c_str());

    return EXIT_SUCCESS;
}
//That's it for the Singleton Pattern.
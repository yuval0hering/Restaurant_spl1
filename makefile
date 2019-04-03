# All Targets
all: rest

# Tool invocations
# Executable "rest" depends on the files bin/Action.o  bin/Customer.o  bin/Dish.o  bin/Restaurant.o  bin/Table.o bin/main.o
rest: bin/main.o bin/Restaurant.o bin/Customer.o bin/AlcoholicCustomer.o bin/CheapCustomer.o bin/SpicyCustomer.o bin/VegeterianCustomer.o bin/Table.o bin/Dish.o bin/BaseAction.o bin/BackupRestaurant.o bin/Close.o bin/CloseAll.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/RestoreRestaurant.o   
	@echo 'Building target: Assignment_1'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/rest bin/main.o bin/Restaurant.o bin/Customer.o bin/AlcoholicCustomer.o bin/CheapCustomer.o bin/SpicyCustomer.o bin/VegeterianCustomer.o bin/Table.o bin/Dish.o bin/BaseAction.o bin/BackupRestaurant.o bin/Close.o bin/CloseAll.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/RestoreRestaurant.o
	@echo 'Finished building target: Assignment_1'
	@echo ' '

# Depends on the source and header files 
bin/main.o: src/main.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

# Depends on the source and header files 
bin/Restaurant.o: src/Restaurant.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Restaurant.o src/Restaurant.cpp

# Depends on the source and header files
bin/BaseAction.o: src/Actions/BaseAction.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/BaseAction.o src/Actions/BaseAction.cpp

# Depends on the source and header files
bin/BackupRestaurant.o: src/Actions/BackupRestaurant.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/BackupRestaurant.o src/Actions/BackupRestaurant.cpp
	
# Depends on the source and header files
bin/Close.o: src/Actions/Close.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Close.o src/Actions/Close.cpp
	
# Depends on the source and header files
bin/CloseAll.o: src/Actions/CloseAll.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/CloseAll.o src/Actions/CloseAll.cpp
	
# Depends on the source and header files
bin/MoveCustomer.o: src/Actions/MoveCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/MoveCustomer.o src/Actions/MoveCustomer.cpp
	
# Depends on the source and header files
bin/OpenTable.o: src/Actions/OpenTable.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/OpenTable.o src/Actions/OpenTable.cpp

# Depends on the source and header files
bin/Order.o: src/Actions/Order.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Order.o src/Actions/Order.cpp
	
# Depends on the source and header files
bin/PrintActionsLog.o: src/Actions/PrintActionsLog.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/Actions/PrintActionsLog.cpp
	
# Depends on the source and header files
bin/PrintMenu.o: src/Actions/PrintMenu.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/PrintMenu.o src/Actions/PrintMenu.cpp
	
# Depends on the source and header files
bin/PrintTableStatus.o: src/Actions/PrintTableStatus.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/PrintTableStatus.o src/Actions/PrintTableStatus.cpp
	
# Depends on the source and header files
bin/RestoreRestaurant.o: src/Actions/RestoreRestaurant.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/RestoreRestaurant.o src/Actions/RestoreRestaurant.cpp
	
# Depends on the source and header files
bin/Dish.o: src/Dish.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Dish.o src/Dish.cpp

# Depends on the source and header files 
bin/Customer.o: src/Customers/Customer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Customer.o src/Customers/Customer.cpp

# Depends on the source and header files 
bin/AlcoholicCustomer.o: src/Customers/AlcoholicCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/AlcoholicCustomer.o src/Customers/AlcoholicCustomer.cpp
	
# Depends on the source and header files 
bin/CheapCustomer.o: src/Customers/CheapCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/CheapCustomer.o src/Customers/CheapCustomer.cpp
	
# Depends on the source and header files 
bin/SpicyCustomer.o: src/Customers/SpicyCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/SpicyCustomer.o src/Customers/SpicyCustomer.cpp
	
# Depends on the source and header files 
bin/VegeterianCustomer.o: src/Customers/VegeterianCustomer.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/VegeterianCustomer.o src/Customers/VegeterianCustomer.cpp
	
# Depends on the source and header files
bin/Table.o: src/Table.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Table.o src/Table.cpp

#Clean the build directory
clean: 
	rm -f bin/*

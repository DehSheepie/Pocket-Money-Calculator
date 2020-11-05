#include <iostream> // std::cout, std::endl
#include <fstream>  // std::fstream
#include <string>   // std::getline
#include <iomanip>  // std::setw

std::string filename = "money.dat";

bool CheckStringValid(std::string s)
{
	if (s == "")
	{
		std::cout << "Please enter a value." << std::endl;
		return false;
	}

	try {
		std::stod(s);
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid input." << std::endl;
		return false;
	}
	catch (std::out_of_range)
	{
		std::cout << "Invalid out of valid range." << std::endl;
		return false;
	}
	return true;
}

bool CheckStringIsInt(std::string s)
{
	if (s == "")
	{
		std::cout << "Please enter a value." << std::endl;
		return false;
	}
	try 
	{
		std::stoi(s);
		return true;
	}
	catch(std::invalid_argument)
	{
		std::cout << "Input invalid." << std::endl;
	}
	catch (std::out_of_range)
	{
		std::cout << "Input out of valid range." << std::endl;
	}
}

void ShowBalance()
{
	std::ifstream file;
	file.open(filename);

	// Check For Error
	if (file.fail())
	{
		std::cerr << "File not found" << std::endl;
		exit(1);
	}
	std::string balance;
	std::getline(file, balance);
	file.close();
	if (CheckStringValid(balance))
	{
		std::cout << "------ Balance ------" << std::endl;
		std::cout << "------ " << std::left << std::setw(8) << balance << "------" << std::endl;
	}
	else
	{
		std::cout << "value in the file in not valid" << std::endl;
	}
}

void OverwriteFile(double value)
{
	std::ofstream file;
	file.open(filename, std::ofstream::trunc); // trunc for overwritting the contents of the file

	if (!file.is_open())
	{
		std::cout << "File could not be overwritten" << std::endl;
		return;
	}

	// Add the value to the file
	file << std::fixed << std::setprecision(2) << value;
	file.close();
}

void AddToBalance(double addition)
{
	std::ifstream file;
	file.open(filename);

	// Check For Error
	if (file.fail())
	{
		std::cerr << "File not found" << std::endl;
		exit(1);
	}
	std::string balance;
	std::getline(file, balance);
	double value;
	file.close();
	if (CheckStringValid(balance))
	{
	 	value = std::stod(balance);
		value += addition;
		OverwriteFile(value);
	}
	else
	{
		std::cout << "Balance value invalid" << std::endl;
	}
}

double GetValueFromUser()
{
	std::string str;
	std::cout << "Enter the ammount you wish to add to the account" << std::endl;
	std::cin >> str;

	if (CheckStringValid(str))
	{
		return std::stod(str);
	}
	else
	{
		std::cout << "Please enter a valid value" << std::endl;
		return double(0);
	}
}

int GetMenuOptionFromUser()
{
	std::string str;
	std::cout << "Enter your option: ";
	std::cin >> str;

	if (CheckStringIsInt(str))
	{
		return std::stoi(str);
	}
	else
	{
		GetMenuOptionFromUser();
	}
}

int main()
{
	// Functionality to implement for MVP:
	// Read/write balance to external file --done--
	// Check Balance
	// Deposit
	// Remove
	// Show menu
	int running = true;
	while (running)
	{
		ShowBalance();
		AddToBalance(GetValueFromUser());
		ShowBalance();
	}


	
	return 0;
}

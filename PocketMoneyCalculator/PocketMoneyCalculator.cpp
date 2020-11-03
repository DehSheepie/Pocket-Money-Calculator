#include <iostream> // std::cout, std::endl
#include <fstream>  // std::fstream
#include <string>   // std::getline
#include <iomanip>  // std::setw

std::string filename = "money.dat";

bool CheckStringValid(std::string s) // Will probably get deleted once I create checkValidOption
{
	if (s == "")
	{
		return false;
	}

	try {
		std::stod(s);
		return true;
	}
	catch (int e)
	{
		std::cout << "Expection number:" << e << std::endl;
		return false;
	}
}

void ShowBalance()
{
	std::ifstream file;
	file.open("money.dat");

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
		std::cout << "value in the file in not an int" << std::endl;
	}
}

int main()
{
	// Functionality to implement for MVP:
	// Read/write balance to external file
	// Check Balance
	// Deposit
	// Remove
	// Show menu

	ShowBalance();
	
	return 0;
}

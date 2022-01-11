#include "Summator.h"
#include <iostream>
#include <fstream>
Summator::Summator() : ExpressionEvaluator() { }
Summator::Summator(size_t n) : ExpressionEvaluator(n) { }

double Summator::calculate() const {
	double sum = 0.0;
	for(size_t i = 0; i < length; ++i)
	{
		sum += mas[i];
	}
	return sum;
}

void Summator::logToScreen() const 
{
	std::cout << "[Summator]" << std::endl;
	std::cout << "[ -" << length << "-" << " operands ]" << std::endl;
	mas[0] >= 0 ? std::cout << mas[0] : std::cout << '(' << mas[0] << ')';
	for(size_t i = 1; i < length; ++i)
	{
		mas[i] >= 0 ? std::cout << " plus " << mas[i] : std::cout << " plus (" << mas[i] << ") ";
	}
	std::cout<<std::endl;
	std::cout << "[ -RESULT- " << calculate() << " ]"<<std::endl << std::endl;
}

void Summator::logToFile(const std::string& filename) const
{
	std::ofstream stream;
	stream.open(filename, std::ios_base::app);
	stream << "[Summator]" << std::endl;
	stream << "[ -" << length << "-" << " operands ]" << std::endl;
	mas[0] >= 0 ? stream << mas[0] : stream << '(' << mas[0] << ')';
	for (size_t i = 1; i < length; ++i)
	{
		mas[i] >= 0 ? stream << " plus " << mas[i] : stream << " plus (" << mas[i] << ") ";
	}
	stream << std::endl;
	stream << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
	stream.close();
}



#include "Subtractor.h"
#include <iostream>
#include <fstream>
Subtractor::Subtractor() : ExpressionEvaluator() { }
Subtractor::Subtractor(size_t n) : ExpressionEvaluator(n) { }

double Subtractor::calculate() const {
	double sub = mas[0];
	for (size_t i = 1; i < length; ++i)
	{
		sub -= mas[i];
	}
	return sub;
}

void Subtractor::logToScreen() const
{
	std::cout << "[Subtractor]" << std::endl;
	std::cout << "[ -" << length << "-" << " operands ]" << std::endl;
	mas[0] >= 0 ? std::cout << mas[0] : std::cout << '(' << mas[0] << ')';
	for (size_t i = 1; i < length; ++i)
	{
		mas[i] >= 0 ? std::cout << " minus " << mas[i] : std::cout << " minus (" << mas[i] << ") ";
	}
	std::cout << std::endl;
	std::cout << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
}

void Subtractor::logToFile(const std::string& filename) const
{
	std::ofstream stream;
	stream.open(filename, std::ios_base::app);
	stream << "[Subtractor]" << std::endl;
	stream << "[ -" << length << "-" << " operands ]" << std::endl;
	mas[0] >= 0 ? stream << mas[0] : stream << '(' << mas[0] << ')';
	for (size_t i = 1; i < length; ++i)
	{
		mas[i] >= 0 ? stream << " minus " << mas[i] : stream << " minus (" << mas[i] << ") ";
	}
	stream << std::endl;
	stream << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
	stream.close();
}
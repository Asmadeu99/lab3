#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() { }
CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) { }

double CustomExpressionEvaluator::calculate()const {
	double result = 0.0;
	for (size_t i = 0; i < length; ++i)
	{
		int x = i + 1;
		if (x % 4 == 2) {
			result /= (mas[i]); 
		}
		else {
			result += (mas[i]); 
		}
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen()const {
	std::cout << "[CustomExpressionEvaluator]" << std::endl;
	std::cout << "[ -" << length << "-" << " operands ]" << std::endl;
	for (size_t i = 0; i < length; ++i)
	{
		if (i != length - 1) {
			int x = i + 1;
			if (mas[i] >= 0) {
				if (x % 4 == 1) {
					std::cout << mas[i] << " div ";
				}
				else {
					std::cout << mas[i] << " plus ";
				}
			}
			else {
				if (x % 4 == 1) {
					std::cout << '(' << mas[i] << ')' << " div ";
				}
				else {
					std::cout << '(' << mas[i] << ')' << " plus ";
				}
			}
		}
		else {
			if (mas[i] >= 0) {
				std::cout << mas[i] << std::endl;
			}
			else {
				std::cout << '(' << mas[i] << ')' << std::endl;
			}
			//std::cout << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
		}
	}
	std::cout << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)const {
	std::ofstream stream;
	stream.open(filename, std::ios_base::app);
	stream << "[CustomExpressionEvaluator]" << std::endl;
	stream << "[ -" << length << "-" << " operands ]" << std::endl;
	for (size_t i = 0; i < length; ++i)
	{
		if (i != length - 1) {
			int x = i + 1;
			if (mas[i] >= 0) {
				if (x % 4 == 1) {
					stream << mas[i] << " div ";
				}
				else {
					stream << mas[i] << " plus ";
				}
			}
			else {
				if (x % 4 == 1) {
					stream << '(' << mas[i] << ')' << " div ";
				}
				else {
					stream << '(' << mas[i] << ')' << " plus ";
				}
			}
		}
		else {
			if (mas[i] >= 0) {
				stream << mas[i] << std::endl;
			}
			else {
				stream << '(' << mas[i] << ')' << std::endl;
			}
			//std::cout << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
		}
	}
	stream << "[ -RESULT- " << calculate() << " ]" << std::endl << std::endl;
	stream.close();
}


void CustomExpressionEvaluator::shuffle()
{	
	double key;
	int j;
	for (int i = 1; i < length; i++) {
		key = mas[i];
		if (key > 0)
			continue;
		j = i - 1;
		while (j >= 0 && mas[j] > 0) {
			mas[j + 1] = mas[j];
			j = j - 1;
		}
		mas[j + 1] = key;
	}
}



void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
	if (mas[i] < 0 && mas[j] >= 0)
	{
		std::swap(mas[i], mas[j]);
	}
}








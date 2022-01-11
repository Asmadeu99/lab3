#include "ExpressionEvaluator.h"
#include <iostream>
ExpressionEvaluator::ExpressionEvaluator() {
	length = 20;
	mas = new double[length];
	for (size_t i = 0; i < length; ++i) {
		mas[i] = 0;
	}
	
}
ExpressionEvaluator::ExpressionEvaluator(size_t n) {
	length = n;
	mas = new double[length];
	for (size_t i = 0; i < length; ++i) {
		mas[i] = 0;
	}
}
void ExpressionEvaluator::setOperand(size_t pos, double value) {
	if (pos < length) {
		mas[pos] = value;
	}
	
}
void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (size_t i = 0; i < n; ++i) {
		mas[i] = ops[i];
	}

}
ExpressionEvaluator::~ExpressionEvaluator() {
	if (mas != NULL)
		delete[] mas;
}

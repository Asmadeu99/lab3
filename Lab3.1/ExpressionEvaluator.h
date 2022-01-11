#pragma once
#include "ILoggable.h"
#include <string>
class ExpressionEvaluator :public ILoggable
{
public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual ~ExpressionEvaluator();
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	virtual double calculate() const = 0;
	void logToScreen() const override {};
	void logToFile(const std::string& filename) const override {};
protected:
	double* mas;
	size_t length;
};


#pragma once
#include "ExpressionEvaluator.h"
#include "ILoggable.h"
class Summator :public ExpressionEvaluator
{
public:
	Summator();
	Summator(size_t n);
	~Summator() override {};
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
	double calculate() const override;
};


#pragma once
#include "ExpressionEvaluator.h"
#include "ILoggable.h"
class Subtractor :public ExpressionEvaluator
{
public:
	Subtractor();
	Subtractor(size_t n);
	~Subtractor() override {};
	void logToScreen() const override;
    void logToFile(const std::string& filename) const override;
	double calculate() const override;
};


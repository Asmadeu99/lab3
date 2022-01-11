
#include <iostream>
#include <string>
#include "ILoggable.h"
#include "IShuffle.h"
#include "Summator.h"
#include "Subtractor.h"
#include "CustomExpressionEvaluator.h"

//������ �����, ���-5, ������� 9

/*��� ��������� CustomExpression: result = x1 / x2 + x3 + x4 + ...
������� �������� � ������������� �������� ����������:
Summator: 7 ���������, ��������� ������� 15, -3.5, 10.5, �2.1, 3.3, 4, 6.3.
CustomExpressionEvaluator: 5 ���������, ��������� ������� 15, 10, -3, 12, -6.5.
Subtractor: 3 ��������, ��������� ����������� 1.5, 4, -2.5.
����� shuffle() � ����������� �������� ���, ����� ������� ��� ��� �������������, �
����� �������������. ����� shuffle(size_t i, size_t j) � ���� i-�� �������
�����������, � j-�� � ���, �� �������� �� �������, ����� � �������� ��� ���������.
������ ������:
[ -7- operands]
15 plus (-3.5) plus 10.5 plus (-2.1) plus 3.3 plus 4 plus 6.3
[ -RESULT- 33.5 ]*/

int main()
{
	ExpressionEvaluator* ex[3];
	ex[0] = new Summator(7);
	double* ops_sum = new double[7]{ 15, -3.5, 10.5, -2.1, 3.3, 4, 6.3 };
	ex[0]->setOperands(ops_sum, 7);

	ex[1] = new Subtractor(3);
	double* ops_sub = new double[3]{ 1.5, 4, -2.5 };
	for(size_t i = 0; i < 3; ++i)
	{
		ex[1]->setOperand(i, ops_sub[i]);
	}

	ex[2] = new CustomExpressionEvaluator(5);
	double* ops_result = new double[5]{ 15, 10, -3, 12, -6.5 };
	ex[2]->setOperands(ops_result, 5);

	for (size_t i = 0; i < 3; ++i)
	{
		ex[i]->logToScreen();
		ex[i]->logToFile("LogFile.txt");
	}

	for (size_t i = 0; i < 3; i++) {
		if (typeid(*ex[i]) == typeid(CustomExpressionEvaluator)) {
			CustomExpressionEvaluator* res = dynamic_cast <CustomExpressionEvaluator*>(ex[i]);
			res->shuffle();
			res->logToScreen();
		}
		
		IShuffle* shuffle = dynamic_cast <IShuffle*> (ex[i]);
		if (shuffle) {
			shuffle->shuffle(1, 2);
			ex[i]->logToScreen();
			
		}
	}

	for (int i = 0; i < 3; ++i) {
		delete ex[i];
	}
	return 0;

}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.

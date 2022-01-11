
#include <iostream>
#include <string>
#include "ILoggable.h"
#include "IShuffle.h"
#include "Summator.h"
#include "Subtractor.h"
#include "CustomExpressionEvaluator.h"

//Хайтул Павел, ИВТ-5, Вариант 9

/*Вид выражения CustomExpression: result = x1 / x2 + x3 + x4 + ...
Порядок создания и инициализации объектов подклассов:
Summator: 7 операндов, присвоить группой 15, -3.5, 10.5, –2.1, 3.3, 4, 6.3.
CustomExpressionEvaluator: 5 операндов, присвоить группой 15, 10, -3, 12, -6.5.
Subtractor: 3 операнда, присвоить поэлементно 1.5, 4, -2.5.
Метод shuffle() – переставить операнды так, чтобы сначала шли все отрицательные, а
затем положительные. Метод shuffle(size_t i, size_t j) – если i-ый операнд
отрицателен, а j-ый – нет, то поменять их местами, иначе – оставить без изменений.
Формат вывода:
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

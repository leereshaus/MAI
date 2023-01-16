//
//  Гусева Софья М80-201Б-20
//
/*
Разработать шаблоны классов согласно варианту задания.
Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат.
Классы должны иметь публичные поля. Фигуры являются фигурами вращения, т.е. равносторонними (кроме трапеции и прямоугольника).
Для хранения координат фигур необходимо использовать шаблон  std::pair.
*/

#include <iostream>
#include <memory> // unique_ptr
#include <algorithm> // for_each, count_if
#include "pentagon.hpp"
#include "stack.hpp"

using figure_type = int;

void writeMenu() {
	std::cout << "0\tВыход из программы\n";
	std::cout << "1\tЗапрос меню\n";
	std::cout << "2\tДобавить фигуру в стек\n";
	std::cout << "3\tУдалить последнюю добавленную фигуру из стека\n";
	std::cout << "4\tПечать фигур в стеке\n";
	std::cout << "5\tПечать количества фигур, площадь которых меньше заданной\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Гусева Софья. М8О-201Б-20. Вариант 6: стек, пятиугольник\nПятиугольник правильный, нижнее основание параллельно оси x.\nНа вход подаются две координаты нижней левой вершины пятиугольника (по осям x и y) и длина стороны\n\n";
	int num = 0;
	Stack<Pentagon<figure_type>> st;

	short comand;
	bool menu = 1;

	writeMenu();
	while (menu) {

		std::cout << '\n';
		std::cout << "Введите команду: ";
		std::cin >> comand;
		std::cout << std::endl;

		switch (comand)
		{
		case 0:
			menu = 0;
			break;
		case 1:
			writeMenu();
			break;
		case 2:
		{
			std::unique_ptr<Pentagon<figure_type>> rec = std::make_unique<Pentagon<figure_type>>();
			try {
				std::cin >> rec;
				st.Push(std::move(rec));
			}
			catch (const char* exception) {
				std::cerr << "ERROR: " << exception << '\n';
			}
		}
		break;
		case 3:
		{
            st.Pop();

		}
		break;
		case 4:
			std::for_each(st.begin(), st.end(), print<figure_type>);
			break;
		case 5:
		{
			int max = 0;
			std::cout << "Введите площадь: ";
			std::cin >> max;
			std::cout << std::endl;
			size_t a = std::count_if(st.begin(), st.end(), [max](std::unique_ptr<Pentagon<figure_type>>& elem) {return elem->Area() < max; });
			std::cout << a << std::endl;
		}
		break;

		}
	}

	return 0;
}

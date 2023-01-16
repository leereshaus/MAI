#include <iostream>
#include <vector>

using namespace std;

class Figure{
public:
    struct point{
        double x, y;
    };
    double a, b, h;
    double S;
    point centre;

public:
    point readPoint(){
        point p;
        while (true) {
            cin >> p.x >> p.y;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Координаты введены неверно. Попробуйте снова" << endl;
            }
            else {
                cin.ignore(32767, '\n');
                return p;
            }
        }
        return p;
    }

    Figure(){};
    virtual void read() = 0;
    virtual double getSquare() = 0;
    virtual double Square() = 0;
    virtual void getCentre() = 0;
    virtual void write() = 0;
};

class Rectangle: public Figure{
public:
    point point1;
    double a, b;

    void read(){
        cout << "Ввод прямоугольника. Стороны прямоугольника параллельны осям координат. Вершины прямоугольника перечисляются следующим образом: " << "\n";
        cout << "  B-----------------C" << "\n";
        cout << "  |                 |" << "\n";
        cout << "a |                 |" << "\n";
        cout << "  |                 |" << "\n";
        cout << "  A-----------------D" << "\n";
        cout << "           b         " << "\n";
        cout << "Введите координаты точки A" << "\n";
        point1 = readPoint();
        cout << "Введите длину стороны а" << "\n";
        cin >> a;
        cout << "Введите длину стороны b" << "\n";
        cin >> b;
    }

    double getSquare(){
        cout << "Площадь прямоугольника = \t";
        return (point1.x + a)*(point1.y + b);
    }

    double Square(){
        return (point1.x + a)*(point1.y + b);
    }

    void getCentre(){
        centre.x = point1.x + b/2;
        centre.y = point1.y + a/2;
        cout << "Геометрический центр прямоугольника имеет координаты: (" << centre.x << "," << centre.y << ")\n";;
        return;
    }

    void write(){
        cout << "Вывод прямоугольника. Вершины прямоугольника перечисляются следующим образом: " << "\n";
        cout << "B-----------------C" << "\n";
        cout << "|                 |" << "\n";
        cout << "|                 |" << "\n";
        cout << "|                 |" << "\n";
        cout << "A-----------------D" << "\n";
        cout << "Координаты точки A: (" << point1.x << "," << point1.y << ")\n";
        cout << "Координаты точки B: (" << point1.x << "," << point1.y + a << ")\n";
        cout << "Координаты точки C: (" << point1.x + b << "," << point1.y + a << ")\n";
        cout << "Координаты точки D: (" << point1.x + b << "," << point1.y << ")\n";
    }
};

class Trapeze: public Figure{
public:
    point point1;
    double a, b, h;

    void read(){
        cout << "Ввод правильной трапеции. Основания трапеции параллельный осям координат. Вершины трапеции перечисляются следующим образом: " << "\n";
        cout << "            a         " << "\n";
        cout << "     B------------C" << "\n";
        cout << "    /       |      \\ " << "\n";
        cout << "   /        | h     \\ " << "\n";
        cout << "  /         |        \\ " << "\n";
        cout << " A--------------------D" << "\n";
        cout << "            b         " << "\n";
        cout << "Введите координаты точки A" << "\n";
        point1 = readPoint();
        cout << "Введите длину стороны a" << "\n";
        cin >> b;
        cout << "Введите длину стороны b" << "\n";
        cin >> a;
        cout << "Введите длину высоты h" << "\n";
        cin >> h;
    }

    double getSquare(){
        cout << "Площадь трапеции = \t";
        return (a + b)/2 * h;
    }

    double Square(){
        return (a + b)/2 * h;
    }

    void getCentre(){
        centre.x = point1.x + b/2;
        centre.y = point1.y + h/2;
        cout << "Геометрический центр трапеции имеет координаты: ( " << centre.x << "," << centre.y << ")\n";
        return;
    }

    void write(){
        cout << "Вывод правильной трапеции трапеции. Вершины трапеции перечисляются следующим образом: " << "\n";
        cout << "    B------------C" << "\n";
        cout << "   /              \\ " << "\n";
        cout << "  /                \\ " << "\n";
        cout << " /                  \\ " << "\n";
        cout << "A--------------------D" << "\n";
        cout << "Координаты точки A: (" << point1.x << "," << point1.y << ")\n";
        cout << "Координаты точки B: (" << 1.5 * point1.x - a/2 << "," << point1.y + h << ")\n";
        cout << "Координаты точки C: (" << 1.5 * point1.x + a/2 << "," << point1.y + h << ")\n";
        cout << "Координаты точки D: (" << point1.x << "," << point1.y << ")\n";
    }
};

class Rhomb: public Figure{
public:
    point point1;
    double a, b;

    void read(){
        cout << "Ввод ромба. Высоты ромба параллельны осям координат. Вершины ромба перечисляются следующим образом: " << "\n";
        cout << "    C" << "\n";
        cout << "   /| \\ " << "\n";
        cout << "  / |a \\ " << "\n";
        cout << " /b |   \\ " << "\n";
        cout << "B-------- D" << "\n";
        cout << " \\  |   /" << "\n";
        cout << "  \\ |  /" << "\n";
        cout << "   \\| /" << "\n";
        cout << "    A" << "\n";
        cout << "Введите координаты точки A" << "\n";
        point1 = readPoint();
        cout << "Введите длину диагонали a" << "\n";
        cin >> a;
        cout << "Введите длину диагонали b" << "\n";
        cin >> b;
    }

    double getSquare(){
        cout << "Площадь ромба = \t";
        return (a * b)/2;
    }

    double Square(){
        return (a * b)/2;
    }

    void getCentre(){
        centre.x = point1.x;
        centre.y = point1.y + a/2;
        cout << "Геометрический центр ромба имеет координаты: (" << centre.x << "," << centre.y << ")\n";
        return;
    }

    void write(){
        cout << "Вывод ромба. Вершины ромба перечисляются следующим образом: " << "\n";
        cout << "    C" << "\n";
        cout << "   / \\ " << "\n";
        cout << "  /   \\ " << "\n";
        cout << " /     \\ " << "\n";
        cout << "B       D" << "\n";
        cout << " \\      /" << "\n";
        cout << "  \\    /" << "\n";
        cout << "   \\  /" << "\n";
        cout << "    A" << "\n";
        cout << "Координаты точки A: (" << point1.x << "," << point1.y << ")\n";
        cout << "Координаты точки B: (" << point1.x - b/2 << "," << point1.y + a/2 << ")\n";
        cout << "Координаты точки C: (" << point1.x << "," << point1.y + a << ")\n";
        cout << "Координаты точки D: (" << point1.x + b/2 << "," << point1.y + a/2 << ")\n";
    }
};

int prov() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Неверный ввод" << endl;
        return 0;
    }
    else {
        cin.ignore(32767, '\n');
        return 1;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Гусева Софья Романовна \n";
    cout << "Лабораторная работа 3. \n";
    cout << "Вариант 3: Разработать классы согласно варианту задания, классы должны  наследоваться от базового класса Figure. Вариант реализован для Прямоугольника, трапеции и ромба. \n";
    cout << "\n";
    int n = 0;
    vector <Figure*> figure;
    while(true){
        cout << "1. Ввести фигуру" << "\n" << "2. Вывести координаты вершин фигуры" << "\n" << "3. Найти площадь фигуры" << "\n" << "4. Найти геометрический центр фигуры" << "\n" << "5. Найти площадь всех фигур" << "\n" << "6. Удалить фигуру по индексу" << "\n" << "0. Выход" << "\n" << "Выполнить операцию: " << "\t";
        cin >> n;
        cout << "\n";
        if (prov()){
            if (n == 1){
                int k = 1;
                cout << "Выберете фигуру для ввода: \n" << "1. Прямоугольник" << "\n" << "2. Правильная трапеция" << "\n" << "3. Ромб" << "\n";
                cin >> k;
                cout << "\n";
                if (prov()){
                    if (k == 1){
                        Rectangle* f = new Rectangle();
                        f->read();
                        figure.push_back(f);
                    }
                    else if (k == 2){
                        Trapeze* f = new Trapeze();
                        f->read();
                        figure.push_back(f);
                    }
                    else if (k == 3){
                        Rhomb* f = new Rhomb();
                        f->read();
                        figure.push_back(f);
                    }
                }
            }
            else if (n == 2){
                for(int i = 0; i < figure.size(); i++){
                    figure[i]->write();
                }
            }
            else if (n == 3){
                for(int i = 0; i < figure.size(); i++){
                    cout << figure[i]->getSquare() << "\n";
                }
            }
            else if (n == 4){
                for(int i = 0; i < figure.size(); i++){
                    figure[i]->getCentre();
                }
            }
            else if (n == 5){
                double sumSq = 0;
                for(int i = 0; i < figure.size(); i++){
                    sumSq += figure[i]->Square();
                }
                cout << "Сумма площадей всех фигур = " << sumSq << "\n";
            }
            else if (n == 6){
                int num = 0;
                cout << "Введите номер фигуры: \t";
                cout << "\n";
                cin >> num;
                if (prov()){
                    if ((num > 0) && (num <= figure.size())){
                        delete figure[num-1];
                        figure.erase(figure.begin() + num - 1);
                    }
                    else{
                        cout << "Данного элемента не существует\n";
                    }
                }
            }
            else if (n == 0){
                for(int i = 0; i < figure.size(); i++)
                    delete figure[i];
                break;
            }
        }
    }
    return 0;
}

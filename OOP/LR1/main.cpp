#include <iostream>
#include "cmath"
#define _USE_MATH_DEFINES

using namespace std;

class Rectangle{
private:
    double x1, x2, y1, y2;

public:
    Rectangle(double x1, double y1, double x2, double y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    void print(){
        std::cout << "(" << x1 << "," << y1 << "), " << "(" << x2 << "," << y2 << ")\n";
    }
    double getSquare(){
        return (x2-x1)*(y2-y1);
    }
    double getPerim(){
        return 2*(x2-x1+y2-y1);
    }
    void move(double a, double b){
        x1 += a;
        x2 += a;
        y1 += b;
        y2 += b;
    }
    void changeSize(double c, double d){
        x2 = (x2-x1) * c + x1;
        y2 = (y2-y1) * d + y1;
    }
    int compareBySq(Rectangle z){
        if (getSquare() > z.getSquare()){
            return 1;
        }
        else if (getSquare() < z.getSquare()){
            return -1;
        }
        return 0;
    }
    int compareByPerim(Rectangle z){
        if (getPerim() > z.getPerim()){
            return 1;
        }
        else if (getPerim() < z.getPerim()){
            return -1;
        }
        return 0;
    }
    Rectangle crossing(Rectangle z){
        int n = 0;
        double a1, b1, a2, b2;
        if ((max(x1, x2) > min(z.x1, z.x2)) || (max(z.x1, z.x2) > min(x1, x2))){
            if ((max(y1, y2) > min(z.y1, z.y2)) || (max(z.y1, z.y2) > min(y1, y2))){
                if ((max(x1, x2) > min(z.x1, z.x2))){
                    a1 = min(z.x1, z.x2);
                    if ((max(x1, x2) > max(z.x1, z.x2))){
                        a2 = max(z.x1, z.x2);
                    }
                    else if ((max(x1, x2) < max(z.x1, z.x2))){
                        a2 = max(x1, x2);
                    }
                }
                else if ((max(z.x1, z.x2) > min(x1, x2))){
                    a1 = min(x1, x2);
                    if ((max(z.x1, z.x2) > max(x1, x2))){
                        a2 = max(x1, x2);
                    }
                    else if ((max(z.x1, z.x2) < max(x1, x2))){
                        a2 = max(z.x1, z.x2);
                    }
                }
                if (max(y1, y2) > min(z.y1, z.y2)){
                    b1 = min(z.y1, z.y2);
                    if ((max(y1, y2) > max(z.y1, z.y2))){
                        b2 = max(z.y1, z.y2);
                    }
                    else if ((max(y1, y2) < max(z.y1, z.y2))){
                        b2 = max(y1, y2);
                    }
                }
                else if ((max(z.y1, z.y2) > min(y1, y2))){
                    b1 = min(y1, y2);
                    if ((max(z.y1, z.y2) > max(y1, y2))){
                        b2 = max(y1, y2);
                    }
                    else if ((max(z.y1, z.y2) < max(y1, y2))){
                        b2 = max(z.y1, z.y2);
                    }
                }
                n = 1;
            }
            else {n = 0;}
        }
        else {n = 0;}
        return Rectangle (a1, b1, a2, b2);
    }
    Rectangle unite(Rectangle z){
        double a1, b1, a2, b2;
        a1 = min(min(x1, x2), min(z.x1, z.x2));
        b1 = min(min(y1, y2), min(z.y1, z.y2));
        a2 = max(max(x1, x2), max(z.x1, z.x2));
        b2 = max(max(y1, y2), max(z.y1, z.y2));
        return Rectangle(a1, b1, a2, b2);
    }
};

Rectangle create(){
    double a1, b1, a2, b2;
    std::cout << "Введите координаты левого нижнего и правого верхнего углов прямоугольника\n";
    std::cin >> a1 >> b1 >> a2 >> b2;
    return Rectangle(a1, b1, a2, b2);
}

int main(){
    setlocale(LC_ALL, "Russian");
    std::cout << "Гусева Софья Романовна \n";
    std::cout << "Лабораторная работа 1. \n";
    std::cout << "Вариант 12: Разработать класс Rectangle, представляющий собой прямоугольник со сторонами, параллельными осям координат. Поля – координаты левого нижнего и правого верхнего угла. Требуется реализовать следующие методы: вычисление площади и периметра, перемещения вдоль осей, изменение размеров, сравнение по площади и по периметру. Реализовать метод получения прямоугольника, представляющего общую часть (пересечение) двух прямоугольников. Реализовать метод объединения двух прямоугольников: наименьший прямоугольник, включающего оба заданных прямоугольника. \n";
    std::cout << "\n";
    int n = 0;
    Rectangle r(0, 0, 0, 0);
    while(1){
        std::cout << "1. Ввести координаты" << "\n" << "2. Вывести координаты" << "\n" << "3. Посчитать площадь" << "\n" << "4. Посчитать периметр" << "\n" << "5. Переместить вдоль осей" << "\n" << "6. Изменить размер" << "\n" << "7. Сравнить по площади и периметру" <<  "\n" << "8. Пересечение двух прямоугольников" << "\n" << "9. Объединение двух прямоугольников" << "\n" << "Выполнить операцию: " << "\t";
        std::cin >> n;
        std::cout << "\n";
        if (n == 1){
            r = create();
            std::cout << "\n";
        }
        else if (n == 2){
            std::cout << "Заданный прямоугольник имеет координаты: \t";
            r.print();
            std::cout << "\n";
        }
        else if (n == 3){
            std::cout <<"Площадь прямоугольника = " << r.getSquare() << std::endl;
            std::cout << "\n";
        }
        else if (n == 4){
            std::cout << "Периметр прямоугольника = " << r.getPerim() << std::endl;
            std::cout << "\n";
        }
        else if (n == 5){
            double a, b;
            std::cout << "Введите смещение (по оси x и по оси y) \n";
            std::cin >> a >> b;
            r.move(a, b);
            r.print();
            std::cout << "\n";
        }
        else if (n == 6){
            double c, d;
            std::cout << "Введите изменение (по оси x и по оси y) \n";
            std::cin >> c >> d;
            r.changeSize(c, d);
            r.print();
            std::cout << "\n";
        }
        else if (n == 7){
            Rectangle s = create();
            if (r.compareBySq(s) == 1){
                std::cout << "Первый прямоугольник больше второго по площади" << std::endl;
            }
            else if (r.compareBySq(s) == -1){
                std::cout << "Первый прямоугольник меньше второго по площади" << std::endl;
            }
            else{
                std::cout << "Площади равны" << std::endl;
            }
            if (r.compareByPerim(s) == 1){
                std::cout << "Первый прямоугольник больше второго по периметру" << std::endl;
            }
            else if (r.compareByPerim(s) == -1){
                std::cout << "Первый прямоугольник меньше второго по периметру" << std::endl;
            }
            else{
                std::cout << "Перметры равны" << std::endl;
            }
            std::cout << "\n";
        }
        else if (n == 8){
            if (n = 1) {
            std::cout << "Первый прямоугольник имеет координаты двух противоположных углов: " << "\t";
            r.print();
            std::cout << "\n";
            Rectangle s = create();
            std::cout << "Второй прямоугольник имеет координаты двух противоположных углов: " << "\t";
            s.print();
            Rectangle p = r.crossing(s);
            std::cout << "Прямоугольник, составленный путем пересечения двух других, имеет координаты двух противоположных углов: " << "\t";
            p.print();
            std::cout << "\n";
            }
            else {std::cout << "Прямоугольники не пересекаются\n";}
            std::cout << "\n";
        }
        else if (n == 9){
            std::cout << "Первый прямоугольник имеет координаты двух противоположных углов: " << "\t";
            r.print();
            std::cout << "\n";
            Rectangle s = create();
            std::cout << "Второй прямоугольник имеет координаты двух противоположных углов: " << "\t";
            s.print();
            Rectangle p = r.unite(s);
            std::cout << "Наименьший прямоугольник, составленный путем объединения двух других, имеет координаты двух противоположных углов: " << "\t";
            p.print();
            std::cout << "\n";
        }
    }
    return 0;
}

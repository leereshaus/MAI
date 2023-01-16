#include <iostream>
#include <math.h>
#include "cmath"
#define _USE_MATH_DEFINES

class Angle{

public:

    int grad, minutes;

    Angle()
    {
    }

    Angle(int grad, int minutes){
        this->grad=grad;
        this->minutes=minutes;
    }

    void print(){
        std::cout << grad << "*" << minutes << "'\n";
    }

    double rad(){
        double rrad = (grad*60 + minutes)*M_PI/10800;
        return rrad;
    }

    Angle diap(Angle z){
        int r, q;
        r = z.grad % 360;
        q = z.minutes;
        return Angle(r, q);
    }

    Angle operator + (const Angle &b) {
        Angle c(0, 0);
        int r = grad*60 + minutes;
        int q = b.grad*60 + b.minutes;
        int sum = r + q;
        c.grad = sum / 60;
        c.minutes = sum % 60;
        return c;
    }

    Angle operator - (const Angle &b) {
        Angle c(0, 0);
        int r = grad*60 + minutes;
        int q = b.grad*60 + b.minutes;
        int diff = r - q;
        if (diff < 0){
            q = - diff % 60;
        }
        else if (diff > 0){
            q = diff % 60;
        }
        r = diff / 60;
        c.grad = r;
        c.minutes = q;
        return c;
    }

    Angle operator / (const int m){
        Angle c;
        int g = this->grad*60 + this->minutes;
        int d = g / m;
        c.minutes = d % 60;
        c.grad = d / 60;
        return c;
    }

    int comp(Angle z){
        if (z.grad > grad){
            return 1;
        }
        else if (z.grad < grad){
            return -1;
        }
        return 0;
    }

    double Cos() {
        return cos(rad());
    }

    double Sin() {
        double r = rad();
        return sin(r);
    }

    double Tan() {
        double r = rad();
        return tan(r);
    }

    double Cot() {
        double r = rad();
        return 1/tan(r);
    }

};

Angle create(){
    int grad, minutes;
    std::cout << "Градусы и минуты угла:\t";
    std::cin >> grad >> minutes;
    std::cout << "\n";
    return Angle(grad, minutes);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Гусева Софья Романовна \n";
    std::cout << "Лабораторная работа 2. \n";
    std::cout << "Вариант 10: Создать класс Angle для работы с углами на плоскости, задаваемыми величиной в градусах и минутах. Обязательно должны быть реализованы: перевод в радианы, приведение к диапазону 0–360, сложение и вычитание углов, деление углов, получение значений тригонометрических функций, сравнение углов. \n";
    std::cout << "\n";
    int n = 0;
    Angle a(0, 0);
    while(1){
        std::cout << "1. Ввести градусы и минуты угла" << "\n" << "2. Вывести градусы и минуты угла" << "\n" << "3. Перевод в радианы" << "\n" << "4. Приведение к диапазону 0-360" << "\n" << "5. Сложение углов" << "\n" << "6. Вычитание углов" << "\n" << "7. Деление заданного угла на число" <<  "\n" << "8. Получение тригонометрических функций" << "\n" << "9. Сравнение углов" << "\n" << "0. Выход" << "\n" << "Выполнить операцию: " << "\t";
        std::cin >> n;
        std::cout << "\n";
        if (n == 1){
            a = create();
            if ((a.minutes > 59) or (a.minutes < 0)){
                std::cout << "Введен неправильный угол \n";
            }
            else {
                std::cout << "\n";
            }
        }
        else if (n == 2){
            std::cout << "Заданный угол: \t";
            a.print();
            std::cout << "\n";
        }
        else if (n == 3){
            std::cout <<"Данный угол в радианах: " << a.rad() << "\n";
            std::cout << "\n";
        }
        else if (n == 4){
            Angle b = a.diap(a);
            std::cout << "Данный угол в диапазоне от 0 до 360 равен углу: " << "\t";
            b.print();
            std::cout << "\n";
        }
        else if (n == 5){
            std::cout << "Первый угол равен: " << "\t";
            a.print();
            std::cout << "\n";
            Angle b = create();
            std::cout << "Второй угол равен: " << "\t";
            b.print();
            if ((b.minutes > 60) or (b.minutes < 0)){
                std::cout << "Введен неправильный угол \n";
            }
            else {
                std::cout << "\n";
                Angle c = a + b;
                std::cout << "Сумма двух углов равна: " << "\t";
                c.print();
                std::cout << "\n";
            }
        }
        else if (n == 6){
            std::cout << "Первый угол равен: " << "\t";
            a.print();
            std::cout << "\n";
            Angle b = create();
            std::cout << "Второй угол равен: " << "\t";
            b.print();
            if ((b.minutes > 60) or (b.minutes < 0)){
                std::cout << "Введен неправильный угол \n";
            }
            else {
                std::cout << "\n";
                Angle c = a - b;
                std::cout << "Разность двух углов равна: " << "\t";
                c.print();
                std::cout << "\n";
            }
        }
        else if (n == 7){
            int m;
            std::cout << "Данный угол равен: " << "\t";
            a.print();
            std::cout << "\n";
            std::cout << "Введите число, на которое хотите разделить угол: " << "\t";
            std::cin >> m;
            std::cout << "\n";
            Angle c = a / m;
            std::cout << "Угол, полученный делением данного угла на заданное число равен: " << "\t";
            c.print();
            std::cout << "\n";
        }
        else if (n == 8){
            std::cout << "Cos alpha = " << a.Cos() << "\n" << "Sin alpha = " << a.Sin() << "\n" << "Tan alpha = " << a.Tan() << "\n" << "Cot alpha = " << a.Cot() << "\n";
            std::cout << "\n";
        }
        else if (n == 9){
            std::cout << "Первый угол равен: " << "\t";
            a.print();
            std::cout << "\n";
            Angle b = create();
            std::cout << "Второй угол равен: " << "\t";
                b.print();
            if ((b.minutes > 60) or (b.minutes < 0)){
                std::cout << "Введен неправильный угол \n";
            }
            else {
                std::cout << "\n";
                if (b.comp(a) == 1){
                    std::cout << "Первый угол больше второго" << "\n";
                }
                else if (b.comp(a) == -1){
                    std::cout << "Первый угол меньше второго" << "\n";
                }
                else{
                    std::cout << "Углы равны" << "\n";
                }
                std::cout << "\n";
            }
        }
        else if (n == 0){
            break;
        }
    }
    return 0;
}

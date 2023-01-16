#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

class Figure {
private:
    double x, y, a, b, h;
public:
    double S;
    Figure(double q, double w, double e, double r, double t);
    double square();
    void print_square();
    void center();
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
    friend bool operator== (const Figure& f1, const Figure& f2);
    Figure &operator=(const Figure& right);
};

#endif // FIGURE_H_INCLUDED

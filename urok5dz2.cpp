#include <iostream>
#include <windows.h>
#include <string>

class Figura
{
protected:
    std::string name_figura;

    virtual std::string get_info_storona() { return ""; }
    virtual std::string get_info_ugol() { return ""; }

public:
    Figura() {};

    void print_info(Figura* f) {
        std::cout << this->name_figura << ":\n" << f->get_info_storona() << "\n" << f->get_info_ugol() << "\n\n";
    };
};

//// трехугольник
class Triangle : public Figura
{
protected:
    // углы
    int A = 0;
    int B = 0;
    int C = 0;
    // стороны
    int a = 0;
    int b = 0;
    int c = 0;

public:
    Triangle(int A, int B, int C, int a, int b, int c) {
        name_figura = "Треугольник";
        this->A = A;
        this->B = B;
        this->C = C;
        this->a = a;
        this->b = b;
        this->c = c;
    };

    std::string get_info_storona() override {
        return "Стороны: a=" + std::to_string(this->a) + " b=" + std::to_string(this->b) + " c=" + std::to_string(this->c);
    }

    std::string get_info_ugol() override {
        return "Углы: A=" + std::to_string(this->A) + " B=" + std::to_string(this->B) + " C=" + std::to_string(this->C);
    }    
};

// прямой треугольник
class Triangle90 : public Triangle
{

public:
    Triangle90(int A, int B, int a, int b, int c) : Triangle(A, B, 90, a, b, c) {
        name_figura = "Прямоугольный треугольник";
    };
};

// равнобедренный
class Triangle2line : public Triangle
{
public:
    Triangle2line(int A, int B, int a, int b) : Triangle(A, B, B, a, b, b) {
        name_figura = "Равнобедренный треугольник";
    };
};

// равносторонний
class Triangle3line : public Triangle
{

public:
    Triangle3line(int a) : Triangle(60, 60, 60, a, a, a) {
        name_figura = "Равносторонний треугольник";
    };
};

//// четырехугольник 
class Quatro : public Figura
{
protected:
    // углы
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    // стороны
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

public:    
    Quatro(int A, int B, int C, int D, int a, int b, int c, int d) {
          name_figura = "Квадрат";
          this->A = A;
          this->B = B;
          this->C = C;
          this->D = D;
          this->a = a;
          this->b = b;
          this->c = c;
          this->d = d;
      };


    std::string get_info_storona() override {
        return "Стороны: a=" + std::to_string(this->a) + " b=" + std::to_string(this->b) + " c=" + std::to_string(this->c) + " d=" + std::to_string(this->d);
    }

    std::string get_info_ugol() override {
        return "Углы: A=" + std::to_string(this->A) + " B=" + std::to_string(this->B) + " C=" + std::to_string(this->C) + " D=" + std::to_string(this->D);
    }
};

// Параллелограмм
class Parrallelogram : public Quatro {
public:
    Parrallelogram(int A, int B, int a, int b) : Quatro(A, B, A, B, a, b, a, b) {
        this->name_figura = "Параллелограмм";
    };
};

// ромб
class Romb : public Parrallelogram {
public:
    Romb(int a, int A, int B) :Parrallelogram(A, B, a, a) {
        name_figura = "Ромб";
    };
};

// Прямоугольник
class Pramougolnik : public Parrallelogram {

public:
    Pramougolnik(int a, int b) :Parrallelogram(90, 90, a, b) {
        name_figura = "Прямоугольник";
    };
};

// Квадрат 
class Kvadrat : public Pramougolnik {
public:
    Kvadrat(int a) : Pramougolnik(a, a) {
        name_figura = "Квадрат";
    };
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    //Figura figura;
    Triangle triangle(10,20,30,50,60,70);
    Triangle90 triangle90(10,20,30,50,60);
    Triangle2line triangle2line(10,20,50,60);
    Triangle3line triangle3line(30);
    Quatro quatro(10, 20, 30, 40, 50, 60, 70, 80);
    Parrallelogram parrallelogram(20, 30, 30, 40);
    Romb romb(30, 30, 40);
    Pramougolnik pramougolnik(10, 20);
    Kvadrat kvadrat(20);

    triangle.print_info(&triangle);
    triangle90.print_info(&triangle90);
    triangle2line.print_info(&triangle2line);
    triangle3line.print_info(&triangle3line);
    quatro.print_info(&quatro);
    parrallelogram.print_info(&parrallelogram);
    romb.print_info(&romb);
    pramougolnik.print_info(&pramougolnik);
    kvadrat.print_info(&kvadrat);
}

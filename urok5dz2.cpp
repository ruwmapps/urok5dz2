#include <iostream>
#include <windows.h>
#include <string>

class Figura
{
protected:
    std::string name_figura;

public:
    Figura() {};

    std::string get_name() {
        return this->name_figura;
    }

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
    Triangle() {};
    Triangle(int A, int B, int C, int a, int b, int c) {
        name_figura = "Треугольник";
        this->A = A;
        this->B = B;
        this->C = C;
        this->a = a;
        this->b = b;
        this->c = c;
    };

    std::string get_info_storona() {
        return "Стороны: a=" + std::to_string(this->a) + " b=" + std::to_string(this->b) + " c=" + std::to_string(this->c);
    }

    std::string get_info_ugol() {
        return "Углы: A=" + std::to_string(this->a) + " B=" + std::to_string(this->b) + " C=" + std::to_string(this->c);
    }
};

// прямой треугольник
class Triangle90 : public Triangle
{
private:
    int C = 90;

public:
    Triangle90(int A, int B, int a, int b, int c) {
        name_figura = "Прямоугольник";
        this->A = A;
        this->B = B;
        this->a = a;
        this->b = b;
        this->c = c;
    };
};

// равнобедренный
class Triangle2line : public Triangle
{
public:
    Triangle2line(int A, int B, int a, int b) {
        name_figura = "Равнобедренный треугольник";
        this->a = a;
        this->b = b;
        this->c = b;
        this->A = A;
        this->B = B;
        this->C = B;
    };
};

// равносторонний
class Triangle3line : public Triangle
{
private:
    int A = 60;
    int B = 60;
    int C = 60;

public:
    Triangle3line(int a) {
        name_figura = "Равносторонний треугольник";
        this->a = a;
        this->b = a;
        this->c = a;
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
    Quatro() {};
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


    std::string get_info_storona() {
        return "Стороны: a=" + std::to_string(this->a) + " b=" + std::to_string(this->b) + " c=" + std::to_string(this->c) + " d=" + std::to_string(this->d);
    }

    std::string get_info_ugol() {
        return "Углы: A=" + std::to_string(this->A) + " B=" + std::to_string(this->B) + " C=" + std::to_string(this->C) + " D=" + std::to_string(this->D);
    }
};

// Параллелограмм
class Parrallelogram : public Quatro {
public:
    Parrallelogram() {};
    Parrallelogram(int A, int B, int a, int b) {
        this->name_figura = "Параллелограмм";
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
    };
};

// ромб
class Romb : public Parrallelogram {
public:
    Romb(int a, int A, int B) {
        name_figura = "Ромб";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    };
};

// Прямоугольник
class Pramougolnik : public Parrallelogram {

public:
    Pramougolnik()  {
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    };
    Pramougolnik(int a, int b) : Pramougolnik() {
        name_figura = "Прямоугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
    };
};

// Квадрат 
class Kvadrat : public Pramougolnik {
public:
    Kvadrat(int a)  {
        name_figura = "Квадрат";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
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

    std::cout << triangle.get_name() << ":\n" << triangle.get_info_storona() << "\n" << triangle.get_info_ugol() << "\n\n";
    std::cout << triangle90.get_name() << ":\n" << triangle90.get_info_storona() << "\n" << triangle90.get_info_ugol() << "\n\n";
    std::cout << triangle2line.get_name() << ":\n" << triangle2line.get_info_storona() << "\n" << triangle2line.get_info_ugol() << "\n\n";
    std::cout << triangle3line.get_name() << ":\n" << triangle3line.get_info_storona() << "\n" << triangle3line.get_info_ugol() << "\n\n";
    std::cout << quatro.get_name() << ":\n" << quatro.get_info_storona() << "\n" << quatro.get_info_ugol() << "\n\n";
    std::cout << parrallelogram.get_name() << ":\n" << parrallelogram.get_info_storona() << "\n" << parrallelogram.get_info_ugol() << "\n\n";
    std::cout << romb.get_name() << ":\n" << romb.get_info_storona() << "\n" << romb.get_info_ugol() << "\n\n";
    std::cout << pramougolnik.get_name() << ":\n" << pramougolnik.get_info_storona() << "\n" << pramougolnik.get_info_ugol() << "\n\n";
    std::cout << kvadrat.get_name() << ":\n" << kvadrat.get_info_storona() << "\n" << kvadrat.get_info_ugol() << std::endl;
}

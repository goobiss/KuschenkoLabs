#include <iostream>

class Chair
{
private:

    double lenght;
    double width;

public:

    Chair() = default;
    Chair(double _lenght, double _width) : lenght(_lenght), width(_width) {};

    void print_sqrt()
    {
        std::cout << (lenght * width) * 4. + width * width << '\n';
    }

    void SetLenght(const double _lenght)
    {
        lenght = _lenght;
    }

    void SetWidth(const double _width)
    {
        width = _width;
    }

    double GetLenght()
    {
        return this->lenght;
    }

    double GetWidth()
    {
        return this->width;
    }

    friend Chair frd(Chair b, Chair a);

};

Chair frd(Chair b, Chair a)
{
    return Chair(a.width + b.width, a.lenght + b.lenght);
}

std::istream& operator >> (std::istream& ist, Chair& ch)
{
    double _lenght;
    double _width;
    std::cout << " Input lenght(Dovzhina) = ";
    ist >> _lenght;
    std::cout << " Input width(Shirina)  = ";
    ist >> _width;

    ch.SetLenght(_lenght);
    ch.SetWidth(_width);

    return ist;
}

int main()
{
    Chair chair_one = { 5.5, 4.4 };
    std::cout << "Chair1 = ";
    chair_one.print_sqrt();

    Chair chair_two;
    std::cin >> chair_two;
    std::cout << "Chair2 = ";
    chair_two.print_sqrt();

    Chair chair_three=frd(chair_one, chair_two);
    std::cout << "Chair3 = ";
    chair_three.print_sqrt();

    system("pause");
}
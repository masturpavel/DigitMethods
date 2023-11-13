
#include <iostream>
#include <cmath>
double Func(double x)
{
	return 2*x+log10(x)+0.5; // 1) pow(2,x)-3*x+2 || 2) (x-3)*cos(x)-1
}
double proizvodnaya(double x)
{
	return (3-x)*sin(x)+cos(x);
}
double func(double x) 
{
	return (-0.5 - log10(x))/2.0; //исходное 2x+lgx=-0,5          
}
int main()	
{
	int choise;
	setlocale(0, "");
	std::cout << "выберите нужную программу:\n1 - отделение корней уравнения \n2 - уточнение корня уравнения методом половинного деления \n3 - уточнение корня уравнения методом хорд\n"
	"4 - уточнение корня методом касательных\n5 - уточнение корня комбинированным методом хорд и касательных\n6 - уточнение корня методом простых итераций\n" ;
	std::cin >> choise;
	double a, b, h, c, d, eps,x,x1,x2,y1,y2,y,x0,x3;

	switch (choise) {
	case 1:
		std::cout << "Введите a,b,h\n";
		std::cin >> a >> b >> h;
		x1 = a;
		x2 = a + h;
		y1 = Func(x1);
		while (x2 < b)
		{
			y2 = Func(x2);
			if (y1*y2 <0)
			{
				std::cout << "x1 = " << x1 << " x2 = " << x2 << std::endl;
			}
			x1 = x2;
			x2 = x1 + h;
			y1 = y2;
		}
		break;
	case 2:
		std::cout << "Введите a,b,eps\n";
		std::cin >> a >> b >> eps;
		
		while (b-a > 2*eps)
		{
			c = (a + b) / 2;
			std::cout << "A = " << a << "\tB = " << b << "\tC = " << c << "\tF(a) = " << Func(a) << "\tF(c) = " << Func(c) << std::endl;
			if (Func(a) * Func(c) < 0)
				b = c;
			else
				a = c;
		}
		std::cout << "x = " << (a + b) / 2 << std::endl;
		break;
	case 3:
		std::cout << "Введите a,b,eps\n";
		std::cin >> a >> b >> eps;
		h = (b - a) / 100;
		y = Func(a);
		d = Func(a + 2 * h) - 2 * Func(a + h) + Func(a);
		if (y*d<0)
		{
			x0 = a;
			c = b;
		}
		else
		{
			x0 = b;
			c = a;
		}
		x1 = (x0*Func(c) - c * Func(x0)) / (Func(c) - Func(x0));
		while (abs(x1-x0>eps))
		{
			x0 = x1;
			x1 = (x0 * Func(c) - c * Func(x0)) / (Func(c) - Func(x0));
		}
		std::cout << "x = " << x1 << std::endl;
		break;
	case 4:
		std::cout << "Введите a,b,eps\n";
		std::cin >> a >> b >> eps;
		h = (b - a) / 100;
		x = Func(a);
		y = Func(a + 2 * h) - 2 * Func(a + h) + Func(a);
		if (x * y > 0)
			x0 = a;
		else
			x0 = b;
		x1 = x0 - (Func(x0) / proizvodnaya(x0));
		while (abs(x1-x0)>eps)
		{
			x0 = x1;
			x1 = x0 - (Func(x0) / proizvodnaya(x0));
		}
		std::cout << "x = " << x1 << std::endl;
		break;
	case 5:
		std::cout << "Введите a,b,eps\n";
		std::cin >> a >> b >> eps;
		h = (b - a) / 100;
		x = Func(a);
		y = Func(a + 2 * h) - 2 * Func(a + h) + Func(a);
		if (x * y < 0)
		{
			x0 = a;
			x1 = b;
			c = b;
		}
		else
		{
			x0 = b;
			x1 = a;
			c = a;
		}
		x2 = (x0*Func(c) - c * Func(x0)) / (Func(c) - Func(x0));
		x3 = x1 - (Func(x1) / proizvodnaya(x1));
		while (abs(x3 - x2) > 2 * eps)
		{
			x0 = x2;
			x2 = (x0*Func(c) - c * Func(x0)) / (Func(c) - Func(x0));
			x1 = x3;
			x3 = x1 - Func(x1) / proizvodnaya(x1);
		}
		x = (x2 + x3) / 2;
		std::cout << "x = " << x << std::endl;
		break;
	case 6:
		std::cout << "Введите x0,eps" << std::endl;
		std::cin >> x0 >> eps;
		x1 = func(x0);
		while (abs(x1-x0)>eps)
		{
			x0 = x1;
			x1 = func(x0);
		}
		std::cout << "x = " << x1 << std::endl;
		break;
	default:
		std::cout << "Неверный номер программы!\n";
	}
	return 0;
}



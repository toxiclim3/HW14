#include <iostream>
#include <cmath>

using namespace std;
/*

Завдання 1
Створити структуру, що описує прямокутник. Написати функції для роботи з цією структурою: переміщення прямокутника, зміна розміру прямокутника, друк прямокутника.

Завдання 2
Створіть структуру, що описує точку в двовимірній системі координат(x, y). За допомогою цієї структури задайте дві точки. Напишіть функцію, яка обчислює відстань між цими двома точками.

Завдання 3
Створіть структуру, що описує простий дріб. Реалізуйте арифметичні операції з дробами: суму, різницю, множення, ділення.

Врахувати можливість скорочення дробів і переведення з неправильного дробу в простий.

*/
struct coords
{
	int x;
	int y;
};

struct rectangle
{
	coords origin; // top left corner
	double sizex;
	double sizey;

};

#pragma region task1

rectangle makeRectangle()
{
	rectangle rect;

	cout << "Please enter the origin of your rectangle (coordinates of the top left corner):" << endl;

	cout << "X: ";
	cin >> rect.origin.x;

	cout << "Y: ";
	cin >> rect.origin.y;

	cout << "Please the width and height of your rectangle:" << endl;

	cout << "Width: " << endl;
	cin >> rect.sizex;
	cout << "Height: " << endl;
	cin >> rect.sizey;

	return rect;
}

void coutRectangle(rectangle& rect)
{
	cout << "Rectangle: " << endl;
	cout << "Origin: (" << rect.origin.x << ", " << rect.origin.y << ")" << endl;
	cout << "Size: Width: " << rect.sizex << ", Height: " << rect.sizey << endl;
}

void moveRectangle(rectangle& rect, int dx, int dy)
{
	rect.origin.x += dx;
	rect.origin.y += dy;
}

void userMoveRectangle(rectangle& rect)
{
	int dx, dy;

	cout << "Current origin: X:" << rect.origin.x << " Y:" << rect.origin.y << endl;

	cout << "Enter dx: " << endl;
	cin >> dx;

	cout << "Enter dy: " << endl;
	cin >> dy;
	moveRectangle(rect, dx, dy);

	cout << endl;
}

void resizeRectangle(rectangle& rect, double dx, double dy)
{
	rect.sizex = dx;
	rect.sizey = dy;
}

void userResizeRectangle(rectangle& rect)
{
	double dx, dy;

	cout << "Current size: Width: " << rect.sizex << " Height: " << rect.sizey << endl;

		cout << "Please enter the new width and height of your rectangle:" << endl;

	cout << "Width: " << endl;
	cin >> dx;

	cout << "Height: " << endl;
	cin >> dy;

	resizeRectangle(rect, dx, dy);
}

#pragma endregion

#pragma region task2

coords makeCoords()
{
	coords coord;

	cout << "Please enter the coordinates of your point:" << endl;

	cout << "X: ";
	cin >> coord.x;

	cout << "Y: ";
	cin >> coord.y;

	return coord;
}

double getDistance(coords& a, coords& b)
{

	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

};

#pragma endregion

#pragma region task3

int gcd(int a, int b) {
	if (b == 0 || a == 0) {
		return a + b;
	}
	else {
		if (a > b)
		{
			gcd(a % b, b);
		}
		else
		{
			gcd(a, b % a);
		}
	}
}

struct fraction
{
	int top;
	int bottom;

	void reduce() //оказывается так можно делать??!!??!!??!?!??!
	{
		int grComDen = gcd(top, bottom);

		top /= grComDen;
		bottom /= grComDen;

		if (bottom < 0) 
		{
			top = -top;
			bottom = -bottom;
		}
	}

	fraction add(fraction& frac2)
	{
		int num = top * frac2.bottom + frac2.top * bottom;
		int denom = bottom * frac2.bottom;

		fraction res;

		res.top = num; 
		res.bottom = denom; 
		res.reduce();

		return res;
	}
	
	fraction sub(fraction& frac2)
	{
		int num = top * frac2.bottom - frac2.top * bottom;
		int denom = bottom * frac2.bottom;

		fraction res;

		res.top = num; 
		res.bottom = denom; 
		res.reduce();

		return res;
	}

	fraction mul(fraction& frac2)
	{
		int num = top * frac2.top;
		int denom = bottom * frac2.bottom;

		fraction res;

		res.top = num; 
		res.bottom = denom; 
		res.reduce();

		return res;
	}	
	
	fraction div(fraction& frac2)
	{
		int num = top * frac2.bottom;
		int denom = bottom * frac2.top;

		fraction res;

		res.top = num; 
		res.bottom = denom; 
		res.reduce();

		return res;
	}

	void convToSimpleFraction() 
	{
		int whole = top / bottom;
		int newNum = top % bottom;

		printf("The fraction %i / %i as a simple fraction is: %i (as the whole part) %i / %i \n", top, bottom,whole,newNum,bottom);
	}

	void cout()
	{
		printf("%i / %i \n", top, bottom);
	}
};

#pragma endregion
int main()
{
	/*
	// task 1 (я начал печатать код в одном файле потому что сейчас нет света, и создавать кучу файлов в replit будет долго)
	rectangle rect;

	rect = makeRectangle();

	coutRectangle(rect);

	userMoveRectangle(rect);

	userResizeRectangle(rect);

	coutRectangle(rect);

	//task 2

	coords point1, point2;

	point1 = makeCoords();
	point2 = makeCoords();

	cout << "Distance between points: " << getDistance(point1, point2) << endl;
	*/
	//task 3


	fraction frac1, frac2;

	frac1.top = 6;
	frac1.bottom = 8;

	frac2.top = 3;
	frac2.bottom = 7;

	frac1.cout();
 	frac1 = frac1.div(frac2);
	frac1.cout();

}
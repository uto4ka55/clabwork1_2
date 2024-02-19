#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*Вивести на екран кількість дійсних коренів біквадратного рівнянняa x^4 + bx^2 + c = 0
 *в залежності від значень його параметрів a,b,c.*/

int main(){
    string aS, bS, cS;
    double a, b, c;

    try {
        cout << "Введіть коефіцієнти a,b i c біквадратного рівняння ax^4 + bx^2 + c = 0 " << endl;
        cout << "a = ";
        cin >> aS;
        cout << "b = ";
        cin >> bS;
        cout << "c = ";
        cin >> cS;
        size_t pos1, pos2, pos3;
        a = stod(aS, &pos1);
        b = stod(bS, &pos2);
        c = stod(cS, &pos3);
        if (pos1 < aS.size()|| pos2 < bS.size() || pos3 < cS.size()){
            throw 1;
        }
    }
    catch(...) {
        cout << endl << "Ви ввели некоректні дані!";
        return 1;
    }

    cout <<endl << "Якщо " << "a = " << a << ", b = " << b << ", c = " << c << endl;
    double discriminant = b * b - 4 * a * c;
    cout << "Дискримінант = " << discriminant << endl;
    if (discriminant > 0) {
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);
        //cout << "t1 = " << t1 << ", t2 = " << t2 << endl;
        if (t1>0 and t2>0) { cout << "Рівняння має 4 розв'язки. "  << endl;}
        else if((t1>0 and t2==0)||(t2>0 and t1==0)){ cout << "Рівняння має 3 розв'язки. "  << endl;}
        else if((t1>0 and t2<0) || (t2>0 and t1 < 0)){ cout << "Рівняння має 2 розв'язки. "  << endl;}
        else if((t1==0 and t2 <0)||(t2==0 and t1<0 )){cout << "Рівняння має 2 розв'язки. "  << endl;}
    } else if (discriminant == 0) {
        double t = -b / (2 * a);
        //cout << "t = " << t << endl;
        if (t > 0) {cout << "Рівняння має 2 розв'язки."  << endl;}
        else if (t == 0) {cout << "Рівняння має 1 розв'язок."  << endl;}
    } else {
        cout << "рівняння не має розв'язків." << endl;
    }

    return 0;
}

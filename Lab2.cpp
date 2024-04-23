/*Создайте иерархию классов Сторона – Квадрат – Куб. 
Класс Квадрат должен содержать метод для вычисления площади квадрата, а класс Куб метод для вычисления объема куба. 
При вычислении объема куба учитывать толщину стенок куба. Последние два класса в иерархии должны иметь конструкторы.

Создайте метод MAIN, в котором создается 2 куба (т.е. 2 объекта класса Куб), 
определяется какой из кубов меньший и сколько надо наполнить водой меньших кубов, чтобы заполнить больший. 
Необходимо также показывать все характеристики создаваемых объектов.*/
#include <iostream>
using namespace std;

// класс Сторона
class Side {
protected:
    double length; // Длина стороны

public:
    Side(double l){
        length = l;
    }
};

// класс Квадрат
class Square : public Side {
public:
    
    Square(double l) : Side(l) {
        
    }

    
    double Area() { // для вычисления площади квадрата
        return length * length;
    }
};

// класс Куб
class Cube : public Square {
private:
    double wall_thickness; // толщина стенки куба

public:
    Cube(double l, double w) : Square(l), wall_thickness(w) {}

    // вычесляю объема куба
    double Volume() {
        double inner_length = length - 2 * wall_thickness; // внутр. длина стороны куба
        double volume;
         if (inner_length > 0) {
            volume = inner_length * inner_length * inner_length;
         } else {
         volume=0;}
         return volume;
    }
    //для вывода характеристик куба
    void DisplayCube() {
        cout << "Длина стороны: " << length << " см" << endl;
        cout << "Толщина стенки: " << wall_thickness << " см" << endl;
        cout << "Объем куба: " << Volume() << " куб.см" << endl;
    }
};

int main() {
    // Создание двух кубов
    Cube cube1(10, 1); //  сторона 10 и толщина стенки 1
    Cube cube2(15, 1.5); // сторона 15 и толщиной стенки 1.5

    // определяю обьем меньшего куба и большего
    double smaller_cube_volume;
    double larger_cube_volume;
    
    if (cube1.Volume() < cube2.Volume()){
        smaller_cube_volume =  cube1.Volume();
    } else {
        smaller_cube_volume = cube2.Volume();
    }
    if (cube1.Volume() >= cube2.Volume()){
         larger_cube_volume = cube1.Volume();
    }else {
         larger_cube_volume = cube2.Volume();
    }
    double num_smaller_cubes = larger_cube_volume / smaller_cube_volume; // сколько меньших кубов с водой нужно, чтобы заполнить больший

    cout << "Характеристики первого куба:" << endl;
    cube1.DisplayCube();
    cout << "\nХарактеристики второго куба:" << endl;
    cube2.DisplayCube();

    //сколько меньших кубов нужно, чтобы заполнить больший
    cout << "\nЧтобы заполнить больший куб, необходимо " << num_smaller_cubes << " меньших кубов." << endl;

    return 0;
}

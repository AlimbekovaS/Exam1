//Программу написала на С++, так как я лучше поняла классы чем структуры
//Вариант №1
//Разработайте приложение «Фирма риелторов».Разработайте структуру «Квартира»(номер квартиры, кол - во комнат, общая площадь, стоимость, продана / свободна / забронирована).Создайте массив из 10 квартир.Реализовать следующий функционал :
//•	Редактировать квартиру
//•	Продать квартиру
//•	Забронировать квартиру
//•	Печать всех квартир
//•	Печать всех проданных квартир
//•	Печать всех свободных квартир
//•	Печать всех забронированных квартир
//•	Расчет прибыли(сумма цены, всех проданных квартир)
//Примечание: для более удобной работы с вашей программой, рекомендуем ввести информацию о квартирах в программе.
#include<iostream>
#include<fstream>
#include<string>
#include"Kvartira.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	Kvartira * f= new Kvartira[15];
	int i = 0;
	ifstream in;
	in.open("kvartiry.txt");
	if (in.is_open())
	{
		int nom_kv, kol_komn, S, price;
		string stat;
		while (!in.eof())
		{
			in >> nom_kv >> kol_komn >> S >> price >> stat;
			Kvartira k(nom_kv, kol_komn, S, price, stat);
			f[i++] = k;
		}
		in.close();
		int nz, nom_red, sold_kv;
		while (true)
		{
			cout << "\nКакое задание? (Для выхода 0)\n";
			cout << "1-Редактировать квартиру\n"
				<< "2-Продать квартиру\n"
				<< "3-Забронировать квартиру\n"
				<< "4-Печать всех квартир\n"
				<< "5-Печать всех проданных квартир\n"
				<< "6-Печать всех свободных квартир\n"
				<< "7-Печать всех забронированных квартир\n"
				<< "8-Расчет прибыли(сумма цены, всех проданных квартир)" << endl;
			cin >> nz;
			
			switch (nz)
			{
			case 0: {break; }
			case 1:
			{
				cout << "Введите номер квартиры которую необходимо редактировать: ";
				cin >> nom_red;
				cout << "введите через пробел номер квартиры, кол - во комнат, общая площадь, стоимость, статус(sold/available/reserved ";
				cin >> nom_kv >> kol_komn >> S >> price >> stat;;
				f[nom_red - 1].setAll(nom_kv, kol_komn, S, price, stat);
				cout << "проверка\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 2:
			{
				cout << "Продать квартиру\n";
				cout << "Введите номер квартиры которая продана: ";
				cin >> sold_kv;
				f[sold_kv - 1].setStat("sold");
				cout << "проверка\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 3: 
			{
				cout << "Забронировать квартиру\n";
				cout << "Введите номер квартиры которая забронирована: ";
				cin >> sold_kv;
				f[sold_kv - 1].setStat("reserved");
				cout << "проверка\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 4:
			{
				cout << "Печать всех квартир\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 5:
			{
				cout << "Печать всех проданных квартир\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showSoldKv();
				}
				cout << "========================================\n\n";
				break;
			}
			case 6:
				cout << "Печать всех свободных квартир\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAvailableKv();
				}
				cout << "========================================\n\n";
				break;
			case 7:
			{
				cout << "Печать всех забронированных квартир\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showReservedKv();
				}

				cout << "========================================\n\n";
				break;
			}
			case 8:
			{
				cout<< "Расчет прибыли(сумма цены, всех проданных квартир)" << endl;
				int pribl = 0;
				for (int k = 0; k < i; k++)
				{
					pribl+=f[k].showPribl();
				}
				cout << pribl<<endl;
				break;
	
			}			
			default:
				break;
			}
			
			ofstream safe;
			safe.open("safe.txt");
			for (int k = 0; k < i; k++)
			{
				safe << f[k].getNom_kv()<<" "<< f[k].getKol_komn() <<" "<< f[k].getS() <<" "<< f[k].getPrice() <<" "<< f[k].getStat() << endl;		
			}
			safe.close();
			cout << "Данные сохранены в файле safe.txt";
		}
	}
	else
	{
		cout << "error";
	}
	delete[]f;
	
	system("pause");
	return 0;
}
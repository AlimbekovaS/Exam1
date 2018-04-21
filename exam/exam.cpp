//��������� �������� �� �++, ��� ��� � ����� ������ ������ ��� ���������
//������� �1
//������������ ���������� ������ ���������.������������ ��������� ���������(����� ��������, ��� - �� ������, ����� �������, ���������, ������� / �������� / �������������).�������� ������ �� 10 �������.����������� ��������� ���������� :
//�	������������� ��������
//�	������� ��������
//�	������������� ��������
//�	������ ���� �������
//�	������ ���� ��������� �������
//�	������ ���� ��������� �������
//�	������ ���� ��������������� �������
//�	������ �������(����� ����, ���� ��������� �������)
//����������: ��� ����� ������� ������ � ����� ����������, ����������� ������ ���������� � ��������� � ���������.
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
			cout << "\n����� �������? (��� ������ 0)\n";
			cout << "1-������������� ��������\n"
				<< "2-������� ��������\n"
				<< "3-������������� ��������\n"
				<< "4-������ ���� �������\n"
				<< "5-������ ���� ��������� �������\n"
				<< "6-������ ���� ��������� �������\n"
				<< "7-������ ���� ��������������� �������\n"
				<< "8-������ �������(����� ����, ���� ��������� �������)" << endl;
			cin >> nz;
			
			switch (nz)
			{
			case 0: {break; }
			case 1:
			{
				cout << "������� ����� �������� ������� ���������� �������������: ";
				cin >> nom_red;
				cout << "������� ����� ������ ����� ��������, ��� - �� ������, ����� �������, ���������, ������(sold/available/reserved ";
				cin >> nom_kv >> kol_komn >> S >> price >> stat;;
				f[nom_red - 1].setAll(nom_kv, kol_komn, S, price, stat);
				cout << "��������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 2:
			{
				cout << "������� ��������\n";
				cout << "������� ����� �������� ������� �������: ";
				cin >> sold_kv;
				f[sold_kv - 1].setStat("sold");
				cout << "��������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 3: 
			{
				cout << "������������� ��������\n";
				cout << "������� ����� �������� ������� �������������: ";
				cin >> sold_kv;
				f[sold_kv - 1].setStat("reserved");
				cout << "��������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 4:
			{
				cout << "������ ���� �������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAll();
				}
				cout << "========================================\n\n";
				break;
			}
			case 5:
			{
				cout << "������ ���� ��������� �������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showSoldKv();
				}
				cout << "========================================\n\n";
				break;
			}
			case 6:
				cout << "������ ���� ��������� �������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showAvailableKv();
				}
				cout << "========================================\n\n";
				break;
			case 7:
			{
				cout << "������ ���� ��������������� �������\n";
				for (int k = 0; k < i; k++)
				{
					f[k].showReservedKv();
				}

				cout << "========================================\n\n";
				break;
			}
			case 8:
			{
				cout<< "������ �������(����� ����, ���� ��������� �������)" << endl;
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
			cout << "������ ��������� � ����� safe.txt";
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
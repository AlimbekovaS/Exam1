#pragma once
#include<string>
using namespace std;
class Kvartira
{
private:
	int nom_kv;
	int kol_komn;
	int S;
	int price;
	string stat;
public:
	Kvartira() = default;
	Kvartira(int nom_kv, int kol_komn, int S, int price, string stat)
	{
		this->nom_kv = nom_kv;
		this->kol_komn = kol_komn;
		this->S = S;
		this->price = price;
		this->stat = stat;
	}
	//accessors
	int getNom_kv() {return nom_kv;}
	int getKol_komn() { return kol_komn; }
	int getS() { return S; }
	int getPrice(){ return  price; }
	string getStat() { return  stat; }
	//mutators
	void setNom_kv(int nom_kv) { this->nom_kv= nom_kv; }
	void setKol_komn(int kol_komn) { this->kol_komn= kol_komn; }
	void setS(int S) { this->S= S; }
	void setPrice(int price) { this->price= price; }
	void setStat(string stat) { this->stat= stat; }
	void setAll(int nom_kv, int kol_komn, int S, int price, string stat)
	{
		this->nom_kv = nom_kv;
		this->kol_komn = kol_komn;
		this->S = S;
		this->price = price;
		this->stat = stat;
	}
	//methods
	void showAll()
	{
		cout << nom_kv << "\t" << kol_komn << "\t" << S << "\t" << price << "\t" << stat << endl;
	}
	void showSoldKv()
	{
		if(stat=="sold")
			cout << nom_kv << "\t" << kol_komn << "\t" << S << "\t" << price << "\t" << stat << endl;
	}
	void showAvailableKv()
	{
		if (stat == "available")
			cout << nom_kv << "\t" << kol_komn << "\t" << S << "\t" << price << "\t" << stat << endl;
	}
	void showReservedKv()
	{
		if (stat == "reserved")
			cout << nom_kv << "\t" << kol_komn << "\t" << S << "\t" << price << "\t" << stat << endl;
	}
	
	int showPribl()
	{
		if (stat == "sold")
		return price;
	}
};

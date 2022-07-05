#pragma once

namespace HeaderFiles::Products
{
	class Product {
	public:
		static int staticId;
		int id = 0;
		string name = "";
		double price = 0;
		string color = "";
		string country = "";
		string dateOfProduction = "";
		string expirationDate = "";


		Product() = default;


		Product(string name, double price, string color, string country, string dateOfProduction, string expirationDate)

		{
			id = staticId++;
			this->name = name;
			this->price = price;
			this->color = color;
			this->country = country;
			this->dateOfProduction = dateOfProduction;
			this->expirationDate = expirationDate;
		}

		string getName()const { return name; }
		double getPrice()const { return price; }
		string getColor()const { return color; }
		string getCountry()const { return country; }
		string getDateOfProduction()const { return dateOfProduction; }
		string getExpirationDate()const { return expirationDate; }


		void print()const {
			cout << "Id: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Price: " << price << endl;
			cout << "Color: " << color << endl;
			cout << "Country: " << country << endl;
			cout << "DateOfProduction: " << dateOfProduction << endl;
			cout << "ExpirationDate: " << expirationDate << endl;
		}

		friend istream& operator>>(istream& input, Product& p);
	};

	int Product::staticId = 0;

	istream& operator>>(istream& input, Product& p) {
		cout << "Enter name: " << endl;
		getline(input, p.name);

		cout << "Enter price: " << endl;
		input >> p.price;
		cin.ignore();

		cout << "Enter color: " << endl;
		getline(input, p.color);

		cout << "Enter country: " << endl;
		getline(input, p.country);

		cout << "Enter dateOfProduction: " << endl;
		getline(input, p.dateOfProduction);

		cout << "Enter expirationDate: " << endl;
		getline(input, p.expirationDate);

		return input;

	}

}


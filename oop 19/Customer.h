#pragma once

namespace HeaderFiles::Users
{
	class Customer :public Person {
		static int StaticId;
		int id = 0;
		string username = "";
		string password = "";


	public:
		Customer() = default;

		Customer(string username, string password, string name, string surname, string dateofBrith)
			:Person(name, surname, dateofBrith)
		{
			id = StaticId++;
			this->username = username;
			this->password = password;
		}

		string getUsername()const { return username; }
		string getPassword()const { return password; }


		void print()const {
			cout << "Id: " << id << endl;
			Person::print();
			cout << "Username: " << username << endl;
			cout << "Password: " << password << endl << endl;
		}

		friend istream& operator>>(istream& input, Customer& p);

	};

	int Customer::StaticId = 0;

	istream& operator>>(istream& input, Customer& c) {
		cout << "Enter name: ";
		getline(input, c.name);

		cout << "Enter surname: ";
		getline(input, c.surname);

		cout << "Enter username: ";
		getline(input, c.username);

		cout << "Enter password: ";
		getline(input, c.password);

		return input;
	}



}


#pragma once

namespace HeaderFiles::Users
{
	class Admin :public Person {
		static int StaticId;
		int id = 0;
		string username = "";
		string password = "";

	public:
		Admin() = default;

		Admin(string username, string password, string name, string surname, string dateofBrith)
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



	};

	int Admin::StaticId = 0;

}


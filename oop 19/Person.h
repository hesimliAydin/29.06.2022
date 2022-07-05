#pragma once

namespace HeaderFiles
{
	class Person {
	protected:
		string name = "";
		string surname = "";
		string dateOfBirth = "";



		Person() = default;

		Person(string name, string surname, string dateOfBirth) {
			this->name = name;
			this->surname = surname;
			this->dateOfBirth = dateOfBirth;
		}

		string getName()const { return name; }
		string getSurname()const { return surname; }
		string getDateOfBirth()const { return dateOfBirth; }


		void print()const {
			cout << "Name: " << name << endl;
			cout << "Surname: " << surname << endl;
			cout << "DateOfBrith: " << dateOfBirth << endl;
		}


	};

}


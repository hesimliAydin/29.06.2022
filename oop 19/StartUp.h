#pragma once

namespace HeaderFiles 
{
	using namespace HeaderFiles::Products;
	using namespace HeaderFiles::Users;



	void startUp() {
		Admin a1("ZoreX", "Aydin123", "Aydin", "Hesimli", "03.12.2003");
		Customer c1("KenanMuradov", "kenan123", "Kenan", "Muradov", "29.08.2004");
		Product p1("Apple", 1.80, "Red and Green", "Iran", "12.04.2022", "12.05.2022");
		LogIn l1;


		cout << "Welcome Zorex Shop Online" << endl;
		int choose;
		size_t id;
		Database dataBase;
		dataBase.addCustomer(c1);
		dataBase.addAdmin(a1);
		Product temp;
		size_t quantity;
		Customer customer;

		while (true)
		{
			cout << "Login or new account? " << endl;
			cout << "Login (1): " << endl
				<< "New account (2)" << endl;
			cin >> choose;
			cin.ignore();
			switch (choose)
			{
			case 1:
				cout << "Are you admin? (1)Yes  (0)No " << endl;
				cin >> l1.admin;
				cin.ignore();
				cout << "Enter username: " << endl;
				getline(cin, l1.username);
				cout << "Enter password: " << endl;
				getline(cin, l1.password);
				try
				{
					dataBase.checkUser(l1);
				}
				catch (const exception& ex)
				{
					cout << ex.what() << endl;
					continue;
				}
				break;
			case 2:
				cin >> customer;
				dataBase.addCustomer(customer);
				break;
			default:
				cout << "Unknown command";
				continue;
			}



			if (l1.admin == true)
			{

				while (true)
				{
					cout << "Enter choice: " << endl
						<< "Uptade: (1)" << endl
						<< "Create: (2)" << endl
						<< "Read:   (3)" << endl
						<< "Delete: (4)" << endl
						<< "Show All Product: (5)" << endl;

					cin >> choose;
					cin.ignore();
					switch (choose)
					{
					case 1:
						cout << "Enter id of the product that you want to uptade: " << endl;
						cin >> id;
						cin.ignore();
						cin >> temp;
						try
						{
							dataBase.Update(id, temp);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						system("cls");
						break;
					case 2:
						cout << "Enter product information: " << endl;
						cin >> temp;
						try
						{
							dataBase.Create(&temp);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						system("cls");
						break;
					case 3:
						cout << "For more information enter id of the product: " << endl;
						cin >> id;
						try
						{
							dataBase.Read(id);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						break;
					case 4:
						cout << "Enter id of the product that you want to delete: " << endl;
						cin >> id;
						try
						{
							dataBase.Delete(id);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						system("cls");
						break;
					case 5:
						dataBase.showAllProduct();
						break;
					default:
						break;
					}
				}
			}
			else
			{
				while (true)
				{
					cout << "ShowAllProduct (1)" << endl
						<< "Read: (2)" << endl;
					cin >> choose;
					switch (choose)
					{
					case 1:

						dataBase.showAllProduct();
						break;
					case 2:
						cout << "For more information enter id of the product: " << endl;
						cin >> id;
						try
						{
							dataBase.Read(id);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						break;
					default:
						break;
					}
				}
			}




		}



	}

}


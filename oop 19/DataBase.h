#pragma once

namespace HeaderFiles
{
	using namespace HeaderFiles::Products;
	using namespace HeaderFiles::Users;

	class Database {
		vector<ProductItem> productItem;
		vector<Customer> customers;
		vector<Admin> admins;

	public:
		void Update(int id, Product product) {
			for (size_t i = 0; i < productItem.size(); i++)
			{
				if (productItem[i].id == id)
				{
					productItem[i].product = &product;

					return;
				}
			}

			throw exception("Can not uptade");
		}


		void Create(Product* product) {

			if (product == nullptr)
			{
				throw exception("Product==nullptr");
			}

			size_t quantity;
			cout << "Enter the quantity: " << endl;
			cin >> quantity;

			ProductItem temp(product, quantity);
			productItem.push_back(temp);

		}


		void Read(int id) {
			for (size_t i = 0; i < productItem.size(); i++)
			{
				if (productItem[i].id == id)
				{
					productItem[i].product->print();

					return;
				}
			}

			throw exception("Id not found");
		}
		void Delete(int id) {
			for (size_t i = 0; i < productItem.size(); i++)
			{
				if (productItem[i].id == id)
				{
					productItem.erase(productItem.begin() + i);

					return;
				}
			}

			throw exception("Id not fount");
		}

		void showAllProduct() {
			for (size_t i = 0; i < productItem.size(); i++)
			{
				productItem[i].print();
			}
		}

		void findCustomer(LogIn login) {
			for (size_t i = 0; i < customers.size(); i++)
			{
				if (customers[i].getUsername() == login.username && customers[i].getPassword() == login.password)
				{
					return;
				}
			}
			throw exception("Wrong username or password");
		}

		void findAdmin(LogIn login) {
			for (size_t i = 0; i < admins.size(); i++)
			{
				if (admins[i].getUsername() == login.username && admins[i].getPassword() == login.password)
				{
					return;
				}
			}

			throw exception("Wrong username or password");

		}

		void checkUser(LogIn login) {
			if (login.admin == true)
			{
				for (size_t i = 0; i < admins.size(); i++)
				{
					if (admins[i].getUsername() == login.username && admins[i].getPassword() == login.password)
					{
						return;
					}
				}
			}
			else
			{
				for (size_t j = 0; j < customers.size(); j++)
				{
					if (customers[j].getUsername() == login.username && customers[j].getPassword() == login.password)
					{
						return;
					}
				}
			}

			throw exception("Wrong username or password");
		}

		void addCustomer(Customer customer) {
			customers.push_back(customer);
		}

		void addAdmin(Admin admin) {
			admins.push_back(admin);
		}

	};


}


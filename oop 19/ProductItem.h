#pragma once


namespace HeaderFiles::Products
{
	class ProductItem {

	public:
		static int staticId;
		int id = 0;
		Product* product;
		size_t quantity = 0;



		ProductItem() = default;

		ProductItem(Product* product, size_t quantity) {
			id = staticId++;
			this->product = product;
			this->quantity = quantity;
		}


		double TotalPrice() {

			if (product == nullptr)
			{
				throw exception("Product==nullptr");
			}

			if (quantity <= 0)
			{
				throw exception("Quantity<=0");
			}

			return product->price * quantity;

		}

		void print()const {
			cout << "Id: " << id << endl;
			cout << "ProductName: " << product->name << endl;
			cout << "Price: " << product->price << endl;
			cout << "Quantity: " << quantity << endl;
		}
	};

	int ProductItem::staticId = 0;


}


#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct():Product(){}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity):Product(category, id, name, quantity)
{
	setYearsOfWarranty(yearsOfWarranty);
	setPrice(price);
	setProducer(producer);
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn):Product(pn)
{
	yearsOfWarranty=pn.yearsOfWarranty;
	price=pn.price;
	producer=pn.producer;
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	yearsOfWarranty=garantieAni;
}

void NonFoodProduct::setPrice(float price)
{
	this->price=price;
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer=producer;
}

int NonFoodProduct::getYearsOfWarranty()
{
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	return price;
}

string &NonFoodProduct::getProducer()
{
	return producer;
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj)
{
	return this->id==obj.id;
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	(Product&)(*this)=a;
	yearsOfWarranty=a.yearsOfWarranty;
	price=a.price;
	producer=a.producer;
	return *this;
}

string NonFoodProduct::getProductType()
{	
	return "NonFoodProduct";
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}

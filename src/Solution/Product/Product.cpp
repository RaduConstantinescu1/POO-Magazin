#include "Product.h"
using namespace std;

Product::Product(){}

Product::~Product(){}

bool Product::checkQuantity(int requestedQuantity)
{	
	return quantity==requestedQuantity;
}

Product::Product(const string &category, int id, const string &name, int quantity)
{
	setCategory(category);
	setId(id);
	setName(name);
	setQuantity(quantity);
}

Product::Product(const Product &p)
{
	category=p.category;
	id=p.id;
	name=p.name;
	quantity=p.quantity;
}

void Product::decreaseQuantity(int requestedQuantity)
{
	if(quantity>requestedQuantity){
		quantity=quantity-requestedQuantity;
	}
	else{
		quantity=0;
	}
}

void Product::increaseQuantity(int requestedQuantity)
{
	quantity=quantity+requestedQuantity;
}

void Product::setCategory(const string &category)
{
	this->category=category;
}

void Product::setId(int id)
{
	this->id=id;
}

void Product::setQuantity(int quantity)
{
	this->quantity=quantity;
}

void Product::setName(const string &name)
{	
	this->name=name;
}

string &Product::getCategory()
{
	return category;
}

int Product::getQuantity()
{	
	return quantity;
}

int Product::getId()
{	
	return id;
}

string &Product::getName()
{
	return name;
}

const Product &Product::operator=(const Product &a)
{
	category=a.category;
	id=a.id;
	name=a.name;
	quantity=a.quantity;
	return *this;
}

json Product::toJSON()
{
	return json(*this);
}

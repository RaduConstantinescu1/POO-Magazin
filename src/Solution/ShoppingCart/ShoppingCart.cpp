#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	setPayMethod(payMethod);
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod=payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	if(quantity>0){
		shoppingCart.insert(pair<int,int>(id,quantity));
	}
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	map<int,int>::iterator it=shoppingCart.find(id);
	if(it!=shoppingCart.end()){
		it->second=it->second+quantity;
	}
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	map<int,int>::iterator it=shoppingCart.find(id);
	if(it!=shoppingCart.end()){
		if(it->second>quantity){
			it->second=it->second-quantity;
		}
		else{
			this->deleteProduct(id);
		}
	
	}
}

int ShoppingCart::getQuantity(int productID)
{	
	map<int,int>::iterator it=shoppingCart.find(productID);
	if(it!=shoppingCart.end()){
		return it->second;
	}
	else{
		return -1;
	}
}

void ShoppingCart::deleteProduct(int productID)
{
	map<int,int>::iterator it=shoppingCart.find(productID);
	if(it!=shoppingCart.end()){
		shoppingCart.erase(it);	
	}
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}

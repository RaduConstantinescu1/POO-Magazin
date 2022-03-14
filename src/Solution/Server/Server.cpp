#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	ShoppingCart* s;
	list<User*>::iterator it=usr.begin();
	while(it!=usr.end()){
		s=new ShoppingCart();
		__UserID__ProductsCart__.insert(pair<int,ShoppingCart*>((*it)->getUserID(),s));
		it++;
	}
}

list<Product *> &Server::getProductsList()
{
	return prod;
	
}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	if (quantity<=0){
		return false;
	}
	list<Product*>::iterator itp=prod.begin();
	list<User*>::iterator itu=usr.begin();
	int k=0;
	while(itp!=prod.end()){
		if((*itp)->getId()==productID){
			k++;
			break;
		}
		itp++;
	}

	while(itu!=usr.end()){
		if((*itu)->getUserID()==userID){
			k++;
		}
		itu++;
	}
	if(k!=2){
		return false;
	}
	k=0;
	map<int, ShoppingCart *>::iterator its=__UserID__ProductsCart__.find(userID);
	map<int, int>::iterator itc=its->second->getShoppingCart().begin();
	while(itc!=its->second->getShoppingCart().end()){
		if((*itc).first==productID){
			k++;
		}
		itc++;
	}
	if(k==1){
		if((*itp)->getQuantity()<quantity){
			return false;
		}
		else{
			its->second->raiseQuantity(productID,quantity);
			(*itp)->decreaseQuantity(quantity);
		}	
	}
	else{
		if((*itp)->getQuantity()<quantity){
			return false;
		}
		else{
			its->second->addProduct(productID,quantity);
			(*itp)->decreaseQuantity(quantity);
		}	
	}
	return true;
	
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	if (quantity<=0){
		return false;
	}
	list<Product*>::iterator itp=prod.begin();
	list<User*>::iterator itu=usr.begin();
	int k=0;
	while(itp!=prod.end()){
		if((*itp)->getId()==productID){
			k++;
			break;
		}
		itp++;
	}
	
	while(itu!=usr.end()){
		if((*itu)->getUserID()==userID){
			k++;
		}
		itu++;
	}
	if(k!=2){
		return false;
	}
	k=0;
	map<int, ShoppingCart *>::iterator its=__UserID__ProductsCart__.find(userID);
	map<int, int>::iterator itc=its->second->getShoppingCart().begin();
	while(itc!=its->second->getShoppingCart().end()){
		if((*itc).first==productID){
			k++;
		}
		itc++;
	}
	if(k==1){
		if(its->second->getQuantity(productID)<=quantity){
			(*itp)->increaseQuantity(its->second->getQuantity(productID));
			its->second->lowerQuantity(productID,quantity);
		}
		else{
			its->second->lowerQuantity(productID,quantity);
			(*itp)->increaseQuantity(quantity);
		}	
	}
	else{
		return false;
	}
	return true;
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}

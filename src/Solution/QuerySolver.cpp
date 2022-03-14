#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
  list<Product*>espressoare;
  list<Product*>::iterator it=server->getProductsList().begin();
  while(it!=server->getProductsList().end()){
  	if((*it)->getCategory()=="espressor" && (*it)->getQuantity()>0 && (*it)->getProductType()=="DiscountedProduct"){
  		espressoare.push_back(*it);
	  }
  	it++;
  }
  return espressoare;
}

list<User*> QuerySolver::Query_3b(){
  list<User*>::iterator it=server->getUsersList().begin();
  list<User*>basicUsers;
  while(it!=server->getUsersList().end()){
  	if((*it)->getUserType()=="BasicUser" && (*it)->getTransportCost()<=11.5){
  		basicUsers.push_back(*it);
	  }
	it++;
  }
  return basicUsers;
}

list<Product*> QuerySolver::Query_3c(){
  list<Product*>::iterator it=server->getProductsList().begin();
  list<Product*>resealedProducts;
  while(it!=server->getProductsList().end()){
  	if((*it)->getProductType()=="ResealedProduct"){
  		ResealedProduct* r=dynamic_cast<ResealedProduct*>(*it);
  		if(r->getReason()=="lipsa_accesorii"){
  			resealedProducts.push_back(r);
	  	}
	  }
  	it++;
  }
  resealedProducts.sort(Utility::compareResealedProduct);
  return resealedProducts;
}

list<Product*> QuerySolver::Query_3d(){
  list<Product*>::iterator it=server->getProductsList().begin();
  list<Product*>foodProducts;
  while(it!=server->getProductsList().end()){
  	if((*it)->getProductType()=="FoodProduct"){
  		FoodProduct* f=dynamic_cast<FoodProduct*>(*it);
  		foodProducts.push_back(f);
	  }
  	it++;
  }
  foodProducts.sort(Utility::compareFoodProduct);
  return foodProducts;
}

list<User*> QuerySolver::Query_3e(){
 list<User*>::iterator it=server->getUsersList().begin();
 list<User*>sameAddress;
 map<string,int>counter;
 while(it!=server->getUsersList().end()){
 	counter[(*it)->getDeliveryData().getCounty()]++;
 	it++;
 }
map<string,int>::iterator it2=counter.begin();
int max=0;
string judet;
while(it2!=counter.end()){
	if(it2->second>max){
		max=it2->second;
		judet=it2->first;
	}
	it2++;
 }
 it=server->getUsersList().begin();
 while(it!=server->getUsersList().end()){
 	if((*it)->getBillingData().getCounty()==(*it)->getDeliveryData().getCounty()
	  && (*it)->getBillingData().getCounty()==judet && (*it)->getBillingData().getApartment()==0){
 		sameAddress.push_back(*it);
	 }
	it++;
 }
 sameAddress.sort(Utility::compareUser);
 return sameAddress;
 
}

list<User*> QuerySolver::Query_3f()
{
	list<User*>::iterator itu=server->getUsersList().begin();
	list<Product*>::iterator itp;
	list<User*>users;
	int stop;
	while(itu!=server->getUsersList().end()){
		stop=0;
		if((*itu)->getUserType()=="PremiumUser"){
			PremiumUser* premium=dynamic_cast<PremiumUser*>(*itu);
			map<int,int>::iterator itd=premium->getDiscounts().begin();
			while(itd!=premium->getDiscounts().end()){
				itp=server->getProductsList().begin();
				while(itp!=server->getProductsList().end()){
					if((*itp)->getCategory()=="telefon"|| (*itp)->getCategory()=="imprimanta"){
						if((*itp)->getId()==itd->first){
							users.push_back(*itu);
							stop++;
						}
					}
					if(stop==1){
						itp=server->getProductsList().end();
					}
					else{
						itp++;
					}
				
				}
				if(stop==1){
					itd=premium->getDiscounts().end();
				}
				else{
					itd++;
				}
				
			}
		}
		itu++;
	}
	return users;
  
}

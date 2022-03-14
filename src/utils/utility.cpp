#include "utility.h"

bool Utility::compareFoodProduct(Product* prod1, Product* prod2)
{
  FoodProduct* p1=dynamic_cast<FoodProduct*>(prod1);
  FoodProduct* p2=dynamic_cast<FoodProduct*>(prod2);
  if (p1->getName() < p2->getName()){return true;}
  if (p1->getName() > p2->getName()){return false;}	
	
  if (p1->getCountryOfOrigin() < p2->getCountryOfOrigin()){return true;}
  if (p1->getCountryOfOrigin() > p2->getCountryOfOrigin()){return false;}
 
  if (p1->getLeiPerKg() < p2->getLeiPerKg()){return true;}
  if (p1->getLeiPerKg() > p2->getLeiPerKg()){return false;}
 
 
  return false;
}

bool Utility::compareResealedProduct(Product* prod1, Product* prod2)
{
	
  ResealedProduct* p1=dynamic_cast<ResealedProduct*>(prod1);
  ResealedProduct* p2=dynamic_cast<ResealedProduct*>(prod2);
  if (p1->getPrice() < p2->getPrice()){return true;}
  if (p1->getPrice() > p2->getPrice()){return false;}
  
  return false;
}

bool Utility::compareUser(User* user1, User* user2)
{
  if (user1->getUserID() < user2->getUserID()){return true;}
  if (user1->getUserID() > user2->getUserID()){return false;}
  
  return false;
}

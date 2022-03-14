#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/User/User.h"

class Utility{

public:
	
static bool compareFoodProduct(Product* , Product*);
static bool compareResealedProduct(Product* ,Product* );
static bool compareUser(User*,User*);

};

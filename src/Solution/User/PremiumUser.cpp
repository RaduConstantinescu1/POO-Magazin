#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser():User(){}

PremiumUser::PremiumUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf,
						 const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl,
						 int id, const string &nume, const string &prenume, const string &email, int premiumSubscriptionCost, const map<int, int> &discounts)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	setDiscounts(discounts);
	setPremiumSubscriptionCost(premiumSubscriptionCost);
}

PremiumUser::PremiumUser(const PremiumUser &up) : User(up)
{
	discounts=up.discounts;
	premiumSubscriptionCost=up.premiumSubscriptionCost;
}

const PremiumUser &PremiumUser::operator=(const PremiumUser &up)
{
	(User&)(*this)=up;
	discounts=up.discounts;
	premiumSubscriptionCost=up.premiumSubscriptionCost;
	return *this;
}

void PremiumUser::displayUser()
{
	throw("undefined");
}

string PremiumUser::getUserType()
{
	return "PremiumUser";
}

float PremiumUser::getTransportCost()
{
	throw("undefined");
}

map<int, int> &PremiumUser::getDiscounts()
{
	return discounts;
}

void PremiumUser::setDiscounts(map<int, int> red)
{
	discounts=red;
}

void PremiumUser::setPremiumSubscriptionCost(int cap)
{
	premiumSubscriptionCost=cap;
}

int PremiumUser::getPremiumSubscriptionCost()
{
	return premiumSubscriptionCost;
}

json PremiumUser::toJSON()
{
	return json(*this);
}

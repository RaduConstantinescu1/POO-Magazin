#include "Address.h"

using namespace std;

Address::Address(){}

Address::Address(const Address &adr)
{
	county=adr.county;
	locality=adr.locality;
	street=adr.street;
	number=adr.number;
	block=adr.block;
	apartment=adr.apartment;
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
	setCounty(jud);
	setLocality(loc);
	setStrada(str);
	setNumber(nr);
	setBlock(bl);
	setApartment(ap);
}

const Address &Address::operator=(const Address &adr)
{
	county=adr.county;
	locality=adr.locality;
	street=adr.street;
	number=adr.number;
	block=adr.block;
	apartment=adr.apartment;
	return *this;	
}

void Address::setStrada(const string &str)
{
	street=str;
}

void Address::setNumber(int nr)
{
	number=nr;
}

void Address::setBlock(const string &bl)
{
	block=bl;
}

void Address::setApartment(int ap)
{
	apartment=ap;
}

void Address::setCounty(const string &jud)
{
	county=jud;
}

void Address::setLocality(const string &loc)
{
	locality=loc;
}

string &Address::getStreet()
{
	return street;
}

int Address::getNumber()
{	
	return number;
}
string &Address::getBlock()
{
	return block;
}

int Address::getApartment()
{
	return apartment;
}

string &Address::getCounty()
{
	return county;
}

string &Address::getLocality()
{
	return locality;
}

bool Address::operator==(const Address &address)
{
	return (locality==address.locality&&street==address.street&&number==address.number&&block==address.block&&apartment==address.apartment);
}

bool Address::operator!=(const Address &address)
{	
	return (locality!=address.locality||street!=address.street||number!=address.number||block!=address.block||apartment!=address.apartment);
}

ostream &operator<<(ostream &os, const Address &a)
{
	os<<a.county<<" ";
	os<<a.locality<<" ";
	os<<a.street<<" ";
	os<<a.number<<" ";
	os<<a.block<<" ";
	os<<a.apartment<<endl;

}

json Address::toJSON()
{
	return json(*this);
}

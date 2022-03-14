#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity=capacity;
	lru.reserve(capacity);
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	vector<int>::iterator it=requestsNo.end();
	it--;
	for(int i=0;i<capacity;i++){
		lru.push_back(*it);
		it--;
	}
	return lru;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.size();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity=capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru=aux;
}

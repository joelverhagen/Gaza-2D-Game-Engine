#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>

using namespace std;

template<class T>
class ResourceManager
{
private:
	map<string, T *> resources;
public:
	ResourceManager()
	{

	}
	~ResourceManager()
	{
		releaseAllResources();
	}

	void addResource(const string &key, T * resource)
	{
		if(resources.find(key) != inputSpriteSheets.end())
		{
			throw runtime_error("A resource with key \""+key+"\" already exists."); 
		}
		resources[key] = resource;
	}

	T * getResource(const string &key)
	{
		if(resources.find(key) != inputSpriteSheets.end())
		{
			throw runtime_error("A resource with key \""+key+"\" does not exist."); 
		}
		return resources[key];
	}

	void releaseResource(const string &key)
	{
		if(resources.find(key) != inputSpriteSheets.end())
		{
			throw runtime_error("A resource with key \""+key+"\" does not exist."); 
		}
		T * resource = resources[key];
		delete resource;
		resources.erase(key);
	}

	void releaseAllResources()
	{
		while(resources.begin() != resources.end() )
		{
            delete resources.begin()->second;
            resources.erase(resources.begin());
        }
	}
};

#endif
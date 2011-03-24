#ifndef GAZARESOURCEMANAGER_HPP
#define GAZARESOURCEMANAGER_HPP

#include "Gaza.hpp"

#include <string>
#include <map>
#include <vector>

namespace Gaza
{
	template<class T>
	class ResourceManager
	{
	public:
		ResourceManager()
		{

		}

		~ResourceManager()
		{
			releaseAll();
		}

		T * get(const std::string &name)
		{
			T * resource = find(name);
			if(resource == 0)
			{
				throw std::runtime_error("A resource with name \""+name+"\" does not exist.");
				return 0;
			}

			return resource;
		}

		void add(const std::string &name, T * resource)
		{
			if(find(name) != 0)
			{
				throw std::runtime_error("A resource with name \""+name+"\" already exists.");
				return;
			}

			resourceMap[name] = resource;
		}

		void release(const std::string &name)
		{
			T * resource = find(name);
			if(resource == 0)
			{
				return;
			}
			delete resource;
			resourceMap.erase(name);
		}

		void releaseAll()
		{
			for(std::map<std::string, T *>::iterator i = resourceMap.begin(); i != resourceMap.end(); i++)
			{
				delete (*i).second;
			}
			resourceMap.clear();
		}

		std::vector<std::string> getResourceNames()
		{
			std::vector<std::string> names;

			for(std::map<std::string, T *>::iterator i = resourceMap.begin(); i != resourceMap.end(); i++)
			{
				names.push_back((*i).first);
			}

			return names;
		}

	private:
		T * find(const std::string &name)
		{
			T * resource = 0;
			std::map<std::string, T *>::iterator i = resourceMap.find(name);

			if(i != resourceMap.end())
			{
				resource = i->second;
			}

			return resource;
		}

		std::map<std::string, T *> resourceMap;
	};
}

#endif
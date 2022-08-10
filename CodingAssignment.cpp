#include <bits/stdc++.h>
using namespace std;

class Planet
{
	string name;
	vector<string> gasses;
	int moons;
	bool rings;

public:
	Planet(string str, vector<string>g, int m, bool r)
	{
		name = str;
		gasses = g;
		moons = m;
		rings = r;
	}
	int numMoons()
	{
		return moons;
	}

	bool hasRings()
	{
		return rings;
	}

	int countMoons(Planet &ob1, Planet &ob2, Planet &ob3, Planet &ob4, Planet &ob5, Planet &ob6)
	{
		int sum = 0;

		if (ob1.rings)sum += ob1.moons;
		if (ob2.rings)sum += ob2.moons;
		if (ob3.rings)sum += ob3.moons;
		if (ob4.rings)sum += ob4.moons;
		if (ob5.rings)sum += ob5.moons;
		if (ob6.rings)sum += ob6.moons;

		return sum;
	}
	string maxGas(Planet &ob1, Planet &ob2, Planet &ob3, Planet &ob4, Planet &ob5, Planet &ob6)
	{
		map<string, int> mp;

		for (auto x : ob1.gasses)
		{
			mp[x]++;
		}
		for (auto x : ob2.gasses)
		{
			mp[x]++;
		}
		for (auto x : ob3.gasses)
		{
			mp[x]++;
		}
		for (auto x : ob4.gasses)
		{
			mp[x]++;
		}
		for (auto x : ob5.gasses)
		{
			mp[x]++;
		}
		for (auto x : ob6.gasses)
		{
			mp[x]++;
		}

		int mx = 0;
		string res;

		for (auto x : mp)
		{
			if (x.second > mx)
			{
				mx = x.second;
				res = x.first;
			}
		}

		return res;
	}
};

int main()
{
	vector<string> gas1;
	Planet Mercury("Mercury", gas1, 0, false);
	vector<string> gas2{"Carbon Dioxide", "Nitrogen"};
	Planet Venus("Venus", gas2, 0, false);
	vector<string> gas3{"Oxygen", "Nitrogen"};
	Planet Earth("Earth", gas3, 1, false);
	vector<string> gas4{"Hydrogen", "Helium"};
	Planet Jupiter("Jupiter", gas4, 79, true);
	vector<string> gas5{"Hydrogen", "Helium"};
	Planet Saturn("Saturn", gas5, 83, true);
	vector<string> gas6{"Methane", "Hydrogen", "Helium"};
	Planet Uranus("Uranus", gas6, 27, true);

	cout << "Count of moons of all planets having rings:" << Mercury.countMoons(Mercury, Venus, Earth, Jupiter, Saturn, Uranus);
	cout << endl;
	cout << "The gas that is found on maximum planets:" << Mercury.maxGas(Mercury, Venus, Earth, Jupiter, Saturn, Uranus);
}
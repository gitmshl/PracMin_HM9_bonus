#include <iostream>

using namespace std;

class Pistole
{
public:

	virtual int damage()
	{
		return 25;
	}
};

class PistoleWithFuse : public Pistole
{
	Pistole* pre_pistole;
public:
	PistoleWithFuse() : pre_pistole() {}
	PistoleWithFuse(Pistole* pre_pistole) : pre_pistole(pre_pistole) {}

	int damage()
	{
		return pre_pistole->damage() > 5 ? pre_pistole->damage() - 5 : 0;
	}
};

class PistoleWithOutFuse : public Pistole
{
	Pistole* pre_pistole;
public:
	PistoleWithOutFuse(Pistole* pre_pistole) : pre_pistole(pre_pistole) {}

	int damage()
	{
		return pre_pistole->damage();
	}
};

class PistoleWithDoubleFuse : public Pistole
{
	Pistole* pre_pistole;
public:
	PistoleWithDoubleFuse(Pistole* pre_pistole) : pre_pistole(pre_pistole) {}

	int damage()
	{
		return pre_pistole->damage() > 10 ? pre_pistole->damage() - 10 : 0;
	}
};

class Person
{

private:
	Pistole* pistole;

public:

	Person() : pistole(new Pistole) {}

	explicit Person(Pistole* pistole) : pistole(pistole) {}

	int damage() {return pistole->damage();}
	virtual bool isTerrorist() = 0;
};

class Terrorist : public Person
{
public:
	explicit Terrorist(Pistole* pistole) : Person(pistole) {}
	bool isTerrorist() {return true;}
};

class Counter_Terrorist : public Person
{
	public:
	explicit Counter_Terrorist(Pistole* pistole) : Person(pistole) {}
	bool isTerrorist() {return false;}
};

int main()
{

	Person* ter = new Terrorist(new PistoleWithFuse(new PistoleWithFuse(new Pistole)));

	cout << ter->damage();
	

	return 0;
}


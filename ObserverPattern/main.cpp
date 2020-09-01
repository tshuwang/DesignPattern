#include <iostream>
#include <list>
using namespace std;

class Observer
{
public:
	virtual void update() = 0;
};

class Subject
{
public:
	

	virtual void detachObserver(Observer *) = 0;
	virtual void attachObserver(Observer *) = 0;
	virtual void NotifyObserver() = 0;
};

class Monster : public Observer
{
public:
	

	void update()
	{
		cout << "Monster attack" << endl;
	}


};

class Trap : public Observer
{
public:
	

	void update()
	{
		cout << "Trap attack" << endl;
	}
};

class Flower : public Observer
{
public:

	void update()
	{
		cout << "Flower " << endl;
	}
};

class hero : public Subject
{
public:
	void attachObserver(Observer * pObserver);
	void detachObserver(Observer * pObserver);
	void NotifyObserver();

private:
	list<Observer *>m_ObserverList;
};

void hero::attachObserver(Observer * pObserver)
{
	m_ObserverList.push_back(pObserver);
}

void hero::detachObserver(Observer * pObserver)
{
	m_ObserverList.remove(pObserver);
}

void hero::NotifyObserver()
{
	list<Observer *>::iterator it = m_ObserverList.begin();
	while (it != m_ObserverList.end())
	{
		(*it)->update();
		it++;
	}
}


int main()
{
	hero *phero = new hero();

	Monster *pMonster = new Monster();
	Trap *ptrap = new Trap();
	Flower *pFlower = new Flower();

	phero->attachObserver(pMonster);
	phero->attachObserver(pFlower);
	phero->attachObserver(ptrap);

	phero->NotifyObserver();

	system("pause");
}
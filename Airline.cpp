#include <string>
#include <iostream>
#include "Airline.h"

using namespace std;

Airline::Airline(int nA321, int nB777, int nB787) : nAirplanes(nA321 + nB777 + nB787)
{
    airplaneList = new Airplane *[nAirplanes];
    for (int i = 0; i < nA321; i++)
    {
        airplaneList[i] = new Airplane(10);
        cout << "Airplane " << i + 1 << " maximum load 10" << endl;
    }
    for (int i = nA321; i < nA321 + nB777; i++)
    {
        airplaneList[i] = new Airplane(32);
        cout << "Airplane " << i + 1 << " maximum load 32" << endl;
    }
    for (int i = nA321 + nB777; i < nAirplanes; i++)
    {
        airplaneList[i] = new Airplane(40);
        cout << "Airplane " << i + 1 << " maximum load 40" << endl;
    }
}

Airline::~Airline()
{
    for (int i = 0; i < nAirplanes; i++)
    {
        cout << "deallocating airplane " << i + 1 << endl;
        delete[] airplaneList[i];
    }
    delete[] airplaneList;
}
void Airline::addShipment(int size)
{
    cout << "Trying to assign shipment of " << size << " containers" << endl;
    s for (int i = 0; i < nAirplanes; i++)
    {
        if (airplaneList[i]->addContainers(size))
        {
            cout << size << " containers added to airplane " << i + 1 << endl;
            break;
        }
        cout << "could not fit " << size << " containers" << endl;
    }
}

void Airline::printSummary() const
{
    cout << "Summary:" << endl;
    for (int i = 0; i < nAirplanes; i++)
    {
        if (airplaneList[i]->currentLoad() > 0)
        {
            cout << "airplane " << i + 1 << " " << airplaneList[i]->currentLoad() << "/" << airplaneList[i]->maxLoad() << endl;
        }
    }
}

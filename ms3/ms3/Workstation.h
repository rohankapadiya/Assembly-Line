/***************************************************************************
Name:   Rohan Sureshbhai Kapadiya
Email:  rskapadiya@myseneca.ca
ID:     149427205
Date:   27-11-2022

** I have done all the coding by myself and only copied the code that my
   professor provided to complete my workshops and assignments. **
****************************************************************************/
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"

using namespace std;

extern deque<sdds::CustomerOrder> g_pending;
extern deque<sdds::CustomerOrder> g_completed;
extern deque<sdds::CustomerOrder> g_incomplete;

namespace sdds 
{

    class Workstation : public Station 
    {
        deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation = nullptr;

    public:
        Workstation(const string& data);

        void fill(ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);

        Workstation* getNextStation() const;

        void display(ostream& os) const;

        Workstation& operator+=(CustomerOrder&& newOrder);

        bool empty() const;
    };
};

#endif
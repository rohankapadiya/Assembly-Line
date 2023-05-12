/***************************************************************************
Name:   Rohan Sureshbhai Kapadiya
Email:  rskapadiya@myseneca.ca
ID:     149427205
Date:   27-11-2022

** I have done all the coding by myself and only copied the code that my
   professor provided to complete my workshops and assignments. **
****************************************************************************/
#ifndef STATION_H
#define STATION_H

#include <string>

using namespace std;
namespace sdds {
    class Station 
    {
        int id;
        string name;
        string description;

        unsigned int nextSerialNum;
        unsigned int numItems;
        
        static size_t m_widthField;
        static int id_generator;

        public:

        Station(const string& record);
        const string& getItemName() const;

        size_t getNextSerialNumber();
        size_t getQuantity() const;

        void updateQuantity();
        void display(ostream& os, bool full) const;
    };
};
#endif
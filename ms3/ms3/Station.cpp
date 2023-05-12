/***************************************************************************
Name:   Rohan Sureshbhai Kapadiya
Email:  rskapadiya@myseneca.ca
ID:     149427205
Date:   27-11-2022

** I have done all the coding by myself and only copied the code that my
   professor provided to complete my workshops and assignments. **
****************************************************************************/

#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_widthField = 0;
int sdds::Station::id_generator = 0;

sdds::Station::Station(const string& record) 
{
    Utilities uti;
    size_t position = 0;
    bool more = true;
    
    id = ++id_generator;
    name = uti.extractToken(record, position, more);
    nextSerialNum = stoi(uti.extractToken(record, position, more));
    numItems = stoi(uti.extractToken(record, position, more));
    m_widthField = m_widthField > uti.getFieldWidth() ? m_widthField : uti.getFieldWidth();
    description = uti.extractToken(record, position, more);
}

const string& sdds::Station::getItemName() const {
    return name;
}

size_t sdds::Station::getNextSerialNumber() {
    return nextSerialNum++;
}

size_t sdds::Station::getQuantity() const {
    return numItems;
}

void sdds::Station::updateQuantity() {
    if (numItems > 0) {
        numItems--;
    }
}

void sdds::Station::display(ostream& os, bool full) const {
    os << std::right;
    os << setw(3) << setfill('0') << id << " | ";
    os << left << setfill(' ') << setw(m_widthField + 1) << name << " | ";
    os << right << setw(6) << setfill('0') << nextSerialNum << " | ";

    if (full) {
        os << setfill(' ');
        os << right;
        os << setw(4) << numItems << " | " << description;
    }

    os << endl;
}
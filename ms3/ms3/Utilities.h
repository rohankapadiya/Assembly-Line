/***************************************************************************
Name:   Rohan Sureshbhai Kapadiya
Email:  rskapadiya@myseneca.ca
ID:     149427205
Date:   27-11-2022

** I have done all the coding by myself and only copied the code that my
   professor provided to complete my workshops and assignments. **
****************************************************************************/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>
#include <stdexcept>

using namespace std;

namespace sdds 
{
    class Utilities 
    {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        string extractToken(const string& str, size_t& next_pos, bool& more);

        static void setDelimiter(char newDelimiter) 
        {
            m_delimiter = newDelimiter;
        }
        static char getDelimiter() {
            return m_delimiter;
        }
    };
};

#endif
/***************************************************************************
Name:   Rohan Sureshbhai Kapadiya
Email:  rskapadiya@myseneca.ca
ID:     149427205
Date:   27-11-2022

** I have done all the coding by myself and only copied the code that my
   professor provided to complete my workshops and assignments. **
****************************************************************************/
#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H

#include "Station.h"

using namespace std;

namespace sdds 
{
    struct Item
    {
        string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const string& src) : m_itemName(src) {};
    };

    class CustomerOrder 
    {
        string m_name;
        string m_product;
        size_t m_cntItem;
        Item** m_lstItem;
        static size_t m_widthField;

        public:
        CustomerOrder();
        CustomerOrder(const string& input);
        CustomerOrder(const CustomerOrder& order);

        CustomerOrder& operator=(const CustomerOrder& order) = delete;
        CustomerOrder(CustomerOrder&& order) noexcept;
        CustomerOrder& operator=(CustomerOrder&& order) noexcept;

        ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const string& itemName) const;
        void fillItem(Station& station, ostream& os);
        void display(ostream& os) const;

    };
};

#endif
#include <string>
#include <iostream>
#include <fstream>

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ifstream &read(std::ifstream &, Sales_data &);
    friend std::ofstream &print(std::ofstream &, const Sales_data &);

public:
    Sales_data() : units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &no) : bookNo(no) {}
    Sales_data(const std::string &no, unsigned us, double price)
        : bookNo(no), units_sold(us), revenue(price * us) {}
    Sales_data(std::ifstream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // Use default copy constructor
    sum.combine(rhs);
    return sum;
}

std::ifstream &read(std::ifstream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ofstream &print(std::ofstream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

int main(int argc, char **argv)
{

    std::ifstream is(argv[1]);
    std::ofstream os(argv[2]);

    Sales_data total(is);
    if (is)
    {
        Sales_data trans(is);
        while (is)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(os, total) << std::endl;
                total = trans;
            }
            read(is, trans);
        }
        print(os, total) << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}
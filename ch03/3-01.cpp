#include <iostream>

using std::cout; using std::endl; using std::cin; using std::cerr;


void print(int x, int y)
{
  if (x < y)
  {
    print(y, x);
    return;
  }

  std::cout << std::endl;
  for (int i = x; i > y; i--)
    std::cout << i << " ";
}


struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};


int main()
{

  //1.09
  int x = 50, sum = 0;
  while (x <= 100)
    sum += x++;
  cout << "The sum of the numbers from 50 to 100  inclusive is " << sum;

  //1.10
  int x=10;
  
  while (x>=0) std::cout << x-- << " ";

  //1.11
  int a = 100, b = 50, c = 50, d = 0;
  print (a,b);
  std::cout <<std::endl;
  print(d, c);

  //ex1.20
  Sales_data item;
  double price;
  while(std::cin >>item.bookNo>>item.units_sold>>price)
  {
    item.revenue=item.units_sold*price;
     cout << item.bookNo << " " << item.units_sold << " " << price << " " << item.revenue <<endl;
  } 

  
  //ex1.21
  Sales_data item1, item2;
  double price1, price2;
  std::cin >> item1.bookNo>>item1.units_sold>>price1;
  std::cin >> item2.bookNo>>item2.units_sold>>price2;
  item1.revenue=item1.units_sold*price1;
  item2.revenue=item2.units_sold*price2;

  if (item1.bookNo == item2.bookNo)
  {
    double total_revenue=item1.revenue+item2.revenue;
    unsigned total_units=item1.units_sold+item2.units_sold;
    if (total_units!=0)
    {
      std::cout <<item1.bookNo<<" "<<total_units<<" "<<total_revenue<<" "<<total_revenue/total_units<<std::endl;
    }
    else std::cout <<"\nThere were no sales\n"; 
  }
  else std::cout <<"\nThe book numbers were not the same\n";

  //ex1.25
  Sales_data book;
  double unit_price;
  if (cin >> book.bookNo>>book.units_sold>>unit_price)
  {
    book.revenue= unit_price * book.units_sold;

    Sales_data current;
    while (cin >> current.bookNo>>current.units_sold>>unit_price)
    {
      current.revenue = unit_price * current.units_sold;

      if (book.bookNo == current.bookNo)
      {
        book.revenue += current.revenue;
        book.units_sold+= current.units_sold;
      }
      else
      {
        cout <<book.bookNo <<" " <<book.units_sold << " " << book.revenue <<" ";

        if (book.units_sold!=0) cout <<book.revenue/book.units_sold << endl;
        else cout <<"No units sold\n";

        book = current;
      }  
    }

     cout <<book.bookNo <<" " <<book.units_sold << " " << book.revenue <<" ";

     if (book.units_sold!=0) cout <<book.revenue/book.units_sold << endl;
     else cout <<"No units sold\n";
  }

  else 
  {
    cerr << "There was an input error";
    return -1;
  }


  return 0;
}
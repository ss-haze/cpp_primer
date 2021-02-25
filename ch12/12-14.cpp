#include <vector>
#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::vector;

struct destination
{
  destination (std::string s, int x)
  :
  str(s),
  serial(x)
  {}
std::string str;
int serial;
};

struct connection
{
  destination* conn;
};

connection connect(destination* d)
{
  connection newConn;
  newConn.conn = d;
 std::cout <<"Opening connection to "<< newConn.conn->str<< " using number "<<newConn.conn->serial<<std::endl;
 return newConn;
}

void disconnect(connection c)
{
  std::cout <<"Closing connection to "<<c.conn->str<<" using number "<<c.conn->serial<<std::endl;
}
// close the given connection 

void end_connection (connection *p)
{
  disconnect (*p);
}


void f(destination &d) 
{
  connection c = connect(&d);
  std::shared_ptr<connection> p (&c, end_connection);
}


int main()
{
  destination dest ("Miami", 125);
  f(dest);

  return 0;
}
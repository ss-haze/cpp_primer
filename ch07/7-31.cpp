class Y;
class X
{
private:
  Y *y_ptr;
};

class Y
{
private:
  X x_mem;
};

int main()
{
  return 0;
}
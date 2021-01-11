
class Debug
{
public:
  constexpr Debug(bool b = true) : rt(b), io(b), other(b) {}
  constexpr Debug(bool r_t, bool i_o, bool o_ther) : rt(r_t), io(i_o), other(o_ther) {}
  constexpr bool any() { return rt || io || other; }

  void set_rt(bool b) { rt = b; }
  void set_io(bool b) { io = b; }
  void set_other(bool b) { other = b; }

private:
  bool rt;
  bool io;
  bool other;
};

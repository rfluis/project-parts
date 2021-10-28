#ifndef TOKENIZER_HEADER
#define TOKENIZER_HEADER
/**/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

bool is_numbr(char c);
bool is_lower(char c);
bool is_upper(char c);
bool is_alpha(char c);
bool is_ident(char c);
bool is_oprtr(char c);

class tokenizer{
public:
  string buffer,stk;
  int cursor,size;
  tokenizer();
  tokenizer(const string& b){buffer = b; reset(); return;}
  /* Interface */
  char rd(){return buffer[cursor];}
  char nx(){return buffer[cursor++];}
  void ad(){cursor++; return;}
  void pb(){stk.push_back(buffer[cursor]); ++cursor; return;}
  void pb(char c){stk.push_back(c);}
  void cltk(){stk=string();}
  void reset(){size=buffer.size();cursor=0;}
  /* Parser */
  void token();
  void tk_number();
  void tk_number_fl_m();
  void tk_number_fl_e();
  void tk_ident();
  void tk_oprtr();
  void tk_oprtr_str();
  /* Out function */
  vector<string> parse();
};


#endif

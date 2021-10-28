/* Autor: Ricardo Francisco Luis Martínez 
 * Proyecto: 
 * Descripción: 
 * Licencia: 
 * Nombre del Archivo: 
*/

#include "tokenizer.hpp"


bool is_numbr(char c){if (c>='0' && c<='9') return true; return false;}
bool is_lower(char c){if (c>='a' && c<='z') return true; return false;}
bool is_upper(char c){if (c>='A' && c<='Z') return true; return false;}
bool is_alpha(char c){if (is_lower(c)) return true; if (is_upper(c)) return true; return false;}
bool is_ident(char c){if (is_alpha(c)) return true; if (c=='_') return true; return false;}
bool is_oprtr(char c){
  if (c==33) return true;
  if (c==34) return true;
  if (c>=37 && c<=47) return true; 
  if (c>=58 && c<=62) return true;
  if (c==91) return true;
  if (c==93) return true;
  if (c==94) return true;
  if (c>=123 && c<=126) return true;
  return false;}



void tokenizer::token(){    
    cltk();
    while(rd()==' ' || rd()=='\t' || rd()=='\n') ad();
    if (is_numbr(rd())) tk_number();
    else if (is_ident(rd())) tk_ident();
      else if (is_oprtr(rd())) tk_oprtr();
    return;}
  void tokenizer::tk_number(){
    pb(); 
    while(is_numbr(rd())) {
      pb();} 
    if (rd()=='.') tk_number_fl_m(); 
    else if (rd()=='e') tk_number_fl_e();
    return;}
  void tokenizer::tk_number_fl_m(){
    pb(); 
    while(is_numbr(rd())) {
      pb();} 
    if (rd()=='e') tk_number_fl_e();
    return;
    }
  void tokenizer::tk_number_fl_e(){
    pb();
    if (rd()=='-' || rd()=='+') pb();
    while(is_numbr(rd())) {
      pb();} 
    return;
    }
  void tokenizer::tk_ident(){pb(); while(is_ident(rd()) || is_numbr(rd())) {pb();}return;}
  void tokenizer::tk_oprtr(){
    if (rd()=='(' || rd()==')' || rd()=='[' || rd()==']' || rd()=='{' || rd()=='}' || rd()==',' || rd()=='.' || rd()==';') {pb(); return;}
    else if (rd()=='>') {pb(); if (rd()=='>') {pb();} if (rd()=='=') {pb();} ; return;}
    else if (rd()=='<') {pb(); if (rd()=='<') {pb();} if (rd()=='=') {pb();} ; return;}
    else if (rd()=='+') {pb(); if (rd()=='+') {pb();} else if (rd()=='=') {pb();} ; return;} 
    else if (rd()=='-') {pb(); if (rd()=='-') {pb();} else if (rd()=='=') {pb();} else if(rd()=='>') {pb();} ; return;} 
    else if (rd()=='*') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='/') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='%') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='&') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='^') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='|') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()==':') {pb(); if (rd()==':') {pb();} return;} 
    else if (rd()=='~') {pb(); if (rd()=='=') {pb();} return;}
    else if (rd()=='!') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='=') {pb(); if (rd()=='=') {pb();} return;} 
    else if (rd()=='\'') {pb(); if (rd()=='\\') {pb();} pb(); pb(); return;}
    else if (rd()=='\"') tk_oprtr_str();
    return;
    }

void tokenizer::tk_oprtr_str(){pb(); while(rd()!='\"') {if (rd()=='\\') pb(); pb();} pb(); return;}
  
vector<string> tokenizer::parse(){
  reset(); vector<string> tokens; 
  int idx; 
  while (cursor<size) {
    token(); 
    cout << stk << " [" << rd() << "]" << cursor << endl;
    tokens.push_back(stk); 
    } 
  return tokens;
  }


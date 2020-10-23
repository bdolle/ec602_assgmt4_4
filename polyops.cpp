// Copyright 2020 Brian Dolle bdolle@bu.edu
// Copyright 2020 Poras Shroff pshroff4@bu.edu
#include"polyops.h"
// #include<iostream>
#include<vector>

Poly add_poly(const Poly &a, const Poly &b){
  Poly x = a;
  Poly y = b;
  //These while statments normalize the sizes
  while(x.size()>y.size()){
    y.push_back(0);
  }
  while (y.size()>x.size()){
    x.push_back(0);
  }
  
  int len_x = static_cast<int>(x.size());
  Poly c(len_x,0);
  for(int i=0; i<len_x; i++){
    c.at(i) = x.at(i)+y.at(i);
  }

  return c;

}

Poly multiply_poly(const Poly & a, const Poly & b){
  Poly x = a;
  Poly y = b;
  int len_c = static_cast<int>(a.size()+b.size()-1);

  Poly c(len_c,0);

  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      c.at(i+j) = c.at(i+j) + x.at(i)*y.at(j);
    }
  }

  // for(int i=0; i<c.size();i++){
  // std::cout << c.at(i) << "\n";
  // }
  return c;
}



// int main(){
//   Poly a(6,0);
//   Poly b(8,0);

//   for(int i=0; i<a.size(); i++){
//     a.at(i) = 9*(i+2);
//   }

//   for(int i=0; i<b.size(); i++){
//     b.at(i) = 2*(i+1);
//   }
//   add_poly(a,b);
//   multiply_poly(a,b);
// }

// Copyright 2020 Brian Dolle bdolle@bu.edu
// Copyright 2020 Poras Shroff pshroff4@bu.edu

#include"bigint.h"
// #include<iostream>
#include<vector>
#include<string>

BigInt reverse_fxn(BigInt a){
  int len = a.length();
  int n = len-1;
  BigInt b = a;
  for(int i=0; i<(len/2);i++){
    std::swap(b.at(i),b.at(n));
    n=n-1;
  }
  return b;
}


BigInt multiply_int(const BigInt &a, const BigInt &b){

  int len_d = static_cast<int>(a.size()+b.size()-1);
  std::vector<int> d(len_d,0);

  BigInt a_prime = reverse_fxn(a);
  BigInt b_prime = reverse_fxn(b);

  int value = 0;
  int digit = 0;
  int carry = 0;

  for(int i=0; i<a_prime.size(); i++){
    for(int j=0; j<b_prime.size(); j++){
       d.at(i+j) = d.at(i+j) + (a_prime.at(i)-'0')*(b_prime.at(j)-'0');
    }
  }

  std::vector<int> ans(len_d,0);
  for(int j=0; j<d.size(); j++){
    value = d.at(j) + carry;
    digit = value % 10;
    ans.at(j) = digit;
    carry = value/10;
  }

  if(carry > 0){
    ans.push_back(carry);
  }

  BigInt c(ans.size(),0);
  for(int i=0; i<c.size(); i++){
    c.at(i) = ans.at(i)+'0';
    // std::cout << c.at(i) << "\n";
  }

  BigInt final = reverse_fxn(c);

  if((a_prime.at(0)-'0')==0)
    final = "0";
  if((b_prime.at(0)-'0')==0)
    final = "0";


  return final;


}

// int main(){
//   // BigInt a = "111111";
//   BigInt a = "0000";
//   BigInt b = "1111111";
//     // BigInt a = "543";
//     // BigInt b = "128";
//     BigInt z = multiply_int(a,b);
//     std::cout << z;

//   // BigInt x = reverse_fxn(a);
//   // BigInt y = reverse_fxn(b);

//   // for(int i=0; i<x.size(); i++){
//   //   std::cout << x.at(i);
//   // }
//   // std::cout << "\n";
//   // for(int i=0; i<y.size(); i++){
//   //   std::cout << y.at(i);
//   // }

// }

#include"bigint.h"
#include<iostream>
#include<vector>
#include<string>
#include<cmath>


BigInt multiply_int(const BigInt &a, const BigInt &b){

  int len_d = static_cast<int>(a.size()+b.size()-1);
  std::vector<int> d(len_d,0);

  int temp = 0;
  int digit = 0;
  int carry = 0;

  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      temp = (a.at(i)-'0')*(b.at(i)-'0')+carry;
      digit = temp % 10;
      carry = floor(temp / 10);
      d.at(i+j) = d.at(i+j)+digit;
    }
  }
  
  if(carry > 0){
    d.push_back(carry);
  }

  BigInt c(d.size(),0);
  for(int i=0; i<c.size(); i++){
    c.at(i) = d.at(i)+'0';
    std::cout << c.at(i) << "\n";
  }

  return c;


}

int main(){
  BigInt a = "111111";
  BigInt b = "1111111";
  multiply_int(a,b);

}

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double distan_np(DataFrame df) {
  
  // access the columns
  NumericVector value = df["value"];
  NumericVector weight = df["weight"];
  NumericVector binary = df["binary"];
  
  int i, n = value.length();
  double actecdf = weight[0], otherecdf = 0, actbin = binary[0], dis = 0;
  
  for(i = 1; i < n; i++){
    dis += (value[i] - value[i-1])*(actecdf - otherecdf)*(actecdf - otherecdf);
    if(binary[i] == actbin){actecdf += weight[i];}
    if(binary[i] == 1 - actbin){otherecdf += weight[i];}
  }
  
  // return a distance
  return dis;
}


#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

#include "utils/randomness.h"
#include "utils/structures.h"
#include "utils/topology_ops.h"
#include "utils/rules.h"
#include "utils/validation.h"
#include "utils/actualization.h"


int main(){
  int L = 15;
  double p = 0.2;
  // densidad de los carros
  double rho = 0.3;

  //evol_carril(cars,L);

  std::vector<motion> new_cars(
    std::vector<motion> vec_cars,
    int v_max,
    double p,
    int L,
    std::vector<int> carril,
    std::string boundary
  )

}

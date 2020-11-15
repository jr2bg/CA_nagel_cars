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

int add_info(int &L, std::string &boundary, double &p){
}

int main(){
  int L = 100;
  double p = 0.2;
  // densidad de los carros
  double rho = 0.3;
  std::string boundary = "open";

  int v_max = 5;
  int n_cars = 5;

  int n_iterations = 100;

  // generación de la lista de carritos
  std::vector<motion> vec_cars (n_cars);
  /////////////////////////////////////////////////////////////////
  motion carrito;
          // pos, vel
  initialize_car(carrito, 0,0);
  vec_cars[0] = carrito;

  initialize_car(carrito, 1,0);
  vec_cars[1] = carrito;

  initialize_car(carrito, 4,0);
  vec_cars[2] = carrito;

  initialize_car(carrito, 5,0);
  vec_cars[3] = carrito;

  initialize_car(carrito, 11,0);
  vec_cars[4] = carrito;
  ////////////////////////////////////////////////////////////////
  std::vector<int> carril = evol_carril(vec_cars, L);
  print_trail(carril);

  for (int i = 0; i < n_iterations; i++){
    vec_cars = new_cars( vec_cars, v_max,  p, L, carril, boundary );
    carril = evol_carril(vec_cars, L);
    print_trail(carril);
  }

  return 0;

}

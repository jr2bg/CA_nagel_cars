/*********************************************************************

Actualización de los estados

**********************************************************************/

//para cada carro en carros
// aplicamos las reglas
// vemos si la posición es válida y lo agregamos a la lista

// creamos un array nuevo de carros, del mismo tamaño que el original
// al final de cada ciclo sobre la lista de carros hacemos un resize

//////////////////////////
// frontera abierta
std::vector<motion> new_cars_open(
  std::vector<motion> vec_cars,
  int v_max,
  double p,
  int L,
  std::vector<int> carril
){
  int n_cars = vec_cars.size();
  int i = 0;
  std::vector<motion> nw_v_cars (n_cars);

  // para cada carro en nuestro vector de carros
  for (auto car:vec_cars){
    // encontramos el aleatorio
    double random_n = uniform_dist_0_1(generator);
    // calculamos la distancia al siguiente vehículo
    int dist_next_veh = calc_dist_betw_veh_open(car, v_max, L, carril);
    // obtenemos un nuevo carrito con la posición y velocidad de evolución
    motion carrito = evolution1car(car, v_max, dist_next_veh, p, random_n);
    // si la posición es válida
    if (valid_pos(carrito.pos, L)){
      // almacenamos la info
      nw_v_cars[i] = carrito;
      // cambiamos la posición del array donde almacenar la info
      i++;
    }
  }
  // resize al vector de carritos nuevos
  nw_v_cars.resize(i);
  // retornamos el vector de carritos
  return nw_v_cars;

}

///////////////////////
// frontera periódica
std::vector<motion> new_cars_peri(
  std::vector<motion> vec_cars,
  int v_max,
  double p,
  int L,
  std::vector<int> carril
){
  int n_cars = vec_cars.size();
  int i = 0;
  std::vector<motion> nw_v_cars (n_cars);

  // para cada carro en nuestro vector de carros
  for (auto car:vec_cars){
    // encontramos el aleatorio
    double random_n = uniform_dist_0_1(generator);
    // calculamos la distancia al siguiente vehículo
    int dist_next_veh = calc_dist_betw_veh_peri(car, L, carril);
    // obtenemos un nuevo carrito con la posición y velocidad de evolución
    motion carrito = evolution1car(car, v_max, dist_next_veh, p, random_n);
    // obtenemos la posición en el anillo
    real_pos_car_peri(carrito, L);
    //std::cout << carrito.pos << " ";
    // almacenamos la info
    nw_v_cars[i] = carrito;
    // cambiamos la posición del array donde almacenar la info
    i++;
  }
  //std::cout << "\n";
  // retornamos el vector de carritos
  return nw_v_cars;
}


//
// Función para cualquier caso
//
std::vector<motion> new_cars(
  std::vector<motion> vec_cars,
  int v_max,
  double p,
  int L,
  std::vector<int> carril,
  std::string boundary
){
  std::vector<motion> carritos;
  if (boundary == "open"){
    carritos = new_cars_open(vec_cars,  v_max,  p,  L, carril);
  }

  else if (boundary == "periodic"){
    carritos = new_cars_peri(  vec_cars,  v_max,  p,  L,  carril);
  }

  return carritos;
}



//////////////////////////////////
//
// Pasar la info de las posiciones de los autos a los carriles ocupados
//
/////////////////////////////////
std::vector<int> evol_carril(std::vector<motion> cars, int L){
  std::vector<int> carril (L , -1);

  for (auto car: cars){
    carril[car.pos] = car.vel;
  }
  return carril;
}

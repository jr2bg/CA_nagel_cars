// array 1D, cada entrada tiene una velocidad o son vacíos
// hay condiciones de frontera abierta y periódica



/**********************************************************************/
//                            REGLAS NAGEL
/**********************************************************************/
int acceleration(int v, int v_max, int dist_next_veh){
  if (dist_next_veh > v +1 && v < v_max) return v + 1;
  return v;
}

int slow_down(int v, int dist_next_veh){
  if (dist_next_veh <= v) return dist_next_veh - 1;
  return v;
}

int random_slow(int v, double p, double random_n){
  if (v > 0 && random_n <= p) return v -1;
  return v;
}

int position_actualization(int v, int postn){
  return v + postn;
}

// las reglas definen el siguiente punto de la evolución
motion car_actualization(int postn, int v){
  motion car;
  car.pos = postn;
  car.vel = v;
  return car;
}


// regresamos un nuevo carro con la evolución adecuada
motion evolution1car(motion car, int v_max, int dist_next_veh, double p, double random_n){
  int v = car.vel;
  int postn = car.pos;


  v = acceleration(v,  v_max,  dist_next_veh);
  v = slow_down(v,   dist_next_veh);
  v = random_slow(v,   p,  random_n);

  postn = position_actualization(c, postn);

  return car_actualization(postn, v);
}

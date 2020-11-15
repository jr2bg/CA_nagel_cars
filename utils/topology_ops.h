

/******************************************************************

cálculo de las distancias
se hace desde el siguiente cuadrito blanco hasta el siguiente carrito,
  contando su casilla

*******************************************************************/
// calcular distancia entre vehículos para la frontera abierta
int calc_dist_betw_veh_open(motion car, int v_max, int L, std::vector<int> carril){
  // tomaremos como -1 a un espacio vacío
  int pst = car.pos;
  // valor a retornar
  int dst = -1;

  // caso 1: hay un carro enfrente
  // caso 2: no hay ningún carro enfrente

  // barrido sobre todos los espacios de carril
  for (int i = pst + 1; i < L ; i++){
    // si hay un carrito enfrente; esto es, velocidad >= 0, entonces obtiene
    // la distancia y corta el ciclo
    if (carril[i] >= 0) {
      dst = i - pst;
      break;
    }
  }

  // si hubo un carrito enfrente entonces que regrese la velocidad
  if (dst != -1) return dst;

  // si no hubo un carrito enfrente significa que es el último de la fila.
  // determinamos que la distancia al siguiente carril es la velocidad máxima + 1
  // para no afectar el mmovimiento
  return v_max + 1;
}


// calcular distancia entre vehículos para la frontera periódica
int calc_dist_betw_veh_peri(motion car, int L, std::vector<int> carril){
  int pst = car.pos;
  int dst = -1;

  // NOTA:  en esta frontera, para todo vehículo habrá un vehículo frente a él

  // barrido sobre todos los espacios de carril
  for (int i = pst + 1; i < L ; i++){
    // si hay un carrito enfrente; esto es, velocidad >= 0, entonces obtiene
    // la distancia y corta el ciclo
    if (carril[i] >= 0) {
      dst = i - pst;
      break;
    }
  }

  // para el último vehículo:
  // barrido desde el comienzo del carril hasta encontrar al siguiente carrito
  if (dst == -1){
    for (int i = 0; i < L ; i++){
      if (carril[i] >= 0) {
        dst = L - pst + i;
        break;
      }
    }
  }
  return dst;
}



/*******************************************************************

Obtiene el valor de la posición real para los carritos en la frontera periodica

***********************************************************************/
void real_pos_car_peri(motion &car, int L){
  if (car.pos >= L) car.pos = car.pos - L;
}

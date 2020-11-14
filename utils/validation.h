/**************************************************************

validación de las distancias recorridas, esto es solo para la frontera OPEN

***************************************************************/

// determina si la posición  es válida o no
bool valid_pos(int pst, int L){
  if (pst < L) return true;
  return false;
}

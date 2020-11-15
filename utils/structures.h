struct motion {
  int pos;
  int vel;
};

void added_pos(motion &car, int pst){
  car.pos = car.pos +pst;
}

void change_vel(motion &car, int v){
  car.vel = v;
}

void initialize_car(motion &car, int pst, int v){
  car.pos = pst;
  car.vel = v;
}


// imprimir el carril en  donde se desplazan los vehículos
void print_trail(std::vector<int> carril){
  for(auto casilla:carril){
    if (casilla == -1) std::cout<< ".";
    else std::cout << casilla;
  }
  std::cout << "\n";
}

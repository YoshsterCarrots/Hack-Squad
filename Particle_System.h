#include <string>
#include <iostream>
#include <sys/ioctl.h>
#include <utility>

using namespace std;



class ParticleSystem{

int rows = 0;
int columns = 0;
int particleNum = 0;
//PLACEHOLDER *head = nullptr;
//PLACEHOLDER *tail = nullptr;
void add_particle() const{
particleNum++;
}

int get_row() const{
return rows;
}

int get_columns() const{
return columns;
}

int numParticles(){
return particleNum;
}

void move_particle(){
//INSERT CODE HERE
}

void draw_particle(){
//INSERT CODE HERE
}

pair<int, int> get_screen_size(){
struct winsize w;
ioctl(0, TIOCGWINSZ, &w);
rows = w.ws_row - 1;
columns = w.ws_col;

return(w.ws_row - 1, w.ws_col);

}

};

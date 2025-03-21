a.out: main.o cell.o Particle.o Particle_System.o particle_graphics.o
	g++ -g -fsanitize=address -std=c++23 *.o

main.o: main.cc cell.h Particle.h Particle_System.h particle_graphics.h
	g++ -g -c -fsanitize=address -std=c++23 main.cc

cell.o: cell.cc
	g++ -g -c -fsanitize=address -std=c++23 cell.cc

Particle.o: Particle.cc
	g++ -g -c -fsanitize=address -std=c++23 Particle.cc

Particle_System.o: Particle_System.cc 
	g++ -g -c -fsanitize=address -std=c++23 Particle_System.cc

particle_graphics.o: particle_graphics.cc colors.h
	g++ -g -c -fsanitize=address -std=c++23 particle_graphics.cc
clean: 
	rm -f *.o a.out

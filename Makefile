a.out: main.o particles.o Particle.o Particle_System.o particle_graphics.o
	g++ -g -fsanitize=address *.o

main.o: main.cc particles.h Particle.h Particle_System.h particle_graphics.h
	g++ -g -fsanitize=address -c main.cc

particles.o: particles.cc
	g++ -g -fsanitize=address -c particles.cc

Particle.o: Particle.cc
	g++ -g -fsanitize=address -c Particle.cc

Particle_System.o: Particle_System.cc
	g++ -g -fsanitize=address -c Particle_System.cc

particle_graphics.o: particle_graphics.cc colors.h
	g++ -g -fsanitize=address -c particle_graphics.cc

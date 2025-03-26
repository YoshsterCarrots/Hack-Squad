a.out: main.o cell.o Particle.o Particle_System.o particle_graphics.o wasserman_pj.o
	g++ -g -fsanitize=address -std=c++23 *.o

main.o: main.cc cell.h Particle.h Particle_System.h particle_graphics.h wasserman_pj.h nicolas_project.h
	g++ -g -c -fsanitize=address -std=c++23 main.cc

cell.o: cell.cc
	g++ -g -c -fsanitize=address -std=c++23 cell.cc

Particle.o: Particle.cc
	g++ -g -c -fsanitize=address -std=c++23 Particle.cc

Particle_System.o: Particle_System.cc 
	g++ -g -c -fsanitize=address -std=c++23 Particle_System.cc

particle_graphics.o: particle_graphics.cc colors.h
	g++ -g -c -fsanitize=address -std=c++23 particle_graphics.cc

wasserman_pj.o: wasserman_pj.cc wasserman_pj.h Particle_System.h particle_graphics.h colors.h
	g++ -g -c -fsanitize=address -std=c++23 wasserman_pj.cc

nicolas_project.o: nicolas_project.cc nicolas_project.h Particle_System.h particle_graphics.h color.h cell.h Particle.h
	g++ -g -c -fsanitize=address -std=c++23 nicolas_project.cc

clean: 
	rm -f *.o a.out

testMaybe: 
	g++ yoshsterTesting.cc cell.cc Particle.cc Particle_System.cc particle_graphics.cc -o testMaybe

main: main.o game_content.o game_plot.o saveload.o start_menu.o game_status.o ascii.o
	g++ -pedantic-errors -std=c++11 $^ -o $@
	
ascii.o: ascii.cpp ascii.h
	g++ -pedantic-errors -std=c++11 -c $<

game_status.o: game_status.cpp game_status.h
	g++ -pedantic-errors -std=c++11 -c $<

start_menu.o: start_menu.cpp start_menu.h game_status.h
	g++ -pedantic-errors -std=c++11 -c $<

saveload.o: saveload.cpp saveload.h game_status.h
	g++ -pedantic-errors -std=c++11 -c $<

game_plot.o: game_plot.cpp ascii.h start_menu.h game_status.h
	g++ -pedantic-errors -std=c++11 -c $<

game_content.o: game_content.cpp game_content.h game_plot.h saveload.h start_menu.h game_status.h ascii.h
	g++ -pedantic-errors -std=c++11 -c $<

main.o: main.cpp game_content.h game_plot.h saveload.h start_menu.h game_status.h ascii.h
	g++ -pedantic-errors -std=c++11 -c $<

clean: 
	rm -f *.o main

.PHONY:	clean

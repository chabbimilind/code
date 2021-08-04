CXX=clang++

%.o: %.cpp 
	$(CXX) -std=c++11 -c -o $@ $< 

bounded_buffer: bounded_buffer.o 
	$(CXX) -o bounded_buffer bounded_buffer.o

clean:
	rm -f *.o bounded_buffer  core

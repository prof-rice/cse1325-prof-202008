info:
	@echo
	@echo "Type 'make hello.cpp' to run the C++ version."
	@echo "Type 'make hello.c' to run the C version."
	@echo "Type 'make hello.py' to run the Python version."
	@echo "Type 'make HelloWorld.java' to run the Java version."
	@echo "    (You may need to run 'sudo apt install openjdk-14-jdk'"
	@echo "     to successfully run the Java version.)"
	@echo "Type 'make clean' to delete all built files and start over."
	@echo

.PHONY: hello.cpp hello.c hello.py HelloWorld.java clean

hello.cpp: 
	$(CXX) hello.cpp -o hello 
	./hello

hello.c:
	cc hello.c
	./a.out

hello.py:
	./hello.py

HelloWorld.java:
	javac HelloWorld.java
	java HelloWorld

clean:
	-rm -f *.o *~ *.class hello a.out

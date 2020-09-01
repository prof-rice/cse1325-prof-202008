all: hello_c hello_cpp Hello.class hello.pyc hello.ruby hello_js hello_vb hello_go 

hello_c: hello.c
	@printf "\n=   C    =\n============\n"
	-gcc hello.c -o hello_c
	-./hello_c
	
hello_cpp: hello.cpp
	@printf "\n=  C++   =\n============\n"
	-g++ hello.cpp -o hello_cpp
	-./hello_cpp

Hello.class: Hello.java
	@printf "\n=  Java  =\n============\n"
	-javac Hello.java
	-java Hello

hello.pyc: hello.py
	@printf "\n= Python =\n============\n"
	-./hello.py

hello.ruby: hello.rb
	@printf "\n=  Ruby  =\n============\n"
	-./hello.rb

hello_js: hello.html
	@printf "\n=   js   =\n============\n"
	-xdg-open hello.html
	@echo '(Look at your browser!)'

hello_go: hello.go
	@printf "\n= golang =\n============\n"
	@echo "### To install gccgo, use 'sudo apt install gccgo'"
	-gccgo -c hello.go
	-gccgo hello.o -o hello_go
	-./hello_go

hello_vb: visualbasic.ods
	@printf "\n= visual basic =\n============\n"
	@echo "### To enable VB, use Tools > Options > LibreOffice > Security > Macro Security > Medium"
	@echo "### OR in Calc: Tools > Macro > Run Macro > visualbasic.ods > Standard > HelloWorld > HelloProfRice"
	-loffice visualbasic.ods "macro:///Standard.HelloWorld.HelloProfRice()"

clean:
	-rm -f *.o *~ a.out hello hello_c hello_cpp Hello.class hello.pyc hello.ruby hello_js hello_go
	-touch visualbasic.ods

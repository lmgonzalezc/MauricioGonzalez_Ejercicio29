plot.png: Onda.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: MauricioGonzalez_Ejercicio29.cpp
	g++ MauricioGonzalez_Ejercicio29.cpp

clean:
	rm -rf a.out Onda.dat plot.png *~

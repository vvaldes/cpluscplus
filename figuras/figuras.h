
#include <iostream>

using namespace std;

class Posicion {
int _x;
int _y;
public:
	//~Posicion() {} // Definido Automaticamente por el compilador
	//Posicion(const Posicion& p) : _x(p._x), _y(p._y) {} // Definido Automatica
	//Posicion& operator=(const Posicion& p) { _x = p._x; _y = p._y; } // D.A.
	Posicion(int x = 0, int y = 0) : _x(x), _y(y) {}
	int get_x() const { return _x; }
	int get_y() const { return _y; }
};

class Figura {
protected:
	const char* _id; // accesible por las clases derivadas
	Posicion _p; // accesible por las clases derivadas
private:
	virtual void dibujar(ostream&) const = 0; // virtual pura
public:
	virtual ~Figura()
	{
		cout << _id << " en Posicion(" << _p.get_x() << ", " << _p.get_y() << ") destruido" << endl;
	}

//Figura(const Figura& f) : _id(f._id), _p(f._p) {} // D.A.
//Figura& operator= (const Figura& f) { _id = f._id; _p = f._p; } // D.A.
	Figura(const char* id, int x = 0, int y = 0) : _id(id), _p(x, y) {}
	virtual void mover(int x, int y) { _p = Posicion(x, y); }
	virtual Figura* clone() const = 0; // virtual pura

friend ostream& operator<<(ostream& sal, const Figura& fig)
{
	fig.dibujar(sal); return sal;
}
};

class Rectangulo : public Figura {
	int _base;
	int _altura;
	virtual void dibujar(ostream&) const;
public:
//virtual ~Rectangulo() {}
//Rectangulo(const Rectangulo& r)
// : Figura(r), _base(r._base), _altura(r._altura) {}
//Rectangulo& operator=(const Rectangulo& r)
// { Figura::operator=(r); _base = r._base; _altura = r._altura; }
	Rectangulo(int b, int a, int x=0, int y=0): Figura((a==b)?"Cuadrado":"Rectangulo", x, y), _base(b), _altura(a) {}
	virtual Rectangulo* clone() const { return new Rectangulo(*this); }
};

class Cuadrado : public Rectangulo {
public:
//virtual ~Cuadrado() {}
//Cuadrado(const Cuadrado& c) : Rectangulo(c) {}
//Cuadrado& operator=(const Cuadrado& c) { Rectangulo::operator=(c) {}
	Cuadrado(int b, int x=0, int y=0) : Rectangulo(b, b, x, y) {}
	virtual Cuadrado* clone() const { return new Cuadrado(*this); }
};


class Triangulo : public Figura {
	int _altura;
	virtual void dibujar(ostream&) const;
public:
//virtual ~Triangulo() {}
//Triangulo(const Triangulo& t)
// : Figura(t), _altura(t._altura) {}
//Triangulo& operator=(const Triangulo& t)
// { Figura::operator=(t); _altura = t._altura; }
	Triangulo(int a, int x=0, int y=0): Figura("Triangulo", x, y), _altura(a) {}
	virtual Triangulo* clone() const { return new Triangulo(*this); }
};

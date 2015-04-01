#include "Figure.h"


Figure::Figure() :Base()
{
	primitives = new std::vector<Base*>(0);
}

void Figure::AddPrimitiv(Base* primitiv){
	primitives->insert(primitives->end(), primitiv);
}

void Figure::Hide(){
	for (std::vector<Base*>::iterator it = primitives->begin(); it != primitives->end(); it++)
		(*it)->Hide();
}

void Figure::Show(){
	for (std::vector<Base*>::iterator it = primitives->begin(); it != primitives->end(); it++)
		(*it)->Show();
}

void Figure::Move(int dx, int dy){
	for (std::vector<Base*>::iterator it = primitives->begin(); it != primitives->end(); it++)
		(*it)->Move(dx, dy);
}

Figure::~Figure()
{
	for (std::vector<Base*>::iterator it = primitives->begin(); it != primitives->end(); it++)
		delete (*it);
	delete primitives;
}

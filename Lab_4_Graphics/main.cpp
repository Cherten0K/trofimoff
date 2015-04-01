#include "graphics.h"
#pragma comment(lib, "libbgi.a")
#include "headers.h"


int main(){
	Figure fig =  Figure();
	fig.AddPrimitiv(new Circle(50, 50, 30));
	fig.AddPrimitiv(new Line(10, 10, 50, 50));
	initwindow(400, 400, "MyWindow");
	fig.Show();
	getch();             // ждать нажатия на любую клавишу
	closegraph();        // закрыть окно с графикой
	return 0;
}
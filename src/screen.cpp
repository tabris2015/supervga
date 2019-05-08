#include "screen.h"
using namespace vga;

Screen::Screen(int max_x, int max_y)
{
    vga_init();
    vga_setmode(G1024x768x256);

}

void Screen::letra(int col, int fil, const char * punA)
{
    char aux;
    int x,y;
    aux = *punA;
    for(y=0; y<12; y++)
    {
        for(x=0; x<8; x++)
        {
            if((aux & 0x80) == 0x80)
                vga_setcolor(14);        // Letra
            else
                vga_setcolor(0);        // Fondo
            vga_drawpixel(col+x,fil+y);
            aux <<= 1;
        }
        punA++; aux = *punA;
    }
}
void Screen::linea(Punto p1, Punto p2, int color)
{
    vga_setcolor(color);
    vga_drawline(p1.x,-p1.y + max_y_,p2.x,-p2.y + max_y_);
}

void Screen::cuadro(Punto p1, Punto p2, int color)
{
    linea(p1,p1,color);
    linea(p1,p2,color);
    linea(p2,p2,color);
    linea(p2,p1,color);
}
std::vector<Punto> Screen::generarSeno(int amplitud, int x_inicial, int x_final, int delta, int offset_x, int offset_y)
{
    std::vector<Punto> resultado;
    for(int x = x_inicial; x < x_final; x += delta)
    {
	Punto aux(x + offset_x, floor(amplitud * sin(M_PI * x / 180)) + offset_y);
        resultado.push_back(aux);
    }
    return resultado;
}

std::vector<Punto> Screen::generarCoseno(int amplitud, int x_inicial, int x_final, int delta, int offset_x, int offset_y)
{
    std::vector<Punto> resultado;
    for(int x = x_inicial; x < x_final; x += delta)
    {
        Punto aux(x + offset_x, floor(amplitud*cos(M_PI*x/180)) + offset_y);
	resultado.push_back(aux);
    }
    return resultado;
}
void Screen::dibujar(std::vector<Punto>& puntos, int color)
{
    for(std::vector<Punto>::iterator it_p = puntos.begin(); it_p != puntos.end(); ++it_p)
    {
        // dibujar una linea entre el punto actual y el punto siguiente
        linea(*it_p, *(it_p + 1), color);
    }
}

Screen::~Screen()
{
    vga_setmode(TEXT);
}

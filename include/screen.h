#ifndef SCREEN_H
#define SCREEN_H
#include <vga.h>
#include <vector>
#include <math.h>
namespace vga
{

struct Punto
{
    int x;
    int y;
};



class Screen
{
private:
    /* data */
    int max_x_;
    int max_y_;
    int mid_x_;
    int mid_y_;

public:
    Screen(int max_x=1024, int max_y=768);
    void letra(int col, int fil, const char * punA);
    void linea(Punto p1, Punto p2, int color);
    void cuadro(Punto p1, Punto p2, int color);
    std::vector<Punto> generarSeno(int amplitud, int x_inicial, int x_final, int delta, int offset_x, int offset_y);
    std::vector<Punto> generarCoseno(int amplitud, int x_inicial, int x_final, int delta, int offset_x, int offset_y);
    void dibujar(std::vector<Punto>& puntos, int color);
    ~Screen();
};
    
}

#endif // !SCREEN_H
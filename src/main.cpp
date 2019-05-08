#include <stdlib.h>
#include <vga.h>
#include <math.h>
#include "letras.h"
#include "screen.h"

using vga::Punto;
using vga::Screen;

int main(void)
{
    Screen screen;      // por defecto 1024x768

    int maxx = screen.getMaxX();
    int maxy = screen.getMaxY();
    
    int midx = screen.getMidX();
    int midy = screen.getMidY();
    
    screen.cuadro(Punto(1,1),Punto(maxx-1,maxy-40),2);
    screen.letra(midx-3,45,flechaU);
    screen.letra(maxx-12,midy-3,flechaR);
    screen.linea(Punto(midx,5),Punto(midx,maxy-45),14);    // eje y
    screen.linea(Punto(5,midy),Punto(maxx-5,midy),14);     // eje x
    screen.letra(midx+5,45,Y);
    screen.letra(maxx-12,midy+5,X);

    std::vector<Punto> seno = screen.generarSeno(200, 0, 360, 5, midx, midy);
    std::vector<Punto> coseno = screen.generarCoseno(150, 0, 360, 5, midx, midy);
    screen.dibujar(seno, 33);

    vga_getch();
    vga_setmode(TEXT);

    return EXIT_SUCCESS;
}

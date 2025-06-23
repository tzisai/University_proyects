#include <conio.h>

int main() {
   clrscr();
   cprintf( "Ejemplo de \"gotoxy\"\r\n\r\n" ); 
   cprintf( "1ª línea" );
   cprintf( "2ª línea" );
   gotoxy( 5, 20 );
   cprintf( "3ª línea" );
   gotoxy( 20, 1 );
   cprintf( "4ª línea" );
   gotoxy( 1, 15 );
   cprintf( "Pulsa una tecla para continuar...\r\n" );
   getch();

   return 0;
}
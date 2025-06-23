#include <stdio.h>

int main(void){
	
	/*Hacemos uso de el codigo ascii conjunto de la herramienta de printf escribimos %c como si fuera un caracter 
	y donde corresponderia una variable colocamos el valor en ascii que correspoinderia a la letrra o simbolo en 
	ascci que queremos usar. */
	//Por ejemplo
  printf("\n%c Ponemos el acento o tilde en canel%cn\n",162, 162); 
  
  printf("\n %c %c %c %c %c %c %c %c %c %c %c %c",160,130,161,162,163,143,144,210,224,223,164,165);
  
  //á: 160 é: 130 í: 161 ó: 162 ú: 163 Á: 143 É: 144 Í: 214 Ó: 224 Ú: 223 ñ: 164 Ñ: 165
  
  
  return 0;
}
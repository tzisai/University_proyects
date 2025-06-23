#include <stdio.h>

int main(){
	char var;
	
	printf("A.altas\n");
	printf("B.bajas\n");
	printf("C.salida\n");
	printf("D.modificaciones\n");	
	printf("Elige la opcion pertinente\n");
	scanf("%c",&var);
switch(var){
	case 'A': case 'a':
		printf("elegiste altas");
		break;
	case 'B': case'b':
		printf("elegiste bajas");
		break;
	case 'C': case'c':
		printf("elegiste salida");
		break;
	case 'D': case'd':
		printf("elegiste modificaciones");
		break;
		
		default:
					printf(" \n");
		break;
}
return 0;
}



import java.util.Scanner;
public class antro{
public static void main(String[] args) {
    System.out.println("que eres?");
    System.out.println("hombre 1     mujer 2 ");
   Scanner input = new Scanner(System.in);
   String sexo_ = input.nextLine();
    int sexo = Integer.parseInt(sexo_);

   System.out.println("Cuanto mides?");
   String estatura_=input.nextLine();
   float estatura= Float.parseFloat(estatura_);

   System.out.println("cuanto dinero tienes?");
   System.out.println("Escribelo explicitamente");
   
   String dinero_=input.nextLine();
   int dinero= Integer.parseInt(dinero_);

   if((sexo==1)){
    if(estatura>=1.70){
        if(dinero>1000){
            System.out.println("puedes entrar papucho");
        }
        else{
            System.out.println("no puedes entrar mi todo tibio");            
        }
    }
    else{
        System.out.println("no puedes entrar mi todo tibio");
    }
   }

   else{
    if(dinero>1000){
        System.out.println("puedes entrar chica");
    }
    else{
        System.out.println("no puedes entrar regrese con mas dinero");            
    }
   }




}


}
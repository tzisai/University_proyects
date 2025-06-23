

public class nombres {

    public static void main(String[] args) {
       a a1 = new a();
       System.out.println("nombre de a "+a1.get_nom());
       a1.set_nom("Jose");
       System.out.println("nombre de a "+a1.get_nom());

       b b1 = new b("Alberto");
       System.out.println("nombre de b "+b1.get_nom());
       b1.set_nom("Magdalena");
       System.out.println("nombre de a "+b1.get_nom());       
    }
} 

class a {
String nombre="Juan";
int edad=23;

public String get_nom(){
return nombre;       }

  public void set_nom(String newName) {
    this.nombre = newName;
  }     }


class b {
String nombre="Maria";
int edad=230;

b(String s){
    nombre=s;
}

public String get_nom(){
return nombre;       }

  public void set_nom(String newName) {
    this.nombre = newName;
  }
}

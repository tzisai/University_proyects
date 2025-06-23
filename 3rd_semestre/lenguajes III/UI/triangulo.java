

public class triangulo{
public static void main(String[] args) {
int a=11;
int b=13;
int c=13;

if((a==b)&&(c==b)){
    System.out.println("es equilatero");
}
else{
    if((a==b)||(c==b)){
        System.out.println("es isoceles");
    }
    else{
        if((a!=b)&&(c!=b)){
            System.out.println("es escaleno");
        }
    }
}

int []arr={1,12,3,4,8,9,11,13,14};


for(int i=0;i<9;i++){
    System.out.print(" "+arr[i]);
    System.out.println("long "+arr.length);

    String w =new String(arr.toString());
System.out.println("string"+w);
}




    }
}
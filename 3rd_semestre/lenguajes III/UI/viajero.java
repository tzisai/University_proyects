public class viajero {
public static void main(String[] args) {
    int [] array= new int[10];
for (int i = 0; i < 10; i++) {
    array[i] = (int)Math.floor(Math.random()*15000+15000);

    if(array[i]>40000){
        System.out.println("El Viajero "+ (i+1)+"con "+array[i] +" pesos va a Europa");            
    }
    else{
        if((array[i]<40000) && (array[i]>25000)){
            System.out.println("El Viajero "+ (i+1)+"con "+array[i] +" pesos va a Cancun");            
        }
        else{
            if(array[i]<25000){
                System.out.println("El Viajero "+ (i+1)+"con "+array[i] +" pesos va a Guayabitos");            

            }
        }
    }



}

}
}



public class maxxd {
  public static void main(String[] args) {

    int [] array= new int[10];
    for (int i = 0; i < 10; i++) {
        array[i] = (int)Math.floor(Math.random()*25);
    }
for(int j =0;j<4;j++){
    
    System.out.println("el numero mas alto entre "+array[j]+ "y "+array[j+1]+" es " + maxmeth.maxmax(array[j], array[j+1]));
    }

}

    public class maxmeth{
        public static int maxmax(int a ,int b){
            if(a>b)
            return a;
            else
            return b;
        }
    }

}




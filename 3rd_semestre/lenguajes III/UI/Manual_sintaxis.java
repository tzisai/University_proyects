public class Manual_sintaxis{
    public static void Main(String[] args){
         /* este es un manual de java para que Isa se acuerde y aprenda como programar en JAVA
          * y talvez mi niña aprenda <3*/

        
        
        String Eli_tqm="quiero coito";

        int numero_nD=10;
        double numero_cD=3.2d;
        boolean Cond =true;
        char letra='a';
        float numero_flotante=6.99f;
        final int valor_no_moficable=23;//este tipo de (final como prefijo) variable es constante y no puede ser cambiada 
        
        int x=1,y=3,z=4;
        int a,b,c;
        a=b=c=9;//mismo valor a varias variables

        //integer types for specific size
        byte num=100;
        short nums=26000;
        int numI=2147483647;

        

        /* DataType	        Size	    Description
            byte	        1 byte	    Stores whole numbers from -128 to 127
            short	        2 bytes	    Stores whole numbers from -32,768 to 32,767
            int	            4 bytes	    Stores whole numbers from -2,147,483,648 to 2,147,483,647
            long	        8 bytes	    Stores whole numbers from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
            float	        4 bytes	    Stores fractional numbers. Sufficient for storing 6 to 7 decimal digits
            double	        8 bytes	    Stores fractional numbers. Sufficient for storing 15 decimal digits
            boolean	        1 bit	    Stores true or false values
            char	        2 bytes	    Stores a single character/letter or ASCII values
         */


        System.out.println("hello world");//print de toda la vida con salto de linea 
        System.out.print("linea sin salto de linea");//print sin salto de linea
        System.out.println((3+3));// se puede hacer operaciones dentro del print 

        System.out.println(Eli_tqm);
        String fusion=Eli_tqm+"y besos";
        System.out.println(Eli_tqm);

        String si="te amo";

        fusion+=si;//esto es equivalente a fusion= fusion+si

        System.out.println(Eli_tqm);

        //casting en java

        //wide casting (autmotic| small -> larger type of data)

        int InT=3;
        double wideningcast=InT;//<-cast in declaration int to double.

        //narrowing casting (manual casting)
        double Doublesote=9.45;
        int INTcast=(int) Doublesote;//<-double to int 

        //Operators in Java

        /*
        Operator	Name	            Description                     	        Example	
            +	    Addition	        Adds together two values	                x + y	
            -	    Subtraction	        Subtracts one value from another	        x - y	
            *	    Multiplication	    Multiplies two values	                    x * y	
            /	    Division	        Divides one value by another	            x / y	
            %	    Modulus	            Returns the division remainder	            x % y	
            ++  	Increment       	Increases the value of a variable by 1	    ++x	
            --  	Decrement       	Decreases the value of a variable by 1	    --x
            
            Operator	Example	    Same As
            =	        x = 5	x    = 5	
            +=	        x += 3	    x = x + 3	
            -=	        x -= 3	    x = x - 3	
            *=	        x *= 3	    x = x * 3	
            /=	        x /= 3	    x = x / 3	
            %=	        x %= 3	    x = x % 3	
            &=	        x &= 3	    x = x & 3	
            |=	        x |= 3	    x = x | 3	
            ^=	        x ^= 3	    x = x ^ 3	
            >>=	        x >>= 3 	x = x >> 3	
            <<=	        x <<= 3 	x = x << 3

            Operator	Name	                    Example	
            ==	        Equal to	                x == y	
            !=	        Not equal	                x != y	
            >	        Greater than	            x > y	
            <	        Less than	                x < y	
            >=	        Greater than or equal to	x >= y	
            <=	        Less than or equal to	    x <= y

            Operator	Name	            Description	                                            Example
            && 	        Logical and	       Returns true if both statements are true	                x < 5 &&  x < 10	
            || 	        Logical or	       Returns true if one of the statements is true	        x < 5 || x < 4	
            !	        Logical not	       Reverse the result, returns false if the result is true	!(x < 5 && x < 10)
         */

        //




        
        }
    }
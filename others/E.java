import javax.crypto.ExemptionMechanism;

class myException extends Exception{
public myException(String s) {
    super(s);
}
}
    
class ThrowsExecp
{
   public static void main(String[] args) //throws myException{
        int a=10;
            if(a<18) {
                throw new myException("meow");
            }
            System.out.println("hi");
        }
    }


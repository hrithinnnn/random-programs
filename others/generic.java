import java.util.*;
class Stack<E>
{  int top;
   E []data;
   public Stack(E[]arr)
   {  top=-1;
      data=arr;
   }
   Boolean isFull()
   {  if(top==data.length-1)
        return true;
      return false;
   }
   Boolean isEmpty()
   {  if(top==-1)
        return true;
      return false;
   }
   void push(E element)
   {  if(isFull()==false)
        data[++top]=element;
      else
        System.out.println("Stack overflow, cannot push element");
   }
   E pop()
   {  if(isEmpty()==false)
        return data[top--];
      else
      {  System.out.println("Stack underflow, cannot pop element");
         return null;
      }
   }
   void display()
   {  int i;
      for(i=0;i<=top;i++)
        System.out.print(data[i]+" ");
      System.out.print("\n");
   } 
}
class E7P2
{  public static void main(String[] args)
   {  Scanner input=new Scanner(System.in);
      int ch1,ch2;
      System.out.println("Enter choice for type of elements you wish to enter\n1.Integer\n2.Double\n3.Character\nEnter any element not in between 1 and 3 to stop");
      ch1=input.nextInt();
      while(ch1>=1&&ch1<=3)
      {  if(ch1==1)
         {  Integer[] a=new Integer[5];
            Stack<Integer> stack=new Stack<Integer>(a);
            System.out.println("Enter choice for operation you wish to perform\n1.Push\n2.Pop\nEnter any element not 1 and 2 to stop");
            ch2=input.nextInt();
            while(ch2==1||ch2==2)
            {  if(ch2==1)
               {  int n;
                  System.out.println("Enter element to push");
                  n=input.nextInt();
                  Integer p=n;
                  stack.push(p);
                  stack.display();
               }
               else if(ch2==2)
               {  System.out.println("Popped element: "+stack.pop());
                  stack.display();
               }
               else {
                  System.out.println("Incorrect choice");
               break;
               }
            }
         }
         else if(ch1==2)
         {  Double[] a=new Double[5];
            Stack<Double> stack=new Stack<Double>(a);
            System.out.println("Enter choice for operation you wish to perform\n1.Push\n2.Pop\nEnter any element not 1 and 2 to stop");
            ch2=input.nextInt();
            while(ch2==1||ch2==2)
            {  if(ch2==1)
               {  double n;
                  System.out.println("Enter element to push");
                  n=input.nextDouble();
                  Double p=n;
                  stack.push(p);
                  stack.display();
               }
               else if(ch2==2)
               {  System.out.println("Popped element: "+stack.pop());
                  stack.display();
               }
               else
                  System.out.println("Incorrect choice");
               System.out.println("Enter choice for operation you wish to perform\n1.Push\n2.Pop\nEnter any element not 1 and 2 to stop");
               ch2=input.nextInt();
            }
         }
         else if(ch1==3)
         {  Character[] a=new Character[5];
            Stack<Character> stack=new Stack<Character>(a);
            System.out.println("Enter choice for operation you wish to perform\n1.Push\n2.Pop\nEnter any element not 1 and 2 to stop");
            ch2=input.nextInt();
            while(ch2==1||ch2==2)
            {  if(ch2==1)
               {  char n;
                  System.out.println("Enter element to push");
                  n=input.next().charAt(0);
                  Character p=n;
                  stack.push(p);
                  stack.display();
               }
               else if(ch2==2)
               {  System.out.println("Popped element: "+stack.pop());
                  stack.display();
               }
               else
                  System.out.println("Incorrect choice");
               System.out.println("Enter choice for operation you wish to perform\n1.Push\n2.Pop\nEnter any element not 1 and 2 to stop");
               ch2=input.nextInt();
            }
         }    
         else
           System.out.println("Incorrect choice");
      }
      System.out.println("Enter choice for type of elements you wish to enter\n1.Integer\n2.Double\n3.Character\nEnter any element not in between 1 and 3 to stop");
      ch1=input.nextInt();
   }
}
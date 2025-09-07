package main;

import java.util.Scanner;

public class Bai_2 {
	public static void main(String[] args){
	     Scanner scanner = new Scanner(System.in);
	     // a)
	     System.out.println("a) ");
	     int n= scanner.nextInt();
	     int a[]=new int [n];
	     for (int i = 0;i < n; i++)
	     { 
	       a[i]=scanner.nextInt();
	       System.out.print(a[i]+" ");
	     }
	     System.out.print("\n\n");
	     // b)
	     System.out.println("b)");
	     int n1;
	     do {
	     n1= scanner.nextInt();
	     }
	     while ( n1 < 15);
	     int a1[]=new int [n1];
	     for (int i = 0;i < n1; i++)
	     { 
	       a1[i]=(int) (Math.random() * 100);
	       System.out.print(a1[i]+" ");
	     } 
	     System.out.print("\n\n");
	     // c)
	     System.out.println("c) ");
	     int x1 = 3;
	     int length= x1 + n1;
	     int a2[]=new int [length];
	     for (int i = 0;i < length; i++)
	     { 
	       if (i>=n1&&i<length){
	         a2[i]=scanner.nextInt();
	         System.out.print(a2[i]+" ");
	       }
	       else {
	       a2[i]=a1[i];
	       System.out.print(a2[i]+" ");
	       }
	     }
	     System.out.print("\n");
	     // d)
	     int a3[]=new int [length];
	     for (int i = 0;i < length; i++)
	     { 
	       a3[i]=a2[i];
	     } 
	     System.out.print("\n");
	     System.out.println("d) ");
	     System.out.println("Sau khi xoa cac so la boi cua 5: ");
	     for (int i=0;i<length;i++){
	       int p=a3[i];
	       if (p%5!=0)
	       System.out.print(a3[i]+" ");
	     } 
	     System.out.print("\n");
	     // e)
	     int a4[]=new int [length];
	     for (int i = 0;i < length; i++)
	     { 
	       a4[i]=a2[i];
	     }
	     System.out.print("\n");
	     System.out.println("e) ");
	     int x= scanner.nextInt();
	     boolean Find = false;
	     for (int i=0;i<length;i++){
	       int p=a4[i];
	       if (p==x){
	       System.out.println("Co so x trong day a");
	         Find = true;
	         break;
	       }
	     }
	    if (!Find)
	      System.out.println("Khong tim thay x trong day a");
	      System.out.print("\n");
	    // f)
	     int a5[]=new int [length];
	     for (int i = 0;i < length; i++)
	     { 
	       a5[i]=a2[i];
	     }
	     System.out.println("f) ");
	     System.out.println("Cac phan tu co so hang chuc la 1 trong day a:");
	     for (int i=0;i< length;i++) {
	       int g=(a5[i]/10)%10;
	       if (g==1){
	         System.out.print(a5[i]+" ");
	       }
	     }
	     scanner.close();
	  }
}

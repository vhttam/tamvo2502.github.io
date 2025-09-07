package main;

import java.util.Scanner;

public class Bai_1 {
	   public static void main(String[] args){
	      Scanner scanner = new Scanner(System.in);
	      // a)
	      int cd = scanner.nextInt();
	      int cr = scanner.nextInt();
	      System.out.println("Dien tich HCN: "+cd * cr);
	      System.out.println ("Chu vi HCN: "+((cd+cr)*2));
	      // b)
	      int a = scanner.nextInt();
	      int b = scanner.nextInt();
	      int c = scanner.nextInt();
	      int max = Math.max(a, b);
	      int solonnhat = Math.max(max ,c);
	      System.out.println("So lon nhat la: "+solonnhat);
	      int min = Math.min(a, b);
	      int sonhonhat = Math.min(min, c);
	      System.out.println("So nho nhat la: "+sonhonhat); 
	      // c)
	      int n =scanner.nextInt();
	      for (int i= 1; i<=n;i++){
	        if (n%i==0)
	        System.out.println(i);
	      } 
	      // d)
	      int x = scanner.nextInt();
	      int count =0;
	      while (x > 0)
	      {
	        x =x/10;
	        count++;
	      }
	      System.out.println(" X co "+ count +" So nguyen duong");
	      scanner.close();
	   }
}
	

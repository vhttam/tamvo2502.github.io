package main;

import java.util.Scanner;
import static java.lang.Math.sqrt;

public class Bai_3 {
	// g)
	// Dùng đệ quy tính Tổng của S= 1 + 2 + 3 +... + n
	private static float tinh_tong_tu_1_den_n (int n) {
		if (n==1)
			return 1;
		return tinh_tong_tu_1_den_n(n-1) + n; 
	}
	//Tính tổng của S = 1/1 + 1/2 + 1/3 + ... + 1/n
	private static float tinh_tong_phan_so (int n) {
		float m = (float) n;
		if (n==1)
			return 1;
		return tinh_tong_phan_so(n-1)+1.0f/m;
	}
	// h)
	private static int PT_Bac_2 (float a, float b, float c, double x1, double x2) {
		int n =-1;
		if (a == 0) {
			if (b == 0) {
				if (c == 0) {
					n=-1;
					System.out.println("Phuong trinh vo so nghiem");
				}
				else {
					n = 1;
					System.out.println("Phuong trinh vo nghiem");
				}
			}
			else {
				n = 0;
				x1= -c/b;
				System.out.println("Phuong trinh co 1 nghiem x = "+ x1);
			}
		}
		else {
			float delta = (b*b) - 4*(a*c);
			if (delta == 0) {
				n = 0;
				x1 = -b/(2*a);
				System.out.println("Phuong trinh co 1 nghiem x = "+ x1);
			}
			else if (delta > 0) {
				n = 2;
				x1 = (-b-sqrt(delta))/(2*a);
				x2 = (-b+sqrt(delta))/(2*a);
				System.out.println("Phuong trinh co 2 nghiem x1 = "+ x1+"   x2 = "+ x2);
			}
			else {
				n = 1;
				System.out.println("Phuong trinh vo nghiem");
			}
		}
		return n;
	}
	// i)
	private static void Perfect_Number(int x) {
		int S=0;
		for (int i = 1;i < x;i++) {
			if (x % i == 0) {
			S+=i;
			}
		}
		if (S == x)
			System.out.println(x+" la so hoan thien");
		else
			System.out.println(x+" khong phai so hoan thien");
	}
	// j)
	private static void SumElementsWithEvenDigitSum (int m) {
		int t=0;
		while (m > 0) {
			t+=(m%10);
			m/=10;
		}
		if (t % 2 == 0)
			System.out.println("So m co tong chu so la chan");
		else
		    System.out.println("So m co tong chu so la le");
	}
	// k)
	private static void splitArrayIntoTriplets (int[] a1, int p) {
		System.out.println("Sau khi chia mang a thanh cac day co 3 phan tu: ");
		for (int i = 0;i < p; i+=3) {
		int[] suba1 = new int [3];
		for (int j = 0; j < 3 && (j + i) < p;j++) {
			suba1[j] = a1[i+j];
			System.out.print(suba1[j]+" ");
		}
		System.out.print("\n");
		}
	}
	// l)
	private static void Sort (int[] a1,int p) {
		for (int i = 0;i < p-1;i++) {
			for (int j = i+1;j < p;j++) {
				if (a1[i] > a1[j]) {
					int temp = a1[i];
					a1[i]=a1[j];
					a1[j]=temp;
				}
			}
		}
		System.out.println("Mang a sau khi sap xep tu be den lon: ");
		for (int i = 0;i < p;i++) {
			System.out.print(a1[i]+" ");
		}
		System.out.print("\n");
		for (int i = 0;i < p-1;i++) {
			for (int j = i+1;j < p;j++) {
				if (a1[i] < a1[j]) {
					int temp = a1[i];
					a1[i]=a1[j];
					a1[j]=temp;
				}
			}
		}
		System.out.println("Mang a sau khi sap xep tu lon den be: ");
		for (int i = 0;i < p;i++) {
			System.out.print(a1[i]+" ");
		}
	}
	// m)
	private static void insertSumBetweenEvens (int[] a2,int p) {
		int[] temp = new int[p * 2];
		int size = 0;
		for (int i = 0;i < p;i++) {
			temp[size++] = a2[i];
			if (i < a2.length -1 && a2[i+1] % 2==0 && a2[i] % 2 == 0) {
				temp[size++] = a2[i] + a2[i+1];
			}
		}
		System.out.print("\n");
		System.out.println("Sau khi them vao giua 2 phan tu chan tong cua no:");
		for (int i = 0;i < size;i++) {
			System.out.print(temp[i]+ " ");
		}
		System.out.print("\n");
	}
	// n)
	private static void countEvenAndOdd(int[] a1, int p) {
		int Even = 0;
		int Odd = 0;
		for (int i = 0;i < p;i++) {
			if (a1[i] % 2 == 0) {
				Even++;
			}
			else
				Odd++;
		}
		System.out.println("So luong so chan trong mang a la: "+ Even);
		System.out.println("So luong so le trong mang a la: "+ Odd);
		System.out.print("\n");
	}
	// o)
	private static void findMinAndMax(int[] a1, int p) {
		int Max = a1[0];
		int Min = a1[0];
		for (int i = 1; i < p;i++) {
			if (Max < a1[i]) {
				Max = a1[i];
			}
			if (Min > a1[i]) {
				Min = a1[i];
			}
		}
		System.out.println("So lon nhat trong mang la: "+ Max);
		System.out.println("So nho nhat trong mang la: "+ Min);
		System.out.print("\n");
	}
	// p)
	private static void calculateAverage(int[] a1, int p) {
		float Average = 0;
		float Sum = 0;
		for (int i = 0; i < p;i++) {
			Sum+=a1[i];
		}
		Average = Sum/p;
		System.out.println("Trung binh cong cac phan tu trong mang a la: "+ Average);
		System.out.print("\n");
	}
    public static void main(String[] args) {
    	Scanner scan = new Scanner(System.in);
    	// Khai báo biến
    	float S, S1, a, b, c;
    	int n, x, m, p;
    	double x1 =0, x2 =0;
    	//Nhập số n
    	System.out.println("Moi nhap so n: ");
    	n= scan.nextInt();
    	// Tính toán và in ra màn hình
    	S =tinh_tong_tu_1_den_n(n);
    	System.out.println("S = 1 + 2 + 3 + ... + n = "+S);
    	S1 = tinh_tong_phan_so(n);
    	System.out.println("S = 1/1 + 1/2 + 1/3 + ... + 1/n = "+S1);
    	// Nhập 3 số a b c
    	System.out.println("Moi nhap 3 so a, b, c: ");
    	a = scan.nextFloat();
    	b = scan.nextFloat();
    	c = scan.nextFloat();
    	// Tính toán các trường hợp và in ra màn hình
    	PT_Bac_2(a,b,c,x1,x2);
    	// Nhập số x để kiểm tra hoàn thiện
    	System.out.println("Moi nhap so x de kiem tra so hoan thien: ");
    	x = scan.nextInt();
    	// Kiểm tra và in ra màn hình
    	Perfect_Number(x);
    	// Nhập số m 
    	System.out.println("Moi nhap so m: ");
    	m = scan.nextInt();
    	// Kiểm tra xem tổng có phải số chẵn không
    	SumElementsWithEvenDigitSum(m);
    	System.out.println("Moi nhap so luong phan tu cua mang: ");
    	p= scan.nextInt();
    	int a1[] = new int [p];
    	System.out.println("Moi nhap cac phan tu trong mang: ");
    	for (int i = 0;i < p;i++) {
    		a1[i]= scan.nextInt();
    	}
    	int[] a2 = new int [p];
    	for (int i = 0;i < p;i++) {
    		a2[i] = a1[i];
    	}
    	// Câu k
    	splitArrayIntoTriplets(a1,p);
    	// Câu l
    	Sort(a1,p);
    	// Câu m
    	insertSumBetweenEvens(a2,p);
    	// Câu n
    	countEvenAndOdd(a1,p);
    	// Câu o
    	findMinAndMax(a1,p);
    	// Câu p
    	calculateAverage(a1,p);
    	scan.close();
    }
}

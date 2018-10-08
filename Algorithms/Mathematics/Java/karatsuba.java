class Main {
  public static void main(String[] args) {
    System.out.print(karatsuba (923,1723));
  }
  private static int karatsuba(int x, int y){
    if (String.valueOf(x).length()==1 || (String.valueOf(y).length()==1)){
		return x*y;
    }
	  else{
		int n = Math.max(String.valueOf(x).length(),String.valueOf(y).length());
		int z = n / 2;
		int a = x /(int) Math.pow(10, z);
		int b = x %(int) Math.pow(10, z);
		int c = y /(int) Math.pow(10, z);
		int d = y %(int) Math.pow(10, z);
		int ac = karatsuba(a,c);
		int bd = karatsuba(b,d);
		int adbc = karatsuba(a+b,c+d) - ac - bd;
		return ac * (int)Math.pow(10, (2*z)) + (adbc * (int)Math.pow(10, z)) + bd;
    }
  }
}
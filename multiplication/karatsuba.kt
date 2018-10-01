fun main(args:Array<String>) {
    print(karatsuba(923, 1723))
  }
fun karatsuba(x:Int, y:Int):Int {
    if ((x).toString().length == 1 || ((y).toString().length == 1))
    {
      return x * y
    }
    else
    {
      val n = Math.max((x).toString().length, (y).toString().length)
      val z = n / 2
      val a = x / Math.pow(10.0, z.toDouble()).toInt()
      val b = x % Math.pow(10.0, z.toDouble()).toInt()
      val c = y / Math.pow(10.0, z.toDouble()).toInt()
      val d = y % Math.pow(10.0, z.toDouble()).toInt()
      val ac = karatsuba(a, c)
      val bd = karatsuba(b, d)
      val adbc = karatsuba(a + b, c + d) - ac - bd
      return ac * Math.pow(10.0, (2 * z).toDouble()).toInt() + (adbc * Math.pow(10.0, z.toDouble()).toInt()) + bd
    }
 }
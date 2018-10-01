function karatsuba(x,y){
	if (x.toString().length==1 || y.toString().length==1){
		return x*y;
  }
	else{
		var n = Math.max(x.toString().length,y.toString().length)
		var z = n / 2
		var a = x / Math.pow(10, z)
		var b = x % Math.pow(10, z)
		var c = y / Math.pow(10, z)
		var d = y % Math.pow(10, z)
		var ac = karatsuba(a,c)
		var bd = karatsuba(b,d)
		var adbc = karatsuba(a+b,c+d) - ac - bd
		return ac * Math.pow(10, 2*z) + (adbc * Math.pow(10, z)) + bd
  }
}

console.log(karatsuba (923,1723))
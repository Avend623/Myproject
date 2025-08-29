let a = 10,
  b = "20",
  c = 80;
/*
  console.log(++a + +b++ + +c++ - +a++);
	++a 11 pre increament
	+ addition operator
	+ unary plus
	b++ post increament 20
	+ add operator
	+ unary plus
	c++ post increament 80
	- subtraction operator
	+ unary plus 
	a++ post increament 10
	total : 100
*/
/*
	console.log(++a + -b + +c++ - -a++ + +a);
	++a pre increament 11
	+ addition operator
	-b unary negative -20
	+ addition operator
	+ unary plus
	c++ post increament 80
	- subtraction operator
	- unary negative -10
	a++ post increament -10
	+ addition operator 
	+a unary plus 10
	total :  94
	*/
/*
	console.log(--c + +b + --a * +b++ - +b * a + --a - +true);
	--c pre decreament 70
	+ addition operator
	+b unary plus 20
	+ addition operator
	--a pre decreament
	* multiplication operator
	+b unary plus 20
	b++ post increament 20
	- subtraction operator
	+b unary plus 20
	* multiplication operator
	a 10 
	+ addition operator
	--a pre decreament 9
	- subtraction operator
	+true unary plus 1
	total : 97
*/
/*
let d = "-100";
let e = "20";
let f = 30;
let g = true;
console.log(-d * +e);
console.log(++g * +(++e) + ++f + -d); // 173
*/

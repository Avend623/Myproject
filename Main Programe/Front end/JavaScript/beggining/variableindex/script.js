/*
	Var
	- Redeclare (Yes)
	- Access before Declare (Undefined)
	- Variable scope Drama [Added To window] (yes)
	- Block or functionn scope (function scope)
*/
/*
	Let
	- Redeclare (No => Error)
	- Access before Declare (Error)
	- Variable scope Drama (no)
	- Block or functionn scope (block scope)
*/
/*
	Const
	- Redeclare (No => Error)
	- Access before Declare (Error)
	- Variable scope Drama (no)
	- Block or functionn scope (block scope)
*/
var aabb = 1;
let a = 1;
if (a === aabb) {
  let a1 = 1;
  console.log(a1);
}

console.log(a1);

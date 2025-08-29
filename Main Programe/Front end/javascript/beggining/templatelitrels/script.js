/*
	Template literls (Template strings)
*/
let title = "Avend";
let desc = "Avend akreyi";
let markup = `
	<div class="card">
		<div class=child>
		<h2> ${title} </h2>
		<p> ${desc} </p>
		</div>
	</div>
`;
document.writeln(markup);

// variable and concatenation chalenge ==

let Title_Content = "Elzero",
  Desc_content = "Elzero Web school",
  Date_content = "25/10";

let markup = `
	<div class="Card">
	<h3> Hello ${Title_Content} </h3>
	<p> ${Desc_content} </p>
	<span> ${Date_content} </span>
	</div>
`;
document.writeln(markup.repeat(4));

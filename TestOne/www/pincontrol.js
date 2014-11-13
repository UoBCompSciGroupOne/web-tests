function lightup() {
	$('#message').load('/arduino/lightup');
	document.getElementById("message").style.color = "green";
};

function lightdown() {
	$('#message').load('/arduino/lightdown');
	document.getElementById("message").style.color = "red";
};
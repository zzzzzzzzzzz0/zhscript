function $(id) {
	return document.getElementById(id);
}
document.oncontextmenu = function() {window.event.returnValue = false;};
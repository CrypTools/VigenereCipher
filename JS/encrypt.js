/*****************************

Use: "Hello World".encrypt("key")
=> "RIJVSUYVJN"

******************************/
function ordA(a) {
    return a.charCodeAt(0) - 65;
}
String.prototype.encrypt = function (key) {
	let i = 0;
    let b;
    key = key.toUpperCase().replace(/[^A-Z]/g, '');
    return this.toUpperCase().replace(/[^A-Z]/g, '').replace(/[A-Z]/g, a => {
        b = key[i++ % key.length];
        return String.fromCharCode(((ordA(a) + ordA(b)) % 26 + 65));
    });
}

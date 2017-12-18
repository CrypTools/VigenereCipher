/**********************************

Use: "RIJVSUYVJN".decrypt("key")
=> "HELLOWORLD"

**********************************/
function ordA(a) {
    return a.charCodeAt(0) - 65;
}
String.prototype.decrypt = function (key) {
	let i = 0;
    let b;
    key = key.toUpperCase().replace(/[^A-Z]/g, '');
    return this.toUpperCase().replace(/[^A-Z]/g, '').replace(/[A-Z]/g, a => {
        b = key[i++ % key.length];
        return String.fromCharCode(((ordA(a) + 26 - ordA(b)) % 26 + 65));
    });
}

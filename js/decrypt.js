/**********************************

Use: "RIJVSUYVJN".decrypt("key")
=> "HELLOWORLD"

**********************************/

String.prototype.decrypt = function(key) {
	function ordA(a) {
		return a.charCodeAt(0) - 65;
	}
	let i = 0;
	let b;
	key = key.toUpperCase().replace(/[^A-Z]/g, '');
	return this.toUpperCase().replace(/[^A-Z]/g, '').replace(/[A-Z]/g, a => {
		b = key[i++ % key.length];
		return String.fromCharCode(((ordA(a) + 26 - ordA(b)) % 26 + 65));
	});
}
module.exports = (text, key) => text.decrypt(key)

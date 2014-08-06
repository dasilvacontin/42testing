
function replaceAll(find, replace, str) {
	  return str.replace(new RegExp(find, 'g'), replace);
}

var fs = require('fs');

function processFile(path) {

	fs.readFile(path, function (err, data) {
		if (err) throw err;
		
		data = data.toString();

		data = replaceAll('</span>', '\\e[0m', data);

		//White
		data = replaceAll('<span style="color: #ffffff;">', '\\e[0;37m', data);
		data = replaceAll('<span style="color: #ebebeb;">', '\\e[0;37m', data);

		//Blue -> cyan
		data = replaceAll('<span style="color: #36b5d4;">', '\\e[0;36m', data);
		data = replaceAll('<span style="color: #64d4ee;">', '\\e[0;36m', data);
		data = replaceAll('<span style="color: #97ecff;">', '\\e[0;36m', data);

		//dark blue -> blue
		data = replaceAll('<span style="color: #1a7290;">', '\\e[0;34m', data);

		//Purple
		data = replaceAll('<span style="color: #c962cf;">', '\\e[0;35m', data);
		data = replaceAll('<span style="color: #b7359f;">', '\\e[0;35m', data);
		data = replaceAll('<span style="color: #842079;">', '\\e[0;35m', data);
		//grey
		data = replaceAll('<span style="color: #d8d8d8;">', '\\e[1;37m', data);
		data = replaceAll('<span style="color: #b7b7b7;">', '\\e[1;37m', data);

		//rose
		data = replaceAll('<span style="color: #ffdcfe;">', '\\e[1;35m', data);
		data = replaceAll('<span style="color: #ffb7fd;">', '\\e[1;35m', data);
		data = replaceAll('<span style="color: #f467d1;">', '\\e[1;35m', data);
		data = replaceAll('<span style="color: #ef8aed;">', '\\e[1;35m', data);
		data = replaceAll('<span style="color: #fc95e3;">', '\\e[1;35m', data);

		//black
		data = replaceAll('<span style="color: #000000;">', '\\e[0;30m', data);

		//green
		data = replaceAll('<span style="color: #a3bd53;">', '\\e[0;32m', data);
		data = replaceAll('<span style="color: #dbe082;">', '\\e[0;32m', data);
		data = replaceAll('<span style="color: #81a038;">', '\\e[0;32m', data);
		data = replaceAll('<span style="color: #8f9335;">', '\\e[0;32m', data);

		//yellow
		data = replaceAll('<span style="color: #f9f6ab;">', '\\e[0;33m', data);
		data = replaceAll('<span style="color: #f9f686;">', '\\e[0;33m', data);
		data = replaceAll('<span style="color: #dede56;">', '\\e[0;33m', data);

		data = replaceAll('<pre style="font: 12px/6px monospace;">', '', data);

		data = replaceAll('</pre>', '', data);

		console.log(data);

	});

}

process.argv.forEach(function(val, index, array) {
	if (index > 1)	processFile(val);
});

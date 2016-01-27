//Create a nodejs Server
//import required modules
var http = require("http");

//build the server and set to listen at port 8081
http.createServer(function (request, response) {
	//send the HTTP header
	//http status 200 : OK
	//Content Type: text/plain
	response.writeHead(200, {'Content-Type': 'text/plain'});

	//send the response body
	response.end('Hello World\n')
}).listen(8081);

//check server running status
console.log('Server running at http://127.0.0.1:8081/');

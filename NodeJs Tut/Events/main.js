// import events module
var events = require('events');
// create an event emitter object
var eventEmitter = new events.EventEmitter();

//Create an event handler
var connectionHandler = function connected() {
	console.log('connection succesful.');

	////fire the data_received event
	eventEmitter.emit('data_received');
}

//bind the connection event with the handler
eventEmitter.on('connection', connectionHandler);

//bind the data_received event with the anonymous function
eventEmitter.on('data_received', function() {
	console.log('data recived succesfully.');
});

//fire the connection event
eventEmitter.emit('connection');

console.log("program ended.");
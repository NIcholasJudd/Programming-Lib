var events = require('events');
var eventEmitter = new events.EventEmitter();

//listener 1
var listener1 = function listener1() {
	console.log('listener1 executed.');
};

// Listner #2
var listner2 = function listner2() {
	console.log('listner2 executed.');
};

//bind the connection event with the listner1 function
eventEmitter.addListener('connection', listener1);

//bind the connection event with listener 2 function
eventEmitter.on('connection', listner2);

var eventListeners = require('events').EventEmitter.listenerCount(eventEmitter, 'connection');
console.log(eventListeners + " Listner(s) listening to connection event");

//fire the connection event
eventEmitter.emit('connection');

//remove the binding of listner1 function
eventEmitter.removeListener('connection', listener1);
console.log("listner1 will not listen now.");

//fire the connection event
eventEmitter.emit('connection');
eventListeners = require('events').EventEmitter.listenerCount(eventEmitter, 'connection');
console.log(eventListeners + " listener(s) listening to connection event");

console.log("program ended.");
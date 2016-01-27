var models = require('../models');
var express = require('express');
var router = express.Router();
// creates a new user
router.post('/create', function(req, res) {
    console.log("HELP");
	models.User.create({
		firstName: req.body.firstName,
		lastName: req.body.lastName,
		phoneNumber: req.body.phoneNumber
	}).then(function() {
		res.redirect('/');
	});
});

//gets all users
router.get('/getUsers', function(req, res) {
    models.User.findAll().then(function(users){
        res.send(users);
    });
});

//deletes a user
router.get('/:user_id/destroy', function(req, res) {
	models.User.destroy({
		where:  {
			id: req.params.user_id
		}
	}).then(function() {
		res.redirect('/');
	});
});

module.exports = router;

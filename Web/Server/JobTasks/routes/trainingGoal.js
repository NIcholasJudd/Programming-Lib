/**
 * Created by nicholasjudd on 19/12/2015.
 */
var models = require('../models');
var express = require('express');
var router = express.Router();

// creates a new training goal
router.post('/create/:user_id', function(req, res) {
    models.TrainingGoal.create({
        UserId:     req.params.user_id,
        title:      req.body.title,
        startDate:  req.body.startDate,
        endDate:    req.body.endDate
    }).then(function() {
        res.redirect('/');
    }, function (error){
        console.log(error);
    });
});
// gets all training goals for user via user table pk
router.get('/getGoals/:user_id', function(req, res) {
    models.TrainingGoal.findAll({
        where: {
            UserId: req.params.user_id
        }
    }).then(function(TrainingGoal){
        res.send(TrainingGoal);
    });
});
//deletes a goal vis user table pk and training goal pk
router.get('/:user_id/trainingGoal/:trainingGoal_id/destroy', function (req, res) {
    models.TrainingGoal.destroy({
        where: {
            id: req.params.trainingGoal_id
        }
    }).then(function() {
        res.redirect('/');
    });
});

module.exports = router;
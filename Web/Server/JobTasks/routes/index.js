var models  = require('../models');
var express = require('express');
var router  = express.Router();


//sets up the user db call route
router.get('/user', function(req, res) {

  models.User.findAll({
  }).then(function(users) {
    res.render('index', {
      title: 'Express',
      users: users
    }, function (error) {
      console.log(error);
    })
  });
});

//sets up the Training Goal db call route
router.get('/TrainingGoal', function(req, res) {
    models.TrainingGoal.findAll({
        include: [
            models.User,
            models.TrainingSchedule
        ]
    }).then(function(TrainingGoal) {
        res.render('index', {
            title: 'Express',
            TrainingGoals: TrainingGoals
        }, function (error) {
            console.log(error);
        })
    });
});

//sets up the Training Schedule db call route
router.get('/TrainingSchedule', function(req, res) {
    models.TrainingSchedule.findAll({
        include: [
            models.TrainingGoal,
            models.User
        ]
    }).then(function(TrainingSchedule) {
        res.render('index', {
            title: 'Express',
            TrainingGoals: TrainingSchedule
        }, function (error) {
            console.log(error);
        })
    });
});

module.exports = router;
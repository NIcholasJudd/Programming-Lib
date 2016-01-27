/**
 * Created by nicholasjudd on 19/12/2015.
 */
var con = require("../config.js");
var models = require('../models');
var express = require('express');
var router = express.Router();
var twilloCon = require('../twillo.js');
var cronJob = require('cron').CronJob;
var dateFormat = require('dateformat');
var sms = {
    name: "",
    phone: "",
    day: "",
    type: "",
    time: "",
    length: "",
    intensity: "",
    message: ""
};

//converts our data type for day to a int value for our cron tasks
function convertDay(day){
    if (day =='sunday'){
        return 0;
    }
    if (day =='monday'){
        return 1;
    }
    if (day =='tuesday'){
        return 2;
    }
    if (day =='wednesday'){
        return 3;
    }
    if (day =='thursday'){
        return 4;
    }
    if (day =='friday'){
        return 5;
    }
    if (day =='saturday'){
        return 6;
    }

}

//sets up our cron tasks and gets the sms message ready to be sent.
function sendSMS(sms) {
    //cron job format = ( min hour dayOfMonth month dayOfWeek year )
    var textJob = new cronJob(dateFormat(sms.time, "MM") +' '+ dateFormat(sms.time, "HH")+' * * ' + convertDay(sms.day) , function () {
        twilloCon.client.sms.messages.create({
            to: sms.phone,
            from: con.twillo_AccountNumber,
            body: 'Hi ' + sms.name + ' ' + sms.type + ' for ' + sms.length + 'min at ' + sms.intensity + 'intensity ' +
            sms.message,
        }, function (err, data) {

        });
    }, null, true);
}
// creates a new goal + gets base user data to prepare and set up text message for cron job
router.post('/create/:user_id/:goal_id', function(req) {
    models.User.findOne({
        where:
        {
            id: req.params.user_id
        }
    }
    ).then(function(users){
        sms.phone = users.phoneNumber;
        sms.name = users.firstName + ' ' + users.lastName;
    });
    console.log("TEST 1");
    console.log(req.body.time);
    sms.type = req.body.type;
    sms.day = req.body.day;
    sms.time = new Date(req.body.time);
    sms.length = req.body.length;
    sms.intensity = req.body.intensity;
    sms.message = req.body.message;
    models.TrainingSchedule.create({
        UserId          : req.params.user_id,
        TrainingGoalId  : req.params.goal_id,
        type            : req.body.type,
        day             : req.body.day,
        time            : req.body.time,
        length          : req.body.length,
        intensity       : req.body.intensity,
        message         : req.body.message
    }).then(function(req, res) {
        sendSMS(sms);
    }), function (error){
        console.log(error);
    };
});
module.exports = router;
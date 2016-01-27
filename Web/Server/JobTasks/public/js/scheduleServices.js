/**
 * Created by nicholasjudd on 19/12/2015.
 */
myApp.factory('scheduleFactory', function($http) {
    return {
        //creates a new schedule
        createSchedule: function(schedule) {
            console.log(schedule);
            return $http.post('/TrainingSchedule/create/' + schedule.cID + '/' + schedule.gID, {
                type: schedule.type,
                day:    schedule.day,
                time:   schedule.alertTime,
                length: schedule.duration,
                intensity: schedule.intensity,
                message: schedule.message
            })
        },
        //gets schedules
        getSchedule: function() {
            return $http.get('/TrainingSchedule/getSchedule');
        }
    }
});
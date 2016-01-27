/**
 * Created by nicholasjudd on 18/12/2015.
 */
myApp.factory('goalFactory', function($http) {
    return {
        //create a goal via the user id
        createGoal: function(goal) {
            return $http.post('/TrainingGoal/create/' + goal.cID, {
                title : goal.title,
                startDate : goal.sDate,
                endDate : goal.eDate
            })
        },
        //get the goal from the db via the user id
        getGoals: function(goal) {
            console.log(goal);
            return $http.get('/TrainingGoal/getGoals/' + goal.cID);
        }
    }
});

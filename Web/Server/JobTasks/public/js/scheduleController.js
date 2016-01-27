/**
 * Created by nicholasjudd on 19/12/2015.
 */
myApp.controller("scheduleController", ['$scope', 'userFactory', 'goalFactory', 'scheduleFactory',
    function ($scope, userFactory, goalFactory, scheduleFactory) {
        $scope.schedule={};
        $scope.selectedUser={};
        $scope.selectedGoal={}
        $scope.Users = [];
        //gets the users fromt he db
        userFactory.getUsers().then(function (results) {
            results.data.forEach(function (user) {
                $scope.Users.push({
                    name: user.firstName + ' ' + user.lastName,
                    id: user.id
                })
            })
            console.log($scope.Users);
        }, function (error) {
            var msg = "get user failed: " + error;
            console.log(error);
            alert(msg);
        });

        //sets the selected user on the form
        $scope.setUser = function (user) {
            $scope.goal={};
            $scope.selectedUser = user;
            $scope.goal.cID = user.id;
            $scope.schedule.cID = user.id;
            getGoalList();
        };

        //sets the selected goal on the form
        $scope.setGoal = function (goal) {
            $scope.selectedGoal = goal;
            $scope.schedule.gID = goal.id;
        };

        $scope.goalList=[];
        //gets the goal list from the db
        function getGoalList() {
            console.log($scope.goal);
            goalFactory.getGoals($scope.goal).then(function (results) {
                    $scope.goalList = results.data;
                    console.log($scope.goalList);
                },
                function (error) {
                    var msg = "Create user failed: " + error;
                    console.log(error);
                    alert(msg);
                })
        }
        //submits the form data and creates a new schedule
        $scope.submitSchedule = function () {
            scheduleFactory.createSchedule($scope.schedule).then(function (data) {
                alert($scope.schedule.title + ' successfully saved in database');
            }, function (error) {
                var msg = "Create user failed: " + error;
                console.log(error);
                alert(msg);
            })

        };
    }
]);
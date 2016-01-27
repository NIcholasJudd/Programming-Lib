/**
 * Created by nicholasjudd on 18/12/2015.
 */

myApp.controller("goalController", ['$scope', 'userFactory', 'goalFactory',
    function ($scope, userFactory, goalFactory) {
        $scope.selectedUser = {};
        $scope.Users = [];
        getUserList();
        //sets the user int he form
        $scope.setUser = function (user) {
            $scope.selectedUser = user;
            $scope.goal.cID = user.id;
        };
        $scope.goalList = [];
        $scope.goal = {
            cID: "",
            title: "",
            sDate: "",
            eDate: ""
        };


//submits the form data and creates a goal
$scope.submitGoal = function () {
    console.log($scope.goal);
    goalFactory.createGoal($scope.goal).then(function (data) {
        alert($scope.goal.title + ' successfully saved in database');
    }, function (error) {
        var msg = "Create user failed: " + error;
        console.log(error);
        alert(msg);
    })

};
//gets the user list
function getUserList() {
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
}
}
])
;
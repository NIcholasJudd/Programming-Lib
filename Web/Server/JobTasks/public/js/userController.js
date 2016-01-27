/**
 * Created by nicholasjudd on 18/12/2015.
 */

var myApp = angular.module('app',[]);
myApp.controller("userController", ['$scope', 'userFactory',
    function ($scope, userFactory) {
        //pre declares the user array
        $scope.user = [{
            firstName: "",
            lastName: "",
            phone: ""
        }];

        //submit function the takes data from the form and pushes it to the db
        $scope.submitUser = function () {
            userFactory.createUser($scope.user).success(function (err, res) {
                alert($scope.user.firstName + ' successfully saved in database');
            }).error(function (err, res) {
                var msg = "Create user failed: " + err;
                console.log(err);
                alert(msg);
            })
        };
    }
]);
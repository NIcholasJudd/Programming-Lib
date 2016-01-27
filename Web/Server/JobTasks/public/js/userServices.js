/**
 * Created by nicholasjudd on 18/12/2015.
 */

myApp.factory('userFactory', function($http) {
    return {
        //createUser is the call to create a user
        createUser: function(user) {
            console.log(user);
            return $http.post('/users/create', {
                firstName: user.firstName,
                lastName: user.lastName,
                phoneNumber: user.phone
            })
        },
        //getUsers is the call to get all users
        getUsers: function() {
            return $http.get('/users/getUsers');
        }

    }
});
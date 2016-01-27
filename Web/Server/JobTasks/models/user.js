"use strict";

module.exports = function (sequelize, DataTypes) {
    var User = sequelize.define("User", {
        firstName: {
            type: DataTypes.STRING,
            field: "first_name"
        },
        lastName: {
            type: DataTypes.STRING,
            field: "last_name"
        },
        phoneNumber: {
            type: DataTypes.STRING(12),
            field: "phone_number"
        }
    }, {
        classMethods: {
            associate: function (models) {
                User.hasMany(models.TrainingGoal)
            }
        }
    });

    return User;
};
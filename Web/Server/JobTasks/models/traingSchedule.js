"use strict";

module.exports = function(sequelize, DataTypes) {
  var trainingSchedule = sequelize.define("TrainingSchedule", {
    type: {
      type: DataTypes.STRING
    },
    day: {
      type: DataTypes.ENUM('monday', 'tuesday', 'wednesday', 'thursday', 'friday', 'saturday', 'sunday')
    },
    time: {
      type: DataTypes.DATE
    },
    length: {
      type: DataTypes.STRING
    },
    intensity: {
      type: DataTypes.ENUM('low', 'medium', 'high')
    },
    message: {
      type: DataTypes.STRING
    }
  }, {
    classMethods: {
      associate: function(models) {
        trainingSchedule.belongsTo(models.User, {
          onDelete: "CASCADE",
          foreignKey: {
            allowNull: false
          }
        });
        trainingSchedule.belongsTo(models.TrainingGoal, {
          onDelete: "CASCADE",
          foreignKey: {
            allowNull: false
          }
        });
      }
    }
  });

  return trainingSchedule;
};
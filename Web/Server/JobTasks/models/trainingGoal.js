"use strict";

module.exports = function(sequelize, DataTypes) {
  var TrainingGoal = sequelize.define("TrainingGoal", {
    title: {
      type: DataTypes.STRING
    },
    startDate: {
      type: DataTypes.DATE,
      field: "start_date"
    },
    endDate: {
      type: DataTypes.DATE,
      field: "end_date"
    }
  }, {
    classMethods: {
      associate: function(models) {
        TrainingGoal.belongsTo(models.User, {
          onDelete: "CASCADE",
          foreignKey: {
            allowNull: false
          }
        });
      }
    }
  });

  return TrainingGoal;
};
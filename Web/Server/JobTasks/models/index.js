var fs        = require("fs");
var path      = require("path");
var Sequelize = require("sequelize");
var con = require("../config.js");
var db        = {};

//connect to database
var sequelize = new Sequelize (con.db_Db, con.db_User, con.db_Password, {
		dialect: 'postgres',
		port: "5432",
		host: 'localhost' 
	});

//finds all model js files minus the current file
fs
  .readdirSync(__dirname)
  .filter(function(file) {
    console.log(__dirname);
    console.log(file);
    return (file.indexOf(".") !== 0) && (file !== "index.js");
  })
  .forEach(function(file) {
    var model = sequelize.import(path.join(__dirname, file));
    db[model.name] = model;
  });

Object.keys(db).forEach(function(modelName) {
  if ("associate" in db[modelName]) {
    db[modelName].associate(db);
  }
});

db.sequelize = sequelize;
db.Sequelize = Sequelize;

module.exports = db;
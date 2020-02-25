var fs = require('fs');

function read(fPath) {
    return new Promise( function(resolve,reject) {
          fs.readFile(path, function (err, data) {
              if(err) return reject(err);
              return resolve(data);
          });
        }
    );
}

read('./students.txt').then(console.log);
/*
 * problem statement
	Before your interview, write a program that runs a server that is accessible on 
	http://localhost:4000/. When your server receives a request on 	
	http://localhost:4000/set?somekey=somevalue it should store the passed key and value 
	in memory. When it receives a request on http://localhost:4000/get?key=somekey it should 
	return the value stored at somekey  
*/

const express = require('express');
const fs = require('fs');
const app = express();
const port = 4000;
var pair = [];

app.get('/', (req, res) => {
	res.write("hello world");
	res.end();
});

app.get('/set', (req, res) => {
	console.log(req.query);
    pair.push(req.query);

	var result = JSON.stringify(pair);

	fs.writeFileSync('./log.txt', result, {encoding:'utf-8', flag:'w'});
	console.log("json objects stored in file");

	res.send("variables set");

});

app.get('/get', (req, res) => {
	var key = req.query.key;

	var data = fs.readFileSync('./log.txt', 'utf8');

	var result2 = JSON.parse(data);
	console.log("parsed result");
	console.log(result2);
//	res.send("value:" + " " + pair[0][key]);

	for(let i=0; i<pair.length; i++){
		if(pair[i].hasOwnProperty(key)){
			res.send("value:" + " " + pair[i][key]);
		}
	}
});

app.listen(port, () => {
	console.log(`server running on port ${port}`);
});





























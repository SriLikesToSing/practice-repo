
const http = require('http');
const express = require('express');
const app = express();

const hostname = '127.0.0.1';
const port = 3000;

app.get('/', function(req, res){
	res.render(path.join(__dirname, '/public/index.html'));
});

app.listen(port, () => {
	console.log(`Server running at http://${hostname}:${port}/`);
});

















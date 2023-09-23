const express = require('express');
const bodyParser = require('body-parser');
const app = express();

// Enable CORS
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});


// Dummy shop data
const shops = [
  { name: 'Shop 1', latitude: 40.12345, longitude: -74.54321 },
  { name: 'Shop 2', latitude: 40.54321, longitude: -74.12345 }
];

app.post('/nearestShop', (req, res) => {
  const { userLatitude, userLongitude } = req.body;

  // Calculate nearest shop
  let nearestShop = null;
  let shortestDistance = Number.MAX_VALUE;

  for (const shop of shops) {
    const distance = calculateDistance(userLatitude, userLongitude, shop.latitude, shop.longitude);
    if (distance < shortestDistance) {
      shortestDistance = distance;
      nearestShop = shop;
    }
  }

  res.json({ nearestShop });
});

function calculateDistance(lat1, lon1, lat2, lon2) {
  // any other function
  return Math.abs(lat1 - lat2) + Math.abs(lon1 - lon2);
}

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
